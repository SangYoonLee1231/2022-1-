#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    char studentNames[100][20];
    int len = 0;
    int num;

    while(1)
    {
        printf("Enter a number.\n");
        printf("0. Terminate the program\n");
        printf("1. Add a Student Name\n");
        printf("4. Search Student Name\n");
        printf("6. Display Student Names\n");
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
                // 1) Add a Student Name
                char given_name[20];
                int is_given_num = false;

                printf("Enter a Student Name : ");
                scanf("%s", &given_name);

                // Cheak if the student Name is unique
                for(int i = 0; i < 100; i++) {
                    if(strcmp(given_name, studentNames[i]) == 0)
                    {
                        printf("Already given Studnet Name.\n\n");
                        is_given_num = true;
                        break;
                    }
                }
                if(is_given_num)
                    break;
                
                // Add a Student Name into an Array
                printf("Successfully added.\n\n");
                strcpy(studentNames[len], given_name);
                len += 1;

                break;
            }

            case 4:
            {
                // 4) Search Student Name
                char given_name[20];
                int is_there = false;

                printf("Enter a Student Name to search : ");
                scanf("%s", &given_name);

                for(int i = 0; i < 100; i++) {
                    if(strcmp(given_name, studentNames[i]))
                    {
                        printf("Given Name is now on position %d.\n", i);
                        is_there = true;
                        break;
                    }
                }
                if(is_there == false)
                    printf("Given Name is NOT in the list.\n\n");

                break;
            }

            case 6:
            {
                // 6) Display Student Names
                for(int i = 0; i < len; i++)
                {
                    printf("Position : %d, Student Name : %s\n", i, studentNames[i]);
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