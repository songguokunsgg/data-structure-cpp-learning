#include <iostream>

using namespace std;

int len(char *s){
    int i;
    for (i = 0;s[i] != '\0';++i);
    return i;
}

class String
{
public:
    char *s;
    int length;

    String(char *s){
        this->s = s;
        this->length = len(s);
    }
    ~String(){};

    void printstring(){
        for (int i = 0;this->s[i] != '\0';++i){
            cout << this->s[i];
        }
        cout << endl;
    }

    bool compare(String *t){
        if (t->length != this->length){
            return false;
        }else{
            for (int i = 0;i < t->length;++i){
                if (t->s[i] != this->s[i]){
                    return false;
                }
            }
            return true;
        }
    }

};

int main()
{
    char *s = "hello world";
    char *t = "asdhuasd";

    // cout << len(s) << " "<< len(t) << endl;

    String *p = new String(s);
    String *q = new String(t);

    p->printstring();
    cout << p->compare(q) << endl;
    
    return 0;
}