#include<iostream>
#include<memory.h>
#include<vector>
#include<stack>

using namespace std;
//방문 여부를 저장할 배열
int w,h;    //지도의 너비와 높이
bool visit[50][50]={{false,},};
int cnt=0;

void dfs(vector<vector<char>> v,int startR, int startC){
    if(v[startR][startC]=='0') return;  //시작지점이 바다인 경우
    if(visit[startR][startC]) return;   //이미 탐색을 완료한 땅인 경우
    cnt++;
    stack<pair<int,int>> s;
    s.push({startR,startC});    //시작점 좌표를 스택에 넣는다
    visit[startR][startC]=true; //시작점 방문표시
    while(!s.empty()){
        //주위 8칸 탐색
        pair<int,int> curPoint=s.top();
        s.pop();
        int x=curPoint.first;   //행번호
        int y=curPoint.second;  //열번호
        
        //10시방향부터 시계방향으로 탐색
        if(x>0){
            if(y>0){
                //10시
                if(v[x-1][y-1]=='1'&&!visit[x-1][y-1]){
                    visit[x-1][y-1]=true; 
                    s.push({x-1,y-1});      
                }       
            }
            //12시
            if(v[x-1][y]=='1'&&!visit[x-1][y]){ 
                visit[x-1][y]=true;
                s.push({x-1,y});
            }
            //1시
            if(y<w-1){
                if(v[x-1][y+1]=='1'&&!visit[x-1][y+1]){ 
                    visit[x-1][y+1]=true;
                    s.push({x-1,y+1});
                }
            }
        }
        //3시
        if(y<w-1){
           if(v[x][y+1]=='1'&&!visit[x][y+1]){ 
                    visit[x][y+1]=true; 
                    s.push({x,y+1});
            }
        }

        if(x<h-1){
            //4시
            if(y<w-1){
                if(v[x+1][y+1]=='1'&&!visit[x+1][y+1]){ 
                    visit[x+1][y+1]=true; 
                    s.push({x+1,y+1});
                }
            }
            //6시
            if(v[x+1][y]=='1'&&!visit[x+1][y]){ 
                    visit[x+1][y]=true; 
                    s.push({x+1,y});
            }
            //7시
            if(y>0){
                if(v[x+1][y-1]=='1'&&!visit[x+1][y-1]){ 
                    visit[x+1][y-1]=true; 
                    s.push({x+1,y-1});
                }
            }
        }
        //9시
        if(y>0){
            if(v[x][y-1]=='1'&&!visit[x][y-1]){ 
                    visit[x][y-1]=true; 
                    s.push({x,y-1});
                }
        }


    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
        
    while(1){
        cin>>w>>h;
        if(w==0&&h==0) break;
        vector<vector<char>> v; //지도를 저장할 벡터
        vector<char> temp;  //지도의 한 행을 저장할 벡터

        //input
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                char i;
                cin>>i;
                temp.push_back(i);
            }
            v.push_back(temp);
            temp.clear();
        }

        //calculation
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                dfs(v,i,j);
                
            }
            
        }

        //output
        cout<<cnt<<endl;

        //initialize
        cnt=0;  //테스트케이스의 결괏값 초기화
        memset(visit,false,sizeof(visit));  //테스트케이스의 visit 배열 초기화
    }
        

    
    
    return 0;
}