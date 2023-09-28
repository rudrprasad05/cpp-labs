#include <iostream>

using namespace std;

int main(){

    // my version
    int arr[] = {3,2,7,8,1,2,0,4,2,4};
    int sorted[10];
    int smallest = 0;
    int swapIndex =0;
    int tempVar = 0;
    int pass = 0;

    for(int i = 0; i < 10; i++){
        smallest = arr[i];

        for(int j = i; j < 10; j++){
            if(arr[j] < smallest){
                smallest = arr[j];
                swapIndex = j;
            }
            pass++;
        }

        tempVar = arr[i];
        arr[i] = arr[swapIndex];
        arr[swapIndex] = tempVar;

        sorted[i] = smallest;

    }

    // actual version


    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    cout << pass;
}