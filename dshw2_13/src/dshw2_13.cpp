#include <iostream>
using namespace std;
#include <string>
#include <fstream>

template <class T>
class stack
{
private:
	int maxSize; //the maxsize of stack
	int itop;   //the position of stack's top
	T *st;		//storing stack's elements
public:
	/*one constructor*/
	stack(){
		maxSize = 20;   //the default value of maxsize is 20
		st = new T[20]; //allocate space for stack
		itop = -1;     //the initial value of itop is -1
	}
	/*one overload of constructor*/
	stack(int size){
		maxSize = size;
		itop = -1;
		st = new T[maxSize];
	}
	 /*destructor*/
	~stack(){
		delete [] st;
	}
	/* Pop an element from the top of the stack*/
	void pop(){
		if(itop == -1){
			cout<<"The stack is empty!"<<endl;
		}
		else{
			itop--;
		}
	}
	/*Push this element into the stack*/
	void push(const T & e){
		if(itop == maxSize -1){
			cout<<"The stack is overflow!"<<endl;
		}
		else{
			st[++itop] = e;
		}
	}
	 /*Return the top element of the stack*/
	T top() {
		T item;
		if (itop == -1) {
			cout << "The stack is empty." << endl;
			return item;
		} else {
			item = st[itop];
			return item;
		}
	}
	/*If the stack is empty, return true; otherwise return false.*/
	bool Isempty(){
		if(itop==-1){
			return true;
		}else{
			return false;
		}
	}
	/*Return the number of the elements in the stack*/
	int size() const{
		return (itop+1);
	}
};

bool delimiterMatching(char* filename){
	string exp; //storing expression
	fstream file(filename,ios::in); //open file
	file>>exp;    //read file into exp
	file.close(); //close file
	cout<<exp<<":"; //print exp
	stack<char> sta;
	/*check elements of exp one by one*/
	for(int i=0;exp[i]!='\0';i++){
		/*check parentheses*/
		if(exp[i]=='('){
			sta.push(exp[i]);
		}
		else if(exp[i]==')'){
			if(sta.Isempty() || sta.top()!='('){ return false;}
			sta.pop();
		}
		/*check brackets*/
		if(exp[i]=='['){
				sta.push(exp[i]);
			}
			else if(exp[i]==']'){
				if(sta.Isempty() || sta.top()!='['){ return false;}
				sta.pop();
			}
		/*check braces*/
		if(exp[i]=='{'){
				sta.push(exp[i]);
			}
			else if(exp[i]=='}'){
				if(sta.Isempty() || sta.top()!='{'){ return false;}
				sta.pop();
			}
	}
	/*check whether the stack is empty in the end*/
	if(sta.Isempty()){
		return true;
	}else{
		return false;
	}
}
int main() {
	/*tests of the delimiterMatching function*/
	if(delimiterMatching("/home/cxy229/text0")){ //file path and name as the function parameter
		cout<<"delimiterMatching succeed!"<<endl;
	}else{
		cout<<"delimiterMatching fail!"<<endl;
	}
	if(delimiterMatching("/home/cxy229/text1")){
		cout<<"delimiterMatching succeed!"<<endl;
	}else{
		cout<<"delimiterMatching fail!"<<endl;
	}
	return 0;
}
