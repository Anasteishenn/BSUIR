#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

struct Student {
    char sur[20] = "";
    int group = 0;
    int fiz = 0, mat = 0, inf = 0;
    bool avscore = 0;
};


double score(int fiz, int mat, int inf) {
    return (fiz + mat + inf) / 3.0;
}


bool writeToFile(const Student* students, int n) {
    ofstream outFile("student_info.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < n; i++) {
            double average = score(students[i].fiz, students[i].mat, students[i].inf);
            outFile << "Информация о студенте " << i + 1 << ":" << endl;
            outFile << "Фамилия: " << students[i].sur << endl;
            outFile << "Номер группы: " << students[i].group << endl;
            outFile << "Оценка по физике: " << students[i].fiz << endl;
            outFile << "Оценка по математике: " << students[i].mat << endl;
            outFile << "Оценка по информатике: " << students[i].inf << endl;
            outFile << "Средний балл: " << average << endl;
        }
        outFile.close();
        return true;
    }
    else {
        return false;
    }
}

bool addStudentsToFile() {
    ifstream testFile("student_info.txt");
    if (!testFile.is_open()) {
        cout << "Файл не найден! Сначала создайте файл." << endl;
        return false;
    }
    testFile.close();

    int n;
    cout << "Введите количество учеников для добавления: ";
    cin >> n;

    ofstream outFile("student_info.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return false;
    }

    for (int i = 0; i < n; i++) {
        Student s;
        cout << "\nДобавляемый студент " << i + 1 << endl;
        cout << "Фамилия: ";
        cin >> s.sur;
        cout << "Номер группы: ";
        cin >> s.group;
        cout << "Оценка по физике: ";
        cin >> s.fiz;
        cout << "Оценка по математике: ";
        cin >> s.mat;
        cout << "Оценка по информатике: ";
        cin >> s.inf;

        double average = score(s.fiz, s.mat, s.inf);

        outFile << "Информация о студенте (добавлен):" << endl;
        outFile << "Фамилия: " << s.sur << endl;
        outFile << "Номер группы: " << s.group << endl;
        outFile << "Оценка по физике: " << s.fiz << endl;
        outFile << "Оценка по математике: " << s.mat << endl;
        outFile << "Оценка по информатике: " << s.inf << endl;
        outFile << "Средний балл: " << average << endl << endl;
    }

    outFile.close();
    cout << "\nУченики успешно добавлены в файл!" << endl;
    return true;
}


void viewFile() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    ifstream inFile("student_info.txt");
    if (inFile.is_open()) {
        char line[256]; 
        cout << "\n СОДЕРЖИМОЕ ФАЙЛА " << endl;
        while (inFile.getline(line, sizeof(line))) {
            cout << line << endl;
        }
        inFile.close();
        cout << " КОНЕЦ ФАЙЛА " << endl;
    }
    else {
        cout << "Файл 'student_info.txt' не найден!" << endl;
    }
}

void individual(Student* students, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].fiz + students[i].mat + students[i].inf;
    }

    double overallAvg = sum / (3 * n);
    cout << "Общий средний балл всех студентов: " << overallAvg << endl;

    int targetGroup;
    cout << "Введите номер интересующей группы: ";
    cin >> targetGroup;

    cout << "\nСтуденты группы " << targetGroup
        << " со средним баллом выше общего:\n";

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (students[i].group == targetGroup) {
            double avg = score(students[i].fiz, students[i].mat, students[i].inf);
            if (avg > overallAvg) {
                found = true;
                cout << "Фамилия: " << students[i].sur
                    << " Средний балл: " << avg << endl;
            }
        }
    }

    if (!found) {
        cout << "Таких студентов не найдено." << endl;
    }
}

bool removeStudent() {
    ifstream FILE("student_info.txt");
    if (!FILE.is_open()) {
        cout << "Файл не найден!" << endl;
        return false;
    }

    ofstream out("temp.txt");
    if (!out.is_open()) {
        cout << "Ошибка создания временного файла!" << endl;
        FILE.close();
        return false;
    }

    char target[20];
    cout << "Введите фамилию студента для удаления: ";
    cin >> target;

    char line[256];
    bool deleting = false;
    bool matchFound = false;

    int skipCount = 0;

    while (FILE.getline(line, sizeof(line))) {
        if (strncmp(line, "Фамилия:", 8) == 0) {

            char fileSurname[20];
            sscanf(line, "Фамилия: %19s", fileSurname);

            if (strcmp(fileSurname, target) == 0) {
                deleting = true;
                matchFound = true;
                skipCount = 0;   
            }
        }

        if (deleting) {
            skipCount++;

            if (skipCount == 7) {
                deleting = false;
                skipCount = 0;
            }

            continue;  
        }
        out << line << endl;
    }

    FILE.close();
    out.close();

    if (!matchFound) {
        cout << "Студент не найден!" << endl;
        remove("temp.txt");
        return false;
    }

    remove("student_info.txt");
    rename("temp.txt", "student_info.txt");

    cout << "\nСтудент успешно удалён!\n";
    cout << "\nТекущее содержимое файла:\n\n";

    ifstream view("student_info.txt");
    while (view.getline(line, sizeof(line))) {
        cout << line << endl;
    }
    view.close();

    return true;
}

