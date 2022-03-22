#include <iostream>
#include <algorithm>
#include <stdio.h> 
#include <time.h> 
using namespace std;
int main() {
	time_t start, end;
	setlocale(LC_ALL,"Russian");
	int n,i;
	int srav = 0;
	int perem = 0;
	int total_cmps = 0;
	time(&start);
	do
	{
		cout << "Enter dimmension of your array: ";   
		cin >> n;
	}
	while (n < 1);
	int* arr = new int[n];    
	int min = 10, max = 100;
	for (i = 0; i < n; i++) {
		arr[i] = min + rand() % (max + 1);
		cout << arr[i] << " ";
		++srav;
	}
	cout << " " << endl;
	const int length = n;
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		++srav;
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			++srav;
			if (arr[currentIndex] < arr[smallestIndex])
				smallestIndex = currentIndex;
				++srav;
		}
		swap(arr[startIndex], arr[smallestIndex]);
		++perem;
	}
	for (int index = 0; index < length; ++index)
		cout << arr[index] << ' ';
		++srav;

	cout << " " << endl;
	time(&end);
	double seconds = difftime(end, start);
	printf("The time: %f seconds\n", seconds);
	cout << " Ñô = " << srav << endl;
	cout << " Mô = " << perem << endl;
	cout << " Mô + Ñô = " << perem + srav << endl;
	system("pause");
	return 0;
	delete[] arr;
}

