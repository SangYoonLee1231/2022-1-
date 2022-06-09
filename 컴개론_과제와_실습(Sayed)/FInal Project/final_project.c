/*
< Library Management Program (Using Structure, Function) >


Write a menu-driven Library Management program in C.
The program should maintain the following information.

Book ID
Book Name
Publication Date
Publisher Name
Author Name
Author Address
Author Phone Number
Author Email Address
Author Short Biography


The program should support the following operations.


Add author information
Update author information
Delete author information 
Search author information

Add book information
Update book information
Delete book information
Search book information
Display a list of all books


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


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Books {
    char book_id[5];
    char book_name[50];
    char publication_date[20];
    char publisher_name[50];
    char author_name[50];
    char author_address[100];
    char author_phone_num[20];
    char author_email_address[50];
    char author_bio[100];
};

struct Book {
    char book_id[5];
    char book_name[50];
    char publication_date[20];
    char publisher_name[50];
    char author_id[5];
};

struct Author {
    char author_id[5];
    char author_name[50];
    char author_address[50];
    char author_phone_num[20];
    char author_email_address[50];
    char author_bio[100];
};


void display_all_authors();
void display_books();
struct Books store_data_in_book_struct(char line[]);

// 기능 구현 함수들
void add_author_info();
void update_author_info();
void delete_author_info();
void search_author_info();

void add_book_info();
void update_book_info();
void delete_book_info();
void search_book_info();
void display_all_books();


//int num_of_books = 0;
int num;


int main(void)
{

    while(1)
    {
        printf("Enter a number.\n\n");
        printf("0. Terminate the program\n");

        printf("1. Add author information\n");
        printf("2. Update author information\n");
        printf("3. Delete author information \n");
        printf("4. Search author information\n\n");

        printf("5. Add book information\n");
        printf("6. Update book information\n");
        printf("7. Delete book information\n");
        printf("8. Search book information\n");
        printf("9. Display a list of all books\n\n");

        printf("=> ");

        scanf("%d", &num);

        printf("\n");


        switch(num)
        {
            case 0:
            {
                // 0) Terminate the program
                exit(0);
                break;
            }
            

            case 1:
            {
                // Case 1 : Add author information
                add_author_info();
                break;
            }

            case 2:
            {
                // Case 2 : Update author information
                update_author_info();
                break;
            }

            case 3:
            {
                // Case 3 : Delete author information 
                delete_author_info();
                break;
            }

            case 4:
            {
                // Case 4 : Search author information
                search_author_info();
                break;
            }
            

            case 5:
            {
                // Case 5 : Add book information
                add_book_info();
                break;
            }

            case 6:
            {
                // Case 6 : Update book information
                update_book_info();
                break;
            }

            case 7:
            {
                // Case 7 : Delete book information
                delete_book_info();
                break;
            }

            case 8:
            {
                // Case 8 : Search book information
                search_book_info();
                break;
            }

            case 9:
            {
                // Case 9 : Display a list of all books
                display_all_books();
                break;
            }

            default:
                break;
        }
    }


    return 0;
}




// ---------------------------------------------------------------------


// display functions

void display_all_authors()
{
    FILE* fAu;

    fAu = fopen("AuthorData.txt", "a+");

    if (fAu == NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    char line[300];
    struct Author author;

    while(gets(line, 300, fAu) == NULL)
    {
        char seps = ",";
        char* token = NULL;

        token = strtok(line, seps);
        strcpy(author.author_id, token);

        token = strtok(NULL, seps);
        strcpy(author.author_name, token);

        token = strtok(NULL, seps);
        strcpy(author.author_address, token);

        token = strtok(NULL, seps);
        strcpy(author.author_phone_num, token);

        token = strtok(NULL, seps);
        strcpy(author.author_email_address, token);

        token = strtok(NULL, seps);
        strcpy(author.author_bio, token);

        printf("%s\t", author.author_id);
        printf("%s\t", author.author_name);
        printf("%s\t", author.author_address);
        printf("%s\t", author.author_phone_num);
        printf("%s\t", author.author_email_address);
        printf("%s\t", author.author_bio);
    }

    fclose(fAu);
}



void display_books()
{
    FILE* fBook;

    fBook = fopen("Booksdata.txt", "a+");

    if(fBook == NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    FILE *fAu;
    fAu = fopen("AuthorData.txt", "a+");

    if (fAu == NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    char line[300];
    struct Books book;
    int author_id;
    int flag = 0;

    while(fgets(line, 300, fBook) == NULL)
    {
        char seps[] = ",";
        char* token = NULL;

        token = strtok(line, seps);
        strcpy(book.book_id, token);

        token = strtok(NULL, seps);
        strcpy(book.book_name, token);

        token = strtok(NULL, seps);
        strcpy(book.publication_date, token);

        token = strtok(NULL, seps);
        strcpy(book.publisher_name, token);

        token = strtok(NULL, seps);
        author_id = (int)token;

        while(fgets(line, 300, fAu) != NULL)
        {
            token = strtok(line, seps);

            if((int)token == author_id)
            {
                token = strtok(NULL, seps);
                strcpy(book.author_name, token);

                token = strtok(NULL, seps);
                strcpy(book.author_address, token);

                token = strtok(NULL, seps);
                strcpy(book.author_phone_num, token);

                token = strtok(NULL, seps);
                strcpy(book.author_email_address, token);

                token = strtok(NULL, seps);
                strcpy(book.author_bio, token);

                flag = 1;
                break;
            }
        }

        if(!flag) {
            printf("Something went wrong. Terminate the process.");
            exit(1);
        }

        printf("\n\nBook ID : %d", book.book_id);
        printf("\nBook Name : %s", book);
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
    }
}

struct Books store_data_in_book_struct(char line[])
{
    struct Books book;

    char seps[] = ",";
    char* token = NULL;

    //char line[300] = line;

    token = strtok(line, seps);
    strcpy(book.book_id, token);

    token = strtok(NULL, seps);
    strcpy(book.book_name, token);

    token = strtok(NULL, seps);
    strcpy(book.publication_date, token);

    token = strtok(NULL, seps);
    strcpy(book.publisher_name, token);

    token = strtok(NULL, seps);
    strcpy(book.author_name, token);

    token = strtok(NULL, seps);
    strcpy(book.author_address, token);

    token = strtok(NULL, seps);
    strcpy(book.author_phone_num, token);

    token = strtok(NULL, seps);
    strcpy(book.author_email_address, token);

    token = strtok(NULL, seps);
    strcpy(book.author_bio, token);


    return book;
}


void display_all_books()
{
    getchar();
    printf("Enter Book Name : ");
    char bookName[20];
    gets(bookName);

    FILE *fBook;
    fBook = fopen("BooksData.txt", "a+");

    if (fBook == NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    FILE *fAu;
    fAu = fopen("AuthorData.txt", "a+");

    if (fAu == NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }


    char line[300];
    int author_id;

    while(fgets(line, 300, fBook) != NULL)
    {
        //puts(line);

        char seps = ",";
        char* token = NULL;

        token = strtok(line, seps);
        printf("%s ", token);

        for (int i = 0; i < 2; i++) {
            token = strtok(NULL, seps);
            printf("%s, ", token);
        }

        token = strtok(NULL, seps);
        author_id = token;

        // find Author info in AuthorData.txt
        char line[60];

        while(fgets(line, 60, fAu) != NULL)
        {
            char seps[] = ",";
            char* token2 = NULL;

            token2 = strtok(line, seps);
            if ((int)token2 == author_id)
            {
                token2 = strtok(NULL, seps);
                printf("%s, ", token2);

                token2 = strtok(NULL, seps);
                printf("%s, ", token2);

                token2 = strtok(NULL, seps);
                printf("%s, ", token2);

                token2 = strtok(NULL, seps);
                printf("%s, ", token2);

                token2 = strtok(NULL, seps);
                printf("%s, ", token2);

                break;
            }
        }
        printf("\n");
    }
}


// ---------------------------------------------------------------------


void add_author_info()
{
    struct Author author;
    int flag;

    bool is_given = false;

    while(1)
    {
        is_given = false;
        getchar();
        printf("Enter Author ID: ");
        gets(author.author_id);
        printf("Enter Author Name: ");
        gets(author.author_name);
        printf("Enter Author Address: ");
        gets(author.author_address);
        printf("Enter Author Phone Number: ");
        gets(author.author_phone_num);
        printf("Enter Author Email Address: ");
        gets(author.author_email_address);
        printf("Enter Author Bio: ");
        gets(author.author_bio);

        FILE* fAu;

        fAu = fopen("AuthorData.txt", "a+");

        if (fAu == NULL) {
            printf("Failed to opening flie. Terminate the program.");
            exit(1);
        }

        fprintf(fAu, "%s,", author.author_id);
        fprintf(fAu, "%s,", author.author_name);
        fprintf(fAu, "%s,", author.author_address);
        fprintf(fAu, "%s,", author.author_phone_num);
        fprintf(fAu, "%s,", author.author_email_address);
        fprintf(fAu, "%s,\n", author.author_bio);
        
        fclose(fAu);

        printf("Continue to add new author info? Yes = 1 / No = 0 \n=> ");
        scanf("%d", &flag);
        if(!flag)  break;
    }
}


void update_author_info()
{
    int given_author_id;

    printf("\nEnter Author ID: ");
    scanf("%d", &given_author_id);
    getchar();

    FILE* fAu;

    fAu = fopen("AuthorData.txt", "a+");

    if (fAu != NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    FILE* temp_fAu;

    temp_fAu = fopen("tempAuthorData.txt", "w");

    if (temp_fAu != NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }


    char line[300];
    struct Author author;

    while (fgets(line, 300, fAu) != NULL)
    {
        char seps[] = ",";
        char* token = NULL;

        token = strtok(NULL, seps);
        strcpy(author.author_name, token);

        token = strtok(NULL, seps);
        strcpy(author.author_address, token);

        token = strtok(NULL, seps);
        strcpy(author.author_phone_num, token);

        token = strtok(NULL, seps);
        strcpy(author.author_email_address, token);

        token = strtok(NULL, seps);
        strcpy(author.author_bio, token);


        if (author.author_id == given_author_id)
        {
            printf("Enter New Author Name: ");
            gets(author.author_name);
            printf("Enter New Author Address: ");
            gets(author.author_address);
            printf("Enter New Author Phone Num: ");
            gets(author.author_phone_num);
            printf("Enter New Author Email Address: ");
            gets(author.author_email_address);
            printf("Enter New Author Bio: ");
            gets(author.author_bio);

            fprintf(temp_fAu, "%s,", author.author_name);
            fprintf(temp_fAu, "%s,", author.author_address);
            fprintf(temp_fAu, "%s,", author.author_phone_num);
            fprintf(temp_fAu, "%s,", author.author_email_address);
            fprintf(temp_fAu, "%s \n", author.author_bio);

            continue;
        }

        fprintf(temp_fAu, "%s,", author.author_name);
        fprintf(temp_fAu, "%s,", author.author_address);
        fprintf(temp_fAu, "%s,", author.author_phone_num);
        fprintf(temp_fAu, "%s,", author.author_email_address);
        fprintf(temp_fAu, "%s", author.author_bio);
    }

    fclose(fAu);
    fclose(temp_fAu);


    int remove_flag = remove("AuthorData.txt");
    if (remove_flag != 0)
        puts("Unable to remove AuthorData.txt");

    int rename_flag = rename("tempAuthorData.txt", "AuthorData.txt");
    if (rename_flag != 0)
        puts("Unable to remove tempBooksData.txt");
}


void delete_author_info()
{
    int given_author_id;

    printf("\nEnter Author ID: ");
    scanf("%d", &given_author_id);
    getchar();

    FILE* fAu;

    fAu = fopen("AuthorData.txt", "a+");

    if (fAu != NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    FILE* temp_fAu;

    temp_fAu = fopen("tempAuthorData.txt", "w");

    if (temp_fAu != NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }


    char line[300];
    struct Author author;

    while (fgets(line, 300, fAu) != NULL)
    {
        char seps[] = ",";
        char* token = NULL;

        token = strtok(NULL, seps);
        strcpy(author.author_name, token);

        token = strtok(NULL, seps);
        strcpy(author.author_address, token);

        token = strtok(NULL, seps);
        strcpy(author.author_phone_num, token);

        token = strtok(NULL, seps);
        strcpy(author.author_email_address, token);

        token = strtok(NULL, seps);
        strcpy(author.author_bio, token);

        if (author.author_id == given_author_id)
        {
            // erase
            continue;
        }

        fprintf(temp_fAu, "%s,", author.author_name);
        fprintf(temp_fAu, "%s,", author.author_address);
        fprintf(temp_fAu, "%s,", author.author_phone_num);
        fprintf(temp_fAu, "%s,", author.author_email_address);
        fprintf(temp_fAu, "%s", author.author_bio);
    }

    fclose(fAu);
    fclose(temp_fAu);


    int remove_flag = remove("AuthorData.txt");
    if (remove_flag != 0)
        puts("Unable to remove AuthorData.txt");

    int rename_flag = rename("tempAuthorData.txt", "AuthorData.txt");
    if (rename_flag != 0)
        puts("Unable to remove tempBooksData.txt");
}


void search_author_info()
{
    getchar();
    printf("Enter Author Name: ");
    char authorName[20];
    gets(authorName);

    FILE *fAu;
    fAu = fopen("AuthorData.txt", "a+");

    if (fAu == NULL) {
        printf("Failed to opening flie. Terminate the program.");
    }

    char line[60];
    int flag = 0;

    while(fgets(line, 60, fAu) != NULL)
    {
        char seps[] = ",";
        char* token = NULL;

        token = strtok(line, seps);
        token = strtok(line, seps);

        if(strcmp(token, authorName) == 0) {
            puts(line);
            flag = 1;
        }
    }

    if(!flag) {
        print("Nothing has found.");
    }

}



void add_book_info()
{
    // Case 5 : Add book information
    struct Book book;
    int id;
    int pick_author;

    bool is_given = false;

    while(1)
    {
        is_given = false;

        printf("\nEnter Book ID: ");
        gets(book.book_id);
        printf("Enter Book Name: ");
        gets(book.book_name);
        printf("Enter Publication Date: ");
        gets(book.publication_date);
        printf("Enter Publisher Name: ");
        gets(book.publisher_name);

        printf("Author List\n");
        display_all_authors();

        printf("To add info of author above list, enter 1.\nTo add a new author, enter 0.");
        scanf("%d", &pick_author);

        if(pick_author) {
            // add info of author above list
            printf("Enter Author ID: ");
            gets(book.author_id);
        }
        else {
            // add a new author
            add_author_info();
            printf("Author List: ");
            display_all_authors();
            printf("Enter Author ID: ");
            gets(book.author_id);
        }

        FILE* fBook;

        fBook = fopen("BooksData.txt", "a+");

        if (fBook == NULL) {
            printf("Failed to opening flie. Terminate the program.");
            exit(1);
        }

        fprintf(fBook, "%s,", book.book_id);
        fprintf(fBook, "%s,", book.book_name);
        fprintf(fBook, "%s,", book.publication_date);
        fprintf(fBook, "%s,", book.publisher_name);
        fprintf(fBook, "%s,\n", book.author_id);

        fclose(fBook);

        printf("\nRecord saved\n");

        break;
    }
}


void update_book_info()
{
    // ask user to enter book ID.
    int given_book_id;

    printf("\nEnter Book ID: ");
    scanf("%d", &given_book_id);
    getchar();

    FILE* fBook;

    fBook = fopen("BooksData.txt", "a+");

    if (fBook == NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    FILE* fAu;

    fAu = fopen("AuthorData.txt", "a+");

    if (fAu != NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    FILE* temp_fBook;

    temp_fBook = fopen("tempBooksData.txt", "w");

    if (temp_fBook != NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    FILE* temp_fAu;

    temp_fAu = fopen("tempAuthorData.txt", "w");

    if (temp_fAu != NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }


    char line[300];
    struct Books book;

    while (fgets(line, 300, fBook) != NULL)
    {
        char seps[] = ",";
        char* token = NULL;

        token = strtok(line, seps);
        strcpy(book.book_id, token);

        token = strtok(NULL, seps);
        strcpy(book.book_name, token);

        token = strtok(NULL, seps);
        strcpy(book.publication_date, token);

        token = strtok(NULL, seps);
        strcpy(book.publisher_name, token);

        token = strtok(NULL, seps);
        strcpy(book.author_name, token);

        token = strtok(NULL, seps);
        strcpy(book.author_address, token);

        token = strtok(NULL, seps);
        strcpy(book.author_phone_num, token);

        token = strtok(NULL, seps);
        strcpy(book.author_email_address, token);

        token = strtok(NULL, seps);
        strcpy(book.author_bio, token);


        if (book.book_id == given_book_id)
        {
            printf("Enter New Book Name: ");
            gets(book.book_name);
            printf("Enter New Publication Date: ");
            gets(book.publication_date);
            printf("Enter New Publisher Name: ");
            gets(book.publisher_name);
            printf("Enter New Author Name: ");
            gets(book.author_name);
            printf("Enter New Author Address: ");
            gets(book.author_address);
            printf("Enter New Author Phone Number: ");
            gets(book.author_phone_num);
            printf("Enter New Author Email Address: ");
            gets(book.author_email_address);
            printf("Enter New Author Short Bio: ");
            gets(book.author_bio);

            fprintf(temp_fBook, "%d,", book.book_id);
            fprintf(temp_fBook, "%s,", book.book_name);
            fprintf(temp_fBook, "%s,", book.publication_date);
            fprintf(temp_fBook, "%s,", book.publisher_name);

            fprintf(temp_fAu, "%s,", book.author_name);
            fprintf(temp_fAu, "%s,", book.author_address);
            fprintf(temp_fAu, "%s,", book.author_phone_num);
            fprintf(temp_fAu, "%s,", book.author_email_address);
            fprintf(temp_fAu, "%s \n", book.author_bio);

            continue;
        }

        fprintf(temp_fBook, "%d ,", book.book_id);
        fprintf(temp_fBook, "%s ,", book.book_name);
        fprintf(temp_fBook, "%s ,", book.publication_date);
        fprintf(temp_fBook, "%s ,", book.publisher_name);

        fprintf(temp_fAu, "%s ,", book.author_name);
        fprintf(temp_fAu, "%s ,", book.author_address);
        fprintf(temp_fAu, "%s ,", book.author_phone_num);
        fprintf(temp_fAu, "%s ,", book.author_email_address);
        fprintf(temp_fAu, "%s", book.author_bio);
    }

    fclose(fBook);
    fclose(fAu);
    fclose(temp_fBook);
    fclose(temp_fAu);


    int remove_flag = remove("BooksData.txt");
    if (remove_flag != 0)
        puts("Unable to remove BooksData.txt");

    remove_flag = remove("AuthorData.txt");
    if (remove_flag != 0)
        puts("Unable to remove AuthorData.txt");


    int rename_flag = rename("tempBooksData.txt", "BooksData.txt");
    if (rename_flag != 0)
        puts("Unable to remove tempBooksData.txt");

    rename_flag = rename("tempAuthorData.txt", "AuthorData.txt");
    if (rename_flag != 0)
        puts("Unable to remove tempBooksData.txt");
}


void delete_book_info()
{
    // ask user to enter book ID.
    int given_book_id;
    int author_id;

    printf("\nEnter Book ID: ");
    scanf("%d", &given_book_id);
    getchar();

    FILE* fBook;

    fBook = fopen("BooksData.txt", "a+");

    if (fBook == NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    FILE* fAu;

    fAu = fopen("AuthorData.txt", "w");

    if (fAu != 0) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    FILE* temp_fBook;

    temp_fBook = fopen("tempBooksData.txt", "w");

    if (temp_fBook != 0) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    FILE* temp_fAu;

    temp_fAu = fopen("tempAuthorData.txt", "w");

    if (temp_fAu != 0) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }


    char line[300];
    struct Books book;

    while (fgets(line, 300, fBook) != NULL)
    {
        if (book.book_id == given_book_id)  continue;
        

        char seps[] = ",";
        char* token = NULL;

        token = strtok(line, seps);
        strcpy(book.book_id, token);

        token = strtok(NULL, seps);
        strcpy(book.book_name, token);

        token = strtok(NULL, seps);
        strcpy(book.publication_date, token);

        token = strtok(NULL, seps);
        strcpy(book.publisher_name, token);

        token = strtok(NULL, seps);
        author_id = (int)token;

        int flag = 0;

        while(fgets(line, 300, fAu) != NULL)
        {
            token = strtok(line, seps);

            if((int)token == author_id)
            {
                token = strtok(NULL, seps);
                strcpy(book.author_name, token);

                token = strtok(NULL, seps);
                strcpy(book.author_address, token);

                token = strtok(NULL, seps);
                strcpy(book.author_phone_num, token);

                token = strtok(NULL, seps);
                strcpy(book.author_email_address, token);

                token = strtok(NULL, seps);
                strcpy(book.author_bio, token);

                flag = 1;
                break;
            }
        }

        if(!flag) {
            printf("Something went wrong. Terminate the process.");
            exit(1);
        }

        token = strtok(NULL, seps);
        strcpy(book.author_address, token);

        token = strtok(NULL, seps);
        strcpy(book.author_phone_num, token);

        token = strtok(NULL, seps);
        strcpy(book.author_email_address, token);

        token = strtok(NULL, seps);
        strcpy(book.author_bio, token);



        fprintf(temp_fBook, "%d ,", book.book_id);
        fprintf(temp_fBook, "%s ,", book.book_name);
        fprintf(temp_fBook, "%s ,", book.publication_date);
        fprintf(temp_fBook, "%s ,", book.publisher_name);

        fprintf(temp_fAu, "%s ,", book.author_name);
        fprintf(temp_fAu, "%s ,", book.author_address);
        fprintf(temp_fAu, "%s ,", book.author_phone_num);
        fprintf(temp_fAu, "%s ,", book.author_email_address);
        fprintf(temp_fAu, "%s", book.author_bio);
    }

    fclose(fBook);
    fclose(fAu);
    fclose(temp_fBook);
    fclose(temp_fAu);


    int remove_flag = remove("BooksData.txt");
    if (remove_flag != 0)
        puts("Unable to remove BooksData.txt");

    remove_flag = remove("AuthorData.txt");
    if (remove_flag != 0)
        puts("Unable to remove AuthorData.txt");


    int rename_flag = rename("tempBooksData.txt", "BooksData.txt");
    if (rename_flag != 0)
        puts("Unable to remove tempBooksData.txt");

    rename_flag = rename("tempAuthorData.txt", "AuthorData.txt");
    if (rename_flag != 0)
        puts("Unable to remove tempBooksData.txt");
}


void search_book_info()
{
    getchar();
    printf("Enter Book Name : ");
    char bookName[20];
    gets(bookName);

    FILE *fBook;
    fBook = fopen("BooksData.txt", "a+");

    if (fBook == NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    FILE *fAu;
    fBook = fopen("AuthorData.txt", "a+");

    if (fAu == NULL) {
        printf("Failed to opening flie. Terminate the program.");
        exit(1);
    }

    char line[60];

    while(fgets(line, 60, fBook) != NULL)
    {
        char seps[] = ",";
        char* token = NULL;

        token = strtok(line, seps);
        token = strtok(line, seps);

        if(strcmp(token, bookName) == 0) {
            puts(line);
        }
    }

    fclose(fBook);
    fclose(fAu);
}



