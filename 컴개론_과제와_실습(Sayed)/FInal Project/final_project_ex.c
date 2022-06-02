#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Books {
    int bookID;
    char bookName[60];
    char publicationDate[40];
    char publisherName[60];
    char authorName[60];
    char authorAddress[100];
    char authorPhoneNumber[40];
    char authorEmailAddress[40];
    char authorBio[100];
};

struct Book {
    char bookID[5];
    char bookName[60];
    char publicationDate[40];
    char publisherName[60];
    char authorID[5];
};

struct Author {
    char authorID[5];
    char authorName[60];
    char authorAddress[100];
    char authorPhoneNumber[40];
    char authorEmailAddress[40];
    char authorBio[100];
};

void displayBooks();
void addBooks();
void addAuthor();
void searchBook();
void displayAuthors();
struct Books storeDataInBookStruct(char line[]);
void printAuthorInfo(struct Author au);


void addBooks()
{
    int next = 1, flag = 0;
    struct Book bk;
    char authorID[5];

    while(1)
    {
        flag = 0;

        printf("\nEnter Book ID: ");
        scanf("%d", &bk.bookID);

        int ret = getchar();

        printf("Enter Book Name: ");
        gets(bk.bookName);
        printf("Enter Publication Date: ");
        gets(bk.publicationDate);
        printf("Enter Publisher Name: ");
        gets(bk.publisherName);

        printf("Author List\n");
        displayAuthors();

        int newAuthorChoice;
        printf("To select author above list enter 0.\nTo add a new author enter 1.");
        scanf("%d", &newAuthorChoice);
        ret = getChar();
        if(newAuthorChoice == 0) {
            printf("Enter Author ID: ");
            gets(bk.authorID);
        }
        else {
            addAuthor();
            printf("Enter Author ID: ");
            displayAuthors();
            printf("Enter Author ID: ");
            gets(bk.authorID);
        }

        FILE* fBookPtr;

        fBookPtr = fopen("BooksData.txt", "a+");

        if (fBookPtr == NULL) {
            printf("Error! opening flie");
            exit(1);
        }

        fprintf(fBookPtr, "%d,", bk.bookID);
        fprintf(fBookPtr, "%s,", bk.bookName);
        fprintf(fBookPtr, "%s,", bk.publicationDate);
        fprintf(fBookPtr, "%s,", bk.publisherName);
        fprintf(fBookPtr, "%s,\n", bk.authorID);

        fclose(fBookPtr);

        printf("\nRecord saved\n");
    }

}

void addAuthor()
{
    int next = 1, flag = 0;
    struct Author au;

    while(1)
    {
        flag = 0;
        printf("\nEnter Author ID: ");
        gets(au.authorID);
        printf("Enter Author Name: ");
        gets(au.authorName);
        printf("Enter Author Address: ");
        gets(au.authorAddress);
        printf("Enter Author Phone Number: ");
        gets(au.authorPhoneNumber);
        printf("Enter Author Email Address: ");
        gets(au.authorEmailAddress);
        printf("Enter Author Short Bio: ");
        gets(au.authorBio);

        FILE* auFile;

        auFile = fopen("AuthorData.txt", "a+");

        if (auFile == NULL) {
            printf("Error! opening flie");
            exit(1);
        }

        fprintf(auFile, "%s,", au.authorID);
        fprintf(auFile, "%s,", au.authorName);
        fprintf(auFile, "%s,", au.authorAddress);
        fprintf(auFile, "%s,", au.authorPhoneNumber);
        fprintf(auFile, "%s,\n", au.authorEmailAddress);
        fprintf(auFile, "%s,\n", au.authorBio);

        fclose(auFile);

        printf("\nRecord Save\n");
        printf("Would you like to add another record \n << Enter 1 to");
        scanf("%d", &next);
        getchar();
        if (next == 0) break;
    }
}


