#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Books {
	char name[60];
	int ID;
	char date[40];
	char author[60];
	char address[100];
	char publisher[60];
	char p_num[40];
};

void displayBooks(struct Books bk);

struct Books bk[20];
int index = 0;

void addBook() {

	int next = 1, flag = 0;
	struct Books book;

	while (1) {

		flag = 0;

		printf("\nEnter Book ID : ");
		scanf_s("%d", &book.ID);


		int ret = getchar();

		printf("\nEnter Book Name : ");
		gets(book.name);

		printf("\nEnter Publisher Name : ");
		gets(book.publisher);

		printf("\nEnter Publication Date : ");
		gets(book.date);

		printf("\nEnter Author Name : ");
		gets(book.author);

		printf("\nEnter Author E-mail Address : ");
		gets(book.address);

		printf("\nEnter Publisher Phone Number : ");
		gets(book.p_num);

		// need to store this data in file

		FILE* fptr;
		
		int error = fopen(&fptr, "StudentsData.txt", "a+");

		if (error != 0)
		{

		}

		fprintf(fptr, "%d ", book.ID);
		fprintf(fptr, "%s ", book.name);
		fprintf(fptr, "%s ", book.author);
		fprintf(fptr, "%s ", book.address);
		fprintf(fptr, "%s ", book.publisher);
		fprintf(fptr, "%s\n", book.p_num);

		printf("\nRecord saved\n");
		printf("\nWould you like to add another record? \n<< Enter 1 to continue and 0 to exit >> ");
		scanf_s("%d", &next);
		ret = getchar();
		if (next == 0) break;
	}
}


void searchBookByName() {
	// get book name from user
	getchar();
	printf("Enter book name");
	char bookName[20];
	gets(bookName);

	// open the file
	FILE* fptr;

	int error = fopen(&fptr, "StudentsSata.txt", "a+");

	if(error != 0) {
		printf("Error!");
		exit(1);
	}

	// read line by line
	// from each line, get book name
	char line[60];
	while (fgets(line, 60, fptr) != NULL) {
		puts(line);

		char seps[] = " ";
		char* token = NULL;
		char* next_token = NULL;

		printf("Tokens:\n");

		token = strtok(line, seps, &next_token);
		printf(" %s\n", token);
		token = strtok(NULL, seps, &next_token);
		printf(" %s\n", token);

		// strcmp (tokem, bookName) == 0 then pus(line);

	}

	// (USE strtok Function)
	

	// compare book name from user to book name from line
}

void displayBook() {

	FILE *fp;

	int error = fopen(&fp, "StudentsData.txt", "a+");

	if(error != 0) {
		printf("failed to open a file");
		exit(1);
	}

	char str[60];

	while (fgets(str, 60, fp) != NULL) {
		puts(str);
	}

	/*
	fprintf(fp, "\n\nID: %d", bk.ID);
	fprintf(fp, "\nName: %s", bk.name);
	fprintf(fp, "\nPublication date: %s", bk.date);
	fprintf(fp, "\nAuthor name: %s", bk.author);
	fprintf(fp, "\nAuthor email address: %s", bk.address);
	fprintf(fp, "\nPublisher: %s", bk.publisher);
	fprintf(fp, "\nPublisher phone number: %s", bk.p_num);
	*/
}


int main(void) {

	int cmd;

	do {

		printf("\n\n<< Book Management System >>\n");
		printf("1. Add Book Information\n");
		printf("2. Search Book by Name\n");
		printf("7. Display a list of all book\n");
		printf("8. Exit\n\n");
		scanf_s("%d", &cmd);

		switch (cmd) {
		case 1:
			addBook();
			break;

		case 2:
		searchBookByName();

		case 7:
			for (int i = 0; i < index; i++) {
				displayBook(bk[i]);
			}
			break;

		case 8:
			return;

		default:
			printf("Invalid Menu Number\n");
			break;

		}
	} while (cmd != 8);

	return 0;
}
