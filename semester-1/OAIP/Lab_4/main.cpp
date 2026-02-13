#include <iostream>
#include <cstdlib>  
#include <ctime>     
#include <cmath>     

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); 
    srand(time(0)); 

    int n;
    cout << "Введите количество элементов массива (не больше 20): ";
    cin >> n;

    if (n <= 0 || n > 20) {
        cout << "Ошибка: размер массива должен быть от 1 до 20.\n";
        return 0;
    }

    const int MAX_SIZE = 20;
    int arr[MAX_SIZE];
    int choice;
    int a, b;
    cout << "Выберите способ заполнения массива:\n";
    cout << "1 - с клавиатуры\n";
    cout << "2 - случайными числами\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Введите " << n << " элементов массива:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    else {
        cout << "Массив, заполненный случайными числами(-100;100) :\n";
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (100+100+1) -100; 
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    
    int lastNegIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) lastNegIndex = i;
    }

    if (lastNegIndex == -1) {
        cout << "В массиве нет отрицательных элементов. Задача не имеет решения.\n";
        return 0;
    }

    if (minIndex == lastNegIndex) {
        cout << "Минимальный элемент и последний отрицательный совпадают. Между ними нет элементов.\n";
        return 0;
    }

    int sum = 0;
    if (minIndex < lastNegIndex) {
        for (int i = minIndex + 1; i < lastNegIndex; i++) {
            sum += abs(arr[i]);
        }
    }
    else {
        for (int i = lastNegIndex + 1; i < minIndex; i++) {
            sum += abs(arr[i]);
        }
    }

    if ((abs(minIndex - lastNegIndex)) == 1) {
        cout << "Между элементами нет чисел для суммирования.\n";
    }
    else {
        cout << "Сумма модулей элементов между минимальным (" << arr[minIndex]
            << ") и последним отрицательным (" << arr[lastNegIndex] << ") = " << sum << endl;
    }

    return 0;
}

