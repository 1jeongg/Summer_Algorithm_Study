#include <iostream>
#include <vector>

using namespace std;

vector<int> a[101]; //인접리스트 
bool visited[101];
int count = 0;

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if(!visited[y]) {
			dfs(y);
			count++;
		}
	} 
} 

int main() {
	int n, m; //노드, 엣지개수
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	} 
	dfs(1);
	cout << count;
}
