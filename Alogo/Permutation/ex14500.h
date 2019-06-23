#pragma once
#include "BaseInclude.h"

using namespace BaseInclude;
namespace ex14500
{
	void ex14500_Run()
	{
		int n, m;
		cin >> n >> m;

		int** valueArray = new int*[n];
		int value;
		for (int i = 0; i < n; i++)
		{
			valueArray[i] = new int[m];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> value;
				valueArray[i][j] = value;
			}
		}

		int caseX[19][4] = {
			{ 0, 1, 0, 1 } ,
			{0,1,2,3},
			{0,0,0,0},
			{0,0,1,0},
			{1,0,1,1},
			{1,0,1,2},
			{0,1,2,1},
			{0,0,1,2},
			{2,0,1,2},
			{0,1,2,0},
			{0,1,2,2},
			{0,1,0,0},
			{0,1,1,1},
			{0,0,0,1},
			{1,1,0,1},
			{0,0,1,1},
		{1,0,1,0},
		{0,1,1,2},
		{1,2,0,1}
		};
		int caseY[19][4] = {
			{ 0, 0, 1, 1 },
			{0,0,0,0},
			{0,1,2,3},
			{0,1,1,2},
			{0,1,1,2},
			{0,1,1,1},
			{0,0,0,1},
			{0,1,1,1},
			{0,1,1,1},
			{0,0,0,1},
			{0,0,0,1},
			{0,0,1,2},
			{0,0,1,2},
			{0,1,2,2},
			{0,1,2,2},
		{0,1,1,2},
		{0,1,1,2},
		{0,0,1,1},
		{0,0,1,1}
		};
		int x = 0;
		int y = 0;
		int total = 0;
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				for (int c = 0; c < 19; c++)
				{
					total = 0;
					for (int k = 0; k < 4; k++)
					{
						x = caseX[c][k] + j;
						y = caseY[c][k] + i;
						if (m <= x || n <= y)
						{
							break;
						}
						if (x < 0 || y < 0)
						{
							break;
						}
						
						total += valueArray[y][x];
					}
					if (max < total)
					{
						max = total;
					}
				}
				
			}
		}
		cout << max << endl;
	}
}