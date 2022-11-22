#include "codec.h"

int encode(char* src ,char* dest, int len)
{
    int count = 0;
    char temp;
    while (count < len)
    {
        temp = src[count];
        if (isalpha(temp))
        { 
            dest[count] = tolower(temp);
        }
        else 
        {
            dest[count] = temp;
        }
        count++;
    }
    return 0;
}

int decode(char* src ,char* dest, int len)
{
    int count = 0;
    char temp;
    while (count < len)
    {
        temp = src[count];
        if (isalpha(temp)) 
        {
            dest[count] = toupper(temp);
        }
        else 
        {
            dest[count] = temp;
        }
        count++;
    }
    return 0;
}