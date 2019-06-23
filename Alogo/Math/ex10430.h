#pragma once
#include "BaseInclude.h"
#include "ex10430.h"

using namespace BaseInclude;

namespace ex10430
{
	void ex10430_Run()
	{
		int a = 0;
		int b = 0;
		int c = 0;

		cin >> a >> b >> c;

		TimeStart();
		int result1 = (a + b) % c;
		int result2 = (a*b) % c;

		cout << result1 << endl;
		cout << result1 << endl;
		cout << result2 << endl;
		cout << result2 << endl;
		TimePrint();
	}
}