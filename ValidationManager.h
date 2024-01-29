#ifndef ValidationManager_h
#define ValidationManager_h
#include "StudentInfo.h"
#include "PromptingManager.h"
#include <unordered_map>
typedef std::unordered_map<int, StudentInfo> StudentInfoMap;

class ValidationManager {
  public:
    void ClearKeyboard();
    int GetValidatedIdInput();
    int GetValidatedSelectionInput(int selection);
    bool IsValidId(StudentInfoMap& students, int id_num);
    bool IsEmptyList(StudentInfoMap& students);
  
  private:
    struct Student student;
    PromptingManager prompt;
};
#endif /* ValidationManager_h */
