//songi
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> gems_set(gems.begin(), gems.end());
    int start =0, end=0; 
    unordered_map<string,int> temp;
    int diffrent = INT_MAX;

    answer.push_back(start);
    answer.push_back(end);
 
 
    while(true){

        if(temp.size() >= gems_set.size()){
            temp[gems[start]]--;
            if(temp[gems[start]]  == 0)
                temp.erase(gems[start]);
            start++;
        }else if(end == gems.size()){
            break;
        }
        else{
            temp[gems[end]]++;
            end++;
        }
 
        if(temp.size() == gems_set.size()){
            if( end - start > 0 && end - start < diffrent){
                diffrent  = end - start;
                answer[0]=start+1;
                answer[1]=end;
            }
        }
    }

 
    return answer;
}