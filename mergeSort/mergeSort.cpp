#include <iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end) {
	int leftSize = mid - start + 1;
	int rightSize = end - mid;
	int* leftArray = new int[leftSize];
	int* rightArray = new int[rightSize];
	for (int i = 0; i < leftSize; i++) {
		leftArray[i] = arr[start + i];

	}
	for (int j = 0; j < rightSize; j++) {
		rightArray[j] = arr[mid + 1 + j];
	}
	int i = 0, k = start, j = 0;
	while (i < leftSize && j < rightSize) {
		if (leftArray[i] < rightArray[j]) {
			arr[k] = leftArray[i];
			i++;
		}
		else {
			arr[k] = rightArray[j];
			j++;
		}
		k++;
		
	}
	while (i < leftSize) {
		arr[k] = leftArray[i];
		k++;
		i++;
	}
	while (j < rightSize) {
		arr[k] = rightArray[j];
		k++;
		j++;
	}
	delete[]leftArray;
	delete[]rightArray;
}
void mergeSort(int arr[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}
void display(int arr[], int n) {
	cout << "Sorted Array is-> ";
	for (int i = 0; i < n; i++) cout << arr[i]<<" ";
}
int main() {
	cout << "Enter size of array ";
	int n; cin >> n;
	int* arr = new int[n];
	cout << "Enter array's items ";
	for (int i = 0; i < n; i++)cin >> arr[i];
	int start = 0, end = n - 1;
	mergeSort(arr, start, end);
	display(arr, n);


	return 0;
}