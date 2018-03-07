#include <algorithm> // sort, max
#include <cstddef> // size_t
#include <iostream>
#include <string>
#include <vector>

#include "Student_info.h"

int main() {
    std::cout << "Enter each student's name, midterm grade, and final grade: " << std::endl;
    Student_info record;
    std::vector<Student_info> students;
    size_t maxLen = 0;

    // read and store
    while(record.read(std::cin)){
        maxLen = std::max(maxLen, record.name().size());
        students.push_back(record);
    }

    // sort
    std::sort(students.begin(), students.end(), compare);

    // output
    for (size_t i = 0; i != students.size(); ++i){
        std::cout << students[i].name() << std::string(maxLen + 1 - students[i].name().size(), ' ')
                  << students[i].letterGrade() << std::endl;
    }

    return 0;
}
