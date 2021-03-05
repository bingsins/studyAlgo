class Solution {
public:
    int numSplits(string s) {
        int answer = 0 ;
        unordered_map<char,int> left, right;
        for (char ch : s) right[ch]++;
        // for(int i=0;i<s.size();i++)
        // {
        //     if(right.count(s[i]))
        //         right[s[i]]++;
        //     else
        //         right[s[i]]=1;
        // }

        for(int i=0;i<s.size();i++)
        {
            // if(left.count(s[i]))
                left[s[i]]++;
            // else
            //     left[s[i]]=1;
            
            right[s[i]]--;
            if(right[s[i]]==0)
                right.erase(s[i]);
            
            if(left.size()==right.size())
            answer++;
        }
        return answer;
    }
};