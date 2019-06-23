#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;
namespace ex10971
{
	void ex10971_Run()
	{
		int n;
		cin >> n;

		int** valueArr = new int*[n];
		for (int i = 0; i < n; i++)
		{
			valueArr[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				cin >> valueArr[i][j];
			}
		}

		vector<int> nArray;
		for (int i = 0; i < n; i++)
		{
			nArray.push_back(i);
		}

		int min = 2147483647;
		int comp = 0;
		bool check = true;
		do
		{
			comp = 0;
			int i = 0;
			check = true;
			for (i = 0; i < n - 1; i++)
			{
				int temp = valueArr[nArray[i]][nArray[i + 1]];
				if (temp == 0)
				{
					check = false;
					break;
				}
				comp += temp;
			}
			if (check)
			{
				int temp = valueArr[nArray[i]][nArray[0]];
				if (temp != 0)
				{
					comp += temp;
					if (min > comp)
					{
						min = comp;
					}
				}
				
			}
		} while(next_permutation(nArray.begin(), nArray.end()));

		cout << min << "\n";
	}
}