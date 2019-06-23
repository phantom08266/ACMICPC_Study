#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex14888
{
	void ex14888_Run()
	{
		int n;
		cin >> n;

		int value[100];
		for (int i = 0; i < n; i++)
		{
			cin >> value[i];
		}
		const int plus = 0;
		const int minus = 1;
		const int mix = 2;
		const int splite = 3;
		vector<int> operate;
		operate.reserve(99);

		for (int i = 0; i < 4; i++)
		{
			int c;
			cin >> c;
			for (int j = 0; j < c; j++)
			{
				operate.push_back(i);
			}
		}
		
		int max = -1000000000;
		int min = 1000000000;
		int calc = 0;
		//음수를 나눌때 C++14처럼 , 나눌때 목만 나오도록
		do
		{
			calc = value[0];
			for (int i = 0; i < n - 1; i++)
			{
				switch (operate[i])
				{
				case 0:
					calc += value[i + 1];
					break;
				case 1:
					calc -= value[i + 1];
					break;
				case 2:
					calc *= value[i + 1];
					break;
				case 3:
					calc /= value[i + 1];
					break;
				}
			}
			if (max < calc)
			{
				max = calc;
			}
			if (min > calc)
			{
				min = calc;
			}
		} while (next_permutation(operate.begin(), operate.end()));
		cout << max << "\n";
		cout << min << "\n";
	}
}