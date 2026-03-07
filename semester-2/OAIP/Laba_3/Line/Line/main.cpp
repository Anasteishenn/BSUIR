#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Spis {
    int info;
    Spis* prev;
    Spis* next;
};

void Create(Spis** begin, Spis** end, int in) {
    Spis* t = new Spis;
    t->info = in;
    t->next = NULL;
    t->prev = NULL;

    if (*begin == NULL) {
        *begin = *end = t;
    }
    else {
        t->prev = *end;
        (*end)->next = t;
        *end = t;
    }
}

void AddToBegin(Spis** begin, Spis** end, int in) {
    Spis* t = new Spis;
    t->info = in;
    t->prev = NULL;
    t->next = NULL;

    if (*begin == NULL) {
        *begin = *end = t;
    }
    else {
        t->next = *begin;
        (*begin)->prev = t;
        *begin = t;
    }
}

void ViewFromBegin(Spis* begin) {
    if (begin == NULL) {
        cout << "Список пуст" << endl;
        return;
    }

    cout << "Список с начала: ";
    Spis* t = begin;
    while (t != NULL) {
        cout << t->info << " ";
        t = t->next;
    }
    cout << endl;
}

void ViewFromEnd(Spis* end) {
    if (end == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    cout << "Список с конца: ";
    Spis* t = end;
    while (t != NULL) {
        cout << t->info << " ";
        t = t->prev;
    }
    cout << endl;
}

void FillRandom(Spis** begin, Spis** end, int n) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        int in = -100 + rand() % 201;  
        Create(begin, end, in);  
    }
}
void DelAll(Spis** begin, Spis** end) {
    Spis* t;
    while (*begin != NULL) {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
    *end = NULL;
}

void Del_5(Spis** begin, Spis** end) {
    if (*begin == NULL) {
        cout << "Список пуст" << endl;
        return;
    }

    AddToBegin(begin, end, 21);
    Spis* current = *begin;

    while (current != NULL) {
        Spis* t = current->next;  

        if (current->info % 10 == 5 || current->info % 10 == -5) {
            cout << "Удаляем элемент: " << current->info << endl;

            if (current == *begin) {
                *begin = current->next;
                if (*begin != NULL) {
                    (*begin)->prev = NULL;
                }
            }
            else if (current == *end) {
                *end = current->prev;
                if (*end != NULL) {
                    (*end)->next = NULL;
                }
            }
            
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            delete current;
        }

        current = t;
    }

    Spis* temp = *begin;
    *begin = (*begin)->next;
    if (*begin != NULL) {
        (*begin)->prev = NULL;
    }
    else {
        *end = NULL;
    }
    delete temp;
}

void swap(Spis** begin, Spis** end) {
    if (*begin == NULL || *begin == *end) return;

    Spis* first = *begin;
    Spis* last = *end;
    Spis* second = first->next;
    Spis* preLast = last->prev;

    last->next = second;
    second->prev = last;
    last->prev = NULL;

    preLast->next = first;
    first->prev = preLast;
    first->next = NULL;

    *begin = last;
    *end = first;
}

int main() {
    setlocale(LC_ALL, "Russian");

    Spis* begin = NULL;
    Spis* end = NULL;
    int choice, n, value;

    do {
        cout << "1. Создать список" << endl;
        cout << "2. Добавить элемент в начало" << endl;
        cout << "3. Добавить элемент в конец" << endl;
        cout << "4. Просмотр с начала" << endl;
        cout << "5. Просмотр с конца" << endl;
        cout << "6. Удалить элементы, заканчивающиеся на 5 " << endl;
        cout << "7. Крайние элементы поменять местами" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (begin != NULL) {
                DelAll(&begin, &end);
            }
            cout << "Введите количество элементов: ";
            cin >> n;
            FillRandom(&begin, &end, n);
            cout << "Список создан" << endl;
            ViewFromBegin(begin);
            break;

        case 2:
            cout << "Введите значение: ";
            cin >> value;
            AddToBegin(&begin, &end, value);
            cout << "Элемент добавлен в начало" << endl;
            ViewFromBegin(begin);
            break;

        case 3:
            cout << "Введите значение: ";
            cin >> value;
            Create(&begin, &end, value);
            cout << "Элемент добавлен в конец" << endl;
            ViewFromBegin(begin);
            break;

        case 4:
            ViewFromBegin(begin);
            break;

        case 5:
            ViewFromEnd(end);
            break;

        case 6:
            cout << "Исходный список:" << endl;
            ViewFromBegin(begin);
            Del_5(&begin, &end);
            cout << "Список после Del_5:" << endl;
            ViewFromBegin(begin);
            break;
        case 7:
            swap(&begin, &end);
            ViewFromBegin(begin);
            break;
        case 0:
            if (begin != NULL) {
                DelAll(&begin, &end);
            }
            cout << "Программа завершена." << endl;
            break;

        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    return 0;
}