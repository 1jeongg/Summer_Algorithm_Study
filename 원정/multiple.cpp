#include <iostream>
using namespace std;

long long multiple(long long a, long long b, long long c){
	
	if (b == 1) 
	   return a%c;
	
	long long x = multiple(a, b/2,c);
	x = (x*x)%c;
	
	if (b % 2) x = (x*a)%c;
	return x;
	
	
}
int main(void){
	long long A,B,C;
	cin >> A >> B >> C;
	cout << multiple(A,B,C);
	return 0;

}
 
