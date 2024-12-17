import csv

# Assuming the CSV content provided is saved in a file named 'cities.csv'
with open("cities.csv", "r") as file:
    reader = csv.DictReader(file)
    # DictReader reads the first line of the CSV file and creates an array of dictionaries
    # where each dictionary has keys (the name of the table columns) and the values of the current row

    cities = {}

    for row in reader:
        print(row)  # This will print each row as a dictionary
        if 'City' in row:
            if row['City'] in cities:
                cities[row['City']] += 1
            else:
                cities[row['City']] = 1

    for city in sorted(cities, key=cities.get, reverse=True):
        
        # sorted by the most common first
        print(f"{city}: {cities[city]}")
