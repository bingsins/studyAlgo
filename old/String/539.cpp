class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int answer = INT_MAX;
        vector<int> seconds;
        
        for (string &tp : timePoints) {
            int h = (tp[0] - '0') * 10 + tp[1] - '0';
            int m = (tp[3] - '0') * 10 + tp[4] - '0';
            //int h = stoi(tp.substr(0, 2)), m = stoi(tp.substr(3, 2));
            seconds.push_back(h * 60 + m);
        }
        
        sort(seconds.begin(), seconds.end());
        
        answer = min(answer, seconds.front() + 24*60 - seconds.back());
        for (int i = 1; i < seconds.size(); ++i){
            //cout<<seconds[i];
            answer = min(answer, seconds[i] - seconds[i - 1]);
        }
        
        return answer;
    }
};