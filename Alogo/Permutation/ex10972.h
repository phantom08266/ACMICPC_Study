#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex10972
{
	void Swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	bool next_permutation(int *a, int n) {
		int i = n - 1; 
		while (i > 0 && a[i - 1] >= a[i]) i -= 1; 
		if (i <= 0) return false; // 마지막 순열 
		int j = n-1;
		while (a[j] <= a[i-1]) j -= 1;
		Swap(a[i-1], a[j]);
		j = n-1; 
		while (i < j) 
		{ 
			Swap(a[i], a[j]);
			i += 1; 
			j -= 1; 
		} 
		return true; 
	} 
	void ex10972_Run()
	{
		int n;
		cin >> n;

		int data[10000] = { 0 };
		int value;
		for (int i = 0; i < n; i++)
		{
			cin >> value;
			data[i] = value;
		}

		/*bool check = next_permutation(data, n);
		if (check == false)
		{
			cout << -1 << endl;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				cout << data[i] << " ";
			}
			cout << endl;
		}*/
		int p = 0;
		for (int i = n - 1; i > 0; i--)
		{
			if (data[i - 1] < data[i])
			{
				p = i; // 내림차순중에 오름차순인 부분 찾기
				break;
			}
		}
		if (p > 0)
		{
			p -= 1;
			int sp = 0;
			for (int i = n - 1; i > p; i--)
			{
				if (data[p] < data[i])
				{
					Swap(data[p], data[i]);
					sp = i;
					break;
				}
			}
			int j = n - 1;
			while (p + 1 < j)
			{
				Swap(data[p + 1], data[j]);
				p += 1;
				j -= 1;
			}

			for (int i = 0; i < n; i++)
			{
				cout << data[i] <<" ";
			}
			cout << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
}