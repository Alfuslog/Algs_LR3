#include <stdio.h>
#include <iostream>
using namespace std;

#define IOPUT(type, var, prompt)\  // просто лутшый макрос йоооу
    cout << prompt;\
    cin >> var


void NewPointer(int *p) {

}

int main(){
    setlocale(LC_ALL, "RUS");
    int size, choise;

    IOPUT(int, size, "\nВведите размер массива: ");
    int* arr = new int[size];

    IOPUT(int, choise, "\nВведите номер задания: ");
    if (cin.fail()) {
        cout << "\nВведено некорректное значение!\n";
        return 0;
    }
    switch (choise) {
    case(1): {
        cout << "hi";

    }
    case 2:{
        return 0;
    }
    default: { cout << "\nНеверный номер задания!\n"; }
    }

    






}