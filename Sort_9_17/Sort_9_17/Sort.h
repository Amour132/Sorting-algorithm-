//1.实现插入、希尔、选择、堆排、冒泡、快排、归并排序
//2.总结各个排序的性能、稳定性等优缺点。

#pragma once

#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *arr, int length); //插入排序
void ShellSort(int *arr, int length); //希尔排序
void SelectSort(int *arr, int length); //选择排序
void BubbleSort(int *arr, int length); //冒泡排序
void QuickSort(int *arr, int start,int end); //快速排序
void HeapSort(int *arr, int length); //堆排序

void Print(int *arr, int length);
