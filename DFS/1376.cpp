class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int result = 0;
        vector<vector<int>> subordinates(n); 
        
        for (int i = 0; i < manager.size(); i++)
            if (manager[i] != -1) subordinates[manager[i]].push_back(i);
        
        
// for (int i = 0; i < subordinates.size(); ++i)
// {
//     for (int j = 0; j < subordinates [i].size () ; ++j)
//         cout << subordinates[i][j] << ' ';
//     cout << endl;
// }
            
        result = DFS(headID, subordinates, informTime);
 
        return result;
    }
    
        int DFS(int start, vector<vector<int>> &subordinates,  vector<int>& informTime ) {
            int maxNum = 0;
            //for (auto i:subordinates[start])
            //maxNum = max(maxNum, DFS(i, subordinates, informTime));
            for (int i = 0; i < subordinates[start].size(); i++)
                maxNum = max(maxNum, DFS(subordinates[start][i], subordinates, informTime));
                
        return informTime[start]+maxNum;
    }
};