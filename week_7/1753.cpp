#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

#define INF 2147483647

using namespace std;

int dist[20001] = { 0 };
vector<pair<int, int>> nodeList[300001];
int whereToStart, V, E;

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,whereToStart });

	while (!pq.empty()) {
		int curNode = pq.top().second;
		int cost = -1 * pq.top().first;
		pq.pop();

		for (int k = 0; k < nodeList[curNode].size(); k++) {
			int newVal = dist[curNode] + nodeList[curNode][k].second;
			int beforeVal = dist[nodeList[curNode][k].first];
			
			if (newVal < beforeVal) {
				dist[nodeList[curNode][k].first] = newVal;
				pq.push({ -1 * newVal, nodeList[curNode][k].first });
			}
		}
	}
}

int main(void) {
	cin >> V >> E >> whereToStart;

	int from, to, d;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &d);
		nodeList[from].push_back({ to, d });
	}

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	dist[whereToStart] = 0;

	dijkstra();

	for (int i = 1; i <= V; i++) {
		if (dist[i] != INF) printf("%d\n", dist[i]);
		else printf("INF\n");
	}

	return 0;
}
