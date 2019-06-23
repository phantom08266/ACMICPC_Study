#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex1934
{
	int GCD(int a, int b)
	{
		if (b == 0)
		{
			return a;
		}
		GCD(b, a % b);
	}

	void ex1934_Run()
	{
		int inValue1, inValue2;
		int gcd;
		int count;
		cin >> count;

		for (int i = 0; i < count; i++)
		{
			cin >> inValue1 >> inValue2;
			gcd = GCD(inValue1, inValue2);
			cout << (inValue1 * inValue2) / gcd << endl;
		}
	}
}