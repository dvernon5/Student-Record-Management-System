#ifndef StudentManager_h
#define StudentManager_h
#include "UserInputHandler.h"
#include "FileManager.h"

class StudentManager {
  public:
    StudentInfoMap InsertStudent(StudentInfoMap& students, FileReference filename);
    StudentInfoMap ModifyStudent(StudentInfoMap& students, FileReference filename);
    StudentInfoMap DeleteStudent(StudentInfoMap& students, FileReference filename);
  
  private:
    UserInputHandler user_input;
    FileManager mode;
    Student student;
    ValidationManager verify;
    PromptingManager prompt;
};

#endif /* StudentManager_h */
