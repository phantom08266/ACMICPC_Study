#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex2309
{
	void ex2309_Run()
	{
		vector<int> valueV;
		int count = 9;
		int value;
		int total = 0;
		int limit = 100;
		int diff = 0;
		for (int i = 0; i < count; i++)
		{
			cin >> value;
			total += value;
			valueV.push_back(value);
		}

		sort(valueV.begin(), valueV.end());
		diff = total - limit;

		int temp1, temp2;
		for (int i = 0; i < count - 1; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (valueV[i] + valueV[j] == diff)
				{
					temp1 = i;
					temp2 = j;
				}
			}
		}
		for (int i = 0; i < count; i++)
		{
			if (temp1 == i || temp2 == i)
			{
				continue;
			}
			cout << valueV[i] << endl;
		}
	}
}