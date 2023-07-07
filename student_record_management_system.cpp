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
		int getID() { return id; }
		int getName() { return name; }
		void setName(std::string name) { this->name = name; }

		std::string toString();

	private:
		int id;
		std::string name;
}

int main()
{
	
}

std::string::Student::toString()
{
	std::stringstream ss;

	ss << id << "," << name;

	return ss.str();
}

void writeToFile(vector<Student> students, string filename)
{
	std::ofstream outFile(filename.c_str());

	if (!outFile.is_open())
	{
		std::cout << "Error 
	}

	for (auto student : students)
	{
		outFile << student.toString() << std::endl;
	}
}

