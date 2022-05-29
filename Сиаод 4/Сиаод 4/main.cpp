#include <iostream>

using namespace std;

void Sort(int* arr, int size) {
    int i = 0;
    int j = size - 1;
    int midlle = arr[size / 2];

    do {
        while (arr[i] < midlle) {
            i++;
        }
        while (arr[j] > midlle) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        Sort(arr, j + 1);
    }
    if (i < size) {
        Sort(&arr[i], size - i);
    }
}

void reverseSort(int* arr, int size) {
    Sort(arr, size);
    int middle = size / 2;
    for (int i = 0; i < middle; i++) {
        swap(arr[i], arr[size - i - 1]);
    }
}

void search(int* arr, int size) {
    int countIterations = 0;
    int flag = 0;
    int symbol;
    cin >> symbol;
    for (int i = 0; i < size; i++) {
        countIterations++;
        if (arr[i] == symbol) {
            countIterations++;
            flag = 1;
            cout << "Индекс элемента: ";
            cout << i << endl;
            cout << "Кол-во сравнений: " << countIterations;
            break;
        }
    }
    if (flag == 0) {
        cout << "Число не найдено, введите другое число ";
        search(arr, size);
    }
}

int main() {
    setlocale(0, "Rus");
    int size;
    cout << "Введите размер массива:";
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        cout << arr[i]<< " ";
    }
    cout <<"Введите цифру для вида поиска числа в массиве:\n\
1 - поиск в массиве отсортированном массиве по возрастанию\n\
2 - поиск в массиве отсортированном массиве по убыванию\n\
3 - поиск в неотсортированном массиве" << endl;
    string choice;
    cin >> choice;

    if (choice == "1") {
        Sort(arr, size);
    }
    if (choice == "2") {
        reverseSort(arr, size);
    }
    cout << "Введите число для поиска не больше 100: ";
    search(arr, size);
    system("pause");
    return 0;
}