#include <iostream>
#include <cstdio>
#include <ctime>

#define SIZE size;
using namespace std;

int delnumber(char *s)
{
    int i, j;
    j = 0;
    for (i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            s[j] = s[i];
            ++j;
        }
    }
    return j;
}

int main()
{
    int size = 30;
    int len, i;
    // char s[size];
    // cin.getline(s,sizeof(s));
    char s[size] = "asdas123asda13onpi313npisdf";

    len = delnumber(s);
    for (i = 0; i < len; ++i)
    {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}