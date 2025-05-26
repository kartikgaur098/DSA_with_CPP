class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int l=0;
     int r=1;
     int maxProfit=0;
     while(r<prices.size()){
        if(prices[r]>prices[l]){
            int Profit=prices[r]-prices[l];
            maxProfit=max(maxProfit,Profit);
        }
        else{
            l=r;
        }
        r++;
     }
     return maxProfit;
    }
};