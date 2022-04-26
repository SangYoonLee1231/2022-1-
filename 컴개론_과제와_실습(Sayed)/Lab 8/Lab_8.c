#include <stdio.h>
#include <string.h>
#include <stdbool.h>


struct Book
{
    int ID;
    char name[20];

    char pub_date[10];
    char pub_name[20];
    int pub_phone_num;

    char author_name[20];
    char author_email[30];
};


int main(void)
{
    struct Book book[100];
    int len = 0;
    int num;

    while(1)
    {
        printf("Enter a number.\n");
        printf("0. Terminate the program\n");
        printf("1. Add book information\n");
        printf("2. Update book information\n");
        printf("3. Delete book information\n");
        printf("4. Search book information\n");
        printf("5. Display a list of book(s) published by an author a\n");
        printf("6. Display a list of book(s) published by a publisher p\n");
        printf("7. Display a list of all book\n");
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
                // Add book information
                int given_ID;
                char given_name[20];

                char given_pub_date[10];
                char given_pub_name[20];
                int given_pub_phone_num;

                char given_author_name[20];
                char given_author_email[30];

                bool is_given = false;


                // Cheak if the given Book ID is unique and not a negative number
                printf("Enter Book ID (MUST new and not a negative num) : ");
                scanf("%d", &given_ID);

                for(int i = 0; i < len; i++) {
                    // If ID is unique
                    if(given_ID == book[i].ID && given_ID >= 0)
                    {
                        printf("Already given ID. Terminate the process.\n\n");
                        is_given = true;
                        break;
                    }
                }
                if(is_given)
                    break;


                // Continue the process if the Book ID is unique and not a negative number
                printf("Book ID is unique and not an negative number. Continue the process.\n");

                printf("Enter Book Name : ");
                scanf("%s", &given_name);

                printf("Enter Publication Date (0000-00-00): ");
                scanf("%s", &given_pub_date);

                printf("Enter Publisher Name : ");
                scanf("%s", &given_pub_name);

                printf("Enter Publisher Phone Number (don't use dash(-)) : ");
                scanf("%d", &given_pub_phone_num);

                printf("Enter an Author Name : ");
                scanf("%s", &given_author_name);

                printf("Enter an Author Email Address : ");
                scanf("%s", &given_author_email);
                

                // Add a Book Infomation into a structure
                printf("Successfully added.\n\n");

                book[len].ID = given_ID;
                strcpy(book[len].name, given_name);
                strcpy(book[len].pub_date, given_pub_date);
                strcpy(book[len].pub_name, given_pub_name);
                book[len].pub_phone_num = given_pub_phone_num;
                strcpy(book[len].author_name, given_author_name);
                strcpy(book[len].author_email, given_author_email);

                len += 1;

                break;
            }

            case 2:
            {
                // Update book information By Book ID
                int given_id;
                char given_book_name;
                int is_there = false;

                int given_new_ID;
                char given_new_name[20];

                char given_new_pub_date[10];
                char given_new_pub_name[20];
                int given_new_pub_phone_num;

                char given_new_author_name[20];
                char given_new_author_email[30];

                printf("Enter a Book ID to update : ");
                scanf("%d", &given_id);


                // Check if the given book ID is exist in the structure
                for(int i = 0; i < 100; i++) {
                    if(given_id == book[i].ID)
                    {
                        printf("I found it.\n");

                        // Update Process
                        printf("Enter NEW Book ID : ");
                        scanf("%d", &given_new_ID);

                        printf("Enter NEW Book Name : ");
                        scanf("%s", &given_new_name);

                        printf("Enter NEW Publication Date (0000-00-00): ");
                        scanf("%s", &given_new_pub_date);

                        printf("Enter NEW Publisher Name : ");
                        scanf("%s", &given_new_pub_name);

                        printf("Enter NEW Publisher Phone Number (don't use dash(-)) : ");
                        scanf("%d", &given_new_pub_phone_num);

                        printf("Enter a NEW Author Name : ");
                        scanf("%s", &given_new_author_name);

                        printf("Enter a NEW Author Email Address : ");
                        scanf("%s", &given_new_author_email);


                        book[i].ID = given_new_ID;
                        strcpy(book[i].name, given_new_name);
                        strcpy(book[i].pub_date, given_new_pub_date);
                        strcpy(book[i].pub_name, given_new_pub_name);
                        book[i].pub_phone_num = given_new_pub_phone_num;
                        strcpy(book[i].author_name, given_new_author_name);
                        strcpy(book[i].author_email, given_new_author_email);

                        is_there = true;

                        printf("Update Completed\n\n");
                        break;
                    }
                }

                if(is_there == false)
                    printf("Failed to found the ID.\n\n");

                break;
            }

            case 3:
            {
                // Delete Book Infomation
                int given_id;
                int is_there = false;
                int idx;

                printf("Enter Book ID to delete : ");
                scanf("%d", &given_id);

                for(int i = 0; i < 100; i++) {
                    if(given_id == book[i].ID)
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
                        book[i] = book[i+1];
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

            case 4:
            {
                // 2) Search book information By ID
                int given_ID;
                bool is_there = false;

                printf("Enter a Book ID to search : ");
                scanf("%d", &given_ID);

                for(int i = 0; i < len; i++) {
                    if(given_ID == book[i].ID)
                    {
                        printf("Given Name is now on position %d.\n", i);
                        
                        printf("Book ID : %d\n", book[i].ID);
                        printf("Book Name : %s\n", book[i].name);
                        printf("Publication Date : %s\n", book[i].pub_date);
                        printf("Publisher Name : %s\n", book[i].pub_name);
                        printf("Publisher Phone Number : %d\n", book[i].pub_phone_num);
                        printf("Author Name : %s\n", book[i].author_name);
                        printf("Author Email Address : %s\n\n", book[i].author_email);

                        is_there = true;
                        break;
                    }
                }
                if(is_there == false)
                    printf("Given Name is NOT in the list.\n\n");

                break;
            }
            
            case 5:
            {
                // Display a list of book(s) published by an author a
                char a[20];
                printf("Enter a name of author to display : ");
                scanf("%s", &a);

                for(int i = 0; i < len; i++)
                {
                    if(strcmp(a, book[i].author_name) == 0)
                    {
                        printf("Book ID : %d\n", book[i].ID);
                        printf("Book Name : %s\n", book[i].name);
                        printf("Publication Date : %s\n", book[i].pub_date);
                        printf("Publisher Name : %s\n", book[i].pub_name);
                        printf("Publisher Phone Number : %d\n", book[i].pub_phone_num);
                        printf("Author Name : %s\n", book[i].author_name);
                        printf("Author Email Address : %s\n\n", book[i].author_email);
                    }
                }
                printf("\n");

                break;
            }

            case 6:
            {
                // Display a list of book(s) published by a publisher p
                char p[20];
                printf("Enter a name of book to display : ");
                scanf("%s", &p);

                for(int i = 0; i < len; i++)
                {
                    if(strcmp(p, book[i].pub_name) == 0)
                    {
                        printf("Book ID : %d\n", book[i].ID);
                        printf("Book Name : %s\n", book[i].name);
                        printf("Publication Date : %s\n", book[i].pub_date);
                        printf("Publisher Name : %s\n", book[i].pub_name);
                        printf("Publisher Phone Number : %d\n", book[i].pub_phone_num);
                        printf("Author Name : %s\n", book[i].author_name);
                        printf("Author Email Address : %s\n\n", book[i].author_email);
                    }
                }
                printf("\n");

                break;
            }

            case 7:
            {
                // 3) Display a List of all Books
                for(int i = 0; i < len; i++)
                {
                    printf("Book ID : %d\n", book[i].ID);
                    printf("Book Name : %s\n", book[i].name);
                    printf("Publication Date : %s\n", book[i].pub_date);
                    printf("Publisher Name : %s\n", book[i].pub_name);
                    printf("Publisher Phone Number : %d\n", book[i].pub_phone_num);
                    printf("Author Name : %s\n", book[i].author_name);
                    printf("Author Email Address : %s\n\n", book[i].author_email);
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