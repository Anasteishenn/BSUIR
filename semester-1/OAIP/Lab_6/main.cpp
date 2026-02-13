#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    char str[1000];
    int numbers[500];
    int count = 0;

	cout << "Enter a string: ";
    gets_s(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            char num_str[20];
            int j = 0;

            while (str[i] >= '0' && str[i] <= '9') {
                num_str[j++] = str[i++];
            }
            num_str[j] = '\0';
            numbers[count++] = atoi(num_str);
        }
    }

    if (count == 0) {
        cout << "there is no numbers";
        return 0;
    }

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}
