#include <iostream>
using namespace std;

#define IOPUT(type, var, prompt) \
    cout << prompt; \
    if (!(cin >> var)) { \
        cout << "\nВведено некорректное значение!\n"; \
        exit(-1); \
    }

// Освобождение памяти для одиночного указателя (например, p1)
template<typename T>
void freePtr(T*& ptr) {
    if (ptr) {
        delete ptr;
        ptr = nullptr; // Предотвращаем висячий указатель
    }
}

// Освобождение памяти для массива (например, arr)
template<typename T>
void freePtr(T*& arr, bool isArray) {
    if (arr) {
        delete[] arr;
        arr = nullptr;
    }
}

// Освобождение памяти для массива указателей (например, ptrArr)
template<typename T>
void freePtr(T**& ptrArr, int size) {
    if (ptrArr) {
        for (int i = 0; i < size; i++) {
            delete ptrArr[i]; // Удаляем каждый элемент массива указателей
        }
        delete[] ptrArr; // Удаляем сам массив указателей
        ptrArr = nullptr;
    }
}

// Ввод массива целых чисел
void InputIntElemsArr(int* arr, int size) {
    printf("\nЗаполните массив через Enter:\n\n");
    for (int i = 0; i < size; i++) {
        cout << i + 1; IOPUT(int, arr[i], ")");
    }
}

// Ввод массива вещественных чисел
void InputFloatElemsArr(double* arr, int size) {
    printf("\nЗаполните массив через Enter:\n\n");
    for (int i = 0; i < size; i++) {
        cout << i + 1; IOPUT(double, arr[i], ")");
    }
}

// Создание массива указателей на целые числа
void NewPointer(int* arr, int size, int**& ptrArr) {
    ptrArr = new int* [size];
    for (int i = 0; i < size; i++) {
        ptrArr[i] = new int(arr[i]);
    }
}

// Создание массива указателей на числа с плавающей запятой
void NewPointer(double* arr, int size, double**& ptrArr) {
    ptrArr = new double* [size];
    for (int i = 0; i < size; i++) {
        ptrArr[i] = new double(arr[i]);
    }
}

// Копирование значения, на которое ссылается p2, в память, на которую ссылается p1
void SetPointer(double*& p1, unsigned* p2) {
    if (p2 == nullptr) {
        std::cerr << "Ошибка: указатель p2 пустой!" << std::endl;
        return;
    }

    if (p1 == nullptr) {
        p1 = new double;
    }

    *p1 = static_cast<double>(*p2); // Копируем значение из p2 в p1
}

int main() {
    setlocale(LC_ALL, "RUS");

    int size, choice;
    double* p1 = nullptr;
    unsigned* p2 = new unsigned(42); // Выделяем память для p2

    IOPUT(int, size, "Введите размер массива: ");
    if (size <= 0) {
        cout << "\nРазмер массива должен быть больше нуля!\n";
        freePtr(p2);
        return 0;
    }
    else if (size > 32) {
        cout << "Память закончилась ";
        freePtr(p2);
        return 0;
    }

    IOPUT(int, choice, "\nВведите номер задания: ");

    switch (choice) {
    case 1: {
        int iMax = 0, sum = 0, Max = 0;
        int* arr = new int[size]; // Выделяем массив
        InputIntElemsArr(arr, size);

        int** ptrArr;
        NewPointer(arr, size, ptrArr);

        for (int i = 0; i < size; i++) {
            if (Max < *ptrArr[i]) {
                Max = *ptrArr[i];
                iMax = i;
            }
        }

        for (int i = 0; i < iMax; i++) {
            if (*ptrArr[i] > 0) {
                sum += *ptrArr[i];
            }
        }

        printf("\n\nМаксимальный элемент массива: %d\n", Max);
        printf("\n\nСумма положительных элементов массива до %d равна: %d\n\n", Max, sum);

        freePtr(arr, true);
        freePtr(ptrArr, size);
        freePtr(p1);
        freePtr(p2);
        return 0;
    }

    case 2: {
        int cntNeg = 0;
        double* arr = new double[size];
        InputFloatElemsArr(arr, size);

        double** ptrArr;
        NewPointer(arr, size, ptrArr);

        for (int i = 0; i < size; i++) {
            if (*ptrArr[i] < 0) {
                cntNeg++;
            }
        }

        printf("\n\nКоличество отрицательных элементов = %d\n", cntNeg);

        freePtr(arr, true);
        freePtr(ptrArr, size);
        freePtr(p1);
        freePtr(p2);
        return 0;
    }

    default:
        cout << "\nНеверный номер задания!\n";
        freePtr(p2);
        return 0;
    }
}
