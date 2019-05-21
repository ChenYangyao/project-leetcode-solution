//should be simple problem
class Solution {
    func findPoisonedDuration(_ timeSeries: [Int], _ duration: Int) -> Int {
        if timeSeries.isEmpty {
            return 0
        }
        
        var ans = duration
        
        for idx in 1..<timeSeries.count {
            ans += min(timeSeries[idx]-timeSeries[idx-1], duration)
        }
        
        return ans
    }
}
