#include <iostream>
using namespace std;
int a,b;
string original_s = "____";

void chatbot(string s){
	if (a == 0) {
		cout << s << "\"재귀함수가 뭔가요?\"" << endl;
		cout << s << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
		cout << s << "라고 답변하였지." << endl;
		return ;
	}
	cout << s << "\"재귀함수가 뭔가요?\"" << endl;
	cout << s << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << endl;	
	cout << s << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
	cout << s << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;
	a--;
	chatbot(original_s+s);
}
void answer(void){
	if (b == 0) return ;
	
	string new_s = "";
	for (int i=0; i<b-1; i++){
		new_s = new_s + original_s;
	}
	cout << new_s << "라고 답변하였지." << endl;
	b--;
	answer();
}
int main(void){
	cin >> a;
	//a = 4;
	b = a;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl; 
	chatbot("");
	answer();
	return 0;
}
