//songi
#include <string>
#include <vector>

using namespace std;

int seperate(string p){
    int l =0 ,r =0 ;
    for(int i =0; i < p.length(); i++){
        if(p[i] == '(') l++;
        else r++;
        if(l == r) return i;
    }
    return p.length();
}

bool isValid(string x){
    int l =1 ,r =0 ;
    if(x[0] == ')')
        return false;

    for(int i =1; i < x.length(); i++){
        if(x[i] == '(') l++;
        else r++;
    }
    if(l == r) return true;
    else return false;
    
}

string flip_u(string x){
    x.pop_back();
    x.erase(0,1);
    for(int i = 0; i < x.length(); i++){
        if(x[i] == '(') x[i] = ')';
        else x[i] = '(';
    }
    return x;
}

string solution(string p) {
    string answer = "", u ="", v = "";
    int index = 0; 
    
    if(p.length() == 0)
        return answer;
    
    index = seperate(p);
    
    u = p.substr(0,index+1);
    v = p.substr(index+1, p.length());
    
    if(isValid(u)){
        answer = u + solution(v);
        return answer;
    }else{
        answer += "(" + solution(v) + ")";
        answer += flip_u(u);
    }
    return answer;
}