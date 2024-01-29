#include "PromptingUser.h"

void PromptingUser::UserForStudentId() {
  std::cout << "Enter Student ID: ";
}

void PromptingUser::UserForStudentFirstName() {
  std::cout << "Enter your first name: ";
}

void PromptingUser::UserForNewStudentFirstName() {
  std::cout << "Enter new first name: ";
}

void PromptingUser::UserForStudentLastName() {
  std::cout << "Enter your last name: ";
}

void PromptingUser::UserForNewStudentLastName() {
  std::cout << "Enter new last name: ";
}

void PromptingUser::UserForInvalidInput() {
  std::cout << "Invalid input. Please enter a number only: ";
}

void PromptingUser::UserForEmptyList() {
  std::cout << "List is empty.\n";
}

void PromptingUser::UserForExistingID() {
  std::cout << "Student ID already exist.\n";
}

void PromptingUser::UserForNonExistingID() {
  std::cout << "Student ID does not exist.\n";
}

void PromptingUser::UserForSuccessfulInsertion(Student& student) {
    std::cout << student.first_name << " " << student.last_name  << " added successfully\n";
}

void PromptingUser::UserForSuccessfulModification(Student &student) {
  std::cout << "Data modified for studentID " << student.id_num << ".\n";
}

void PromptingUser::UserForSuccessfulDeletion(Student &student) {
  std::cout << "Student ID " << student.id_num << " deleted successfull.\n";
}

void PromptingUser::UserForInvalidMenuSelection() {
  std::cout << "Invalid selection. Please try again.\n";
}

void PromptingUser::UserToAddStudent() {
  std::cout << "\nADD STUDENT: \n------------\n";
}

void PromptingUser::UserToModifyStudent() {
  std::cout << "\nMODIFY STUDENT: \n---------------\n";
}

void PromptingUser::UserToDeleteStudent() {
  std::cout << "\nDELETE STUDENT: \n----------------\n";
}

void PromptingUser::UserToPrintStudents() {
  std::cout << "\nLIST ALL STUDENTS:  \n------------------\n";
}

void PromptingUser::UserWithGoodbyeMessage() {
  std::cout << "\nThank you... Goodbye!\n";
}
