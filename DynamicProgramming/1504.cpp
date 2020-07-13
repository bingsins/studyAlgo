//1504.Count Submatrices With All Ones 
//@Author : hyunji.erica

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++){
            int c = 0;
            for(int j=m-1; j >= 0; j--){
                if(mat[i][j]) c++;
                else c = 0;
                mat[i][j] = c;
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x = INT_MAX;
                for(int k=i; k<n; k++){
                    if(!mat[k][j]) break;
                    x = min(x,mat[k][j]);
                    ans += x;
                }   
            }
        }
        return ans;
    }
};
