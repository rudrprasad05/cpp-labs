#include <iostream>

using namespace std;

int sum(int n, int m = 0){
	
	
	if(n <= 1){
		return n;
	}
	
	return n + sum(n - 1, m);
}

int main(){
	int num;
	
	cout << "enter number" << endl;
	cin >> num;
	
	cout << "Sum of natural Numbers till " << num << "is: " << sum(num);
}