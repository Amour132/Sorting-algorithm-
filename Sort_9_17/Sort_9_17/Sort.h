//1.ʵ�ֲ��롢ϣ����ѡ�񡢶��š�ð�ݡ����š��鲢����
//2.�ܽ������������ܡ��ȶ��Ե���ȱ�㡣

#pragma once

#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *arr, int length); //��������
void ShellSort(int *arr, int length); //ϣ������
void SelectSort(int *arr, int length); //ѡ������
void BubbleSort(int *arr, int length); //ð������
void QuickSort(int *arr, int start,int end); //��������
void HeapSort(int *arr, int length); //������

void Print(int *arr, int length);
