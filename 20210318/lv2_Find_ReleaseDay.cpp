//hyunji.erica - lv2. find relase day through progress&speed
#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 0;
    int max_day = 0;
    for(int i =0; i<progresses.size() ; i++){
        day = (99 - progresses[i]) / speeds[i] ;
        
        if(answer.empty() || max_day < day){
            answer.push_back(1);
        }else{
            (answer.back())++;
        }
        if(max_day < day)
            max_day = day;
        
    }
    
    return answer;
}

/*
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;   
    vector<int> release_day(progresses.size(), -1);
    int day = 0, cnt = 0; 
    while(1){
        if(cnt == progresses.size())
            break;
        for(int i = 0; i< progresses.size(); i++){
            progresses[i] += speeds[i];
            if( progresses[i] >=100 && release_day[i] == -1){
                release_day[i] = day;
                cnt++;
            }
        }
        day++;
    }
    
    int max = 0;
    for(int i =0; i<release_day.size(); i++){
        if(release_day[i] >= max){
            max = release_day[i];
        }
            release_day[i] = max;
    }
    cnt = 1;
    int prev = release_day[0];
    for(int i = 1; i < release_day.size(); i++){
        
        if(prev != release_day[i]){
            answer.push_back(cnt);
            cnt = 1;
        }
        else{
            cnt ++;
        }
        prev = release_day[i];
    }
    answer.push_back(cnt);
    return answer;
}*/
