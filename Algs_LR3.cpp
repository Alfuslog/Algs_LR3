#include <stdio.h>
#include <iostream>
using namespace std;

#define IOPUT(type, var, prompt)\
    cout << prompt;\
    if (!(cin >> var) ){\
        cout << "\nВведено некорректное значение!\n";\
        exit(-1);\
    }

void InputElemsArr(int *arr, int size){
    printf("\nЗаполните массив через Enter:\n\n");
    for (int i = 0; i < size; i++) {
        cout << i + 1; IOPUT(int, arr[i], ")");
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
    InputElemsArr(arr, size);

    int** ptrArr = new int*[size];
    NewPointer(arr, size, ptrArr);

    IOPUT(int, choise, "\nВведите номер задания: ");
    switch (choise) {
    case(1): {
        
        for (int i = 0; i < size; i++) {
            cout << *ptrArr[i] << ' ';
        }

        

        goto End;
    }
    case 2:{

        goto End;
    }
    default: { cout << "\nНеверный номер задания!\n"; }
       End:
           freePtr(arr, ptrArr);
           return 0;
    }

    






}