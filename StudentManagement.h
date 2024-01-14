#ifndef StudentManagement_h
#define StudentManagement_h
#include "StudentInfo.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <utility>

class StudentManagement {
  public:
    void InsertStudent();
    void DeleteStudent();
    void ModifyStudent();
    void PrintStudent();
    void PrintMenu();
    void WriteToFile(std::string filename);
    void LaunchStudentManagement();
    bool IsValidId(int id_num);
    bool IsEmptyList();
    std::unordered_map<int, StudentInfo> ReadToFile(std::string filename);
    
  private:
    Student student;
    StudentInfo student_info;
    std::unordered_map<int, StudentInfo> students;
};
#endif /* StudentManagement_h */
