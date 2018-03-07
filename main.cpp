/*
Exercise 10-1 Rewrite the student-grading program from page 166 to generate letter grades.

Exercise 10-2 Rewirte the median function from page 140 so that we can call it witheither a vector or a built-in array. The function should allow contaiers or any arithmetic type.

*/

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

    // testing if the median function can take an array instead of a vector
    int integers[] = {12, 5, 6, 10, 10, 3}; // median = 8
    int middle = 0;
    median(integers, integers + sizeof(integers) / sizeof(*integers), middle);
    std::cout << "Array's median: " << middle << std::endl;

    return 0;
}
