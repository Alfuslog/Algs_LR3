#include <stdio.h>
#include <iostream>
using namespace std;

#define IOPUT(type, var, prompt)\
    cout << prompt;\
    if (!(cin >> var) ){\
        cout << "\nВведено некорректное значение!\n";\
        exit(-1);\
    }
    

void InputElemsArr() {

}

void NewPointer(int *arr, int* ptr) {
    int i;
    IOPUT(int, i, "Выберете индекс элемента, указывающего на элемент массива: ");

    *ptr = *arr + i-1;
}

int main(){
    setlocale(LC_ALL, "RUS");
    int size, choise, elem;

    IOPUT(int, size, "Введите размер массива: ");
    int* arr = new int[size];

    IOPUT(int, choise, "\nВведите номер задания: ");

    switch (choise) {
    case(1): {
        printf("\nЗаполните массив через Enter:\n");
        for (int i=0; i < size; i++) {
            cin >> elem;
            if (cin.fail()) { cout << "\nВведено некорректное значение!\n"; return 0; }
            
            InputElemsArr();
        }
        
    }
    case 2:{
        return 0;
    }
    default: { cout << "\nНеверный номер задания!\n"; }
    }

    






}