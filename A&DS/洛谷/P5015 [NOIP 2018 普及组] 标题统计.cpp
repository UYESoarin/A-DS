#include<iostream>
//#include<string>
using namespace std;
int answer_GETLINE(string& str){
	getline(cin,str);//for space
	int ans=0;
	for(auto ch:str)if(isalnum(ch))ans++;
	//isdigit islower isupper isalpha
	return ans;
}
int answer_CIN(string& str){
	int ans=0;
	while(cin>>str)ans+=str.size();//<ctrl z> to terminate cin
	return ans;
}
int answer_CINBasedOnFiveChar(){
	char ch;
	int ans=0;
	for(int i=0;i<5;i++)if(cin>>ch)ans++;//ch!=' ' or '\n'
	return ans;
}
int main(){
	string str;
	int ans=answer_CINBasedOnFiveChar();
	cout<<ans;
	return 0;
}