void displayAuthors()
{
    FILE* auFile;

    auFile = fopen("AuthorData.txt", "a+");

    if (auFile == NULL) {
        printf("Error! opening flie");
        exit(1);
    }

    char line[600];
    struct Author aut;

    while(fgets(line, 600, auFile) != NULL)
    {
        char seps = ",";

        char* token = NULL;
        char* next_token = NULL;

        token = strtok(line, seps);
        strcpy(aut.authorID, 5, token);

        token = strtok(NULL, seps);
        strcpy(aut.authorName, 60, token);

        token = strtok(NULL, seps);
        strcpy(aut.authorAddress, 100, token);

        token = strtok(NULL, seps);
        strcpy(aut.authorPhoneNumber, 40, token);

        token = strtok(NULL, seps);
        strcpy(aut.authorEmailAddress, 40, token);

        token = strtok(NULL, seps);
        strcpy(aut.authorBio, 100, token);

        token = strtok(NULL, seps);

        printAuthorInfo();
    }

    fclose(auFile);
}


void printAuthorInfo(struct Author au)
{
    printf("%s\t", au.authorID);
    printf("%s\t", au.authorName);
    printf("%s\t", au.authorAddress);
    printf("%s\t", au.authorPhoneNumber);
    printf("%s\t", au.authorEmailAddress);
    printf("%s\t", au.authorBio);
}


