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
	//n�� ��ǥ��
	int SumSameValue2(int n, int sum)
	{
		int count = 0;
		if (n < sum) // �Ұ��� ����� ��
		{
			return 0;
		}
		if (n == sum) // Ż������
		{
			return 1;
		}
		for (int i = 1; i <= 3; i++) // ���� ����� ��
		{
			count += SumSameValue2(n, sum + i);
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
			TimeStart();
			count = 0;
			//count = SumSameValue(n, 10, 0);
			count = SumSameValue2(n, 0);
			cout << count << endl;
			TimePrint();
		}

	}
}