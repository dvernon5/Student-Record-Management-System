#include "StudentManager.h"

StudentInfoMap StudentManager::InsertStudent(StudentInfoMap& students, FileReference& filename) {
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

StudentInfoMap StudentManager::ModifyStudent(StudentInfoMap& students, FileReference& filename) {
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

StudentInfoMap StudentManager::DeleteStudent(StudentInfoMap &students, FileReference& filename) {
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

void StudentManager::PrintStudents(StudentInfoMap &students) {
  if (verify.IsEmptyList(students)) {
    prompt.UserForEmptyList();
  } else {
    PrintStudentTableHeaders();
    PrintStudentsInformation(students);
  }
}

void StudentManager::PrintStudentTableHeaders() {
  std::cout << std::setw(20) << std::left << "STUDENT ID"
  << std::setw(1)  << std::left << "STUDENT NAME\n";
  std::cout << std::setw(20) << std::left << "-----------"
  << std::setw(1)  << std::left << "--------------\n";
}

void StudentManager::PrintStudentsInformation(StudentInfoMap &students) {
  std::vector<StudentPair> vector_of_students;
  vector_of_students = SortStudent(students);
  for (const auto& student : vector_of_students) {
    std::cout << std::setw(20) << std::left << student.first
    << std::setw(1)  << std::left << student.second.GetFirstName()
    << " " << student.second.GetLastName()  << "\n";
  }
}

bool StudentManager::CompareFirstNames(StudentPair &student1, StudentPair &student2) {
  return student1.second.GetFirstName() < student2.second.GetFirstName();
}

std::vector<StudentPair> StudentManager::SortStudent(StudentInfoMap &students) {
  std::vector<StudentPair> student_info;
  for (const auto& student : students) {
    student_info.push_back(student);
  }
  sort(student_info.begin(), student_info.end(), &StudentManager::CompareFirstNames);

  return student_info;
}
