import csv
from collections import Counter

# Assuming the CSV content provided is saved in a file named 'cities.csv'
with open("cities.csv", "r") as file:
    reader = csv.DictReader(file)
    # DictReader reads the first line of the CSV file and creates an array of dictionaries
    # where each dictionary has keys (the name of the table columns) and the values of the current row

    counts = Counter()
    # Counter is an object with good functions for counting

    for row in reader:
        print(row)
        if 'City' in row:
            city = row['City']
            counts[city] += 1


    for city, count in counts.most_common():
        #Iterates over the items in the Counter object:
        # counts.most_common() returns a list of the elements and their counts,
        # sorted by the most common first.
        print(f"{city}: {count}")
