#include <iostream>
using namespace std;

void insertion_sort(int arr[], int len){
        int i,j,key;
        for (i=1;i<len;i++){
                key = arr[i];
                j=i-1;
                while((j>=0) && (arr[j]>key)) {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;
        }
}

int main(){
    int arr[] = {3,2,5,6,8,7,10,9};
    int len = 8;
    insertion_sort(arr,len);

    for (int i = 0;i < len;i++){
        cout << arr[i] << " ";
    }
    cout <<endl;

    return 0;
}