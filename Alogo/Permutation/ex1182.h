#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex1182
{
	void ex1182_Run()
	{
		int n, s;
		cin >> n >> s;

		int valueArray[20];
		
		for (int i = 0; i < n; i++)
		{
			cin >> valueArray[i];
		}

		int count = 1;
		vector<int> sumIndexVector;
		sumIndexVector.reserve(20);
		int sumSameCount = 0;

		while (count <= n)
		{
			for (int i = 0; i < count; i++)
			{
				sumIndexVector.push_back(0);
			}

			for (int i = 0; i < n- count; i++)
			{
				sumIndexVector.push_back(1);
			}

			int sum = 0;
			do
			{
				sum = 0;
				for (int i = 0; i < n; i++)
				{
					if (sumIndexVector[i] == 0)
					{
						sum += valueArray[i];
					}
				}
				if (sum == s)
				{
					sumSameCount++;
				}
			} while (next_permutation(sumIndexVector.begin(), sumIndexVector.end()));
			sumIndexVector.clear();
			count++;
		}
		cout << sumSameCount << endl;
	}
}