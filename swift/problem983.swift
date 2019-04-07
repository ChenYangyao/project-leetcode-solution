//ref: https://leetcode.com/problems/minimum-cost-for-tickets/solution/
//Approach 2
class Solution {
    private var days = [Int]()
    private var costs = [Int]()
    private var cache = [Int:Int]()
    private var length = 0
    private let durations = [1, 7, 30]
    
    func mincostTickets(_ days: [Int], _ costs: [Int]) -> Int {
        self.days = days
        self.costs = costs
        self.length = days.count
        
        defer {
            cache = [:]
        }
        
        return cost(0)
    }
    
    private func cost(_ today: Int) -> Int {
        if (today >= length) {
            return 0
        }
        
        if (cache[today] != nil) {
            return cache[today]!
        }
        
        var tmp = Int.max
        var future = today
        
        for k in 0..<3 {
            while (future < length && days[future] < days[today] + durations[k]) {
                future += 1
            }
            tmp = min(tmp, cost(future) + costs[k])
        }
        
        cache[today] = tmp
        
        return tmp
    }
}
