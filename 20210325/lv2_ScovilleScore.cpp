#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<scoville.size();i++){
        pq.push(scoville[i]);
    }    
    
    while(1){
        if(pq.top() >= K)
            return answer;
        
        if(pq.size() == 1)
            return -1;
        int min_val = pq.top();
        pq.pop();
        int second_min_val = pq.top();
        pq.pop();
        int new_scoville = min_val + (second_min_val*2);
        pq.push(new_scoville);
        answer++;
    }
    
    return answer;
}
