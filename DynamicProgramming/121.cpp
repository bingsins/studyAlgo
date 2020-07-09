#include <string>
#include <iostream>

using namespace std;

// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {

//         int minPrice = INT_MAX, MaxProfit = 0;

//         for (std::vector<int>::size_type i = 0; i < prices.size(); i++)
//         {
//             if (prices[i] < minPrice)
//                 minPrice = prices[i];
//             MaxProfit = max(MaxProfit, prices[i] - minPrice);
//         }

//         return MaxProfit;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX, MaxProfit = 0 ;
        
    for (std::vector<int>::size_type i = 0; i < prices.size(); i++) {
        if(prices[i] < minPrice)
            minPrice = prices[i];
        //std::cout << "minPrice:" << minPrice;
            //std::cout << "prices[i] - minPrice:" << prices[i] - minPrice  ;
        //std::cout << "MaxProfit:" << MaxProfit << std::endl;
        if(MaxProfit <  prices[i] - minPrice){
            MaxProfit = prices[i] - minPrice;
            //std::cout << "MaxProfit:" << MaxProfit << std::endl;
        }
    }
        return MaxProfit;
    }
};