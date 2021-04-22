#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> word;
    word.insert(make_pair(words[0],1));
    
    for(int i=1; i<words.size();i++){
        if( word.count(words[i]) != 0 || words[i].front() != words[i-1].back()) {
            return {(i%n)+1, (i/n)+1};
        }
        word.insert(make_pair(words[i],1));
    }

    return {0,0};
}
