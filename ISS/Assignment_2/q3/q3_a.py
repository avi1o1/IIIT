import json
import requests as req
from bs4 import BeautifulSoup
import matplotlib.pyplot as plt
import pymysql
import pymysql.cursors

# Scraping the top 250 shows from the IMDB website
def scrapeTop250() -> list[list[str]]:
    # Creating a user, to access IMDB site remotely
    header = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3"}
    # Retrieving the top 250 shows from the IMDB website (in form of HTML code)
    response = req.get("https://www.imdb.com/chart/toptv/?ref_=nv_tvv_250/", headers=header)
    soup = BeautifulSoup(response.text, "html.parser")

    # Extracting the top 250 shows from the HTML code
    top250 = soup.find_all("script", type="application/json")
    jsonFile = json.loads(top250[0].text)
    top250List = []

    for ele in jsonFile['props']['pageProps']['pageData']['chartTitles']['edges']:
        # Extracting Show Name, Rating, Genre, Number of Episodes
        title = ele['node']['titleText']['text'].replace("'", "")
        rating = ele['node']['ratingsSummary']['aggregateRating']
        count = ele['node']['episodes']['episodes']['total']
        genres = ""
        for genre in ele['node']['titleGenres']['genres']:
            genres += genre['genre']['text'] + ', '
        
        # Adding data to the temporary list
        top250List.append([title, rating, genres[:-2], count])
    
    # Returning the list of lists containing all the useful information
    return top250List

# Saving the top 250 shows to a MySQL server
def saveToDatabase(lst: list[list[str]]) -> None:
    # Setting up the connection to the MySQL server
    mydb = pymysql.connect(host="localhost", user="root", password="urmomgey")
    mycursor = mydb.cursor()

    # Check if 'topShows' database exists, if not create one
    mycursor.execute("SHOW DATABASES LIKE 'topShows'")
    if not mycursor.fetchone():
        mycursor.execute("CREATE DATABASE topShows")

    # Open the 'topShows' database
    mycursor.execute("USE topShows")

    # Creating a table if it does not exist
    mycursor.execute("SHOW TABLES LIKE 'Top250'")
    if not mycursor.fetchone():
        mycursor.execute("CREATE TABLE Top250(Title VARCHAR(255), Rating VARCHAR(255), Genre VARCHAR(255), EpisodeCount VARCHAR(255))")

        # Inserting the data into the table
        for ele in lst:
            mycursor.execute(f"INSERT INTO Top250 (Title, Rating, Genre, EpisodeCount) VALUES ('{ele[0]}', '{ele[1]}', '{ele[2]}', '{ele[3]}')")

    mydb.commit()
    return None

# Plotting a line graph for genre (on x-axis) vs frequency (on y-axis)
def plotGraph1() -> None:
    # Setting up the connection to the MySQL server
    mydb = pymysql.connect(host="localhost", user="root", password="urmomgey")
    mycursor = mydb.cursor()

    # Check if 'topShows' database exists, if not create one
    mycursor.execute("SHOW DATABASES LIKE 'topShows'")
    if not mycursor.fetchone():
        print("No database to plot from.")
        return None

    # Open the 'topShows' database
    mycursor.execute("USE topShows")

    # Checking if the table exists
    mycursor.execute("SHOW TABLES LIKE 'Top250'")
    if not mycursor.fetchone():
        print("No table to plot")
        return None

    # Extracting the data from the table
    mycursor.execute("SELECT Genre FROM Top250")
    data = mycursor.fetchall()

    # Counting the frequency of each genre
    genreFreq = {}
    for ele in data:
        genres = ele[0].split(", ")
        for genre in genres:
            if genre in genreFreq:
                genreFreq[genre] += 1
            else:
                genreFreq[genre] = 1
    
    # Plotting the graph
    plt.bar(list(genreFreq.keys()), list(genreFreq.values()))
    plt.xlabel("Genre")
    plt.ylabel("Frequency")
    plt.xticks(rotation=90)
    plt.title("Genre vs Frequency")
    plt.show()
    return None

# Plotting a line graph for no of episodes (on x-axis) vs frequency (on y-axis)
def plotGraph2() -> None:
    # Setting up the connection to the MySQL server
    mydb = pymysql.connect(host="localhost", user="root", password="urmomgey")
    mycursor = mydb.cursor()

    # Check if 'topShows' database exists, if not create one
    mycursor.execute("SHOW DATABASES LIKE 'topShows'")
    if not mycursor.fetchone():
        print("No database to plot from.")
        return None

    # Open the 'topShows' database
    mycursor.execute("USE topShows")

    # Checking if the table exists
    mycursor.execute("SHOW TABLES LIKE 'Top250'")
    if not mycursor.fetchone():
        print("No table to plot")
        return None

    # Extracting the data from the table
    mycursor.execute("SELECT EpisodeCount FROM Top250")
    data = mycursor.fetchall()

    # Counting the frequency of each genre
    episodeFreq = {}
    for ele in data:
        if int(ele[0]) in episodeFreq:
            episodeFreq[int(ele[0])] += 1
        else:
            episodeFreq[int(ele[0])] = 1
    
    # Plotting the graph
    import numpy as np

    episodeFreq = dict(sorted(episodeFreq.items(), key=lambda item: int(item[0])))
    plt.plot(list(episodeFreq.keys()), list(episodeFreq.values()), marker='o', linestyle='-')
    plt.xlabel("Number of Episodes")
    plt.ylabel("Frequency")
    plt.title("Number of Episodes vs Frequency")
    x_values = list(episodeFreq.keys())
    max_x = max(x_values)
    plt.xticks(np.arange(0, max_x, step=100))

    plt.show()
    return None

if __name__ == "__main__":
    # Scraping the top 250 shows from the IMDB website
    top250 = scrapeTop250()
    # for ele in top250:
    #     print(ele)
    
    # Adding data to the MySQL server
    saveToDatabase(top250)

    # Graphing
    plotGraph1()
    plotGraph2()
