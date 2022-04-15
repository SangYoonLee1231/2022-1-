#include <stdio.h>

struct Students
{
    int ID;
    char name[20];
    char address[200];
    char phone[15];
    float studentGPA;
    char ListOfCourses[10][20];
};

int main() {
    struct Students std1, std2, std3;

    struct CourseInfo crsinfo[20];
    struct Students std[100];
    int index = 0;
    int next = 1;
    while(1) {
        system("cls");
    }
}

struct CourseInfo
{
    int courseID;
};
