#include <iostream>
#define MAX 100

using namespace std;

typedef struct array{
    int val[MAX];
    int length;

    array(int values[], int length){
        for (int i = 0;i<length;i++){
            this->val[i] = values[i];
        }
        this->length = length;
    };

    void print(){
        for(int i = 0;i < this->length;++i){
            cout << this->val[i] << " ";
        }
        cout << endl;
    }

}array;

int main(){
    int temp[] = {4,6,3,2,9,8,1,5};
    int length = 8;
    array ls(temp,length);
    ls.print();
    return 0;
}