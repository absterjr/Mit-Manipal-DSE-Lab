

1. Creating the database and table:

```
CREATE DATABASE IF NOT EXISTS students_db;
USE students_db;

CREATE TABLE IF NOT EXISTS students (
  student_id INT,
  student_name STRING,
  previous_semester_grade INT
)
ROW FORMAT DELIMITED
FIELDS TERMINATED BY ','
STORED AS TEXTFILE;
```

2. Inserting data into the table:

```
INSERT INTO students VALUES
(1, 'John Doe', 80),
(2, 'Jane Smith', 75),
(3, 'Bob Johnson', 90),
(4, 'Alice Williams', 85);
```

3. Updating a record in the table:

```
UPDATE students
SET previous_semester_grade = 95
WHERE student_id = 2;
```

4. Deleting a record from the table:

```
DELETE FROM students
WHERE student_id = 4;
```

5. Dropping the table:

```
DROP TABLE IF EXISTS students;
```

6. Fetching the data in ascending order:

```
SELECT * FROM students
ORDER BY previous_semester_grade ASC;
```

7. Fetching the data in descending order:

```
SELECT * FROM students
ORDER BY previous_semester_grade DESC;
```

8. Counting the number of students based on grade:

```
SELECT previous_semester_grade, COUNT(*) as num_students
FROM students
GROUP BY previous_semester_grade;
``` 
