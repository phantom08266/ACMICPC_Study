#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex2609
{
	int GCD(int a, int b)
	{
		if (b == 0)
		{
			return a;
		}
		GCD(b, a % b);
	}

	int GCD2(int a, int b)
	{
		while (b != 0)
		{
			int temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}
	void ex2609_Run()
	{
		int inputValue1, inputValue2;
		int gcd;
		cin >> inputValue1 >> inputValue2;
		TimeStart();

		gcd = GCD(inputValue1, inputValue2);
		cout << gcd << endl;
		cout << (inputValue1 * inputValue2) / gcd << endl;
		TimePrint();
	}

}