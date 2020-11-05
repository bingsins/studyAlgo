class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        while(arr.size()>1)
        {
            int idx,prod;
            int min = INT_MAX;
            for(int i=0;i<arr.size()-1;i++)
            {
                prod = arr[i] * arr[i+1];
                if(min > prod)
                {
                    min = prod;
                    if(arr[i]<arr[i+1]) idx = i;
                    else idx = i+1;
                }
            }
            sum += min;
            arr.erase(arr.begin() + idx);
        }
        return sum;
    }
};
