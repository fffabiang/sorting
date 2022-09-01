#include <iostream>

using namespace std;

void printArray(int* arr, int size) {


	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl << endl;

}


void quickSortRecursion(int numArray[], int startPos, int endPos) {


	int greaterThanPivot = -1;

	int pivotPos = endPos;

	//Base case ends recursion
	if (startPos >= endPos) {
		return;
	}

	//Sorting the received array
	for (int i = startPos; i < endPos; i++) {


		if (numArray[i] > numArray[pivotPos] && greaterThanPivot == -1) {
			greaterThanPivot = i;
		}

		if (numArray[i] < numArray[pivotPos] && greaterThanPivot != -1) {

			int tmp = numArray[greaterThanPivot];
			numArray[greaterThanPivot] = numArray[i];
			numArray[i] = tmp;

			//cout << "Swapping " << tmp << " with " << numArray[greaterThanPivot] << endl;

			greaterThanPivot++;

		}
	}

	// Swapping the pivot with the auxiliar greater value (if there was any)
	if (greaterThanPivot != -1) {

		int tmp = numArray[greaterThanPivot];
		numArray[greaterThanPivot] = numArray[pivotPos];
		numArray[pivotPos] = tmp;

		pivotPos = greaterThanPivot;

	}


	// cout << "Quick sort finished from " << startPos << " to " << endPos << " pivot at " << pivotPos << endl;

	//Split arrays from pivot and sort them with recursion
	quickSortRecursion(numArray, startPos, pivotPos - 1);
	quickSortRecursion(numArray, pivotPos + 1 , endPos);


}

void quickSort(int numArray[], int size) {

	cout << "Starting quicksort..." << endl;

	quickSortRecursion(numArray, 0, size - 1);

	cout << "Finished quicksort." << endl;

}

void merge(int arr[], int p, int q, int r) {

	// Create L ← A[p..q] and M ← A[q+1..r]
	int n1 = q - p + 1;
	int n2 = r - q;

	int* L = new int[n1];
	int* M = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		M[j] = arr[q + 1 + j];

	// Maintain current index of sub-arrays and main array
	int i, j, k;
	i = 0;
	j = 0;
	k = p;

	// Until we reach either end of either L or M, pick larger among
	// elements L and M and place them in the correct position at A[p..r]
	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}

	// When we run out of elements in either L or M,
	// pick up the remaining elements and put in A[p..r]
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = M[j];
		j++;
		k++;
	}
}

void mergeSort(int numArray[], int start, int end) {

	//cout << "current start " << start << " end " << end << endl;

	//Base case
	if (start >= end) {
		return; 
	}
	else {

		//Divide
		int middle = (end + start) / 2;

		//Conquer
		mergeSort(numArray, start, middle);
		mergeSort(numArray, middle +1 , end);

		//cout << "about to merge from " << start << " to " << middle << " to " << end << endl;

		//Combine results
		merge(numArray, start, middle, end);

	}

}
 

void bubbleSort(int numArray[], int size) {

	cout << "Bubble sort not implemented yet." << endl;

}

int main() {

	char option;
	int numbers[10] = { 7, 18, 14, 1 , 16, 4, 11, 5, 3, 8 };


	cout << "Before sorting:";
	printArray(numbers, 10);
	cout << "Choose the sorting algorithm: " << endl;
	cout << " [1] Quick sort" << endl;
	cout << " [2] Merge sort" << endl;
	cout << " [3] Bubble sort" << endl;

	cin >> option;

	switch (option) {

	case '1':
		quickSort(numbers, 10);
		break;

	case '2':
		mergeSort(numbers, 0, 9);
		break;

	case '3':
		bubbleSort(numbers, 10);
		break;

	default:
		break;
	}


	cout << endl << "After sorting:";
	printArray(numbers, 10);

	return 0;
}