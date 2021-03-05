class Solution {
public:

    unordered_set<string> answer;
    
    int numTilePossibilities(string tiles) {
        dfs("", tiles);

        return answer.size()-1;
        
    }
    void dfs(string current, string remind){
        answer.insert(current);
         for(int i = 0; i< remind.length(); i++){
            string temp_curr = current,temp_re = remind ;
             
            temp_curr  = temp_curr + remind[i];
            temp_re.erase(i,1);
             
            dfs(temp_curr, temp_re);
        }
    }
};