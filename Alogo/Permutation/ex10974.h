#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex10974
{
	void ex10974_Run()
	{
		int n;
		cin >> n;

		TimeStart();
		vector<int> data;
		for (int i = 0; i < n; i++)
		{
			data.push_back(i + 1);
		}
		do
		{
			for (int i = 0; i < n; i++)
			{
				cout << data[i] << " ";
			}
			cout << "\n";
		} while (next_permutation(data.begin(), data.end()));
		TimePrint();
	}

	/*void ex10974_Run()
	{
		int n;
		cin >> n;
		
		TimeStart();
		int data[8];
		for (int i = 0; i < n; i++)
		{
			data[i] = i + 1;
			cout << data[i] << " ";
		}
		cout << "\n";
		while (true)
		{
			int i = n -1;
			while (i > 0 && data[i - 1] > data[i])
			{
				i--;
			}
			if (i <= 0)
			{
				break;
			}
			int j = n - 1;
			while (data[i - 1] >= data[j])
			{
				j--;
			}

			swap(data[i - 1], data[j]);

			int k = n - 1;
			while (i < k)
			{
				swap(data[i], data[k]);
				i++;
				k--;
			}

			for (int l = 0; l < n; l++)
			{
				cout << data[l] << " ";
			}
			cout << "\n";
		}
		TimePrint();
	}*/
}