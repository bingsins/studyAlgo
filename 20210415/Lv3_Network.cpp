//songi
#include <string>
#include <vector>

using namespace std;
vector<bool> visit (200, false) ;
int nums; 

void dfs( int i, vector<vector<int>> &computers){
    visit[i] = true;
    for (int j=i ; j < nums; j++){
            if(!visit[j] && computers[i][j]){
                dfs(j,  computers);
            }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;    
    nums = n;
    for (int i = 0; i < nums; i++){
        // for (int j = 0; j < n; j++){
            if(!visit[i]){
                answer++;
                dfs(i,  computers);
            }
        // }
    }

    return answer;
}