void displayBooks()
{
    FILE* fBookPtr;

    fBookPtr = fopen("Booksdata.txt", "a+");

    if(fBookPtr == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    char line[600];
    struct Books bk;

    while(fgets(line, 600, fBookPtr) != NULL)
    {
        bk = storeDataInBookStruct(line);
    }
}


// 파일 1개일 때
void updateBookInfo()
{
    // ask user to enter book ID.
    int bookID;

    printf("\nEnter Book ID: ");
    scanf_s("%d", &bookID);
    getchar();

    FILE* fBookPtr;

    int error = fopen_s(&fBookPtr, "C:\\Users\\chhat\\Downloads\\BooksData.txt", "a+");

    if (error != 0) {
        printf("Error! opening file");
        return;
    }

    FILE* tempfBookPtr;

    error = fopen_s(&tempfBookPtr, "C:\\Users\\chhat\\Downloads\\tempBooksData.txt", "w");

    if (error != 0) {
        printf("Error! opening file");
        return;
    }

    char line[600];
    struct Books bk;
    while (fgets(line, 600, fBookPtr) != NULL) {
    bk = storeDataInBookStruct(line);
    if (bk.bookID == bookID) {
    printf("Enter New Book Name: ");
    gets(bk.bookName);
    printf("Enter New Publication Date: ");
    gets(bk.publicationDate);
    printf("Enter New Publisher Name: ");
    gets(bk.publisherName);
    printf("Enter New Author Name: ");
    gets(bk.authorName);
    printf("Enter New Author Address: ");
    gets(bk.authorAddress);
    printf("Enter New Author Phone Number: ");
    gets(bk.authorPhoneNumber);
    printf("Enter New Author Email Address: ");
    gets(bk.authorEmailAddress);
    printf("Enter New Author Short Bio: ");
    gets(bk.authorBio);
    fprintf(tempfBookPtr, "%d ,", bk.bookID);
    fprintf(tempfBookPtr, "%s ,", bk.bookName);
    fprintf(tempfBookPtr, "%s ,", bk.publicationDate);
    fprintf(tempfBookPtr, "%s ,", bk.publisherName);
    fprintf(tempfBookPtr, "%s ,", bk.authorName);
    fprintf(tempfBookPtr, "%s ,", bk.authorAddress);
    fprintf(tempfBookPtr, "%s ,", bk.authorPhoneNumber);
    fprintf(tempfBookPtr, "%s ,", bk.authorEmailAddress);
    fprintf(tempfBookPtr, "%s \n", bk.authorBio);
    continue;
    }
    fprintf(tempfBookPtr, "%d ,", bk.bookID);
    fprintf(tempfBookPtr, "%s ,", bk.bookName);
    fprintf(tempfBookPtr, "%s ,", bk.publicationDate);
    fprintf(tempfBookPtr, "%s ,", bk.publisherName);
    fprintf(tempfBookPtr, "%s ,", bk.authorName);
    fprintf(tempfBookPtr, "%s ,", bk.authorAddress);
    fprintf(tempfBookPtr, "%s ,", bk.authorPhoneNumber);
    fprintf(tempfBookPtr, "%s ,", bk.authorEmailAddress);
    fprintf(tempfBookPtr, "%s", bk.authorBio);
    }
    fclose(fBookPtr);
    fclose(tempfBookPtr);
    int flag = remove("C:\\Users\\chhat\\Downloads\\BooksData.txt");
    if (flag != 0) puts("Unable to remove BooksData.txt");
    int flagR = rename("C:\\Users\\chhat\\Downloads\\tempBooksData.txt", "C:\\Users\\chhat\\Downloads\\BooksData.txt");
    if (flagR != 0) puts("Unable to remove tempBooksData.txt");
}


void displayAuthors()
{
    FILE* auFile;

    auFile = fopen("AuthorData.txt", "a+");

    if (auFile == NULL) {
        printf("Error! opening flie");
        exit(1);
    }

    char line[600];
    struct Author aut;

    while(fgets(line, 600, auFile) != NULL)
    {
        char seps = ",";

        char* token = NULL;
        char* next_token = NULL;

        token = strtok(line, seps);
        strcpy(aut.authorID, 5, token);

        token = strtok(NULL, seps);
        strcpy(aut.authorName, 60, token);

        token = strtok(NULL, seps);
        strcpy(aut.authorAddress, 100, token);

        token = strtok(NULL, seps);
        strcpy(aut.authorPhoneNumber, 40, token);

        token = strtok(NULL, seps);
        strcpy(aut.authorEmailAddress, 40, token);

        token = strtok(NULL, seps);
        strcpy(aut.authorBio, 100, token);

        token = strtok(NULL, seps);

        printAuthorInfo();
    }

    fclose(auFile);
}


void printAuthorInfo(struct Author au)
{
    printf("%s\t", au.authorID);
    printf("%s\t", au.authorName);
    printf("%s\t", au.authorAddress);
    printf("%s\t", au.authorPhoneNumber);
    printf("%s\t", au.authorEmailAddress);
    printf("%s\t", au.authorBio);
}


void displayBooks()
{
    FILE* fBookPtr;

    fBookPtr = fopen("Booksdata.txt", "a+");

    if(fBookPtr == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    char line[600];
    struct Books bk;

    while(fgets(line, 600, fBookPtr) != NULL)
    {
        bk = storeDataInBookStruct(line);
    }
}


// 파일 1개일 때
void deleteBookInfo()
{
    // ask user to enter book ID.
    int bookID;

    printf("\nEnter Book ID: ");
    scanf_s("%d", &bookID);
    getchar();

    FILE* fBookPtr;

    int error = fopen_s(&fBookPtr, "C:\\Users\\chhat\\Downloads\\BooksData.txt", "a+");

    if (error != 0) {
        printf("Error! opening file");
        return;
    }

    FILE* tempfBookPtr;

    error = fopen_s(&tempfBookPtr, "C:\\Users\\chhat\\Downloads\\tempBooksData.txt", "w");

    if (error != 0) {
        printf("Error! opening file");
        return;
    }
    
    char line[600];
    struct Books bk;

    while (fgets(line, 600, fBookPtr) != NULL)
    {
        bk = storeDataInBookStruct(line);
        if (bk.bookID == bookID)
        {
            // remove
            continue;
        }

        fprintf(tempfBookPtr, "%d ,", bk.bookID);
        fprintf(tempfBookPtr, "%s ,", bk.bookName);
        fprintf(tempfBookPtr, "%s ,", bk.publicationDate);
        fprintf(tempfBookPtr, "%s ,", bk.publisherName);
        fprintf(tempfBookPtr, "%s ,", bk.authorName);
        fprintf(tempfBookPtr, "%s ,", bk.authorAddress);
        fprintf(tempfBookPtr, "%s ,", bk.authorPhoneNumber);
        fprintf(tempfBookPtr, "%s ,", bk.authorEmailAddress);
        fprintf(tempfBookPtr, "%s", bk.authorBio);

    }

    fclose(fBookPtr);
    fclose(tempfBookPtr);
    
    int flag = remove("C:\\Users\\chhat\\Downloads\\BooksData.txt");
    if (flag != 0) puts("Unable to remove BooksData.txt");
    int flagR = rename("C:\\Users\\chhat\\Downloads\\tempBooksData.txt", "C:\\Users\\chhat\\Downloads\\BooksData.txt");
    if (flagR != 0) puts("Unable to remove tempBooksData.txt");
}