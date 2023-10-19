class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "";
        string s2 = "";
        stack<char> st1;
        stack<char> st2;
        for(int i=0;i<s.length();i++){
            if(st1.empty() && s[i] == '#'){
                continue;
            }
            else if(st1.empty()){
                st1.push(s[i]);
            }
            else if(!st1.empty() && s[i] == '#'){
                st1.pop();
            }
            else{
                st1.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(st2.empty() && t[i] == '#'){
                continue;
            }
            else if(st2.empty()){
                st2.push(t[i]);
            }
            else if(!st2.empty() && t[i] == '#'){
                st2.pop();
            }
            else{
                st2.push(t[i]);
            }
        }
        while(!st1.empty()){
            s1 = st1.top() + s1;
            st1.pop();
        }
        while(!st2.empty()){
            s2 = st2.top() + s2;
            st2.pop();
        }
        return s1 == s2;
    }
};