#include<iostream>
#include<vector>
using namespace std;
int trip[200][200];

vector<int> root;
vector<int> path;

int find(int x){		//find 연산 
	if(root[x] == x) 
		return x; 	// // 배열 인덱스와 값이 같다면 해당 값 리턴
	return root[x] = find(root[x]);	// 재귀를 통해 루트노드를 찾아감 
}

void isunion(int x, int y){ 			//union 연산 
	x = find(x);	// find연산으로 각각의 루트 노드 찾기 
	y = find(y);
	
	if(x == y) 
		return;
		
	if(x < y)		//크기를 비교해서 값 변경 
	root[y] = x;
	else
	root[x] = y;
}
	
int main() {
	int N,M,i,j;
	cin >> N >> M;
	
	root = vector<int> (N+1,0);
	path = vector<int> (M+1,0);
	
	for(i = 1; i <= N; i++)
	{
		root[i] = i; 	// 초기화 진행 
	}
	
	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= N; j++)
		{
			cin >> trip[i][j];
			if(trip[i][j]== 1)
			 isunion(i,j);		//관계가 1인 도시는 union연산 
		}
	}
	for(i = 1; i <= M; i++)
	 cin >> path[i];	// 여행루트 저장 
	
	bool check = true;
	
	for(i = 1; i < M; i++){		 
		if(find(path[i]) != find(path[i+1])){
			check = false;
			break;
		}
	}
	
	if(check) 
		cout << "YES";
	else
		cout << "NO";
		
	return 0;
}