void sortByGroup() {
    ifstream in("student_info.txt");
    if (!in.is_open()) {
        cout << "Файл не найден!" << endl;
        return;
    }

    Student arr[1000];
    int count = 0;
    char line[256];

    while (in.getline(line, 256)) {

        Student s;

        in.getline(line, 256);
        sscanf(line, "Фамилия: %19s", s.sur);

        in.getline(line, 256);
        sscanf(line, "Номер группы: %d", &s.group);

        in.getline(line, 256);
        sscanf(line, "Оценка по физике: %d", &s.fiz);

        in.getline(line, 256);
        sscanf(line, "Оценка по математике: %d", &s.mat);

        in.getline(line, 256);
        sscanf(line, "Оценка по информатике: %d", &s.inf);

        in.getline(line, 256);

        arr[count++] = s;
    }
    in.close();

        for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j].group > arr[j + 1].group) {
                Student tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    
    ofstream out("student_info.txt");

    for (int i = 0; i < count; i++) {
        double avg = score(arr[i].fiz, arr[i].mat, arr[i].inf);

        out << "Информация о студенте " << i + 1 << ":\n";
        out << "Фамилия: " << arr[i].sur << "\n";
        out << "Номер группы: " << arr[i].group << "\n";
        out << "Оценка по физике: " << arr[i].fiz << "\n";
        out << "Оценка по математике: " << arr[i].mat << "\n";
        out << "Оценка по информатике: " << arr[i].inf << "\n";
        out << "Средний балл: " << avg << "\n\n";
    }

    out.close();

    cout << "\nСтуденты успешно отсортированы по номеру группы!\n\n";

    viewFile();
}

void sortByAverageAndRewrite() {
    ifstream in("student_info.txt");
    if (!in.is_open()) {
        cout << "Файл не найден!" << endl;
        return;
    }

    Student arr[500];
    int count = 0;
    char line[256];

    while (in.getline(line, 256)) {

        if (strncmp(line, "Информация", 10) != 0)
            continue;

        Student s;

        in.getline(line, 256);
        sscanf(line, "Фамилия: %19s", s.sur);

        in.getline(line, 256);
        sscanf(line, "Номер группы: %d", &s.group);

        in.getline(line, 256);
        sscanf(line, "Оценка по физике: %d", &s.fiz);

        in.getline(line, 256);
        sscanf(line, "Оценка по математике: %d", &s.mat);

        in.getline(line, 256);
        sscanf(line, "Оценка по информатике: %d", &s.inf);

        in.getline(line, 256); 

        arr[count++] = s;
    }
    in.close();

    if (count == 0) {
        cout << "В файле нет студентов!" << endl;
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            double avg1 = (arr[j].fiz + arr[j].mat + arr[j].inf) / 3.0;
            double avg2 = (arr[j + 1].fiz + arr[j + 1].mat + arr[j + 1].inf) / 3.0;

            if (avg1 < avg2) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    ofstream out("student_info.txt");
    if (!out.is_open()) {
        cout << "Ошибка записи файла!" << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        double average = (arr[i].fiz + arr[i].mat + arr[i].inf) / 3.0;

        out << "Информация о студенте " << i + 1 << ":" << endl;
        out << "Фамилия: " << arr[i].sur << endl;
        out << "Номер группы: " << arr[i].group << endl;
        out << "Оценка по физике: " << arr[i].fiz << endl;
        out << "Оценка по математике: " << arr[i].mat << endl;
        out << "Оценка по информатике: " << arr[i].inf << endl;
        out << "Средний балл: " << average << endl << endl;
    }

    out.close();
    cout << "Файл успешно отсортирован и перезаписан!" << endl;
}


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    int x;
    int n = 0;
    Student* students = nullptr;

    do {
        cout << "Программа обработки файла записей" << endl;
        cout << "Меню: " << endl;
        cout << "Введите 1 для создания файла:" << endl;
        cout << "Введите 2 для просмотра файла:" << endl;
        cout << "Введите 3 для добавления учеников:" << endl;
        cout << "Введите 4 для решения индивидуального задания:" << endl;
        cout << "Введите 5 для редактирования" << endl;
        cout << "Введите 0 для выхода из программы:" << endl;
        cin >> x;

        if (x == 0) {
            cout << "Выход из программы." << endl;
            break;
        }
        else if (x == 1) {
            cout << "Введите количество учеников: ";
            cin >> n;
            students = new Student[n];

            for (int i = 0; i < n; i++) {
                cout << "\nСтудент " << i + 1 << endl;
                cout << "Фамилия: ";
                cin >> students[i].sur;
                cout << "Номер группы: ";
                cin >> students[i].group;
                cout << "Оценка по физике: ";
                cin >> students[i].fiz;
                cout << "Оценка по математике: ";
                cin >> students[i].mat;
                cout << "Оценка по информатике: ";
                cin >> students[i].inf;

                double average = score(students[i].fiz, students[i].mat, students[i].inf);
                cout << "Средний балл: " << average << endl;
            }


            if (writeToFile(students, n)) {
                cout << "\nДанные успешно записаны в файл student_info.txt!" << endl;
            }
            else {
                cout << "Ошибка открытия файла!" << endl;
            }

        }
        else if (x == 2) {
            viewFile();
        }
        else if (x == 3) {
            addStudentsToFile();
        }
        else if (x == 4) {
            cout << "Решение индивидуального задания..." << endl;
            individual(students, n);

        }
        else if (x == 5) {
            int g = 0;
            cout << "Выберите 1 - Удаление; 2 - Сортировка: ";
            cin >> g;

            if (g == 1) {
                removeStudent();
            }
            else if (g == 2) {
                int h=0;
                cout << "1-По номеру группы, 2- По фамилии " << endl;
                cin >> h;
                if (h == 1) {
                    cout << "Сортировка по номеру группы " << endl;
                    sortByGroup();
                }
                else {
                    cout << "Сортировка по фамилии " << endl;
                    sortByAverageAndRewrite();
                }
            }
            else {
                cout << "Неверный ввод!" << endl;
            }
        }

    } while (true);

    delete[] students;
    return 0;
}