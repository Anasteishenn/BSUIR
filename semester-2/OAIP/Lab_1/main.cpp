#include <iostream>
using namespace std;
//5 вариант

int akerman(int m, int n) {
	if (m == 0) {
		return n + 1;
	}
	if (m > 0 && n > 0) {
		return akerman(m - 1, akerman(m, n - 1));
	}
	else if (m > 0) {
		return akerman(m - 1, 1);
	}
}

int no(int m, int n) {
	if (m == 0) return n + 1;
	if (m == 1) return n + 2;
	if (m == 2) return 2 * n + 3;
	return -1;
}

int main() {
	int m, n;
	cout << "Enter m, n" << endl;
	cin >> m >> n;
	cout <<"wuth: A ("<<m<<","<<n<<") = " << akerman(m, n)<<endl;
	//no_recursion
	cout << "wuthout: A (" << m << "," << n << ") = " << no(m, n);
	return 0;
}