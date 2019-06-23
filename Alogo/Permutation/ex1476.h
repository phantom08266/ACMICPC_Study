#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex1476
{
	void ex1476_Run()
	{
		int e, s, m;
		cin >> e >> s >> m;

		int te = 0;
		int ts = 0;
		int tm = 0;
		long long year = 0;
		while (true)
		{
			if(te >= 15)
				te = 1;
			else
				te++;

			if(ts >= 28)
				ts = 1;
			else
				ts++;
			
			if (tm >= 19)
				tm = 1;
			else
				tm++;

			year++;
			if(e == te && s == ts && m == tm)
			{
				break;
			}
		}
		cout << year << endl;
	}
}