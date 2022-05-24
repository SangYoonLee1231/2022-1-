/*
Write a menu-driven Library Management program in C.
The program should maintain the following information.

Book ID
Book Name
Publication Date
Publisher Name
Publisher Phone Number
Author Name
Author Email Address

The program should support the following operations.


Add book information
Update book information
Delete book information
Search book information
Display a list of book(s) published by an author a
Display a list of book(s) published by a publisher p
Display a list of all book


Book ID should be unique.
Book ID should not be a negative number. 
*/

// 수정 전

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void add_book_info();
void update_book_info();
void delete_book_info();
void search_book_info();
void display_books_by_author();
void display_books_by_publisher();
void display_all_books();


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


struct Book book[100];
int len = 0;
int num;


int main(void)
{

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
                // Case 1 : Add book information
                add_book_info();
                break;
            }

            case 2:
            {
                // Case 2 : Update book information By Book ID
                update_book_info();
                break;
            }

            case 3:
            {
                // Case 3 : Delete Book Infomation
                delete_book_info();
                break;
            }

            case 4:
            {
                // Case 4 : Search book information By ID
                search_book_info();
                break;
            }
            
            case 5:
            {
                // Case 5 : Display a list of book(s) published by an author a
                display_books_by_author();
                break;
            }

            case 6:
            {
                // Case 6 : Display a list of book(s) published by a publisher p
                display_books_by_publisher();
                break;
            }

            case 7:
            {
                // Case 7 : Display a List of all Books
                display_all_books();
                break;
            }

            default:
                break;
        }
    }


    return 0;
}




void add_book_info()
{
    // Case 1 : Add book information
    // 구조체 하나 선언하는 것으로 바꾸기
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
        return;


    // Continue the process if the Book ID is unique and not a negative number
    printf("Available Book ID. (unique and not an negative number) Continue the process.\n");

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
}




void update_book_info()
{
    // Case 2 : Update book information By Book ID
    int given_id;

    printf("Enter a Book ID to update : ");
    scanf("%d", &given_id);

    char given_book_name;
    int is_there = false;

    int given_new_ID;
    char given_new_name[20];

    char given_new_pub_date[10];
    char given_new_pub_name[20];
    int given_new_pub_phone_num;

    char given_new_author_name[20];
    char given_new_author_email[30];

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
            return;
        }
    }

    if(is_there == false)
        printf("Failed to found the ID.\n\n");
}



void delete_book_info()
{
    // Case 3 : Delete Book Infomation
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
}



void search_book_info()
{
    // Case 4 : Search book information By ID
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
}



void display_books_by_author()
{
    // Case 5 : Display a list of book(s) published by an author a
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
}



void display_books_by_publisher()
{
    // Case 6 : Display a list of book(s) published by a publisher p
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
}



void display_all_books()
{
    // Case 7 : Display a List of all Books
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
}