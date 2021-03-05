class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(auto x : nums) 
            umap[x]+=1;
        
        vector<pair<int, int>> data;
        for (auto x : umap) 
            data.push_back(make_pair(x.second, x.first));
        
        sort(data.begin(), data.end(), greater());

        vector<int> result;
        for(int i=0;i<k;i++) 
            result.push_back(data[i].second);
        
        return result;
    
    }
};
