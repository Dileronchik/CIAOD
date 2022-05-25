#include <iostream>
#include <ctime>

using namespace std;

int Sort(int* array, int size) {
    int count = 0;
    int i = 0;
    int j = size - 1;
    int midlle = array[size / 2];

    do {
        while (array[i] < midlle) {
            count += 1;
            i++;
        }
        while (array[j] > midlle) {
            count += 1;
            j--;
        }
        if (i <= j) {
            count += 2;
            swap(array[i], array[j]);
            i++;
            j--;
        }
    } while (i <= j);


    if (j > 0) {
        count += 1;
        Sort(array, j + 1);
    }
    if (i < size) {
        count += 1;
        Sort(&array[i], size - i);
    }
    return count;
}

void timer(int* array, int size) {
    unsigned int start_time = clock();
    int counter = Sort(array, size);
    unsigned int end_time = clock();
    unsigned int search_time = start_time - end_time / CLOCKS_PER_SEC;
    cout << "Time: " << search_time << endl;
    cout << "Counter: " << counter << endl;
}


int main() {
    int size;
    cin >> size;
    int* array = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    timer(array, size);
    if (size < 1000000) {
        for (int i = 0; i < size; i++) {
            //cout << array[i] << " ";
        }
    }
    system("pause");
    return(0);
}
