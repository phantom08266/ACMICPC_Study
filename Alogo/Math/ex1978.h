#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex1978
{
	bool Prime(int value)
	{
		if (value < 2)
		{
			return false;
		}
		else
		{
			for (int i = 2; i*i <= value; i++)
			{
				if (value % i == 0)
				{
					return false;
				}
			}
			return true;
		}
	}

	void ex1978_Run()
	{
		int count = 0; 
		cin >> count;

		int i = 0;
		int value = 0;
		int primeCount = 0;
		while (i != count)
		{
			cin >> value;
			if (Prime(value))
			{
				primeCount++;
			}
			i++;
		}
		cout << primeCount << endl;
	}
}