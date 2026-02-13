#include <iostream>
#include<cmath>
using namespace std;

float Y(int n, int current) {
	if (current > n) {
		return 0;
	}
	return sqrt(current + Y(n, current + 1));
}

double no(int i, int n, double result) {
	for (int i = n; i >= 1; i--) {
		result = sqrt(i + result);
	}
	return result;
}

int main() {
	int n=0;
	double y=0;
	int current = 1;
	cout << "Enter n ";
	cin >> n;

	
	
	cout << "NO recursion " << no(0,n,0) <<endl;
	cout << "WITH recursion " << Y(n,current);
	
	return 0;
}
