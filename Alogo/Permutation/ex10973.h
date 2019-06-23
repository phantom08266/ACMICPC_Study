#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex10973
{
	/*void Swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}*/
	void ex10973_Run()
	{
		int n;
		cin >> n;

		int data[10000] = { 0 };
		for (int i = 0; i < n; i++)
		{
			cin >> data[i];
		}

		int i = n -1;
		while (i > 0 && data[i - 1] < data[i])
		{
			i -= 1;
		}
		if (i <= 0)
		{
			cout << -1 << endl;
		}
		else
		{
			int j = n - 1;
			while (j > 0 && data[i - 1] < data[j])
			{
				j -= 1;
			}
			swap(data[i - 1], data[j]);

			int k = n - 1;
			while (i < k)
			{
				swap(data[i], data[k]);
				i += 1;
				k -= 1;
			}

			for (int c = 0; c < n; c++)
			{
				cout << data[c] << " ";
			}
			cout << endl;
		}
	}
}