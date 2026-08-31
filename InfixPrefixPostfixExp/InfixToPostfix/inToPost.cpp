#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string solve(string val1, char op, string val2){
        string ans = "";
        ans += val1;
        ans += val2;
        ans += op;
        return ans;
    }
    bool checkOperand(char term){
        if(term>='a' && term<='z')return true;
        else if(term>='A' && term<='Z')return true;
        else if(term>='0' && term<='9')return true;
        return false;
    }
    int prio(char op){
        if(op == '+' || op == '-')return 1;
        else if(op == '*' || op == '/')return 2;
        return 3;
    }
    string infixToPostfix(string& s) {
        // code here
        int n = s.size();
        stack<string>operand;
        stack<char>operators;
        for(int i=0;i<n;i++){
            char term = s[i];
            if(checkOperand(term))operand.push(string(1, term));
            else if(term=='(')operators.push(term);
            else if(!operators.size()) operators.push(term);
            else if(term == ')'){
                while(!operators.empty() && operators.top() != '('){
                    string val2 = operand.top();
                    operand.pop();
                    string val1 = operand.top();
                    operand.pop();
                    char op = operators.top();
                    operators.pop();
                    string res = solve(val1,op,val2);
                    operand.push(res);
                }
                operators.pop();
            }
            else if(operators.size() && operators.top() == '(')operators.push(term);
            else if(operators.size() && prio(operators.top()) < prio(term))operators.push(term);
            else{
                while(operators.size() && operators.top() != '(' && (prio(term) < prio(operators.top()) || (prio(term) == prio(operators.top()) && term != '^'))){
                    string val2 = operand.top();
                    operand.pop();
                    string val1 = operand.top();
                    operand.pop();
                    char op = operators.top();
                    operators.pop();
                    string res = solve(val1,op,val2);
                    operand.push(res);
                }
                operators.push(term);
            }
        }
        while(!operators.empty()){
            string val2= operand.top();
            operand.pop();
            string val1 = operand.top();
            operand.pop();
            char op = operators.top();
            operators.pop();
            string res = solve(val1,op,val2);
            operand.push(res);
        }
        return operand.top();
    }
};
