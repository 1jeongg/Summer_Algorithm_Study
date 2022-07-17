#include<iostream>
#include<cmath>

using namespace std;

long long findN(long long num, long long key){    //num! 값이 인수로 갖는 key의 최대 제곱수를 반환(ex : 24,2이면 3이 반환)
    long long result=0;
    for(long long int i=key;num/i>=1;i*=key){
        result+=num/i;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n,m;
    cin>>n>>m;
    if(m==n||m==0) cout<<0;
    else{
        long long TwoN,FiveN;
        TwoN=findN(n,2)-(findN(m,2)+findN(n-m,2));
        FiveN=findN(n,5)-(findN(m,5)+findN(n-m,5));
        cout<<min(TwoN,FiveN);
    }
    
    return 0;
}