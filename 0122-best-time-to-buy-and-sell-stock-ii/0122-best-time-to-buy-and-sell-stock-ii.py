class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        profit=0          
        buy=10**9
        sell=0
        for i in prices:
            if(i<buy):
                buy=i
            if(i>buy):
                sell=i
                profit +=sell-buy
                buy=i
        return profit  