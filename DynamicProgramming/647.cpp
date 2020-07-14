#include <string>
#include <iostream>
using namespace std; 

int countSubstrings(string s) {
        int length=s.size();
        int count=0;
        for(int i=0;i<length;i++) {
			//cout <<  "i:"<< i<< "\n";
            for(int size=0;i-size>=0 && i+size<length &&s[i-size]==s[i+size] ;size++) { 
				//if(s[i-size]==s[i+size])
                count++;
				// cout <<  "111111111111111111111\n";
				// cout <<  "size:"<< size<< "\n";
				// cout <<  i-size << i+size<< "\n";
				// cout <<  s[i-size] << s[i+size]<< "\n";
            }
			
		for(int size=1;i-size+1>=0 && i+size<length && s[i-size+1]==s[i+size];size++) { 
                count++;
				// cout <<  "2222222222222222222\n";
				// cout <<  i-size+1 << i+size<< "\n";
				// cout <<  s[i-size+1] << s[i+size]<< "\n";
            }
        }
        return count;
    }

int countSubstrings2(string s) {
        int length=s.size();
        int count=0;
        for(int size=0;size<length;size++) {                  
            for(int i=0; size+i<length;i++) { 
				if(s[ i]==s[size+i])
                count++;
				// cout <<  "111111111111111111111\n";
				// cout <<   i << size+i<< "\n";
				// cout <<  s[ i] << s[size+i]<< "\n";
            }

        }
        return count;
    }

int main() 
{ 
    string str ="aaa"; 
	int count = countSubstrings(str);
	cout << count << "\n"; 
	//int count2 = countSubstrings2(str);
	//cout << count2 << "\n"; 
	
    return 0; 
} 
