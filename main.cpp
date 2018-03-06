#include <algorithm> // sort, max
#include <cstddef> // size_t
#include <iostream>
#include <string>
#include <vector>

#include "Student_info.h"

int main() {
    std::cout << "Enter each student's name, midterm grade, final grade, and homework grades: " << std::endl;
    Student_info record;
    std::vector<Student_info> students;
    std::string s;
    size_t maxLen = 0;

    // read and store
    while(record.read(std::cout)){
        maxLen = std::max(maxLen, record.name().size());
        students.push_back(record);
    }


    return 0;
}
