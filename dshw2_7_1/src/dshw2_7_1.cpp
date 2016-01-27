//============================================================================
// Name        : dshw2_7_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stack>
#include <string>

class Calculator{
public:
	double calculate(string InfixExp){
		Calculator::InfixExp = InfixExp;
		PostfixExp.clear();
		res = 0;
		infix_to_suffix(InfixExp);
		cal_suffix(PostfixExp);
		return res;
	}
	double res;
	string InfixExp,PostfixExp;
private:
	void infix_to_suffix(string exp){
		i=0;
		stack<char> sta;
		for (;;i++) {
			if (exp[i] == '\0') {
				for(;!sta.empty();){
					if(sta.top()=='('){cout<<"error1!!!"<<endl;return;}
					PostfixExp += sta.top();
					sta.pop();
				}
				return;
			}
			if (exp[i] >= '0' && exp[i] <= '9') { //是数字
				PostfixExp += exp[i];
			} else {
				PostfixExp += ' ';
				if(exp[i]=='('){
					sta.push(exp[i]);
				}else if(exp[i]==')'){
					if(sta.empty()){cout<<"error2!!!"<<endl;return;}
					for(;sta.top()!='('&&!sta.empty();){
						PostfixExp += sta.top();
						sta.pop();
					}
					if (sta.top() == '(') {
						sta.pop();
					}else{
						cout<<"error3!!!"<<endl;
						return;
					}
				}else{
					for(;!sta.empty() && sta.top()!='(' && !((exp[i]=='*'||exp[i]=='/')&&(sta.top()=='+'||sta.top()=='-'));){
						PostfixExp += sta.top();
						sta.pop();
					}
					sta.push(exp[i]);
				}
			}
		}
	}
	void cal_suffix(string exp){
		i=0;
		stack<double> sta;

		for(;exp[i]!='\0';i++){
			int t=0,tt=1;
			if(exp[i]>='0'&&exp[i]<='9'){
				for(;exp[i]>='0'&&exp[i]<='9';i++){
					t=t*tt+(exp[i]-'0');
					tt*=10;
				}
				sta.push(t);
			}
			if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
				int num2=sta.top();
				sta.pop();
				int num1=sta.top();
				sta.pop();
				sta.push(cal(num1,num2,exp[i]));
			}
		}
		res = sta.top();
	}
	double cal(double num1,double num2,char op){
		if(op=='+'){
			return num1+num2;
		}else if(op=='-'){
			return num1-num2;
		}else if(op=='*'){
			return num1*num2;
		}else if(op=='/'){
			return num1/num2;
		}else{
			return 0;
		}
	}

	int i;

};

int main() {
	Calculator calcu;//(28*(34-33))
	double result;
	result = calcu.calculate("23+(34*45)/(5+6+7)");//23+(34*45)/(5+6+7)
	cout<<calcu.InfixExp<<endl;
	cout<<calcu.PostfixExp<<endl;
	cout<<result<<endl;
	return 0;
}
