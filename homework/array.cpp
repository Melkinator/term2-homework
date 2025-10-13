#include <iostream>
using namespace std;

void del(int arr[], int *size, int del) {
    if (del<=*size-1&&del>=0&&*size!=0) {
        for (int i=0;i<*size;i++) {
            if (i==del) {
                for (int j=i;j<*size;j++) {
                    arr[j] = arr[j+1];                    
                }
            }
        }
        (*size)--;
    } else {
        cout << "Your index number is bigger/smaller than the array\n";
    }   
}

void add(int arr[], int *size, int pos, int add) {
    int temp;
    if (pos<=*size-1&&pos>=0&&*size!=0) {
        (*size)++;
        for (int i=*size-1;i>pos;i--) {
            temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
        }
        arr[pos] = add;
    } else {
        cout << "Your index number is bigger/smaller than the array\n";
    }
}

int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    del(arr, &size, 5);

    for (int i=0;i<size;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    add(arr, &size, 5, 8);

    for (int i=0;i<size;i++) {
        cout << arr[i] << " ";
    }
}