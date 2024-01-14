#include "StudentInfo.h"

StudentInfo::StudentInfo(std::string f_name, std::string l_name)
           : students{f_name, l_name} {}

std::string StudentInfo::GetFirstName() const {
  return students.first_name;
}

std::string StudentInfo::GetLastName() const{
  return students.last_name;
}
