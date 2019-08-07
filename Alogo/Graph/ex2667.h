#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <stack>
#include <algorithm>
#include <stdio.h>
using namespace std;

namespace ex2667
{
	char arr[26][26];
	bool check[26][26];
	int mx[4] = { 0,0,1,-1 };
	int my[4] = { 1,-1,0,0 };
	int N;
	int DFS(int x, int y, char c)
	{
		int count = 0;
		stack<pair<int, int>> node;
		pair<int, int> p = make_pair(x, y);
		node.push(p);
		if (c == '1' && check[x][y] == false)
		{
			check[x][y] = true;
			count++;

			for (int i = 0; i < 4; i++)
			{
				int moveX = x + mx[i];
				int moveY = y + my[i];

				if ((0 <= moveX && moveX < N) && (0 <= moveY && moveY < N))
				{
					if (arr[moveX][moveY] == '1' && check[moveX][moveY] == false)
					{
						count += DFS(moveX, moveY, arr[moveX][moveY]);
					}
				}
			}
		}
		
		return count;
	}

	void ex2667_Run()
	{
		cin >> N;

		//ют╥б
		for (int i = 0; i < N; i++)
		{
			scanf("%s", &arr[i]);
		}
		int count = 0;
		int temp[400];

		//Loop
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int hcount = DFS(i, j, arr[i][j]);
				if (hcount != 0)
				{
					temp[count] = hcount;
					count++;
				}
			}
		}
		cout << count << endl;
		if (count >= 1)
			sort(temp, &temp[count]);
		for (int i = 0; i < count; i++)
		{
			cout << temp[i] << endl;
		}

		getchar();
	}
}
