#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int n = 5, m = 7;
   
    int** B = new int* [n];
    for (int i = 0; i < n; i++) {
        B[i] = new int[m](); 
    }
   
    B[0][0] = B[0][1] = B[0][2] = B[0][3] = B[1][0] = B[1][4] = B[2][1] = B[2][5] = B[3][2] = B[3][6] = B[4][3] = B[4][4] = B[4][6] = 1;

    cout << "B = \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << B[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n";

    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n]();
    }

    for (int j = 0; j < m; ++j) 
    {
        int l1 = -1, l2 = -1;
        for (int i = 0; i < n; ++i)
        {
            if (B[i][j] == 1)
            {
                if (l1 != -1)
                {
                    l2 = i;
                    break;
                }
                l1 = i;
            }
        }
        if (l2 == -1 && l1 != -1) 
            A[l1][l1] = 1;
        else if (l1 != -1 && l2 != -1)
            A[l1][l2] = A[l2][l1] = 1;
    }

    cout << "\nA = \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        delete[] B[i];
        delete[] A[i];
    }
    delete[] B;
    delete[] A;

    return 0;
}