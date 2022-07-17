#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool broken[10]={false,};    //고장난 버튼 번호들을 저장할 배열

int check(int N){   //N이 현재 리모콘으로 입력 가능한 숫자인지
    if(N==0){
        if(broken[0]){  //0이 고장난 경우
            return 0;
        }else return 1;
    }
    int len=0;  //n의 총 자리수(=버튼 입력 횟수)
    while(N>0){
        if(broken[N%10]) return 0;
        N/=10;
        len++;
    }
    return len;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;  //목적 채널
    int M;  //고장난 버튼 개수
    int cnt;    //버튼 누르는 횟수(결괏값)
    //input
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int x;
        cin>>x;
        broken[x]=true;
    }
    cnt=abs(N-100);    //+/-만 사용한 경우의 버튼 입력 횟수
    for(int i=0;i<1000000;i++){ //최대 이동 가능한 채널은 1000000이다.
    //+)만약 N=500000이라면 채널 1000000으로 이동한 뒤 500000번 -를 눌러 N으로 이동하는 것이 가능한 최대 횟수이므로
        int len=check(i);   //입력 가능한 i의 길이(=누르는 횟수)
        if(len>0){  //=i가 입력 가능하다면
            if(cnt>len+abs(N-i)) cnt=len+abs(N-i);
        }
    }
    cout<<cnt<<endl;
    
    
    /*
    6999
    6 고장남
    7000--
    1 5
    5 1 1 1 1 1
    주어진 버튼들로 만들 수 있는 목적 채널과 가장 가까운 수
    일단 자릿수가 클수록 우선도가 커짐

    */

    
    return 0;
}