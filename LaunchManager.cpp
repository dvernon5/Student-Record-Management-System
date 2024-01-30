#include "LaunchManager.h"

void LaunchManager::LaunchingManagementSystem() {
  const std::string FILENAME = "student_data.json";
  students = mode.ReadToFile(students, FILENAME);
  const int NUMBER_OF_SELECTION = 5;
  int selection{0};
  do {
    student.PrintStudentMenu();
    selection = verify.GetValidatedSelectionInput(selection);
    switch(selection) {
      case 1:
        prompt.UserToAddStudent();
        student.InsertStudent(students, FILENAME);
        break;
      case 2:
        prompt.UserToModifyStudent();
        student.ModifyStudent(students, FILENAME);
        break;
      case 3:
        prompt.UserToDeleteStudent();
        student.DeleteStudent(students, FILENAME);
        break;
      case 4:
        prompt.UserToPrintStudents();
        student.PrintStudents(students);
        break;
      case 5:
        prompt.UserWithGoodbyeMessage();
        break;
      default:
        prompt.UserForInvalidMenuSelection();
        break;
    }
  } while (selection != NUMBER_OF_SELECTION);
}
