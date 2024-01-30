#ifndef LaunchManager_h
#define LaunchManager_h
#include "FileManager.h"
#include "StudentManager.h"

class LaunchManager {
  public:
    void LaunchingManagementSystem();
  
  private:
    FileManager       mode;
    StudentManager    student;
    ValidationManager verify;
    PromptingManager  prompt;
    StudentInfoMap    students;
};
#endif /* LaunchManager_h */
