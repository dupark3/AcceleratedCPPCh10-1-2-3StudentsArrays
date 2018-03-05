#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <iostream>
#include <vector>

class Student_info{
public:
    Student_info(); // default constructor
    Student_info(std::istream&); // constructor with argument
    std::istream& read(std::istream&);
    std::string name const(); // accessor
    std::string letterGrade const();

private:
    std::string n;
    double midterm;
    double final;
    std::vector<double> homework;
    double finalGrade;
};

#endif // GUARD_student_info_h
