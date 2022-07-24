#include<iostream>
#include<cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    int P[1001];
    for(int i=1;i<=N;i++){
        cin>>P[i];
    }
    int dp[N+1]={0,};
    for(int i=1;i<=N;i++){
        int max=P[i];
        for(int j=1;j<=i/2;j++){
            if(dp[i-j]+dp[j]>max){
                max=dp[i-j]+dp[j];
            }
        }
        dp[i]=max;
    }

    cout<<dp[N];




    return 0;
}