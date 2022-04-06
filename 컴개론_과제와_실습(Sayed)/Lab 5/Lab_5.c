#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int studentIDS[100] = {0, };
    int len = 0;
    int num;

    while(1)
    {
        printf("Enter a number.\n");
        printf("0. Terminate the program\n");
        printf("1. Add a Student ID\n");
        printf("2. Delete Student ID\n");
        printf("3. Insert Student ID at a given position or index\n");
        printf("4. Search Student ID\n");
        printf("5. Update Student ID\n");
        printf("6. Display Student IDs\n");
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
                // 1) Add a Student ID
                int given_id;
                int is_given_num = false;

                printf("Enter a student ID : ");
                scanf("%d", &given_id);

                // Cheak if the student ID is unique
                for(int i = 0; i < 100; i++) {
                    if(given_id == studentIDS[i])
                    {
                        printf("Already given Studnet ID.\n\n");
                        is_given_num = true;
                        break;
                    }
                }
                if(is_given_num)
                    break;
                
                // Add a Student ID into an Array
                printf("Successfully added.\n\n");
                studentIDS[len] = given_id;
                len += 1;

                break;
            }


            case 2:
            {
                // 2) Delete Student ID
                int given_id;
                int is_there = false;
                int idx;

                printf("Enter a Student ID to delete : ");
                scanf("%d", &given_id);

                for(int i = 0; i < 100; i++) {
                    if(given_id == studentIDS[i])
                    {
                        is_there = true;
                        idx = i;
                        break;
                    }
                }

                if(is_there)
                {   
                    for(int i = idx; i < len; i++)
                    {
                        studentIDS[i] = studentIDS[i+1];
                    }
                    len -= 1;
                    printf("Delete Completed\n\n");
                }
                else
                {
                    printf("Failed to found the ID.\n\n");
                }

                break;
            }


            case 3:
            {
                // 3) Insert Student ID at a given position or index
                int given_id;
                int given_idx;
                int is_given_num = false;

                printf("Enter a student ID : ");
                scanf("%d", &given_id);
                printf("Enter a number of position to push it : ");

                // Cheak if the student ID is unique
                for(int i = 0; i < 100; i++) {
                    if(given_id == studentIDS[i])
                    {
                        printf("Already given Studnet ID.\n\n");
                        is_given_num = true;
                        break;
                    }
                }
                if(is_given_num)
                    break;
                
                // Add a Student ID into an Array
                printf("Successfully added.\n\n");
                if (given_idx < len)
                {
                    int i = len;
                    for(i; i > given_idx; i--) {
                        studentIDS[i] = studentIDS[i-1];
                    }
                }
                studentIDS[given_idx] = given_id;
                len += 1;

                break;
            }


            case 4:
            {
                // 4) Search Student ID
                int given_id;
                int is_there = false;

                printf("Enter a Student ID to search : ");
                scanf("%d", &given_id);

                for(int i = 0; i < 100; i++) {
                    if(given_id == studentIDS[i])
                    {
                        printf("Given ID is now on position %d.", i);
                        is_there = true;
                        break;
                    }
                }
                if(is_there == false)
                    printf("Given ID is NOT in the list.\n\n");

                break;
            }


            case 5:
            {
                // 5) Update Student ID
                int given_id;
                int is_there = false;
                int change_id;

                printf("Enter a Student ID to update : ");
                scanf("%d", &given_id);

                for(int i = 0; i < 100; i++) {
                    if(given_id == studentIDS[i])
                    {
                        printf("I found it. Which number to change? : ");
                        scanf("%d", &change_id);

                        studentIDS[i] = change_id;
                        is_there = true;

                        printf("Update Completed\n\n");
                        break;
                    }
                }

                if(is_there == false)
                    printf("Failed to found the ID.\n\n");

                break;
            }


            case 6:
            {
                // 6) Display Student IDs
                for(int i = 0; i < len; i++)
                {
                    printf("Position : %d, Student ID : %d\n", i, studentIDS[i]);
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