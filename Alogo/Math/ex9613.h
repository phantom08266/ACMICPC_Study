#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex9613
{
	int GCD(int a, int b)
	{
		if (b == 0)
		{
			return a;
		}
		return GCD(b, a % b);
	}
	void ex9613_Run()
	{
		/*int t;
		cin >> t;
		while (t--) {
			int a[111];
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				cin >> a[i];
			}
			long long sum = 0;
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					sum += GCD(a[i], a[j]);
				}
			}
			cout << sum << '\n';
		}*/
		int valueArray[100];
		string value;
		int valueCount = 0;
		long long sum = 0;
		int count;
		cin >> count;
		cin.get();
		for (int i = 0; i < count; i++)
		{
			std::getline(std::cin, value);
			stringstream st(value);
			int j = 0;
			bool first = true;
			while (std::getline(st, value, ' '))
			{
				if (first == true)
				{
					valueCount = atoi(value.c_str());
					first = false;
				}
				else
				{
					valueArray[j++] = atoi(value.c_str());
				}
			}
			sum = 0;
			for (int k = 0; k < valueCount -1; k++)
			{
				for (int h = k+1; h < valueCount; h++)
				{
					sum += GCD(valueArray[k], valueArray[h]);
				}
			}
			cout << sum << endl;
		}
	}
}