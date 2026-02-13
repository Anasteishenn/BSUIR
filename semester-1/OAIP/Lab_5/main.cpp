#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int** mass;
    int rows;
    int cols;
    int choice;

    cout << "Enter size(rows)" << endl;
    cin >> rows;

    cout << "Enter size(cols)" << endl;
    cin >> cols;

    mass = new int* [rows];
    for (int i = 0; i < rows; i++) {
        mass[i] = new int[cols];
    }

    cout << "Random(1) or by yourself(2)? ";
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mass[i][j] = rand() % 201 - 100; // от -100 до 100
            }
        }
    }
    else if (choice == 2) {
        cout << "Enter array elements row by row:" << endl;
        for (int i = 0; i < rows; i++) {
            cout << "Enter row " << i + 1 << " (" << cols << " numbers): ";
            for (int j = 0; j < cols; j++) {
                cin >> mass[i][j];
            }
        }
    }
    else {
        cout << "Invalid input" << endl;

        for (int i = 0; i < rows; i++) {
            delete[] mass[i];
        }
        delete[] mass;

        return 1;
    }

    cout << "Your massive: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }

    int* maxElements = new int[rows];
    for (int i = 0; i < rows; i++) {
        int maxVal = mass[i][0];
        for (int j = 1; j < cols; j++) {
            if (mass[i][j] > maxVal) {
                maxVal = mass[i][j];
            }
        }
        maxElements[i] = maxVal;
    }

    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (maxElements[j] > maxElements[j + 1]) {
                int* tempRow = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = tempRow;

                int tempMax = maxElements[j];
                maxElements[j] = maxElements[j + 1];
                maxElements[j + 1] = tempMax;
            }
        }
    }

    cout << "Sort massive: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }

    delete[] maxElements;

    
    for (int i = 0; i < rows; i++) {
        delete[] mass[i];
    }
    delete[] mass;

    return 0;
}