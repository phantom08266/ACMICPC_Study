#pragma once
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

namespace ex1260
{
	//전역변수 사용이유 : 디폴트 초기화 하기위함.
	vector<int> node[1001];
	bool bUsed[1001];

	void DSP(int startNode)
	{
		bUsed[startNode] = true;
		cout << startNode << " ";

		for (unsigned int i = 0; i < node[startNode].size(); i++)
		{
			int nextNode = node[startNode][i];
			if (bUsed[nextNode] == false)
			{
				DSP(nextNode);
			}
		}
	}
	
	void BFS(int startNode)
	{
		queue<int> q;
		memset(bUsed, false, sizeof(bUsed));
		bUsed[startNode] = true;
		q.push(startNode);
		while (!q.empty()) {
			int n = q.front();
			q.pop();
			cout << n << " ";
			for (unsigned int i = 0; i < node[n].size(); i++) {
				int next = node[n][i];
				if (bUsed[next] == false) {
					bUsed[next] = true;
					q.push(next);
				}
			}
		}
	}
	void ex1260_Run()
	{
		//n 정점 수, m 간선의 수, 시작할 번호
		int n, m, s;

		cin >> n >> m >> s;

		int v1, v2;
		for (int i = 0; i < m; i++)
		{
			cin >> v1 >> v2;
			node[v1].push_back(v2);
			node[v2].push_back(v1);
		}
		//적은 수를 먼저 방문하라고 하였으므로 sort 해야함
		for (int i = 1; i < n; i++)
		{
			sort(node[i].begin(), node[i].end());
		}
		DSP(s);
		cout << "\n";
		memset(bUsed, false, sizeof(bUsed));
		BFS(s);
	}
}