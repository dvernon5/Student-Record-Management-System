#include "StudentManagement.h"
#include <iostream>

namespace ClearKeyboard {
  void ClearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}
using namespace ClearKeyboard;

namespace Validation {
  int GetValidatedInput() {
    int user_input;
    while (!(std::cin >> user_input)) {
      std::cout << "Invalid selection. Please enter a number only: ";
    }
    ClearInputBuffer();
    return user_input;
  }

  int GetValidatedInput(int low, int high) {
    int user_input;
    while (!(std::cin >> user_input) || user_input < low || user_input > high) {
      std::cout << "Please enter a number from " << low << " to " << high << ": ";
    }
    ClearInputBuffer();
    return user_input;
  }
}

bool StudentManagement::IsValidId(int id_num) {  
  return students.find(id_num) != students.end();
}

bool StudentManagement::IsEmptyList() {
  if (students.empty()) {
    std::cout << "List is empty\n";
    return true;
  }
  
  return false;
}

void StudentManagement::InsertStudent() {
  std::cout << "Enter Student ID: ";
  student.id_num = Validation::GetValidatedInput();
  if (IsValidId(student.id_num)) {
    std::cerr << "Student ID already exist.\n";
    return;
  }
  std::cout << "Enter your first name: " << std::flush;
  getline(std::cin, student.first_name);
  std::cout << "Enter your last name: " << std::flush;
  getline(std::cin, student.last_name);
  students.emplace(student.id_num, StudentInfo(student.first_name, student.last_name));
  std::cout << student.first_name << " "
            << student.last_name  << " added successfully\n";
  WriteToFile("student_data.json");
}


void StudentManagement::ModifyStudent() {
  if (IsEmptyList()) {
    return;
  }
  std::cout << "Enter student ID: ";
  student.id_num = Validation::GetValidatedInput();
  if (!IsValidId(student.id_num)) {
    std::cerr << "Student ID does not exist.\n";
    return;
  }
  std::cout << "Enter new first name: ";
  getline(std::cin, student.first_name);
  std::cout << "Enter new last name: ";
  getline(std::cin, student.last_name);
  students[student.id_num] = StudentInfo(student.first_name, student.last_name);
  std::cout << "Data modified for studentID " << student.id_num << ".\n";
  WriteToFile("student_data.json");
}

void StudentManagement::DeleteStudent() {
  if (IsEmptyList()) {
    return;
  }
  std::cout << "Enter student ID: ";
  student.id_num = Validation::GetValidatedInput();
  if (!IsValidId(student.id_num)) {
    std::cerr << "Student ID does not exist.\n";
    return;
  }
  students.erase(student.id_num);
  std::cout << "Student ID " << student.id_num << " deleted successfull.\n";
  WriteToFile("student_data.json");
}

void StudentManagement::PrintStudent() {
  if (IsEmptyList()) {
    return;
  }
  std::cout << std::setw(20) << std::left << "STUDENT ID"
            << std::setw(1)  << std::left << "STUDENT NAME\n";
  std::cout << std::setw(20) << std::left << "-----------"
            << std::setw(1)  << std::left << "--------------\n";
  for (const auto& student : students) {
    std::cout << std::setw(20) << std::left << student.first
              << std::setw(1)  << std::left << student.second.GetFirstName()
              << " " << student.second.GetLastName()  << "\n";
  }
}

void StudentManagement::PrintMenu() {
  std::cout << "\nWelcome to the Student Management System\n";
  std::cout << "1. Add Student.\n";
  std::cout << "2. Modify Student.\n";
  std::cout << "3. Delete Student.\n";
  std::cout << "4. List Student.\n";
  std::cout << "5. EXIT\n";
  std::cout << "Your Selection >> ";
}

void StudentManagement::WriteToFile(std::string filename) {
  std::ofstream outfile(filename);
  if (!outfile.is_open()) {
    throw std::runtime_error("Error! Cannot open file.");
  }
  nlohmann::json json_array;
  for (const auto& student : students) {
    nlohmann::json json_data;
    json_data["studentid"] = student.first;
    json_data["firstname"] = student.second.GetFirstName();
    json_data["lastname"]  = student.second.GetLastName();
    json_array.push_back(json_data);
  }
  std::string json_student_info = json_array.dump();
  outfile << json_student_info;
  outfile.close();
}

std::unordered_map<int, StudentInfo> StudentManagement::ReadToFile(std::string filename) {
  std::ifstream infile(filename);
  if (!infile.is_open()) {
    throw std::runtime_error("Error! Cannot open file.");
  }
  std::string file_content((std::istreambuf_iterator<char>(infile)),
                            std::istreambuf_iterator<char>());
  nlohmann::json json_data;
  try {
    if (!file_content.empty()) {
      std::istringstream iss(file_content);
      iss >> json_data;
      if (json_data.is_array()) {
        for (const auto& student: json_data) {
          int id_num             = student["studentid"];
          std::string first_name = student["firstname"];
          std::string last_name  = student["lastname"];
          students[id_num]       = StudentInfo(first_name, last_name);
        }
      }
    }
  } catch (nlohmann::json::parse_error &e) {
    std::cerr << "Error parsing data\n";
  }
  infile.close();
  
  return students;
}

void StudentManagement::LaunchStudentManagement() {
  students = ReadToFile("student_data.json");
  int selection{0};
  do {
    PrintMenu();
    selection = Validation::GetValidatedInput(1, 5);
    switch(selection) {
      case 1:
        std::cout << "\nADD STUDENT: \n------------\n";
        InsertStudent();
        break;
      case 2:
        std::cout << "\nMODIFY STUDENT: \n---------------\n";
        ModifyStudent();
        break;
      case 3:
        std::cout << "\nDELETE STUDENT: \n----------------\n";
        DeleteStudent();
        break;
      case 4:
        std::cout << "\nLIST ALL STUDENTS:  \n------------------\n";
        PrintStudent();
        break;
      case 5:
        std::cout << "\nThank you... Goodbye!\n";
        break;
    }
  } while (selection != 5);
}
