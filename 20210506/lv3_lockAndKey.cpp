#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key){
    int size = key.size();
    vector < vector <int> > tmp(size,vector <int>(size,0)); 
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            tmp[i][j] = key[size-j-1][i];
        }
    }
    return tmp;
}

bool check(int x, int y, int lock_size, vector<vector<int>>key, vector<vector<int>> padded_lock){
    int key_size = key.size();
    int size = padded_lock.size();

    for (int i=x; i<x+key_size; i++) {
        for (int j=y; j<y+key_size; j++) {
            padded_lock[i][j] += key[i-x][j-y];
        }
    }

    for (int i=key_size-1; i<lock_size+key_size-1; i++) {
        for (int j=key_size-1; j<lock_size+key_size-1; j++) {
            if (padded_lock[i][j] == 1) continue;
            return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int lock_size = lock.size();
    int key_size = key.size();
    int size = lock_size + 2*(key_size-1);

    vector < vector <int> > padded_lock(size,vector <int>(size,0));

    for(int i=key_size-1; i<=size-key_size; i++) {
        for(int j=key_size-1; j<=size-key_size; j++) {
            padded_lock[i][j] = lock[i-key_size+1][j-key_size+1];
        }
    }

    for(int r=0; r<4; r++) {
        for(int i=0; i<=size-key_size; i++) {
            for(int j=0; j<=size-key_size; j++) {
                if(check(i, j, lock_size, key, padded_lock)) {
                    answer = true;
                    return answer;
                }
            }
        }
        key = rotate(key);
    }
    return answer;
}

