//784.Letter Case Permutation
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> results;
        dfs(S, 0, results);
        return results;
    }
    void dfs(string s, int idx, vector<string> &results) {
        if(idx==s.size()) {
            results.push_back(s);
            return;
        }
        if(isalpha(s[idx]))
        {
            s[idx] = tolower(s[idx]);
            dfs(s,idx+1,results);
            s[idx] = toupper(s[idx]);
            dfs(s,idx+1,results);
        }
        else
            dfs(s,idx+1,results);
    }
};
