# Student-Record-Management-System

This is a Student Record Management System program written in C++. It allows you to manage student records by performing operations such as adding a student, modidying students, deleting a student, listing all students, and exiting the program. The program reads and writes student records from/to a file named "Students.txt"

## Features
* Add a student: You can add a new student to the record by providing the Student's ID and name.
* List all students: This option displaysa table of all the students in the record, showing their IDs and names.
* Modify a student: If you need to update a student's information, you can enter the student's ID and provide a new name.
* Delete a student: To remove a student from the record, enter the student's ID.
* Exit: This option allows you to exit the program.

## Usage
1. Compile the source code using a C++ compiler.
2. Run the compiled executable file.
3. The program will display a menu with the available options.
4. Enter the number corresponding to the desired option and press Enter.
5. Follow the prompts to perform the selected operation.
6. Repeat steps 4-5 until you choose to exit the program.

## File Format
The student records are stored in a comma-separated values (CSV) file named "Students.txt". Each line in the file represents a student and contains the student's ID and name, separated by a comma. 

Example file format:
```Shell
  1,John Doe
  2,Jane Doe
  3,Chris Smith
```
Furthermore, if you want to see the path to your created file follow these steps (Only if you're using Xcode IDE).

```Shell
1. Go to File setting and select "Project Settings..."
2. In the "Per-User Project Settings:" above the "Advanced..." button click the arraw on the right-side of your project path. (Ex: /Xcode/DerivedData-> (Click arrow)
3. In the "DerivedData" looks for your project name and select it.
4. Select the "Build" directory.
5. Select the "Products" directory.
6. Select the "Debug" directory.
7. In the "Debug" directory it will show your created file if successfully created.
```

**Note:** if the "Students.txt" file does not exist, the program will create a new file when you add the first student.

## Dependencies

This program uses the following libraries:

* iostream: Provides input/output stream functionality.
* fstream: Enables file stream operations for reading and writing files.
* sstream: Supports string stream operations for parsing and formatting data.
* vector: Implements dynamic arrays to store and manipulate student records.
* Iomanip: Allows for formatting the output in a table-like structure.
* string: Provide string manipulation functions.
