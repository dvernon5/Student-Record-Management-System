class StudentInfo {
  public:
    StudentInfo(std::string f_name = "", std::string l_name = "");
    std::string GetFirstName() const;
    std::string GetLastName() const;
    int GetStudentId();
  
  private:
    Student students;
};

#endif /* StudentInfo_h */
