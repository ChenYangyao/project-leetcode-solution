import Foundation

class Solution {
    func climbStairs(_ n: Int) -> Int {
        return lround((pow((1+sqrt(5))/2,Double(n+1))-pow((1-sqrt(5))/2,Double(n+1)))/sqrt(5))
    }
}
