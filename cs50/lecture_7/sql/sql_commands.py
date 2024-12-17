
-----sql-----
sqllite3 - enters sql mode
sqlite3 cities.db - create/open a file database
.mode csv - open the csv mode
.import file.csv new_file name - creates a new file
with the data of cities.csv
.quit

SELECT *FROM cities; - prints the whole db
SELECT columns_name/s FROM table;


DELETE FROM cities; - deletes the whole db
.schema - shows the structure


AVG - average
COUNT
    SELECT COUNT(*) FROM cities;
    #counts the rows
    SELECT COUNT(Name) FROM cities;
    #counts the rows where Name column has no NULL value

DISTINCT - different
    SELECT DISTINCT(City) FROM cities;
    #returns every different city
    ELECT COUNT(DISTINCT(City)) FROM cities;
    #returns the n opf diff cities

LOWER
MAX
MIN
UPPER

WHERE
    SELECT COUNT(*) FROM cities WHERE City = " Los Angeles";
    #count on row by row how many times the column City is Los Angeles
    SELECT COUNT(*) FROM cities WHERE City = " Los Angeles" AND Age = " 25";

LIKE
ORDER BY
    SELECT City, COUNT(*) FROM cities GROUP BY City ORDER BY COUNT(*) ASC;
    #ASC - ascending order
    #DESC - DESCENDING ORDER
    #it counts how many times each city occurs
    #and orders it from smallest to larges

    SELECT City, COUNT(*) AS popularity FROM cities GROUP BY City ORDER BY popularity DESC LIMIT 2;
    #same but the second column is now called popularity
LIMIT
    SELECT columns_name/s FROM table LIMIT 10;
    #10 results only
GROUP BY
    SELECT City, COUNT(*) FROM cities GROUP BY City;
    #it counts how many times each city occurs

INSERT INTO table (column, ...) VALUES(value, ...)
    INSERT INTO cities (Name, Age) VALUES('Gosho','100');
    #inserts at the end of the table Gosho, 100, NULL
DELETE FROM table(column, ...) VALUES(value, ...)
    DELETE FROM cities WHERE Name IS 'Gosho';
UPDATE
    UPDATE cities SET Name = 'Svetoslav Nikov', City = 'Balchik';
    #make every name to svetoslav nikov and every city to balchik


