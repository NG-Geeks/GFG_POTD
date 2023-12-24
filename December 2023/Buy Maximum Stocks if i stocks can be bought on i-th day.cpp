Question :: Buy Maximum Stocks if i stocks can be bought on i-th day


In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where price[i] denotes the price of the stock on the ith day.
There is a rule that a customer can buy at most i stock on the ith day.
If the customer has an amount of k amount of money initially. The task is to find out the maximum number of stocks a customer can buy. 
Solution::
class Solution {
    bool static cmp(pair<int,int>&a , pair<int,int>&b){
        if(a.first==b.first)return a.second<b.second;
        return a.first<b.first;
    }
public:
    int buyMaximumProducts(int n, int k, int prices[]){
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({prices[i] , i+1});
        }
        sort(begin(v) , end(v) , cmp);
        int cnt =0;
        for(auto &i:v){
            while(i.first<=k && i.second--){
                k = k-i.first;
                cnt++;
            }
        }
        return cnt;
    }
};
