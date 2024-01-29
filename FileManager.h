#ifndef FileManager_h
#define FileManager_h
#include "StudentInfo.h"
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>
#include <unordered_map>

typedef std::unordered_map<int, StudentInfo> StudentInfoMap;
typedef const std::string& FileReference;
class FileManager {
  void WriteToFile(StudentInfoMap students, FileReference filename);
  StudentInfoMap ReadToFile(StudentInfoMap students, FileReference filename);
};
#endif /* FileManager_h */
