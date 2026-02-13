#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double term(double x, int k)
{
    if (k == 0)
        return x * x * x / 3.0;  

    return term(x, k - 1) * (-x * x * (4.0 * k * k - 1) / (4.0 * pow(k + 1, 2) - 1));
}

// Рекурсивная сумма ряда
double S(double x, int n)
{
    if (n == 1)
        return term(x, 0);

    return S(x, n - 1) + term(x, n - 1);
}

double Y(double x)
{
    return ((1 + x * x) / 2.0) * atan(x) - x / 2.0;
}

int main()
{
    setlocale(LC_ALL, "rus");

    double a, b, h;
    cout << "Введите a b h: ";
    cin >> a >> b >> h;

    int n;
    cout << "Введите количество членов ряда n: ";
    cin >> n;

    cout << "x\t\tS(x)\t\tY(x)\t\t|Y(x)-S(x)|\n";
    cout << "-------------------------------------------------------\n";

    for (double x = a; x <= b; x += h)
    {
        double s = S(x, n);
        double y = Y(x);

        cout << x << "\t" << s << "\t" << y << "\t" << fabs(y - s) << "\n";
    }

    return 0;
}
