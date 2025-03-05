#include <stdio.h>
#include <iostream>
using namespace std;

#define IOPUT(type, var, prompt)\
    cout << prompt;\
    if (!(cin >> var) ){\
        cout << "\nВведено некорректное значение!\n";\
        exit(-1);\
    }

void InputIntElemsArr(int *arr, int size){
    printf("\nЗаполните массив через Enter:\n\n");
    for (int i = 0; i < size; i++) {
        cout << i + 1; IOPUT(int, arr[i], ")");
    }
}
void InputFloatElemsArr(int* arr, int size) {
    printf("\nЗаполните массив через Enter:\n\n");
    for (int i = 0; i < size; i++) {
        cout << i + 1; IOPUT(double, arr[i], ")");
    }
}

void NewPointer(int *arr, int size, int **ptrArr) {
    for (int i = 0; i < size; i++) {
        ptrArr[i] = new int(arr[i]);
    }
}

void WritePtr(int** ptrArr, int iPtr, int chislo) {
    *(ptrArr[iPtr - 1]) = chislo;
}

void ReadPtr(int** ptrArr, int iPtr) {
    cout << *(ptrArr[iPtr - 1]);
}


void freePtr(int *arr, int **ptrArr) {
    delete[] arr;
    delete[] ptrArr;
}

int main(){
    cin.clear();
    setlocale(LC_ALL, "RUS");

    int size, choise;

    IOPUT(int, size, "Введите размер массива: ");
    int* arr = new int[size];

    IOPUT(int, choise, "\nВведите номер задания: ");
    switch (choise) {
    case(1): {
        int iMax = 0, sum = 0, Max = 0;

        InputIntElemsArr(arr, size);

        int** ptrArr = new int* [size];
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

        freePtr(arr, ptrArr);
        return 0;
    }
    case 2:{
        int cntNeg = 0;

        int* arr = new int[size];

        InputFloatElemsArr(arr, size);

        int** ptrArr = new int* [size];
        NewPointer(arr, size, ptrArr);

        for (int i = 0; i < size; i++) {
            if (*ptrArr[i] < 0) {
                cntNeg++;
            }
        }

        printf("\n\nКоличество отрицательных элементов = %f\n");

        freePtr(arr, ptrArr);
        return 0;
    }
    default: { cout << "\nНеверный номер задания!\n"; }
    }

    






}