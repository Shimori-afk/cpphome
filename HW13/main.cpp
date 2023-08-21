#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int marks[4];
};

float calculateAverage(Student student)
{
    float sum = 0;
    int marksIdx = 4;
    for (int i = 0; i < marksIdx; ++i)
    {
        sum += student.marks[i];
    }
    return sum / 4;
}

void sortByAverage(Student students[], int size)
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (calculateAverage(students[j]) > calculateAverage(students[j + 1]))
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

Student& getTopStudent(Student students[], int size) {
    sortByAverage(students, size);
    return students[size - 1];
}

int countStudentsAboveAverage(Student students[], int size, float threshold)
{
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (calculateAverage(students[i]) > threshold)
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    const int arraySize = 5;
    Student students[arraySize] = {
        { "Student 1", { 80, 90, 85, 88 } },
        { "Student 2", { 70, 75, 65, 80 } },
        { "Student 3", { 90, 95, 98, 88 } },
        { "Student 4", { 60, 70, 75, 80 } },
        { "Student 5", { 85, 80, 88, 90 } }
    };

    for (int i = 0; i < arraySize; ++i) {
        float average = calculateAverage(students[i]);
        std::cout << students[i].name << " - Average: " << average << std::endl;
    }

    Student& topStudent = getTopStudent(students, arraySize);
    std::cout << "Top student: " << topStudent.name << std::endl;

    float threshold = 75.0;
    int countAbove75 = countStudentsAboveAverage(students, arraySize, threshold);
    std::cout << "Number of students with average above 75%: " << countAbove75 << std::endl;

    return 0;
}
