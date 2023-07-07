#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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
}

int getIndexOf(std::vector<Student>&, int);
void addStudent(std::vector<Student>&);
void modifyStudent(std::vector<Student>&);
void deleteStudent(std::vector<Student>&);
void writeToFile(std::vector<Student>&, string);
void displayStudents(std::vector<Student>&);

int main()
{
	
}

std::string::Student::toString()
{
	std::stringstream ss;

	ss << id << "," << name;

	return ss.str();
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

	for (Student student : students)
	{
		std::cout << student.getName() << " " << student.getId();
	}

	std::cout << std::endl;
}

