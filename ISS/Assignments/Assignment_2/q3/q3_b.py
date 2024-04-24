import pymysql
import pymysql.cursors

# Function to filter data based on year, rating and episodes
def filterData():
    # Setting up the connection to the MySQL server
    mydb = pymysql.connect(host="localhost", user="root", password="urmomgey")
    mycursor = mydb.cursor()

    # Check if 'topShows' database exists, if not create one
    mycursor.execute("SHOW DATABASES LIKE 'topShows'")
    if not mycursor.fetchone():
        print("No database to filter from")
        return None

    # Open the 'topShows' database
    mycursor.execute("USE topShows")

    # Creating a table if it does not exist
    mycursor.execute("SHOW TABLES LIKE 'Top250'")
    if not mycursor.fetchone():
        print("No table to filter")
        return None

    # Filtering the data based on year, rating and number of episodes
    cat = int(input("Enter the category to filter by (0: Genre, 1: Rating, 2: Episode Count) : "))

    if cat == 0:
        genre = input("Genre to filter by : ")
        mycursor.execute(f"SELECT * FROM Top250 WHERE Genre LIKE '%{genre}%'")

    elif cat == 1:
        min_rating = float(input("Minimum Rating : "))
        max_rating = float(input("Maximum Rating : "))
        mycursor.execute(f"SELECT * FROM Top250 WHERE CAST(Rating AS DECIMAL(10,2)) BETWEEN {min_rating} AND {max_rating}")

    elif cat == 2:
        min_epsCount = int(input("Minimum number of episodes : "))
        max_epsCount = int(input("Maximum number of episodes : "))
        mycursor.execute(f"SELECT * FROM Top250 WHERE CAST(EpisodeCount AS UNSIGNED) BETWEEN {min_epsCount} AND {max_epsCount}")

    else:
        print("Invalid category entered")
        return None

    data = mycursor.fetchall()
    return data

if __name__ == "__main__":
    data = filterData()

    # Displaying the data
    if data is not None:
        for each in data:
            print(each[0])
            print(f"\tRating : {each[1]}")
            print(f"\tGenre : {each[2]}")
            print(f"\tNumber of Episodes : {each[3]}")
