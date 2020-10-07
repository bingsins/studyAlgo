//hyunji.erica - 833.Find And Replace in String
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
		string ans = "";
        unordered_map<int,int> tmp_map;
		
		for(int i = 0; i<indexes.size(); i++){
		    if(S.substr(indexes[i], sources[i].length()) == sources[i])
                tmp_map.insert(make_pair(indexes[i], i));
		}
        for(int i = 0; i<S.length();){
            if(tmp_map.count(i)){
                ans += targets[tmp_map[i]];
                i += sources[tmp_map[i]].length();
            }else{
                ans += S[i];
                i++;
            }
        }
        return ans;
    }
};
