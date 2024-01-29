#ifndef PromptingManager_h
#define PromptingManager_h
#include "Student.h"
#include <unordered_map>

class PromptingManager {
  public:
    void UserForStudentId();
    void UserForStudentFirstName();
    void UserForNewStudentFirstName();
    void UserForStudentLastName();
    void UserForNewStudentLastName();
    void UserForInvalidInput();
    void UserForEmptyList();
    void UserForExistingID();
    void UserForNonExistingID();
    void UserForSuccessfulInsertion(Student& student);
    void UserForSuccessfulModification(Student& student);
    void UserForSuccessfulDeletion(Student& student);
    void UserForInvalidMenuSelection();
    void UserToAddStudent();
    void UserToModifyStudent();
    void UserToDeleteStudent();
    void UserToPrintStudents();
    void UserWithGoodbyeMessage();
};

#endif /* PromptingManager_h */
