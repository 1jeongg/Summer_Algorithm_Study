#include <iostream>
#include <vector>
using namespace std;

vector<int> computer[10001];
vector<int> visited;
vector<int> hacked;

int max_hacking=0;

void dfs(int node){
	hacked[node]++;
	if(max_hacking < hacked[node]) max_hacking = hacked[node];
	
	for(int i = 0; i < computer[node].size(); i++){
		
		int previous_com = computer[node][i];
		
		if(!visited[previous_com]){
			visited[previous_com] = 1;
			dfs(previous_com);
		}
	}
}

int main() {
	int N,M,A,B,i;
	cin >> N >> M;
	hacked = vector<int>(N+1,0);	
	for(i=0; i<M; i++){ //A가 B를 신뢰한다 
		cin >> A >> B;
		computer[A].push_back(B);
	}

	for(i=1; i<=N; i++){
		visited = vector<int>(N+1,0);
		visited[i] = 1;
		dfs(i);
	}
	
	for(i=1; i<=N; i++){
		//cout << i << " / " << hacked[i] << endl;
		if(max_hacking == hacked[i]) cout << i << " ";
	}

}
