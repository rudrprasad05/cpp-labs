#include <iostream>

using namespace std;

void swap(int a[], int x, int y){
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

int main(){
    int arr[] = {3,2,7,8,1,2,0,4,2,4};
    int pass = 0;

    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 10 - i - 1; j++){

            if(arr[j] > arr[j+1] ){
                int temp = arr[j];

                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            pass++;
        }
        
    }

    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    cout << pass;

    
}