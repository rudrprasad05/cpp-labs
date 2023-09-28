#include <iostream>

using namespace std;

int main(){
    int arr[] = {3,2,7,8,1,2,0,4,2,4};
    int pass = 0;

    for(int i = 0; i < 10; i++){
        for(int j = i + 1; j < 10; j++){
            if(arr[j] < arr[i]){
                cout << arr[i] << " " << arr[j] << endl;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            pass++;
        }
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    cout << "pass: " << pass << endl;

}



