class Cashier {
public:
    unordered_map<int,int> stock;
    int dis, nums, count =0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        dis = discount;
        nums = n;
        count = 0;
    for (int i = 0; i < products.size(); ++i) {
        stock[products[i]]=prices[i];
    }

    }
    
    double getBill(vector<int> product, vector<int> amount) {
        count++; 
        double result=0;
        for (int i = 0; i < product.size(); ++i) {
        result += stock[product[i]] * amount[i];
           
        }
        
        if(count%nums == 0 ){
            
            count = 0;
            result = result - ((dis*result)/100.0);
        // result = ((dis * result) / 100);
        }
            
        return result;
            
    }
};

static int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */