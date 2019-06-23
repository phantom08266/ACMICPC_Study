#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex9095
{
	int SumSameValue(int n, int c, int t)
	{
		int count = 0;

		if (c <= 0)
		{
			return count;
		}
		else
		{
			for (int h = 1; h <= 3; h++)
			{
				if (h + t == n)
				{
					count++;
				}
				count += SumSameValue(n, c - 1, h + t);
			}

		}
		return count;
	}
	void ex9095_Run()
	{
		int loop;
		int count = 0;
		
		cin >> loop;

		int n;
		for (int i = 0; i < loop; i++)
		{
			cin >> n;
			count = 0;
			count = SumSameValue(n, 10, 0);
			cout << count << endl;
		}
		
	}
}