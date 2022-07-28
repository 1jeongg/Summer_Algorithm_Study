#include <iostream>
#include <queue>
using namespace std;

int N,K;

queue<pair<int, int>> Q;

bool visited[100001];
int minimum = 200000;

bool isvalid(int number){
	if(visited[number] || number < 0 || number > 100000) return false;
	return true;
}

void BFS(int start){
	
	while(!Q.empty()){
		int data = Q.front().first;
		int second = Q.front().second;
		q.pop(); //버림
		 
		//if(second > minimum){return;}
		
		if(start == K){
			cout << "destination in " << second << " times" << endl;
			minimum = second;
			return;
		}
		
		if(isvalid(start+1)){
			//cout << "+1" << endl;
			visited[start+1] = 1;
			Q.push({start+1, second+1});
		} 
		if(isvalid(start-1)){
			cout << "-1" << endl;
			visited[start-1] = 1;
			Q.push({start-1, second+1});
		}
		if(isvalid(start*2)){
			cout << "*2" << endl;
			visited[start*2] = 1;
			Q.push({start*2, second+1});
		}
	}

	
}

int main() {
	cin >> N >> K;
	
	visited[N] = 1;
	BFS(N);
	
	cout << minimum <<endl;
	
}
