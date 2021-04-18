#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string current, vector<vector<string>> ticket_list, vector<string> &answer, vector<bool> &visit, int ticket_cnt){
    
    answer.push_back(current);
    if(ticket_cnt == ticket_list.size()) return true;
    
    for(int i = 0; i < ticket_list.size(); i++){
        if(ticket_list[i][0] == current && visit[i] == false){
            visit[i] = true;
            bool success = dfs(ticket_list[i][1], ticket_list, answer, visit, ticket_cnt+1);
            if(success == true)
                return true;
            visit[i] = false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visit(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, answer, visit, 0);
    return answer;
}
