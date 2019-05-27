//ref: https://leetcode.com/problems/beautiful-arrangement-ii/solution/
//Approach 2
class Solution {
    func constructArray(_ n: Int, _ k: Int) -> [Int] {
        var ans = [Int](repeating: 0, count: n)
        if (n-k < 1) {
            return []
        }
        
        for i in 1..<(n-k) {
            ans[i-1] = i
        }
        
        for i in 0...k {
            ans[i+n-k-1] = (i%2 == 0) ? (n-k + i/2) : (n - i/2)
        }
        
        return ans
    }
}
