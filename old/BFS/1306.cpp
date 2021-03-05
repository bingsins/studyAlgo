class Solution {
public:    
    bool canReach(vector<int>& arr, int start) {
        std::queue<int> q;
        int arr_size = arr.size();
         
        q.push(start);
        
        while(q.empty() == false){
            int node = q.front();
            q.pop();
            
            if(arr[node] == 0){
                return true;   
            }
            
            if(arr[node] < 0)
                continue;
            
            int next_index = node - arr[node];            
            if(next_index >= 0)
            {
                q.push(next_index);
            }   
            next_index = node + arr[node];
            if(next_index < arr_size)
            {
                q.push(next_index);
            }
            arr[node] = -1;
        }
           return false; 
    }
};
