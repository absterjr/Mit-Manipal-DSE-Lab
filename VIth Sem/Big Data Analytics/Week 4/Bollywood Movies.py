#!/usr/bin/env python

import sys

# input comes from STDIN (standard input)
for line in sys.stdin:
    # remove leading and trailing whitespace
    line = line.strip()

    # split the line into fields
    fields = line.split(',')

    # extract relevant fields
    movie_id = fields[0]
    movie_name = fields[1]
    release_year = fields[2]
    genre = fields[3]
    likes = float(fields[4])
    dislikes = float(fields[5])

    # calculate the rating
    rating = likes / (likes + dislikes)

    # emit the intermediate key-value pair
    print('%s\t%f' % ('average_rating', rating))
    # emit the intermediate key-value pair
    print('%s\t%d' % (release_year, 1))
    # emit the intermediate key-value pair
    print('%s\t%d' % (genre, 1))

#!/usr/bin/env python

import sys

# initialization
total_rating = 0
num_movies = 0

# input comes from STDIN (standard input)
for line in sys.stdin:
    # remove leading and trailing whitespace
    line = line.strip()

    # split the line into fields
    key, value = line.split('\t')

    # check if the intermediate key is 'average_rating'
    if key == 'average_rating':
        # update the total rating and number of movies
        total_rating += float(value)
        num_movies += 1

# calculate the average rating
average_rating = total_rating / num_movies

# emit the final output key-value pair
print('%s\t%f' % ('result', average_rating))


#!/usr/bin/env python

import sys

# initialization
current_year = None
num_movies = 0

# input comes from STDIN (standard input)
for line in sys.stdin:
    # remove leading and trailing whitespace
    line = line.strip()

    # split the line into fields
    key, value = line.split('\t')

    # convert the value to an integer
    try:
        value = int(value)
    except ValueError:
        continue

    # check if the key is the same as the current year
    if current_year == key:
        # update the number of movies for the current year
        num_movies += value
    else:
        # emit the final output key-value pair for the previous year
        if current_year is not None:
            print('%s\t%d' % (current_year, num_movies))
        
        # reset the counters for the new year
        current_year = key
        num_movies = value

# emit the final output key-value pair for the last year
if current_year is not None:
    print('%s\t%d' % (current_year, num_movies))

#!/usr/bin/env python

import sys

# initialization
current_genre = None
num_movies = 0

# input comes from STDIN (standard input)
for line in sys.stdin:
    # remove leading and trailing whitespace
    line = line.strip()

    # split the line into fields
    key, value = line.split('\t')

    # convert the value to an integer
    try:
        value = int(value)
    except ValueError:
        continue

    # check if the key is the same as the current genre
    if current_genre == key:
        # update the number of movies for the current genre
        num_movies += value
    else:
        # emit the final output key-value pair for the previous genre
        if current_genre is not None:
            print('%s\t%d' % (current_genre, num_movies))
        
        # reset the counters for the new genre
        current_genre = key
        num_movies = value

# emit the final output key-value pair for the last genre
if current_genre is not None:
    print('%s\t%d' % (current_genre, num_movies))



from pyspark import SparkContext

# Create a SparkContext
sc = SparkContext("local", "PhoneAnalysis")

# Load the dataset into an RDD
phones_rdd = sc.textFile("phones.csv")

# Filter the RDD to keep only the phones with more than 3 cores and 32GB internal memory
filtered_rdd = phones_rdd.filter(lambda x: int(x.split(",")[3]) > 3 and int(x.split(",")[1]) >= 32)

# Count the number of phones that meet the criteria
num_phones = filtered_rdd.count()

# Print the result
print("Number of phones with more than 3 cores and 32GB internal memory: ", num_phones)

from pyspark import SparkContext

# Create a SparkContext
sc = SparkContext("local", "PhoneAnalysis")

# Load the dataset into an RDD
phones_rdd = sc.textFile("phones.csv")

# Map each phone to a tuple of (phone_name, front_camera_megapixels)
mapped_rdd = phones_rdd.map(lambda x: (x.split(",")[0], float(x.split(",")[6])))

# Sort the RDD by front_camera_megapixels in descending order
sorted_rdd = mapped_rdd.sortBy(lambda x: x[1], ascending=False)

# Take the top 10 phones
top_10_phones = sorted_rdd.take(10)

# Print the result
print("Top 10 phones with the highest front camera megapixels: ")
for phone in top_10_phones:
    print(phone[0], phone[1])
