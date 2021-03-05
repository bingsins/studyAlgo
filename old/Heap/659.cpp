class Solution {
public:
    bool isPossible(vector<int>& nums) {
       map<int, int> frequency; 
        for(auto i : nums) frequency[i]++;
        
        
        for(int i=nums.size()-1;i>=0;i--) {
            int n=nums[i],count;
            
            if(frequency[n]==0) continue;      
            
            for(count=0;frequency[n]--<=frequency[n-1];n--,count++){
                ;
            }
            
            if(count<2) 
                return false;
        }
        
        
        return true;
    }
}; 



class Solution {
public:
    bool isPossible(vector<int>& nums) {
        typedef vector<vector<int>> pi;
        priority_queue<pi, vector<pi>, greater<pi> > Q;
        //priority_queue<vector<vector<int>> , greater<vector<vector<int>> > > Q;
        //int count = 0;
        // for (auto element: nums){
        //     // cout << element << endl;
        //     if(!Q.size())
        //         Q.push(element);
        //     if(Q.top() == element){
        //         count++;
        //         //Q.pop();
        //     }else{
        //         Q.push(element);
        //         //Q.pop();
        //     }
        // }
        // while (!Q.empty()){
        // cout << Q.top() << endl;
        // Q.pop();
        // }
        // cout << count << endl;
        // if(count >= 2)
        //     return true;
        // else 
            return false;
            
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<vector<vector<int>> , greater<vector<vector<int>> > > Q;
        //int count = 0;
        for (auto element: nums){
            // cout << element << endl;
            if(!Q.size())
                Q.push(element);
            if(Q.top() == element){
                count++;
                //Q.pop();
            }else{
                Q.push(element);
                //Q.pop();
            }
        }
        while (!Q.empty()){
        cout << Q.top() << endl;
        Q.pop();
        }
        cout << count << endl;
        if(count >= 2)
            return true;
        else 
            return false;
            
    }
};



class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // typedef vector<vector<int>> pi;
        // priority_queue<pi, vector<pi>, greater<pi> > Q;
        priority_queue< vector<int>  , greater<  int> > Q;
        int count = 0;
        for (auto element: nums){
            // cout << element << endl;
            if(!Q.size())
                Q.push(element);
            if(Q.top() == element){
                count++;
                //Q.pop();
            }else{
                Q.push(element);
                //Q.pop();
            }
        }
        // while (!Q.empty()){
        // cout << Q.top() << endl;
        // Q.pop();
        // }
        cout << count << endl;
        if(Q.size() >= 3)
            return true;
        else 
            return false;
            
    }
};


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<int, vector<int>  , greater<  int> > Q;
        int count = 0;
        for (auto element: nums){
            // cout << element << endl;
            if(!Q.size())
                Q.push(element);
            if(Q.top() == element){
                count++;
                //Q.pop();
            }else{
                Q.push(element);
                //Q.pop();
            }
        }
        while (!Q.empty()){
        cout << Q.top() << endl;
        Q.pop();
        }
        if(nums.size() >= 3)
            return true;
        else 
            return false;
            
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // typedef vector<vector<int>> pi;
        // priority_queue<pi, vector<pi>, greater<pi> > Q;
        //priority_queue<vector<vector<int>> , greater<vector<vector<int>> > > Q;
        int index = 0;
        
        map<int,int> M;
        map<int, int>::iterator it;
        
        vector<vector<int>> answer;
        answer.resize(2);
        int i;
        
        for (auto &element: nums){
            M[element]+=1;
        }
        
        // for ( const auto &element : M )
        // {
        //    cout << element.first << '\t' << element.second << endl;
        // } 
        
        
         for ( const auto &element : M )
        {
             
             if(element.second > 1){
                 index++;
                  for(int j=0;j<element.second;j++)
                      answer[j].push_back(element.first);
             }
             
             if(element.second == 1){
                 answer[index].push_back(element.first);
             }
         }
            for(int i=0;i<answer.size();i++){
                for(int j=0;j<answer[i].size();j++)
                    cout<<answer[i][j]<<" ";
                cout<<endl;
            } 
        
        for (int i=0; i<answer.size(); i++) {
            cout<<answer[i].size()<<" ";
            if(answer[i].size() >= 3 ||answer[i].size() ==0 ) ; 
                else return false;
        }
        return true;
             
             
             
//             answer[i].push(element.first);
//             cout << element.first << '\t' << element.second << endl;
             
//             if(!answer[index].size()){
//             answer[index].push(element.first);
//             --element.second;
//             }
             
//              if(answer[index].size() && answer[index].back() == element.first){
//                  index++;
                 
//              }else{
//                  answer[index].push(element.first);
//                  --element.second;
//              }
        // } 

        
                // while (!Q.empty()){
        // cout << Q.top() << endl;
        // Q.pop();
        // }
        // for (auto element: nums){
        //     // cout << element << endl;
        //     if(!Q[index].size())
        //         Q[index].push(element);
        //     if(Q[index].top() == element){
        //         index++;
        //         //Q.pop();
        //     }else{
        //         Q[index].push(element);
        //         //Q.pop();
        //     }
        // }
        // while (!Q.empty()){
        // cout << Q.top() << endl;
        // Q.pop();
        // }
        // cout << count << endl;
        // if(count >= 2)
        //     return true;
        // else 
            // return false;
            
    }
};


// class Solution {
// public:
//     bool isPossible(vector<int>& nums) {
        
//         map<int, int> frequency; 
        
//         for(auto i : nums) frequency[i]++;
        
//         for(auto i : nums)
//         {
//             if(frequency[i] == 0) continue;
//             else if(frequency[i] > 0 && frequency[i+1] > 0 && frequency[i+2] > 0)
//             {
//                 frequency[i]--;
//                 frequency[i+1]--;
//                 frequency[i+2]--;
//             }
//             else return false;
//         }
//         return true;
        
//     }
// };