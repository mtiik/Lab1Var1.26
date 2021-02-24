#include <iostream>
#include <vector>

using namespace std;

void inputArr(vector <double>* arr) {
	for (int i = 0; i < arr->size(); ++i) {
		cin >> arr->at(i);
	}
}

double calculateArithmMean(vector <double>* arr, double z) {
	double buffer = 0;
	int counter = 0;
	for (int i = 0; i < arr->size(); ++i) {
		if (arr->at(i) <= z) {
			buffer += arr->at(i);
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

void createNewArr(vector <double>* arr, vector <double>* newArr) {
	for (int i = 0; i < arr->size(); ++i) {
		if (arr->at(i) < 0) {
			newArr->push_back(arr->at(i));
		}
	}
	reverse(newArr->begin(), newArr->end());
}

void outputArr(vector <double>* arr) {
	if (arr->size() == 0) {
		cout << "no negative elements";
	}
	else {
		for (int i = 0; i < arr->size(); ++i) {
			cout << arr->at(i) << " ";
		}
	}
	cout << '\n';
}

int main() {
	double z, mean = 0;
	int size;
	bool flag;
	char key[1];
	vector <double> arr;
	vector <double> newArr;
	do {
		cout << "enter arr size: ";
		cin >> size;
		cout << "enter 'z': ";
		cin >> z;

		arr.resize(size);
		inputArr(&arr);
		mean = calculateArithmMean(&arr, z);
		flag = testingForPositivity(mean);
		if (flag) {
			createNewArr(&arr, &newArr);
			outputArr(&newArr);
		}
		else {
			outputArr(&arr);
		}
		cout << "do u want to continue? [y/n] ";
		cin >> key[0];
	} while (key[0] != 'n');


	return 0;
}