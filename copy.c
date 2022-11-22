#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include "codec.h"
#include <string.h>
#include <errno.h>
#define BUF_SIZE 8192




int main(int argc, char **argv)  // copy contect of the first file to the other. if before the first file we put '-l' then it will be treated as a link
{
    if (argc == 3)
    {
        int src, dest, in, out; 
        char buf[BUF_SIZE];
        
        src = open(argv[1], O_RDONLY);
        if (src < 0)
        {
            printf("Usage : copy <file1> <file2>");
            exit(-1);
        }

        dest = open(argv[2] ,O_WRONLY|O_CREAT , 0666);  // if second file does not exist, we create it
        if (dest < 0)
        {
            printf("Usage : copy <file1> <file2>");
            exit(-2);
        }

        while (1) // copy data to second file until first file is finished
        {
            in = read(src, buf, BUF_SIZE);
            if (in <= 0) 
            {
                break;
            }
            out = write(dest, buf, in);
            if (out <= 0)
            {
                break;
            }
        }
        close(src); 
        close(dest); 

        printf("file contents is copied\n");
    }

    else if (argc == 4) // if main received 4 parameters (second will be '-l') then we treat the third parameter as a link
    {
        int dest, opt;
        char *buf;
        ssize_t temp_size, in;
        

        opt = getopt(argc, argv,":if:l"); 
        if (opt != 'l')
        {
            printf("Usage : copy <file1> <file2>");
            exit(-1);
        }
        
        dest = open(argv[3] ,O_WRONLY|O_CREAT , 0666);
        if (dest < 0)
        {
            printf("Usage : copy <file1> <file2>");
            exit(-2);
        }

        struct stat attributes;
        if(stat(argv[2], &attributes) == -1)
        {
            printf("Usage : copy <file1> <file2>");
            exit(-3);
        }

        temp_size = attributes.st_size + 1;
        if (attributes.st_size == 0)
        {
            temp_size = PATH_MAX;
        }

        buf = malloc(temp_size);
        if (buf == NULL) 
        {
            printf("Usage : copy <file1> <file2>");
            exit(-4);
        }

        in = readlink(argv[2], buf, temp_size);
        if (in < 0) 
        {
            printf("Usage : copy <file1> <file2>")
            perror("Error printed by perror");;
            exit(-5);
        }

        write(dest, buf, in);
        free(buf);
        close(dest);
        printf("file contents is copied\n");
        return 0;
    }
}
