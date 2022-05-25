#include<iostream>

using namespace std;

int countIterations = 0;
int countSwap = 0;
const int nmax = 100000;

void Merge(int arr[], int begin, int end)
{
	int i = begin;
	int	t = 0;
	int	midlle = begin + (end - begin) / 2;
	int	j = midlle + 1;
	int	d[nmax];

	while (i <= midlle && j <= end) {
		countIterations++;
		if (arr[i] <= arr[j]) {
			countIterations++;
			d[t] = arr[i];
			countSwap++;
			i++;
		}
		else {
			d[t] = arr[j];
			countSwap++;
			j++;
		}
		t++;
	}

	while (i <= midlle) {
		countIterations++;
		d[t] = arr[i];
		countSwap++;
		i++;
		t++;
	}

	while (j <= end) {
		countIterations++;
		d[t] = arr[j];
		countSwap++;
		j++;
		t++;
	}

	for (i = 0; i < t; i++) {
		countIterations++;
		arr[begin + i] = d[i];
		countSwap++;
	}
}

void Sort(int* arr, int left, int right)
{
	if (left < right) {
		countIterations++;
		if (right - left == 1) {
			countIterations++;
			if (arr[right] < arr[left]) {
				countIterations++;
				swap(arr[left], arr[right]);
			}
		}
		else {
			Sort(arr, left, left + (right - left) / 2);
			Sort(arr, left + (right - left) / 2 + 1, right);
			Merge(arr, left, right);
		}
	}
}




int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "¬ведите размер ";
	cin >> n;
	int arr[nmax];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
	cout << endl;
	unsigned int start_time = clock();
	Sort(arr, 0, n - 1);
	unsigned int end_time = clock();
	unsigned int search_time = start_time - end_time / CLOCKS_PER_SEC;
	cout << endl;
	cout << "Time: " << search_time << endl;
	cout << "Swaps + Iterations: " << countSwap + countIterations;
	system("pause");
	return 0;
}
