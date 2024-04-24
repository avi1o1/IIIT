import pymysql
import pymysql.cursors
from wordcloud import WordCloud
import matplotlib.pyplot as plt

# Retrieving data from MySQL server
def getShowList():
    # Setting up the connection to the MySQL server
    mydb = pymysql.connect(host="localhost", user="root", password="urmomgey")
    mycursor = mydb.cursor()

    # Check if 'topShows' database exists, if not create one
    mycursor.execute("SHOW DATABASES LIKE 'topShows'")
    if not mycursor.fetchone():
        print("No database found.")
        return None

    # Open the 'topShows' database
    mycursor.execute("USE topShows")

    # Checking if the table exists
    mycursor.execute("SHOW TABLES LIKE 'Top250'")
    if not mycursor.fetchone():
        print("No table found.")
        return None

    # Extracting the data from the table
    mycursor.execute("SELECT Title, Rating FROM Top250")
    data = mycursor.fetchall()
    return data


# Function to create a word cloud
def createWordCloud(data: dict) -> None:
    # Given a dictionary, create a word cloud out of its keys, such that the key with the largest value has the largest size in the wordcloud
    wordcloud = WordCloud(width = 1200, height = 900, background_color ='black', min_font_size = 1).generate_from_frequencies(data)
    plt.figure(figsize = (8, 8), facecolor = None)
    plt.imshow(wordcloud)
    plt.axis("off")
    plt.tight_layout(pad = 0)
    plt.show()
    return None

if __name__ == "__main__":
    # Retrieving the Show Titles
    temp = getShowList()
    # print(temp)

    # Refining the data
    data = {}
    if temp is not None:
        for ele in temp:
            data[ele[0]] = float(ele[1])
        # print(data)
        
        # CReating the word cloud
        createWordCloud(data)
