//hyunji.erica - 완주하지 못한 선수
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<string>::iterator iter;
    vector<string>::iterator findIter;
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    findIter = completion.begin();
    for(iter=participant.begin(); iter != participant.end(); iter++){
        if(*iter == *findIter){
            findIter++;
        }else{
            answer = *iter;
            break;
        }
        
    }
    
    /*
    for(iter = participant.begin(); iter !=participant.end(); iter++) {
        findIter = find(completion.begin(), completion.end(), *iter);
        if(findIter == completion.end()){
            answer = *iter;
            break;
        }else{
            completion.erase(findIter);
        }
    }*/
    return answer;
}
