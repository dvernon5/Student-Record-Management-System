#include <iostream>
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

		void toString();

	private:
		int id;
		std::string name;
}
