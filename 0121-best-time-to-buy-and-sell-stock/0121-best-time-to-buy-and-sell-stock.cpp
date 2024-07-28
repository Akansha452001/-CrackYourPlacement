class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buyprice=INT_MAX;
       int maxprofit=INT_MIN;
       for(int i=0;i<prices.size();i++){
        if(buyprice<prices[i]){
            int profit=prices[i]-buyprice;
           maxprofit=max(profit,maxprofit);
        }else{
            buyprice=prices[i];
        }
       }
       return maxprofit==INT_MIN?0:maxprofit;
    }
};