#include <iostream>
#include <cmath>
using namespace std;


int main() {
    setlocale(LC_ALL, "RU");
    double alpha;
    cout << "Введите значение a: ";
    if (!(cin >> alpha)) {
        cout << "Ошибка: введено не число." << endl;
        return 1;
    }
    
    double root1 = pow(alpha,2) - 4;        
    double root2 = 2 * alpha + 2 * sqrt(root1);
    double root3 = sqrt(pow(alpha, 2) - 4) + alpha + 2;
    double root4 = alpha + 2;

    if (root1 < 0) {
        cout << "Ошибка, нельзя извлечь корень." << endl;
        return 1;
    }
    if (root2 < 0) {
        cout << "Ошибка: подкоренное выражение 0." << endl;
        return 1;
    }
    if (root3 <= 0) {
        cout << "Ошибка: знаменатель <= 0." << endl;
        return 1;
    }
    if (root4 <= 0) {
        cout << "Ошибка: подкоренное выражение <= 0." << endl;
        return 1;
    }

    
    double z1 = sqrt(root2) / root3;
    double z2 = 1/ sqrt(root4);

    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;

    return 0;
}
