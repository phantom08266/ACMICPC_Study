#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex6603
{
	void ex6603_Run()
	{
		int k;
		const int MAX_K_Count = 12;
#pragma region 방법 1
		//일단 이 방법은 동일한 값을 next_permutation이 처리할 수 있는걸 아느냐 같음.
		//그리고 next_permutation은 오름차순만 되는듯 함. 하여 벡터로 처리해서 
		//나중에 sort알고리즘을 통해 해결해야 될 것으로 판단.
		/*
		int s[MAX_K_Count];
		int sIndex[MAX_K_Count];
		while (true)
		{
			cin >> k;
			if (k == 0)
			{
				break;
			}

			for (int i = 0; i < k; i++)
			{
				cin >> s[i];
			}

			for (int i = 0; i < k - 6; i++)
			{
				sIndex[i] = 0;
			}
			for (int i = 0; i < 6; i++)
			{
				sIndex[i + (k - 6)] = 1;
			}

			do
			{
				for (int i = 0; i < k; i++)
				{
					int index = sIndex[i];
					if (index == 1)
					{
						cout << s[i] << " ";
					}
				}
				cout << "     ";
				for (int i = 0; i < k; i++)
				{
					int index = sIndex[i];
					cout << index << " ";
				}
				cout << "\n";
			} while (next_permutation(sIndex, &sIndex[k]));
			cout << "\n";
		}*/
#pragma endregion

#pragma region 방법 2
		vector<int> s;
		vector<int> sIndex;

		while (true)
		{
			cin >> k;
			if (k == 0)
			{
				break;
			}

			for (int i = 0; i < k; i++)
			{
				int value;
				cin >> value;
				s.push_back(value);
			}

			for (int i = 0; i < k - 6; i++)
			{
				sIndex.push_back(0);
			}
			for (int i = 0; i < 6; i++)
			{
				sIndex.push_back(1);
			}

			vector<vector<int>> sList;
			do
			{
				vector<int> list;
				for (int i = 0; i < k; i++)
				{
					if (sIndex[i] == 1)
					{
						list.push_back(s[i]);
					}
				}
				sList.push_back(list);
			} while (next_permutation(sIndex.begin(), sIndex.end()));
			sort(sList.begin(), sList.end());
			for (vector<vector<int>>::iterator iter = sList.begin(); iter != sList.end(); iter++)
			{
				for (vector<int>::iterator v = iter->begin(); v != iter->end(); v++)
				{
					cout << *v << " ";
				}
				cout << "\n";
			}
			cout << "\n";
			s.clear();
			sIndex.clear();
		}
#pragma endregion
	}
}