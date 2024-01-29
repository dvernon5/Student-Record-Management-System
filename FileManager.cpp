#include "FileManager.h"

void FileManager::WriteToFile(StudentInfoMap students, FileReference filename) {
  std::ofstream outfile(filename);
  if (!outfile.is_open()) {
    throw std::runtime_error("Error! Cannot open file to write.");
  }
  nlohmann::json json_array;
  for (const auto& student : students) {
    nlohmann::json json_data;
    json_data["studentid"] = student.first;
    json_data["firstname"] = student.second.GetFirstName();
    json_data["lastname"]  = student.second.GetLastName();
    json_array.push_back(json_data);
  }
  std::string json_student_info = json_array.dump();
  outfile << json_student_info;
  outfile.close();
}

StudentInfoMap FileManager::ReadToFile(StudentInfoMap students, FileReference filename) {
  std::ifstream infile(filename);
  if (!infile.is_open()) {
    throw std::runtime_error("Cannot open file to read.");
  }
  std::string file_content((std::istreambuf_iterator<char>(infile)),
                            std::istreambuf_iterator<char>());
  nlohmann::json json_data;
  try {
    if (!file_content.empty()) {
      std::istringstream iss(file_content);
      iss >> json_data;
      if (json_data.is_array()) {
        for (const auto& student : json_data) {
          int id_num             = student["studentid"];
          std::string first_name = student["firstname"];
          std::string last_name  = student["lastname"];
          students[id_num]       = StudentInfo(first_name, last_name);
        }
      }
    }
  } catch (nlohmann::json::parse_error &e) {
    std::cerr << e.what() << "\n";
  }
  infile.close();
  
  return students;
}
