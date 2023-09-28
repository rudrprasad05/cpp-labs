#include <iostream>

using namespace std;

int main(){
    int arr[] = {10,3,12,5,1,8,0,4,2,4};
    int pass = 10;

    for (int i = 0; i < 10; i++){
        // set min index to the first element
        int min_index = i;

        for (int j = i + 1; j < 10; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

    }

    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    
}