//songi
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int temp=0;
    for(int i = 0; i < prices.size(); i++){
        temp =0;
        for(int j = i+1; j < prices.size(); j++){
            temp++;
            if(prices[i] > prices[j])
                break;
        }
        answer.push_back(temp);            
    }
    //answer.push_back(0);
    return answer;
}