//ref: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/
//Approach 1
class Solution {
    func maxProfit(_ prices: [Int], _ fee: Int) -> Int {
        var cash = 0; var hold = -prices[0]
        
        for date in 1..<prices.count {
            cash = max(cash, hold + prices[date] - fee)
            hold = max(hold, cash - prices[date])
        }
        
        return cash
    }
}
