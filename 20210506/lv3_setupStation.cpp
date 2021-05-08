//songi
//1st code 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    vector<int> range_check(n, false);
    
    for(auto station:stations){
        int start = station-w-1;
        int end = station+w-1;
        for(int i =0; i < range_check.size(); i++)
        {
         if(start <= i && i <= station)  { range_check[i] = true;}
         if(station <= i && i <= end)   range_check[i] = true;
        }
    }
    auto it = find(range_check.begin(), range_check.end(), 0);
    while (it != range_check.end() ){
        answer++;
        for(int i = 0 ;i < (w*2 +1 ); it++, i++){
            *it = true;
        }
    it = find(range_check.begin(), range_check.end(), 0);

    }
    return answer;
}

//2nd code
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1;
    int distance = w*2 +1;
    vector<int> range_check(n, false);
    //sort(stations.begin(), stations.end());
    
    for(auto station:stations){
        int left = station-w;
        int right = station+w;
        
        if(start >= left && start <= right) 
            start = right + 1;
        
        while(start < left){
            if(start + distance-1 < left){
                start = start + distance;
                answer++;
            }else{
                start = right + 1;
                answer++;
            }
        }
    }
    while(start < n+1){
        start = start + distance;
        answer++;
        }
    return answer;
}
//3rd code 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1;
    int distance = w*2 +1;
    //vector<int> range_check(n, false);
    //sort(stations.begin(), stations.end());
    
    for(auto station:stations){
        int left = station-w;
        int right = station+w;
        // answer += ceil((double)(left - start)/distance);
        answer +=  (left - start)/distance;
        if((left - start)%distance > 0)
            answer++;
        start = right + 1;
    }
    if(start < n+1){
        answer +=  (n+1 - start)/distance;
        if((n+1 - start)%distance > 0)
            answer++;
    }
    return answer;
}