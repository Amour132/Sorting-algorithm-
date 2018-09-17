#include "Sort.h"

int main()
{
	int arr[] = { 1024, 87, 95, 45, 36, 96, 48, 58, 611};
	Print(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	//QuickSort(arr, 0, 10);
	HeapSort(arr, sizeof(arr)/sizeof(arr[0]));
	Print(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}