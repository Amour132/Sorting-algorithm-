#include "Sort.h"

//��������
//�ŵ㣺�ȵ㣬�ٶȿ�
//ȱ�㣺Ч�ʻ���ݱȽϴ������ı䣬�����������Ӵ���ÿ�ζ���Ҫ�ƶ���ʱ��Ч�ʽϵ�
//���ܣ�O��n^2��
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

//ϣ������
//�ŵ㣺Ч�����ֱ�Ӳ����ߣ���Ϊ��ǰ�Ĵ���ʹ�����������
//ȱ�㣺���ȶ�
//���ܣ�O(n^1.3)
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

//ѡ������
//�ŵ㣺�����ƶ�������֪
//ȱ�㣺�ٶ��������ȶ�
//���ܣ�O(n^2)
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
				min = j;  //�ҳ���С�ķ���ǰ��
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

//ð������
//�ŵ㣺�ȶ��Ժ�
//ȱ�㣺Ч�ʵ�
//���ܣ�O(n^2)
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
				int temp = arr[j];   //��������
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//��������
//�ŵ㣺Ч�ʸ� �ٶȿ�
//ȱ�㣺���ȶ�
//���ܣ�O(n*logn)
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

//������
//�ŵ㣺��Ч
//ȱ�㣺���ȶ�
//���ܣ�O(n*logn)

int Swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void HeapAdjust(int *arr, int length, int root)
{
	int temp = arr[root];	//���浱ǰ�ڵ�
	int i = 2 * root + 1;		//�ýڵ�������������е�λ�����
	while (i <= length)
	{
		if (i + 1 <= length && arr[i + 1] > arr[i])
		{
			i++;
		}
		//������϶ѵĶ��壬���õ���λ��
		if (arr[i] <= temp)
		{
			break;
		}
		//�����ӽڵ������ƶ����滻���丸�ڵ�
		arr[root] = arr[i];
		root = i;
		i = 2 * root + 1;
	}
	arr[root] = temp;
}

void HeapSort(int *arr, int length) //������
{
	int i = 0;
	int j = 0;
	for (i = length / 2-1; i >= 0; i--)//�����
	{
		HeapAdjust(arr, length, i);
	}
	for (j = length-1; j >0 ; j--)

	{
		Swap(arr, 0, j); //���ķŵ������
		HeapAdjust(arr, j-1, 0); //�ٴν��µĴ��
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