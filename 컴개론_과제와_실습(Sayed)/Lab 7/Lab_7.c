#include <stdio.h>
#include <string.h>
#include <stdbool.h>


struct Students
{
    int ID;
    char name[20];
    float studentGPA;
};


int main(void)
{
    struct Students std[100];
    int len = 0;
    int num;

    while(1)
    {
        printf("Enter a number.\n");
        printf("0. Terminate the program\n");
        printf("1. Add Student Information (Student ID, Name and GPA)\n");
        printf("2. Search Student by ID\n");
        printf("3. Search Student by Name\n");
        printf("4. Display a List of all Students\n");
        printf("=> ");

        scanf("%d", &num);

        switch(num)
        {
            case 0:
            {
                // 0) Terminate the program
                return 0;
                break;
            }
            

            case 1:
            {
                // 1) Add Student Information (Student ID, Name and GPA)
                int given_ID;
                char given_name[20];
                float given_GPA;

                bool is_given = false;

                printf("Enter a Student ID : ");
                scanf("%d", &given_ID);

                printf("Enter a Student Name : ");
                scanf("%s", &given_name);

                printf("Enter a Student GPA : ");
                scanf("%f", &given_GPA);

                // Cheak if the student ID and Name is unique
                for(int i = 0; i < len; i++) {
                    // If ID is unique
                    if(given_ID == std[i].ID)
                    {
                        printf("Already given Student ID.\n\n");
                        is_given = true;
                        break;
                    }

                    // If Name is unique
                    if(strcmp(given_name, std[i].name) == 0)
                    {
                        printf("Already given Studnet Name.\n\n");
                        is_given = true;
                        break;
                    }
                }
                if(is_given)
                    break;
                
                // Add a Student Name into an Array
                printf("Successfully added.\n\n");

                std[len].ID = given_ID;
                strcpy(std[len].name, given_name);
                std[len].studentGPA = given_GPA;

                len += 1;

                break;
            }

            case 2:
            {
                // 2) Search Student by ID
                int given_ID;
                bool is_there = false;

                printf("Enter a Student ID to search : ");
                scanf("%d", &given_ID);

                for(int i = 0; i < len; i++) {
                    if(given_ID == std[i].ID)
                    {
                        printf("Given Name is now on position %d.\n", i);
                        printf("Student ID : %d, Name : %s, GPA : %.2f\n\n", std[i].ID, std[i].name, std[i].studentGPA);
                        is_there = true;
                        break;
                    }
                }
                if(is_there == false)
                    printf("Given Name is NOT in the list.\n\n");

                break;
            }

            case 3:
            {
                // 3) Search Student by Name
                char given_name[20];
                bool is_there = false;

                printf("Enter a Student Name to Search : ");
                scanf("%s", &given_name);

                for(int i = 0; i < len; i++) {
                    if(strcmp(given_name, std[i].name) == 0)
                    {
                        printf("Given Name is now on position %d.\n", i);
                        printf("Student ID : %d, Name : %s, GPA : %.2f\n\n", std[i].ID, std[i].name, std[i].studentGPA);
                        is_there = true;
                        break;
                    }
                }
                if(is_there == false)
                    printf("Given Name is NOT in the list.\n\n");

                break;
            }

            case 4:
            {
                // 3) Display a List of all Students
                for(int i = 0; i < len; i++)
                {
                    printf("Position : %d, Student ID : %d, Name : %s, GPA : %.2f\n", i, std[i].ID, std[i].name, std[i].studentGPA);
                }
                printf("\n");

                break;
            }


            default:
                break;
        }
    }


    return 0;
}