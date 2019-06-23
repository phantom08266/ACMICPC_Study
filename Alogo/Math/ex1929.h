#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

const int MAX = 1000000;
bool check[MAX + 1];
namespace ex1929
{
	void ex1929_Run()
	{
		/*check[0] = check[1] = true;
		for (int i = 2; i*i <= MAX; i++) {
			cout << i << endl;
			if (i == 46349)
			{
				cout << "" << endl;
			}
			if (check[i] == false) {
				for (int j = i + i; j <= MAX; j += i) {
					check[j] = true;
				}
			}
		}
		int m, n;
		cin >> m >> n;
		for (int i = m; i <= n; i++) {
			if (check[i] == false) {
				cout << i << '\n';
			}
		}*/
		

		bool primeCheck[1000001] = { false };
		primeCheck[0] = primeCheck[1] = true;
		for (int i = 2; i*i <= MAX; i++) // 소수 구하는 공식 적용
		{
			if (primeCheck[i] == false)
			{
				for (int j = i + i; j <= MAX; j += i)
				{
					primeCheck[j] = true;
				}
			}
		}
		int first, second;
		cin >> first >> second;
		for (int i = first; i <= second; i++)
		{
			if (primeCheck[i] == false)
			{
				cout << i << endl;
			}
		}
	}
	//에라토스테네스의 체 이용(실패 이유는 소수를 int로 저장하려고 해서 문제 발생. 스택오버플로우 발생함.... )
	//void ex1929_Run()
	//{
	//	int first, second;
	//	cin >> first >> second;

	//	int primeArray[5000];
	//	bool primeCheck[1000001] = { false };
	//	//memset(primeCheck, true, sizeof(primeCheck));
	//	for (int i = 2; i <= second; i++)
	//	{
	//		if (primeCheck[i] == false)
	//		{
	//			primeArray[i] = i;
	//			if(first <= i)
	//				cout << primeArray[i] << endl;
	//			// i*i 가 i*2 가 아닌 이유는 2*2, 3*2를 생각해봤을때 어차피 2의 배수에서 이미 고려했을것이므로!!
	//			for (int j = i * i; j <= second; j += i)
	//			{
	//				primeCheck[j] = true;
	//			}
	//		}
	//	}
	//}


	//방안1
	/*bool Prime(int value)
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

	void ex1929_Run()
	{
		int first, second;
		cin >> first >> second;

		for (int i = first; i <= second; i++)
		{
			if (Prime(i))
			{
				cout << i << endl;
			}
		}
	}*/
}