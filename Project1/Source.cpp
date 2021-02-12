#include <iostream>

using namespace std;

void inputArr(double* arr, int counter) {
	for (int i = 0; i < counter; ++i) {
		cin >> arr[i];
	}
}

void outputArr(double minusArr[], int arrCounter) {
	for (int i = 0; i < arrCounter; ++i) {
		cout << minusArr[i] << " ";
	}
}

double arrAverageCount(double arr[], int counter, double z) {
	double average = 0;
	int averageCounter = 0;
	for (int i = 0; i < counter; ++i) {
		if (arr[i] <= z) {
			average += arr[i];
			++averageCounter;
		}
	}
	return average / averageCounter;
}

int minusSearch(double arr[], int counter, int arrCounter) {
	for (int i = 0; i < counter; ++i) {
		if (arr[i] < 0) {
			++arrCounter;
		}
	}
	return arrCounter;
}

int createArr(double arr[], int counter, int arrCounter, double* minusArr) {
	arrCounter = minusSearch(arr, counter, arrCounter);
	for (int i = 0; i < counter; ++i) {
		if (arr[i] < 0) {
			minusArr[arrCounter - 1] = arr[i];
			--arrCounter;
		}
	}
	return arrCounter;
}

int main() {
	int arrSize, arrCounter = 0;
	double z, average, arr[1000], minusArr[1000];
	cin >> arrSize >> z;
	inputArr(arr, arrSize);
	outputArr(arr, arrSize);
	average = arrAverageCount(arr, arrSize, z);
	if (average > 0) {
		arrCounter = createArr(arr, arrSize, arrCounter, minusArr);
		outputArr(minusArr, arrCounter);
	}
	return 0;
}