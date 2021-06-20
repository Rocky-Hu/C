#include <stdio.h>
#include <fcntl.h>

int main()
{
    int num;
    FILE *fptr;
    fptr = fopen("d:\\1.txt", "w");

    if(fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fprintf(fptr, "%d", 1213);
    fclose(fptr);

    return 0;
}
