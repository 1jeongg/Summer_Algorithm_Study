#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int E,S,M;
    cin>>E>>S>>M;
    //문제와 달리 mod N=0의 값이 최대 값으로 표기되므로(ex: 0~14가 아니라 1~15)
    if(E==15) E=0;
    if(S==28) S=0;
    if(M==19) M=0;
    for(int i=1;i<7981;i++){    //7980이 15,28,19의 최소 공배수이므로
        if(i%15==E){
            if(i%28==S){
                if(i%19==M){
                    cout<<i;
                    break;
                }
            }
        }
    }
}