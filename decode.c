#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

int main(int argc, char **argv) // receive the type of decoding and the message. print the decoded message.
{
    char* loc;
    if (!strcmp(argv[1] , "codec1"))
    {
        loc = "./libcodec1.so";
    }
    else if (!strcmp(argv[1] , "codec2"))
    {
        loc = "./libcodec2.so";
    }
    else
    {
        printf("Usage : decode <codec> <message>");
        exit(-1);
    }
    
    void *handle = dlopen(loc , RTLD_LAZY);
    if (handle == NULL) 
    {
        printf("Usage : decode <codec> <message>");
        exit(-2);
    }

    int (*func)(char* , char* , int); 
    *(void **) (&func) = dlsym(handle, "decode");
    
    char* final = malloc(strlen(argv[2]) + 1);
    (*func)(argv[2], final , strlen(argv[2]));
    
    printf("%s\n" , final);
    free(final);
    dlclose(handle);
    return 0;
}