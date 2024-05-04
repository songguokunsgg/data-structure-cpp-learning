#include <stdio.h>

void printstring(char *s){
    int i = 0;
    for (i;s[i] != '\0';++i)
        printf("%c",s[i]);
    printf("\n");
}

int main(){
    char *s = "hello world";
    printstring(s);

    printf("%c\n",s[4]);

    return 0;
}