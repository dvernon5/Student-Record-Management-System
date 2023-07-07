#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

Class Student
{ 
	public:
		Student() = default;
		Student(int id, std::string name) : id(id), name(name) {}
		int getId() { return id; }
		int getName() { return name; }
		void setName(std::string name) { this->name = name; }

		std::string toString();

	private:
		int id;
		std::string name;
};

vector<Student> readFile(std::string filename);
int getIndexOf(std::vector<Student>&, int);
void addStudent(std::vector<Student>&);
void modifyStudent(std::vector<Student>&);
void deleteStudent(std::vector<Student>&);
void displayStudents(std::vector<Student>&);
void writeToFile(std::vector<Student>&, string);
void displayMenu();

int main()
{
	vector<Student> students;
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
				std::cout << "\nThank you... goodbye!\n";
				break;

			default:
				std::cout << "\nInvalid selection\n";
				break;
		}
	} while (selection != 5);

	return 0;
}

std::string::Student::toString()
{
	std::stringstream ss;

	ss << id << "," << name;

	return ss.str();
}

std::vector<Student> readFile(std::string filename)
{
	vector<Student> students;
	std::ifstream inFile(filename.c_str());  // infile.open(filename.c_str());
	std::string line = "";

	if (!inFile.is_open())
	{
		std::cout << "ERROR in opening file " << filename << "!\nExiting..";
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
		students.push_back(Student(id, name));
	}

	inFile.close();
	return students;
}
int getIndexOf(std::vector<Student>& students, int id)
{
	int index = -1;
	std::vector<Student>::iterator itr;
	
	for (itr = students.begin(); itr != students.end(); ++itr)
	{
		if (student[i].getId() == id)
		{
			index = (int)std::distance(students.begin(), itr);  // assign id index number.
			return 0;
		}
	}

	return index;			
}

void addStudent(std::vector<Student>& students)
{
	int id = 0;
	std::cout << "Enter student ID: ";
	std::cin  >> id;
	std::cin.ignore();
	
	int index = getIndexOf(students, id);

	if (index != -1)
	{
		// Student already present
		std::cout << "This student is already present!" << std::endl;
		return;
	}

	std::string name;
	std::cout << "Enter your name: ";
	getline(std::cin, name);

	students.push_back(Student(id, name));

	std::cout << name << " added successfully." << std::endl;
	writeToFile(students, "Students.txt");
}

void modifyStudent(std::vector<Student>& students)
{
	if (!students.empty())
	{
		std::cout << "List is empty" << std::endl;
		return;
	}

	int id = 0;
	std::cout << "Enter Student ID: ";
	std::cin  >> id;
	std::cin.ignore();
	
	int index = getIndexOf(students, id);

	if (index == -1)
	{
		std::cout << "Sorry, no student found for ID " << id << "." << std::cout;
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
	if (!students.empty())
	{
		std::cout << "List is empty." << std::endl;
		return;
	}

	int id = 0;
	std::cout << "Enter Student ID: ";
	std::cin  >> id;
	std::cin.ignore();

	int index = getIndexOf(students, id);

	if (index == -1)
	{
		std::cout << "Sorry no student found for ID " << id << "." << std::endl;
	}

	students.erase(students.begin() + index);

	std::cout << "Student ID " << id << " is deleted successfully." << std::endl;
	writeToFile(students, "Students.txt");
}

void writeToFile(std::vector<Student>& students, std::string filename)
{
	std::ofstream outFile(filename.c_str());

	if (!outFile.is_open())
	{
		std::cout << "Error in opening file " << filename << "." << std::endl;
	}

	for (auto student : students)
	{
		outFile << student.toString() << std::endl;
	}

	outFile.close();
}

void displayStudents(std::vector<Student>& students)
{
	if (!students.empty())
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

void displayMenu()
{
	std::cout << "1. Add student" << std::endl;
	std::cout << "2. Modify student" << std::endl;
	std::cout << "3. Delete student" << std::endl;
	std::cout << "4. List all students" << std::endl;
	std::cout << "5. EXIT" << std::cendl;
	std::cout << "Selection >> ";
}

