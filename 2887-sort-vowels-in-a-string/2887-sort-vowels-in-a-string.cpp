class Solution {
public:
    string sortVowels(string s) {
        vector<int> chk;
        vector<char> v;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                chk.push_back(i);
                v.push_back(s[i]);
            }
            else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                chk.push_back(i);
                v.push_back(s[i]);
            }
        }
        sort(v.begin(),v.end());
        int x = 0;
        for(auto it:chk){
            s[it] = v[x];
            x++;
        }
        return s;
    }
};