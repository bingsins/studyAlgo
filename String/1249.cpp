//hyunji.erica - 1249.Minimum Remove to Make Valid Parentheses
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //The first character in a string is denoted by a value of 0 (not 1).
        //http://www.cplusplus.com/reference/string/string/operator[]/
        stack<int> par_idx;
        for (int i=0; i<s.length(); ++i) {
            if(s[i] == '('){
                par_idx.push(i);
            }else if(s[i] == ')') {
                if( par_idx.empty() == false && s[par_idx.top()] == '(') {
                    par_idx.pop();
                }else
                    par_idx.push(i);
            }
         }
        
        unordered_set<int> remove_idx;
        while( par_idx.empty() == false ) {
            remove_idx.insert(par_idx.top());
            par_idx.pop();
        }
        
        string ans;
        for(int i=0; i<s.length(); ++i) {
            if( remove_idx.count(i) == 0 )
                ans.push_back(s[i]);
        }
        return ans;
    }
};
