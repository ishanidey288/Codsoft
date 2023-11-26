#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    double grade;
};

int main() {
    int numStudents;

    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    if (numStudents <= 0) {
        std::cerr << "Invalid number of students. Exiting program." << std::endl;
        return 1;
    }

    std::vector<Student> students;

    for (int i = 0; i < numStudents; ++i) {
        Student student;
        std::cout << "Enter the name of student " << i + 1 << ": ";
        std::cin >> student.name;

        std::cout << "Enter the grade for " << student.name << ": ";
        std::cin >> student.grade;

        if (student.grade < 0 || student.grade > 100) {
            std::cerr << "Invalid grade entered. Exiting program." << std::endl;
            return 1;
        }

        students.push_back(student);
    }

    double totalGrade = 0.0;
    for (const auto& student : students) {
        totalGrade += student.grade;
    }
    double averageGrade = totalGrade / numStudents;

    auto minMax = std::minmax_element(students.begin(), students.end(),
        [](const Student& s1, const Student& s2) {
            return s1.grade < s2.grade;
        });

    double highestGrade = minMax.second->grade;
    double lowestGrade = minMax.first->grade;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nGrade Summary:\n";
    std::cout << "Average Grade: " << averageGrade << std::endl;
    std::cout << "Highest Grade: " << highestGrade << " (Student: " << minMax.second->name << ")\n";
    std::cout << "Lowest Grade: " << lowestGrade << " (Student: " << minMax.first->name << ")\n";

    return 0;
}
