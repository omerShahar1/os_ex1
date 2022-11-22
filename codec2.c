#include "codec.h"

int encode(char* src ,char* dest, int len)
{
    int count = 0;
    char ch;
    while (count < len)
    {
        ch = src[count];
        char temp = ~(ch);
        temp += 1;
        dest[count] = temp;
        count++;
    }
    return 0;
}

int decode(char* src ,char* dest, int len)
{
    int count = 0;
    char ch;
    while (count < len)
    {
        ch = src[count];
        char temp = ~((ch - 1));
        dest[count] = temp;
        count++;
    }
    return 0;
}