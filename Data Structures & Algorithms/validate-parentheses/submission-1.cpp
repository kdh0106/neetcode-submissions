#include<iostream>
#include<stack>

bool isopen(char c){
    if(c == '(' || c == '{' || c == '[')
        return true;
    return false;
}

bool canclose(char c1, char c2){
    if(c1 == ')' && c2 == '(')
        return true;
    else if(c1 == '}' && c2 == '{')
        return true;
    else if(c1 == ']' && c2 == '[')
        return true;
    return false;
}

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.length(); i++){
            if(i == 0){
                stk.push(s[i]);
                continue;
            }
            if(isopen(s[i]))
                stk.push(s[i]);
            else if(stk.empty())
                return false;
            else if(canclose(s[i], stk.top())){
                stk.pop();
            }
            else
                return false;
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};
