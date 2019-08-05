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

	void Loop(int index, int l, vector<char> pwd, vector<char> lockVector)
	{
		int pwdSize = pwd.size();
		if (l == pwdSize) //탈출조건
		{
			int vowelsCount = 0;
			int noVowelsCount = 0;
			for (char v : pwd)
			{
				if (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u')
				{
					vowelsCount++;
				}
				else
				{
					noVowelsCount++;
				}
			}
			if (vowelsCount >= 1 && noVowelsCount >= 2)
			{
				for (int i = 0; i < l; i++)
				{
					cout << pwd[i];
				}
				cout << "\n";
			}
			return;
		}
		int lockSize = lockVector.size();
		if (index >= lockSize) // 불가능한 경우
		{
			return;
		}
		pwd.push_back(lockVector[index]);
		Loop(index + 1, l, pwd, lockVector);
		pwd.pop_back();
		Loop(index + 1, l, pwd, lockVector);
	}

	void Loop2(string lockArray, int l, int index, string temp)
	{
		//탈출조건
		int size = temp.size();
		if (l == size)
		{
			int vowelsCount = 0;
			int noVowelsCount = 0;
			for (int i = 0; i < size; i++)
			{
				if (temp[i] == 'a' || temp[i] == 'e' ||
					temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')
				{
					vowelsCount++;
				}
				else
				{
					noVowelsCount++;
				}
			}
			if (vowelsCount >= 1 && noVowelsCount >= 2)
			{
				cout << temp << "\n";
			}
			return;
		}
		//불가능한 조건
		if (index >= lockArray.size())
		{
			return;
		}

		Loop2(lockArray, l, index + 1, temp + lockArray[index]);
		Loop2(lockArray, l, index + 1, temp);
	}

	void ex1759_Run2()
	{
		int l, c;
		cin >> l >> c;

		vector<char> lock;
		for (int i = 0; i < c; i++)
		{
			char value;
			cin >> value;
			lock.push_back(value);
		}
		sort(lock.begin(), lock.end());

		vector<char> temp;
		Loop(0, l, temp, lock);
	}

	void ex1759_Run3()
	{
		int l, c;
		cin >> l >> c;

		string lock2;
		for (int i = 0; i < c; i++)
		{
			char value;
			cin >> value;
			lock2 += value;
		}
		sort(lock2.begin(), lock2.end());

		string temp2;
		Loop2(lock2, l, 0, temp2);
	}
}