#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Stack {
    int info;
    Stack* next;
};

Stack* InStack(Stack* p, int in) {
    Stack* t = new Stack;
    t->info = in;
    t->next = p;
    return t;
}

void View(Stack* t) {
    if (t == NULL) {
        cout << "Стек пуст" << endl;
        return;
    }

    cout << "Содержимое стека:" << endl;
    while (t != NULL) {
        cout << t->info << " ";
        t = t->next;
    }
    cout << endl;
}

Stack* Del_All(Stack* p) {
    Stack* t;
    while (p != NULL) {
        t = p;
        p = p->next;
        delete t;
    }
    return p;
}

Stack* OutStack(Stack* p, int* out) {
    Stack* t = p;
    *out = p->info;
    p = p->next;
    delete t;
    return p;
}

// Сортировка перестановкой адресов двух соседних элементов
void Sort_p(Stack** p) {
    if (*p == NULL || (*p)->next == NULL) {
        cout << "Стек пуст или содержит только один элемент" << endl;
        return;
    }

    Stack* t = NULL, * t1, * r;

    do {
        for (t1 = *p; t1->next->next != t; t1 = t1->next) {
            if (t1->next->info > t1->next->next->info) {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
            }
        }
        t = t1->next;
    } while ((*p)->next->next != t);

    cout << "Стек отсортирован (перестановкой указателей)" << endl;
}

// Сортировка обменом информацией между текущим и следующим элементами
void Sort_info(Stack* p) {
    if (p == NULL || p->next == NULL) {
        cout << "Стек пуст или содержит только один элемент" << endl;
        return;
    }

    Stack* t = NULL, * t1;
    int r;

    do {
        for (t1 = p; t1->next != t; t1 = t1->next) {
            if (t1->info > t1->next->info) {
                r = t1->info;
                t1->info = t1->next->info;
                t1->next->info = r;
            }
        }
        t = t1;
    } while (p->next != t);

    cout << "Стек отсортирован (обменом информацией)" << endl;
}

//перестановка адресов двух соседних элементов
Stack* Del_5(Stack* b) {
    b = InStack(b, 21);

    if (b == NULL) return b;

    Stack* p = b;           
    Stack* t = p->next;    

    while (t != NULL) {
        if (t->info % 10 == 5 || t->info % 10 == -5) { 
            p->next = t->next;
            delete t;
            t = p->next;
        }
        else {
            p = t;
            t = t->next;
        }
    }
    t = b;
    b = b->next;
    delete t;
    return b;
}

Stack* FillStack(Stack* begin, int n) {
    int in;
    srand(time(NULL));

    for (int i = 1; i <= n; i++) {
        int min = -100;
        int max = 100;
        int in = min + rand() % (max - min + 1);
        begin = InStack(begin, in);
    }
    return begin;
}

Stack* New_Stack_plus(Stack* b) {
    int inf;
    Stack* new_b = NULL;
    Stack* temp = b;

    while (temp != NULL) {
        temp = temp->next;
    }

    while (b != NULL) {
        b = OutStack(b, &inf);
        if (inf > 0) {
            new_b = InStack(new_b, inf);
        }
    }
    return new_b;
}

Stack* New_Stack_minus(Stack* b) {
    int inf;
    Stack* new_b = NULL;

    while (b != NULL) {
        b = OutStack(b, &inf);
        if (inf < 0) {
            new_b = InStack(new_b, inf);
        }
    }

    return new_b;
}

Stack* Swap(Stack* begin) {
    Stack* p = begin;
    Stack* min = begin;  
    Stack* max = begin;  
    int min_val = begin->info;
    int max_val = begin->info;

    while (p != NULL) {
        if (p->info < min_val) {
            min_val = p->info;
            min = p;
        }
        if (p->info > max_val) {
            max_val = p->info;
            max = p;
        }
        p = p->next;
    }
    cout << "Минимальный: " << min_val << endl;
    cout << "Максимальный: " << max_val<< endl;

    int temp = min->info;
    min->info = max->info;
    max->info = temp;
}

int main() {
    setlocale(LC_ALL, "Russian");

    Stack* begin = NULL;
    int choice, n, kol;
    int outValue;

    do {
        cout << "\n1. Создать стек" << endl;
        cout << "2. Просмотр" << endl;
        cout << "3. Удалить элементы, заканчивающиеся на 5" << endl;
        cout << "4. Добавить элемент в стек" << endl;
        cout << "5. Извлечь элемент из стека" << endl;
        cout << "6. Стек только из положительных элементов" << endl;
        cout << "7. Стек только из отрицательных элементов" << endl;
        cout << "8. Сортировка стека (перестановкой указателей)" << endl;
        cout << "9. Сортировка стека (обменом информацией)" << endl;
        cout << "10. Доп задание" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (begin != NULL) {
                begin = Del_All(begin);
            }
            cout << "Введите количество элементов: ";
            cin >> n;
            begin = FillStack(begin, n);
            cout << "Стек создан" << endl;
            View(begin);
            break;

        case 2:
            View(begin);
            break;

        case 3:
            cout << "Исходный стек:" << endl;
            View(begin);
            begin = Del_5(begin);
            cout << "Стек после удаления элементов, заканчивающихся на 5:" << endl;
            View(begin);
            break;

        case 4:
            cout << "Введите число для добавления: ";
            cin >> n;
            begin = InStack(begin, n);
            cout << "Элемент добавлен" << endl;
            View(begin);
            break;

        case 5:
            if (begin == NULL) {
                cout << "Стек пуст" << endl;
            }
            else {
                begin = OutStack(begin, &outValue);
                cout << "Извлечен элемент: " << outValue << endl;
                cout << "Стек после извлечения:" << endl;
                View(begin);
            }
            break;

        case 6: {
            Stack* temp = begin;
            Stack* new_stack = New_Stack_plus(begin);
            begin = new_stack;
            cout << "Новый стек (только положительные элементы):" << endl;
            View(begin);
            break;
        }

        case 7: {
            Stack* temp = begin;
            Stack* new_stack = New_Stack_minus(begin);
            begin = new_stack;
            cout << "Новый стек (только отрицательные элементы):" << endl;
            View(begin);
            break;
        }

        case 8:
            cout << "Исходный стек:" << endl;
            View(begin);
            Sort_p(&begin);
            cout << "Стек после сортировки (перестановкой указателей):" << endl;
            View(begin);
            break;

        case 9:
            cout << "Исходный стек:" << endl;
            View(begin);
            Sort_info(begin);
            cout << "Стек после сортировки (обменом информацией):" << endl;
            View(begin);
            break;
        case 10:
            cout << Swap(begin);
            View(begin);
            break;

        case 0:
            if (begin != NULL) {
                begin = Del_All(begin);
            }
            cout << "Программа завершена." << endl;
            break;

        default:
            cout << "Повторите попытку" << endl;
        }
    } while (choice != 0);

    return 0;
}




