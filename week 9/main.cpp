#include <iostream>

using namespace std;

int sum(int n){
	

	if(n <= 1){
		return n;
	}
	
	return n + sum(n - 1);
	
}

int main(){
	int num, min, range_sum;
	
	cout << "enter number" << endl;
	cin >> num;
	
	cout << "Sum of natural Numbers till " << num << " is: " << sum(num) << endl;
	
	cout << "enter max" << endl;
	cin >> num;
	
	cout << "enter min";
	cin >> min;
	
	range_sum = 
}
