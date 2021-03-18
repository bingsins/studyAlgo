#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    
    int current_weights=0;
    int answer=0, index = 0;
    //int *array = new int[bridge_length];
    queue<int> current;
    
    while(true){
        
        if(index == truck_weights.size()){
            break;
        }
        
        answer++;
        if(current.size() ==bridge_length){
            current_weights-=current.front();
            current.pop();
        }

        
        if(current_weights + truck_weights[index]  <= weight){
            current.push(truck_weights[index]);
            current_weights+=truck_weights[index];
            index++;
        }else{
            current.push(0);
        }

    }
    
    return answer + bridge_length;
}