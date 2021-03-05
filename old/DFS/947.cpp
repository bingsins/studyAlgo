class Solution {
public:
    void connectStone(int i, int j, vector<int>& parent){
        int x = findRoot(i, parent);
        int y = findRoot(j, parent);
        
        parent[x] = y;
    }
    
    int findRoot(int i, vector<int>& parent){
        if(parent[i] != i)
            i = findRoot(parent[i], parent);
        
        return i;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        vector<int> parent(N,0);
        
        for(int i = 0; i < N; i++)  parent[i] = i;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    connectStone(i, j, parent);
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < N; i++){
            if(parent[i] == i) res++;
        }
        return N-res;
    }
};
