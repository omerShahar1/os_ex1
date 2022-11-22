#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv) //program accept two the two files names as arguments and check if identical.
{
    FILE *fp1 = fopen(argv[1], "r"); // first file - read only
    FILE *fp2 = fopen(argv[2], "r"); // second file - read only
    
    if (fp1 == NULL || fp2 == NULL)  // check files are open
    {
        printf("Usage : cmp <file1> <file2>");
        exit(-1);
    }

    char ch1 = getc(fp1);
    char ch2 = getc(fp2);

    while (ch1 != EOF && ch2 != EOF) // run untill one of the files data is over
    {
        if (ch1 != ch2)
        {
            printf("Not identical\n");
            return 0;
        }
        
        ch1 = getc(fp1);
        ch2 = getc(fp2);
    }
    
    if ((ch1 != EOF && ch2 == EOF) || (ch1 == EOF && ch2 != EOF)) // if one file isover but the over is not then they are not identical
    {
        printf("Not identical\n");
        return 0;
    }
    
    printf("Identical\n");
    fclose(fp1);
    fclose(fp2);
    return 0;
}