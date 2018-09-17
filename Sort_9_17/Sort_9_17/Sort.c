#include "Sort.h"

//插入排序
//优点：稳点，速度快
//缺点：效率会根据比较次数而改变，尤其是数据庞大并且每次都需要移动的时候效率较低
//性能：O（n^2）
void InsertSort(int *arr, int length)
{
	int i = 0;
	for (i = 1; i < length; i++)
	{
		int j = i - 1;
		int temp = arr[i];
		while (temp < arr[j] && j > 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

//希尔排序
//优点：效率相比直接插入变高，因为提前的处理使数组相对有序
//缺点：不稳定
//性能：O(n^1.3)
void ShellSort(int *arr, int length)
{
	int gap = length;
	int i = 0;
	while (gap != 1)
	{
		gap = gap / 3 + 1;
		for (i = 1; i < length; i += gap)
		{
			int j = i - gap;
			int temp = arr[i];
			while (temp < arr[j] && j > 0)
			{
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = temp;
		}
	}
}

//选择排序
//优点：数据移动次数已知
//缺点：速度慢，不稳定
//性能：O(n^2)
void SelectSort(int *arr, int length)
{
	int i = 0;
	int j = 0;
	int min = 0;
	for (i = 0; i < length; i++)
	{
		min = i;
		for (j = i+1; j < length; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;  //找出最小的放在前面
			}
		}
		if (min != i)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

//冒泡排序
//优点：稳定性好
//缺点：效率低
//性能：O(n^2)
void BubbleSort(int *arr, int length)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < length-1; i++)
	{
		for (j = 0; j < length-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];   //两两交换
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//快速排序
//优点：效率高 速度快
//缺点：不稳定
//性能：O(n*logn)
void QuickSort(int *arr, int start,int end)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	if (start<end)
	{
		i = start + 1;
		j = end;
		while (i<j)
		{
			if (arr[i]>arr[start])  
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				j--;
			}
			else
			{
				i++;
			}
		}
		if (arr[i] >= arr[start])
		{
			i--;
		}
		temp = arr[i];
		arr[i] = arr[start];
		arr[start] = temp;
		QuickSort(arr, start, i);
		QuickSort(arr, j, end);
	}
}

//堆排序
//优点：高效
//缺点：不稳定
//性能：O(n*logn)

int Swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void HeapAdjust(int *arr, int length, int root)
{
	int temp = arr[root];	//保存当前节点
	int i = 2 * root + 1;		//该节点的左孩子在数组中的位置序号
	while (i <= length)
	{
		if (i + 1 <= length && arr[i + 1] > arr[i])
		{
			i++;
		}
		//如果符合堆的定义，则不用调整位置
		if (arr[i] <= temp)
		{
			break;
		}
		//最大的子节点向上移动，替换掉其父节点
		arr[root] = arr[i];
		root = i;
		i = 2 * root + 1;
	}
	arr[root] = temp;
}

void HeapSort(int *arr, int length) //堆排序
{
	int i = 0;
	int j = 0;
	for (i = length / 2-1; i >= 0; i--)//建大堆
	{
		HeapAdjust(arr, length, i);
	}
	for (j = length-1; j >0 ; j--)

	{
		Swap(arr, 0, j); //最大的放到最后面
		HeapAdjust(arr, j-1, 0); //再次建新的大堆
	}
}

void Print(int *arr, int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}