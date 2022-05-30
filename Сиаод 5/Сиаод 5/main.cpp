#include <iostream>

using namespace std;

void quickSort(int* arr, int size) {
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
		quickSort(arr, j + 1);
	}
	if (i < size) {
		quickSort(&arr[i], size - i);
	}
}

void reverseSort(int* arr, int size) {
	quickSort(arr, size);
	int middle = size / 2;
	for (int i = 0; i < middle; i++) {
		swap(arr[i], arr[size - i - 1]);
	}
}

void binarySearch(int* arr, int size) {
	int key;
	cout << "Введите ключ : ";
	cin >> key;

	int counter = 0;
	int left = 0;
	int right = size - 1;
	int mid;
	bool flag = false;
	while (left < right) {
		counter++;
		mid = (left + right) / 2;

		counter++;
		if (arr[mid] == key) {
			flag = true;
			break;
		}
		counter++;
		if (key > arr[mid]) {
			left = mid + 1;
		}
		counter++;
		if (key < arr[mid]) {
			right = mid;
		}
	}
	if (flag == true) {
		cout << "Индекс ключа в массиве: " << mid << endl;
		cout << "Кол-во итераций: " << counter;
	}
	else {
		cout << "Такого ключа нет ";
	}
}

void binaryReverse(int* arr, int size) {
	int key;
	cout << "Введите ключ : ";
	cin >> key;

	int counter = 0;
	int left = 0;
	int right = size - 1;
	int mid;
	bool flag = false;
	while (left < right) {
		counter++;
		mid = (left + right) / 2;

		counter++;
		if (arr[mid] == key) {
			flag = true;
			break;
		}
		counter++;
		if (key > arr[mid]) {
			right = mid;
		}
		counter++;
		if (key < arr[mid]) {
			left = mid + 1;
		}
	}
	if (flag == true) {
		cout << "Индекс ключа в массиве:  " << mid << endl;
		cout << "Кол-во итераций: " << counter;
	}
	else {
		cout << "Такого ключа нет ";
	}
}

int main() {
	setlocale(0, "Rus");
	int choice;
	int size;
	cout << "Введите размер массива: ";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
		cout << arr[i]<<" ";
	}

	cout << endl;
jump:
	cout << "Введите вариант поиска: " << endl;
	cout << "1 - Поиск в возрастающем массиве;" << endl;
	cout << "2 - Поиск в убывающем массиве;" << endl;
	cin >> choice;
	switch (choice) {
	case 1: {
		quickSort(arr, size);
		binarySearch(arr, size);
		break;
	}
	case 2: {
		reverseSort(arr, size);
		binaryReverse(arr, size);
		break;
	}
	default:
		goto jump;
	}
	system("pause");
	return 0;
}