//hyunji.erica 
/*
n = 1  ugly = [1]
n = 2  1*2 1*3 1*5 [1,2]
n = 3  2*2 1*3 1*5 [1,2,3]
n = 4  2*2 2*3 1*5 [1,2,3,4]
n = 5  3*2 2*3 1*5 [1,2,3,4,5]
n = 6  3*2 2*3 2*5 [1,2,3,4,5,6]
n = 7  4*2 3*3 2*5 [1,2,3,4,5,6,8]
n = 8  5*2 3*3 2*5 [1,2,3,4,5,6,8,9]
n = 9  5*2 4*3 2*5 [1,2,3,4,5,6,8,9,10]
n = 10 6*2 4*3 3*5 [1,2,3,4,5,6,8,9,10,12]
n = 11 7*2 5*3 3*5 [1,2,3,4,5,6,8,9,10,12,15]
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        int two_index = 0;
        int three_index = 0;
        int five_index = 0;

        vector<int> ugly;
        ugly.push_back(1);

        for(int i = 1; i < n ; i++) {
            int two_tmp = ugly[two_index] * 2;
            int three_tmp = ugly[three_index] * 3;
            int five_tmp = ugly[five_index] * 5;

            int res = min(two_tmp, min(three_tmp, five_tmp));
            ugly.push_back(res);

            if(res == two_tmp) two_index++;
            if(res == three_tmp) three_index++;
            if(res == five_tmp) five_index++;
        }

        return ugly[n-1];
    }
};
