#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp;

    char line[200];
    int count = 0;

    fp = fopen("given_file.txt", "r");

    if(fp == NULL) {
        printf("Error!");
        exit(1);
    }

    while(fgets(line, 200, fp) != NULL)
    {
        char seps[] = " ";
        char* token = NULL;

        token = strtok(line, seps);

        while(token != NULL)
        {
            token = strtok(NULL, seps);
            count++;
        }
    }

    fclose(fp);

    printf("Words : %d", count);

    return 0;
}