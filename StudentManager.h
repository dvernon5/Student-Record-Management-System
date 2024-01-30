#ifndef StudentManager_h
#define StudentManager_h
#include "UserInputHandler.h"
#include "FileManager.h"

typedef std::pair<int, StudentInfo> StudentPair;
class StudentManager {
  public:
    void PrintStudents(StudentInfoMap& students);
    StudentInfoMap InsertStudent(StudentInfoMap& students, FileReference& filename);
    StudentInfoMap ModifyStudent(StudentInfoMap& students, FileReference& filename);
    StudentInfoMap DeleteStudent(StudentInfoMap& students, FileReference& filename);
  
  private:
    UserInputHandler user_input;
    FileManager mode;
    Student student;
    ValidationManager verify;
    PromptingManager prompt;
    void PrintStudentTableHeaders();
    void PrintStudentsInformation(StudentInfoMap& students);
    static bool CompareFirstNames(StudentPair& student1, StudentPair& student2);
    std::vector<StudentPair> SortStudent(StudentInfoMap& students);
};

#endif /* StudentManager_h */
