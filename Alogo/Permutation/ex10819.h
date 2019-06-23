#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex10819
{
	int CalcProcess(int* data, int* index, int n)
	{
		int result = 0;
		
		for (int i = 0; i <= n - 2; i++)
		{
			result += abs(data[index[i]] - data[index[i + 1]]);
		}
		return result;
	}
	//int CalcProcess(int* data, int n)
	//{
	//	int result = 0;
	//	for (int i = 0; i <= n - 2; i++)
	//	{
	//		/*if (i + 1 < n)*/
	//		{
	//			result += abs(data[i] - data[i+1]);
	//		}
	//	}
	//	return result;
	//}
	void ex10819_Run()
	{
		int n;
		cin >> n;

		int bigData = 0;
		int index[8];
		int data[8];
		for (int i = 0; i < n; i++)
		{
			cin >> data[i];
			index[i] = i;
		}
		bigData = CalcProcess(data, index, n);
		/*sort(data, data+ n);
		do
		{
			int temp = CalcProcess(data, n);
			if (bigData < temp)
			{
				bigData = temp;
			}
		} while (next_permutation(data, data + n));
		cout << bigData << endl;*/
		while (true)
		{
			int i = 0;
			for (i = n - 1; i > 0; i--)
			{
				if (index[i - 1] < index[i]) // 오름차순이면
				{
					break;
				}
			}
			if (i == 0) // 반복문 탈출조건
			{
				break;
			}
			int j = 0;
			for (j = n - 1; j > i-1; j--)
			{
				if (index[i - 1] < index[j])
				{
					break;
				}
			}

			swap(index[i - 1], index[j]);

			int k = n - 1;
			while (i < k)
			{
				swap(index[i], index[k]);
				i++;
				k--;
			}
			int compare = CalcProcess(data, index, n);
			if (bigData < compare)
			{
				bigData = compare;
			}
		}
		cout << bigData;
	}
}