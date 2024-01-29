#include "UserInputHandler.h"

int UserInputHandler::GetStudentIdInput() {
  prompt.UserForStudentId();
  student.id_num = verify.GetValidatedIdInput();
  
  return student.id_num;
}

std::string UserInputHandler::GetStudentFirstNameInput() {
  prompt.UserForStudentFirstName();
  getline(std::cin, student.first_name);
  
  return student.first_name;
}

std::string UserInputHandler::GetStudentNewFirstNameInput() {
  prompt.UserForNewStudentFirstName();
  getline(std::cin, student.first_name);
  
  return student.first_name;
}

std::string UserInputHandler::GetStudentLastNameInput() {
  prompt.UserForStudentLastName();
  getline(std::cin, student.last_name);
  
  return student.last_name;
}

std::string UserInputHandler::GetStudentNewLastNameInput() {
  prompt.UserForNewStudentLastName();
  getline(std::cin, student.last_name);
  
  return student.last_name;
}
