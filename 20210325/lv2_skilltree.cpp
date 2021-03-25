#include <string>
#include <iostream>
#include <vector>

using namespace std;

int chekSkills(string skill, string trees){
    int exIndex = -9999;
    
    for(int i = 0; i < skill.size(); i++){
        for(int j = 0; j < trees.size(); j++){
            if(skill[i] == trees[j]){
                    if(exIndex < j) {
                        if(exIndex == -1){
                            return 0; 
                        }else{
                            exIndex= j;
                            break;
                        }
                    }else{
                        return 0; 
                    }
                }
            else{
                if(j  == trees.size()-1){
                    exIndex= -1;
                }
            }
        }
    }
    return 1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(string trees:skill_trees){
        answer += chekSkills(skill,trees );
    }
    
    return answer;
}