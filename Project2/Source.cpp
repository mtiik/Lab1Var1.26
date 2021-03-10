#include <iostream>

using namespace std;

void inputArr(double* arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}
}

double calculateArithmMean(double* arr, double z, int size) {
	double buffer = 0;
	int counter = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] <= z) {
			buffer += arr[i];
			++counter;
		}
	}
	return buffer / counter;
}

bool testingForPositivity(double mean) {
	if (mean > 0) {
		return true;
	}
	else return false;
}

int searchMinusElm(double* arr, int size){
	int counter = 0;
	for(int i = 0; i < size; ++i) {
		if(arr[i] < 0) {
			++counter;
		}
	}
	return counter;
}

void createNewArr(double* arr, double* newArr, int size, int newSize) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] < 0) {
			newArr[newSize - 1] = arr[i];
			--newSize;
		}
	}
}

void outputArr(double* arr, int size) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}

int main() {
	double z, mean = 0;
	int size, newSize = 0;
	bool flag;
	char key[1];
	double* arr = new double;
	double* newArr = new double;
	do {
		cout << "enter arr size: ";
		cin >> size;
		cout << "enter 'z': ";
		cin >> z;

		*arr = size;
		inputArr(arr, size);
		mean = calculateArithmMean(arr, z, size);
		flag = testingForPositivity(mean);
		if (flag) {
			newSize = searchMinusElm(arr, size);
			*newArr = newSize;
			createNewArr(arr, newArr, size, newSize);
			outputArr(newArr, newSize);
			outputArr(arr, size);
		}
		else {
			outputArr(arr, size);
		}
		cout << "do u want to continue? [y/n] ";
		cin >> key[0];
	} while (key[0] != 'n');


	return 0;
}
