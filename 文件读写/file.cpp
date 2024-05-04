/* 行的概念



*/

#include <iostream>

using namespace std;

int main()
{
    FILE *fp = fopen("file.txt", "r");

// 调用一次fgetc，文件指针后移
    char ch;

    while (ch != '\n'){
        ch = fgetc(fp);
        cout << ch;
    }

    cout << fgetc(fp) << endl;

    char *s = fgets(fp);

    return 0;

}
