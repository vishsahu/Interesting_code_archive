#include <stdio.h>
#include <errno.h>

void main(int argc, char * argv[])
{
    char ch;
    FILE *fp1, *fp2;

    if (fp1 = fopen(argv[1], "r")) {
        fp2 = fopen(argv[2], "w");
        int offset = -1;

        while (fseek(fp1, offset--, SEEK_END) == 0) {
            ch = fgetc(fp1);
            fputc(ch, fp2);
        }
        printf("**File copied successfully in reverse order**\n");
    }
    else {
        perror("Error occured\n");
    }
    fclose(fp1);
    fclose(fp2);
}
