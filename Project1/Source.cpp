#include <iostream>

using namespace std;

void inputArr(double arr[], int size) {
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}
}

double calculateArithmMean(double arr[], int size, double z) {
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

int createNewArr(double arr[], int size, double newArr[]) {
	int counter = 0, buffer = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] < 0) {
			++counter;
		}
	}
	buffer = counter;
	for (int i = 0; i < size; ++i) {
		if (arr[i] < 0) {
			newArr[counter - 1] = arr[i];
			--counter;
		}
	}
	return buffer;
}

void outputArr(double arr[], int size) {
	if (size == 0) {
		cout << "no negative elements";
	}
	else {
		for (int i = 0; i < size; ++i) {
			cout << arr[i] << " ";
		}
	}
	cout << '\n';
}

int main() {
	double z, mean = 0;
	int size;
	bool flag;
	char key[1];
	double arr[1000];
	do {
		cout << "enter arr size: ";
		cin >> size;
		cout << "enter 'z': ";
		cin >> z;

		inputArr(arr, size);
		mean = calculateArithmMean(arr, size, z);
		flag = testingForPositivity(mean);
		if (flag) {
			double newArr[1000];
			int newArrSize = 0;
			newArrSize = createNewArr(arr, size, newArr);
			outputArr(newArr, newArrSize);
		}
		else {
			outputArr(arr, size);
		}
		cout << "do u want to continue? [y/n] ";
		cin >> key[0];
	} while (key[0] != 'n');


	return 0;
}