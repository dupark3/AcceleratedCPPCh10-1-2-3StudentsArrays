#include <iostream>

Student_info::Student_info() : midterm(0), final(0), finalGrade(0) { };
Student_info::Student_info(std::istream& is) : { ::read(is); };

std::istream& Student_info::read(std::istream& is){
    is >> n >> midterm >> final;
    finalGrade = midterm * 0.4 + final * 0.6;
}

bool compare(const Student_info& x, const Student_info& y){
    return x.name() < y.name();
}
