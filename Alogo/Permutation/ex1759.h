#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;

namespace ex1759
{
	bool CheckIncludeVowels(vector<char> temp)
	{
		char vowels[5] = { 'a','e','i','o','u' };
		bool check = false;
		bool success = false;
		int vowelCount = 0;
		int consonantCount = 0;

		for (char tc : temp)
		{
			check = false;
			for (char v : vowels)
			{
				if (tc == v)
				{
					check = true;
					break;
				}
			}
			if (check)
			{
				vowelCount++;
			}
			else
			{
				consonantCount++;
			}
		}
		if (vowelCount >= 1 && consonantCount >= 2)
		{
			success = true;
		}
		return success;
	}
	void ex1759_Run()
	{
		int l, c;
		cin >> l >> c;

		const int MAX = 15;
		char lock[MAX];
		for (int i = 0; i < c; i++)
		{
			cin >> lock[i];
		}

		sort(lock, &lock[c]);

		vector<int> index;
		index.reserve(MAX);
		for (int i = 0; i < c - l; i++)
		{
			index.push_back(0);
		}
		for (int i = 0; i < l; i++)
		{
			index.push_back(1);
		}
		vector<vector<char>> data;
		
		bool check;
		do
		{
			vector<char> temp;
			temp.reserve(l);
			for (int i = 0; i < c; i++)
			{
				if (index[i] == 1)
				{
					temp.push_back(lock[i]);
				}
			}
			check = CheckIncludeVowels(temp);
			if (check)
			{
				data.push_back(temp);
			}
		} while (next_permutation(index.begin(), index.end()));

		
		for (vector<vector<char>>::reverse_iterator rd = data.rbegin(); rd != data.rend(); rd++)
		{
			for (vector<char>::iterator riter = rd->begin(); riter != rd->end(); riter++)
			{
				cout << *riter;
			}
			cout << "\n";
		}
	}
}