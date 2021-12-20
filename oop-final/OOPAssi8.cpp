//============================================================================
// Name        : OOPAssi8.cpp
// Author      : Mugdha Malpe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*Name: Mugdha Malpe
 Roll. No. 21153
 Batch: G1   Div: SE01*/

#include<iostream>
#include <cstdlib>

using namespace std;

int n;
template<class T>

void selection_sort() {
	T temp;

	// inputing elements
	cout << "\nEnter total no. of elements: ";
	cin >> n;
	T arr[n];

	cout << "\nEnter elements: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Enter array[" << i << "]= ";
		cin >> arr[i];
	}

	//code for selection sort
	//Best, average and worst case time complexity: n^2 which is independent of distribution of data.
	for (int i = 0; i < n - 1; i++) {
		//by default we'll compare with 1st element, so min=0
		//int min = i;

		//to compare elements
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}

		//to perform swapping
//		temp = arr[i];
//		arr[i] = arr[min];
//		arr[min] = temp;
	}

	cout << "\nThe sorted array is: ";

	//display of sorted array
	for (int i = 0; i < n; i++) {
		cout << " " << arr[i];
	}

}

int main() {
	int ch;

	do {
		cout << "\n\n\t*****PERFORM SELECTION SORT*****";
		cout << "\n\t---------------MENU-------------";
		cout << "\n1. Sort integer Values";
		cout << "\n2. Sort float Values";
		cout << "\n3. Sort char Values";
		cout << "\n4. EXIT";
		cout << "\n\nEnter your choice : ";
		cin >> ch;

		switch (ch) {

		case 1:

			selection_sort<int>();
			break;

		case 2:

			selection_sort<float>();
			break;

		case 3:

			selection_sort<char>();
			break;

		case 4:
			cout << "Exiting...thank you..." << endl;
			exit(0);

		}

	} while (ch != 3);

	return 0;
}

