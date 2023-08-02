#include <iostream>
#include<stack>
using namespace std;

bool isPair(char open,char close){
    if(open == '(' && close == ')')
        return true;
    else if(open == '[' && close == ']')
        return true;
    else if(open == '{' && close == '}')
        return true;
    else
        return false;
}
bool areBalanced(string exp){
    stack<char> s;
    bool f=true;
    for(int i=0; i<exp.length(); i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            s.push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if(s.empty() || !isPair(s.top(),exp[i])){
                f=false;
            }
            else if(isPair(s.top(),exp[i])){
                s.pop();
            }
        }
    }
    if(f==true && s.empty())
        return true;
    else
        return false;
}

int main()
{
    string exp;
    cin>>exp;
    if(areBalanced(exp))
        cout<<"Balanced"<<endl;
    else
        cout<<"Not Balanced"<<endl;
    return 0;
}
