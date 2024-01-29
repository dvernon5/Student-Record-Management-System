#include "ValidationManager.h"

void ValidationManager::ClearKeyboard() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int ValidationManager::GetValidatedIdInput() {
  while (!(std::cin >> student.id_num)) {
    prompt.UserForInvalidInput();
    ClearKeyboard();
  }
  ClearKeyboard();
  
  return student.id_num;
}

int ValidationManager::GetValidatedSelectionInput(int user_selection) {
  while (!(std::cin >> user_selection)) {
    prompt.UserForInvalidInput();
    ClearKeyboard();
  }
  ClearKeyboard();
  
  return user_selection;
}

bool ValidationManager::IsValidId(StudentInfoMap& students, int id_num) {
  return students.find(id_num) != students.end();
}

bool ValidationManager::IsEmptyList(StudentInfoMap& students) {
  return students.empty();
}
