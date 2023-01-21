#include <stdio.h>
#include <stdlib.h>
int main()
{
    char hey[20];
    FILE *fptr;
    fptr = fopen("C:\\Users\\Adi\\Desktop\\codes\\C\\file handling\\Writing.txt", "r");
    if (fptr == NULL)
    {
        printf("error in reading file!\n");
        return -1;
    }
    while (fscanf(fptr, "%s\n", hey) != EOF)

        //fscanf(fptr,"%s",hey);
        printf("%s", hey);
    fclose(fptr);
    return 0;
}
