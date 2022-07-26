#include <iostream>
#include <stack>

using namespace std;
int value[26];

int main()
{
	int num, i;
	stack<double>cal;
	string str;
	
	cin >> num;
	cin >> str;
	for(i = 0; i < num ; i++)
	{
		int N;
		cin >> N;
		value[i] = N;
	}
	
	for(i=0; i<str.length();i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			cal.push(value[str[i] - 'A']);	// 문자열이 들어오면 아스키코드로 변경 
		}
		else		// 계산 순서를 고려해야 함 
		{
			double num2 = cal.top();
			cal.pop();
			double num1 = cal.top();
			cal.pop();
			if (str[i] == '*')
			num1 *= num2;
			else if (str[i] == '/')
			num1 /= num2;
			else if (str[i] == '+')
			num1 += num2;
			else num1 -= num2;
			cal.push(num1);
		}
	}
	
	cout.precision(2);	// 소수점 둘째자리 까지 
	cout << fixed << cal.top();
		
	return 0;
}
