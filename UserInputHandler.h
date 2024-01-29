#ifndef UserInputHandler_h
#define UserInputHandler_h
#include "ValidationManager.h"

class UserInputHandler {
  public:
    int GetStudentIdInput();
    std::string GetStudentFirstNameInput();
    std::string GetStudentNewFirstNameInput();
    std::string GetStudentLastNameInput();
    std::string GetStudentNewLastNameInput();
  
  private:
    Student student;
    ValidationManager verify;
    PromptingManager prompt;
};

#endif /* UserInputHandler_h */
