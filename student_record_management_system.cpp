#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

class Student
{
    public:
        Student() = default;
        Student(std::string name) : name(name) {}
        std::string getName() { return name; }
        void setName(std::string name) { this->name = name; }
        std::string toString();
    
    private:
        std::string name;
};

std::map<int, Student> readFile(std::string);
int  getIndexOf(std::map<int, Student>&, int);
void addStudent(std::map<int, Student>&);
void modifyStudent(std::map<int, Student>&);
void deleteStudent(std::map<int, Student>&);
void displayStudents(std::map<int, Student>&);
void writeToFile(std::map<int, Student>&, std::string);
void displayMenu();

int main(void)
{
    std::map<int, Student> students = readFile("Students.txt");
    int selection = 0;
    
    do
    {
        displayMenu();
        std::cin >> selection;
        std::cin.ignore();
        
        switch(selection)
        {
            case 1:
                std::cout << "\nADD STUDENT: \n----------\n";
                addStudent(students);
                break;
                
            case 2:
                std::cout << "\nMODIFY STUDENT: \n-----------------\n";
                modifyStudent(students);
                break;
            
            case 3:
                std::cout << "\nDELETE STUDENT: \n----------------\n";
                deleteStudent(students);
                break;
            
            case 4:
                std::cout << "\nLIST ALL STUDENTS: \n---------------\n";
                displayStudents(students);
                break;
                
            case 5:
                std::cout << "\nThank you... Goodbye!\n";
                break;
            
            default:
                std::cout << "\nInvalid selection\n";
        }
        
    } while (selection != 5);
    
    return 0;
}  /* End of Program */

std::string Student::toString()
{
    std::stringstream ss;
    
    ss << name;
    
    return ss.str();
}

std::map<int,Student> readFile(std::string filename)
{
    std::map<int, Student> students;
    std::ifstream inFile(filename.c_str());  /* inFile.open(filename.cstr()); */
    std::string line = "";
    
    if (!inFile.is_open())
    {
        std::cout << "ERROR in opening file " << filename << "!\nExiting";
        exit(EXIT_FAILURE);
    }
    
    while (getline(inFile, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> tokens;
        std::string token;
        
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }
        
        int id = stod(tokens[0]);
        std::string name = tokens[1];
        students[id] = Student(name);
    }
    
    inFile.close();
    
    return students;
}

int getIndexOf(std::map<int, Student>& students, int id)
{
    auto index = -1;
    auto itr = students.find(id);

    if (itr != students.end())
    {
        index = itr->first;
    }
    
    return index;
}

void addStudent(std::vector<Student>& students)
{
    int id;
    std::cout << "Enter student ID: ";
    std::cin  >> id;
    std::cin.ignore();
    
    int index = getIndexOf(students, id);

    if (index != -1)
    {
        // student already present
        std::cout << "This student is already present!" << std::endl;
        return;
    }
    
    std::string name;
    std::cout << "Enter your name: ";
    getline(std::cin, name);
    
    students[id] = Student(name);
    
    std::cout << name << " added sucessfully." << std::endl;
    writeToFile(students, "Student.txt");
}

void modifyStudent(std::map<int, Student>& students)
{
    if (students.empty())
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    int id;
    std::cout << "Enter student ID: ";
    std::cin  >> id;
    std::cin.ignore();
    
    int index = getIndexOf(students, id);
    
    if (index == -1)
    {
        // student not found
        std::cout << "Sorry, no student found for ID " << id << "." << std::endl;
        return;
    }
    
    std::string name;
    std::cout << "Enter your name: ";
    getline(std::cin, name);
    students[index].setName(name);
    
    std::cout << "Data modified for student ID " << id << "." << std::endl;
    writeToFile(students, "Students.txt");
}

void deleteStudent(std::vector<Student>& students)
{
    if (students.empty())
    {
        std::cout << "List is empth." << std::endl;
        return;
    }
    
    int id;
    std::cout << "Enter student ID: ";
    std::cin  >> id;
    std::cin.ignore();
    
    int studentID = getIndexOf(students, id);
    
    if (studentID == -1)
    {
        std::cout << "Sorry, no student found for ID " << id << "." << std::endl;
    }
    
    students.erase(studentID);
    
    std::cout << "Student ID " << id << " deleted successfully." << std::endl;
    writeToFile(students, "Students.txt");
    
}

void displayStudents(std::vector<Student>& students)
{
    if (students.empty())
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    std::cout << std::setw(20) << std::left << "STUDENT ID" << std::setw(1) << std::left << "STUDENT NAME" << std::endl;
    std::cout << std::setw(20) << std::left << "-----------" << std::setw(1) << std::left << "--------------" << std::endl;

    for (Student student : students)
    {
        std::cout << std::setw(20) << std::left << student.getId() << std::setw(1) << std::left << student.getName() << std::endl;
    }

    std::cout << std::endl;
}

void writeToFile(std::vector<Student>& students, std::string filename)
{
    std::ofstream outFile(filename.c_str());
    
    if (!outFile.is_open())
    {
        std::cout << "Error in opening file " << filename << "." << std::endl;
        exit(EXIT_FAILURE);
    }
    
    for (auto student: students)
    {
        outFile << student.toString() << std::endl;
    }
    
    outFile.close();
}

void displayMenu()
{
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. Modify Student" << std::endl;
    std::cout << "3. Delete Student" << std::endl;
    std::cout << "4. List all Students" << std::endl;
    std::cout << "5. EXIT" << std::endl;
    std::cout << "Your Selection >> ";
}
