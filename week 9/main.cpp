#include <iostream>

using namespace std;

int sum(int n){
	

	if(n == 1){
		return 0;
	}

	return n + sum(n + 1);
	
}

double fact(double n){
	if(n <= 1){
		return n;
	}
	return n * fact(n - 1);
}

double test(int i){
	if (i == 0){
		return 4;
	}
	return (5 * i * test(i - 1));
}

int main(){
	
	cout << test(4);
	
}
