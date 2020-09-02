class Solution {
public:
    typedef pair<float ,pair<int , int>> pi;
    priority_queue<pi, vector<pi>, greater<pi> > Q;
    vector<vector<int>> answer; 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        for(int i=0 ; i<points.size() ; i++){
        int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        Q.push({distance,{points[i][0],points[i][1]}});
        }
        //cout << Q.top().first << " ";
        for(int i=0 ; i<K ; i++){
            answer.push_back({Q.top().second.first,Q.top().second.second});       
            Q.pop();
        }
        
        return answer;
    }
};

// class Solution {
// public:
    //priority_queue<int, vector<int>, greater<int>> Q;
    //priority_queue< pair<float ,pair<int , int>>, greater<int> > Q ;
//     vector<vector<int>> answer ; 
//     priority_queue< pair<float ,pair<int , int>>> Q;
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//         for(int i=0 ; i<points.size() ; i++){
//         int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
//         Q.push({distance,{points[i][0],points[i][1]}});
//         }
        
//         //cout << Q.top().first << " ";
//         for(int i=0 ; i<K ; i++){
//             answer.push_back({Q.top().second.first,Q.top().second.second});       
//             Q.pop();
//         }
        
//         return answer;
//     }
//         vector<vector<int>> answer ; 
//     vector< pair<float ,pair<int , int>>> Q;
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//         for(int i=0 ; i<points.size() ; i++){
//         int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
//         Q.push_back({distance,{points[i][0],points[i][1]}});
//         }
        
//         //cout << Q.top().first << " ";
//         sort(Q.begin(), Q.end());
//         for(int i=0 ; i<K ; i++){
//             answer.push_back({ Q[i].second.first, Q[i].second.second});       
//         }
        
//         return answer;
//     }
};