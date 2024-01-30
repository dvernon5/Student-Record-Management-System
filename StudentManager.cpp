#include "StudentManager.h"

StudentInfoMap StudentManager::InsertStudent(StudentInfoMap& students, FileReference filename) {
  student.id_num = user_input.GetStudentIdInput();
  if (verify.IsValidId(students, student.id_num)) {
    prompt.UserForExistingID();
  } else {
    student.first_name = user_input.GetStudentFirstNameInput();
    student.last_name  = user_input.GetStudentLastNameInput();
    students.emplace(student.id_num, StudentInfo(student.first_name, student.last_name));
    prompt.UserForSuccessfulInsertion(student);
    mode.WriteToFile(students, filename);
  }
  
  return students;
}

StudentInfoMap StudentManager::ModifyStudent(StudentInfoMap& students, FileReference filename) {
  if (verify.IsEmptyList(students)) {
    prompt.UserForEmptyList();
  } else {
    student.id_num = user_input.GetStudentIdInput();
    if (!verify.IsValidId(students, student.id_num)) {
      prompt.UserForNonExistingID();
    } else {
      student.first_name = user_input.GetStudentNewFirstNameInput();
      student.last_name  = user_input.GetStudentNewLastNameInput();
      students[student.id_num] = StudentInfo(student.first_name, student.last_name);
      prompt.UserForSuccessfulModification(student);
      mode.WriteToFile(students, filename);
    }
  }
  
  return students;
}

StudentInfoMap StudentManager::DeleteStudent(StudentInfoMap &students, FileReference filename) {
  if (verify.IsEmptyList(students)) {
    prompt.UserForEmptyList();
  } else {
    student.id_num = user_input.GetStudentIdInput();
    if (!verify.IsValidId(students, student.id_num)) {
      prompt.UserForNonExistingID();
    } else {
      students.erase(student.id_num);
      prompt.UserForSuccessfulDeletion(student);
      mode.WriteToFile(students, filename);
    }
  }
  
  return students;
}
