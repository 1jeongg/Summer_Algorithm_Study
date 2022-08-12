#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;


vector<pair<int,int>> tree[10001];  //각각 {자식노드, 가중치}
bool visited[10001]={false,};

int diameter=0;
int endPoint=0;

void dfs(int root, int len){    //root는 dfs 시작 노드, len은 최초 root값에서 현재 노드 root까지의 거리
    if(visited[root]) return;
    
    visited[root]=true;
    if(diameter<len){
        diameter=len;   //최초 노드에서 가장 멀리 떨어진 노드까지의 거리
        endPoint=root;  //최초 노드에서 가장 멀리 떨어진 노드 번호
    }

    for(int i=0;i<tree[root].size();i++){
        dfs(tree[root][i].first,len+tree[root][i].second);  //자식노드 방문
    }
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;  //노드 개수
    int p,c,w;  //각각 부모노드, 자식노드, 가중치
    cin>>N;

    for(int i=0;i<N-1;i++){
        cin>>p>>c>>w;
        tree[p].push_back({c,w});
        tree[c].push_back({p,w});
    }
    dfs(1,0);
    diameter=0;
    memset(visited,false,sizeof(visited));

    dfs(endPoint,0);    //지름 구하기
    cout<<diameter;
    
}