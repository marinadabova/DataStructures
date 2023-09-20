#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
	int* arr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap

	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return (2 * i + 1);
	}
	int right(int i) {
		return (2 * i + 2);
	}
	void insertKey(int k);
	void MaxHeapify(int i);
	int extractMax();

};
void MaxHeap::insertKey(int k) {
	if (heap_size == capacity) {
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	int i = heap_size - 1;
	arr[heap_size] = k;
	heap_size++;

	while (i != 0 && arr[parent(i)] < arr[i]){
		swap(&arr[i], &arr[parent(i)]);
		i = parent(i);
	}
}
void MaxHeap::MaxHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l < heap_size && arr[l] > arr[i])
		largest = l;
	if (r < heap_size && arr[r] > arr[largest])
		largest = r;
	if (largest != i){
		swap(&arr[i], &arr[largest]);
		MaxHeapify(largest);
	}
}

int MaxHeap::extractMax() {
	if (heap_size <= 0)
		return INT_MIN;
	if (heap_size == 1) {
		heap_size--;
		return arr[0];
	}
	int root =arr[0];
	arr[0] = arr[heap_size - 1];
	heap_size--;
	MaxHeapify(0);

	return root;
}
void heapify(int arr[], int n, int i) {
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i){
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n){
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--)	{
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}
