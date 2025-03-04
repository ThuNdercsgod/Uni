#include <iostream>

struct Student
{
    int fn;
    int course;
    double grade;
};

struct Group
{
    Student *students;
    double average;
};

Student *createStudents(int size);
int inputNumber();
Student inputStudent();
double inputStipendium();
double averageGrade(Group group, int size);
int amountOfStipendiums(Group group, int size, double minGrade);

int main()
{
    std::cout << "Enter the number of students in the group:" << std::endl;
    int N = inputNumber();

    Group group;
    group.students = createStudents(N);

    if (!group.students)
    {
        return 1;
    }

    std::cout << "Enter the data of the students in the group:" << std::endl;
    for (int i = 0; i < N; i++)
    {
        group.students[i] = inputStudent();
    }

    double minStipendium = inputStipendium();

    std::cout << "The average grade for the group: " << averageGrade(group, N) << std::endl;
    std::cout << "Amoutn of students with stipendium: " << amountOfStipendiums(group, N, minStipendium) << std::endl;

    delete[] group.students;

    return 0;
}

Student *createStudents(int size)
{
    Student *students = new (std::nothrow) Student[size];

    if (!students)
    {
        std::cout << "Memory allocation error!" << std::endl;

        return nullptr;
    }

    return students;
}

int inputNumber()
{
    int number;
    bool valid;

    do
    {
        valid = true;
        std::cin >> number;

        if (!(number >= 1 && number <= 500))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
        }
    } while (valid == false);

    return number;
}

Student inputStudent()
{
    Student student;
    bool valid;

    do
    {
        valid = true;
        std::cin >> student.fn >> student.course >> student.grade;

        if (!((student.fn >= 10000 && student.fn < 100000) &&
              (student.course >= 1 && student.course <= 4) &&
              student.grade >= 2 && student.grade <= 6))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
        }
    } while (valid == false);

    return student;
}

double inputStipendium()
{
    double minStipendium;
    bool valid;

    do
    {
        valid = true;
        std::cin >> minStipendium;

        std::cout << "Enter the minimum grade for stipendium: " << std::endl;
        if (!(minStipendium >= 2 && minStipendium <= 6))
        {
            std::cout << "Wrong input! Try again:" << std::endl;
            valid = false;
        }
    } while (valid == false);

    return minStipendium;
}

double averageGrade(Group group, int size)
{
    double average = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        average += group.students[i].grade;
        count++;
    }

    average /= count;

    return average;
}

int amountOfStipendiums(Group group, int size, double minGrade)
{
    int amount = 0;

    for (int i = 0; i < size; i++)
    {
        if (group.students[i].grade >= minGrade)
        {
            amount++;
        }
    }

    return amount;
}