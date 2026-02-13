#include <iostream>
#include <cmath>  

using namespace std;

double f(double x, int choice) {
    switch (choice) {
    case 1: return 2 * x;     
    case 2: return x * x;     
    case 3: return x / 3.0;   
    default:
        cout << "Неверный выбор функции!" << endl;
        return 0;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    double a, b, z, x, y;
    int choice;

    cout << "Введите a: ";
    if (!(cin >> a)) {
        cout << "Вы ввели не число!" << endl;
        return 1;
    }

    cout << "Введите b: ";
    if (!(cin >> b)) {
        cout << "Вы ввели не число!" << endl;
        return 1;
    }

    cout << "Введите z: ";
    if (!(cin >> z)) {
        cout << "Вы ввели не число!" << endl;
        return 1;
    }

    cout << "Выберите функцию f(x):" << endl;
    cout << "1) f(x) = 2x\n2) f(x) = x^2\n3) f(x) = x/3" << endl;
    if (!(cin >> choice)) {
        cout << "Введите 1, 2 или 3." << endl;
        return 1;
    }

    if (z <= 0) {
        x = (z * z) / 2.0;
    }
    else{
        x = sqrt(z);
    }
     
    if (cos(x) == 0) {
        cout << "Ошибка: деление на ноль (cos(x)=0)" << endl;
        return 1;
    }
    if (tan(x / 2.0) == 0) {
        cout << "Ошибка: ln(0) не существует" << endl;
        return 1;
    }

    
    y = (b * f(x, choice)) / cos(x) + a * log(abs(tan(x / 2.0)));

    cout << "Результат: y = " << y << endl;

    return 0;
}
