#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

namespace ex11724
{
	vector<int> nodeVector[1000];
	bool checkNode[1000];

	void DFS(int x)
	{
		checkNode[x] = true;

		for (int i = 0; i < nodeVector[x].size(); i++)
		{
			int node = nodeVector[x][i];
			if (checkNode[node] == false)
			{
				DFS(node);
			}
		}
	}

	void ex11724_Run()
	{
		int N, M; //N : 정점, M : 간선
		cin >> N >> M;


		int sV, eV;
		for (int i = 0; i < M; i++)
		{
			cin >> sV >> eV;
			nodeVector[sV].push_back(eV);
			nodeVector[eV].push_back(sV);
		}

		DFS(1);
		int count = 1;
		for (int i = 1; i <= N; i++)
		{
			if (checkNode[i] == false)
			{
				count++;
				DFS(i);
			}
		}
		cout << count << endl;
	}
}