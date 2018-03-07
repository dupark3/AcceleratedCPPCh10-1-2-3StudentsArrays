#include <algorithm> // sort
#include <iostream>
#include <cstdio> // EOF
#include <string>

#include "Student_info.h"

Student_info::Student_info() : midterm(0), final(0), finalGrade(0) { };
Student_info::Student_info(std::istream& is) { read(is); };

std::istream& Student_info::read(std::istream& in) {
    if (in){
        in >> n >> midterm >> final;
        finalGrade = midterm * 0.4 + final * 0.6;
    }
    return in;
}

std::string Student_info::letterGrade() const{
    // static const variables of letter grade benchmarks, corresponding letter grades, and number of grades
    static const double  numbers[] = {97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
    static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};
    static const size_t numberSize = sizeof(numbers) / sizeof(*numbers);

    for (size_t i = 0; i != numberSize; ++i){
        if (finalGrade >= numbers[i]){
            return letters[i];
        }
    }

    return "?\?\?";
}

bool compare(const Student_info& x, const Student_info& y){
    return x.name() < y.name();
}

template <class inputIter, class T>
T median(inputIter first, inputIter last){
    std::vector<T> temp;
    while(first != last){
        temp.push_back(*first++);
    }
    std::sort(temp.begin(), temp.end());

    size_t size = temp.size();
    T mid = size / 2;
    size % 2 == 0 ? mid = (temp[mid - 1] + temp[mid]) / 2 : mid = temp[mid];

    return mid;
}
