#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;

int N, M;
bool dfs[10];
int dfs_arr[10];

void solve (int x) {
	if (x == M) {
	   for (int i=0; i<M; i++) // M 은 dfs_arr의 길이 
	   	    printf("%d ", dfs_arr[i]);
	   printf("\n");
	   return;	
	}
 
	for (int i=1; i<N+1; i++){
      //   if (!dfs[i]) { // 이미 지나온 노드가 아니라면 
         	
	         dfs[i] = true;
	         dfs_arr[x] = i;
	         solve(x+1);	
	         dfs[i] = false;
	         
	//	}		
	}	
}


int main(void) {
	
	cin >> N >> M;
	solve(0);
	
	return 0;
}
