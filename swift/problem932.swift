//ref: Divide and Conquer
//https://leetcode.com/problems/beautiful-array/solution/
class Solution {
    private var cache = [Int:[Int]]()
    
    func beautifulArray(_ N: Int) -> [Int] {
        self.cache = [Int:[Int]]()
        return form(N)
    }
    
    private func form(_ N: Int) -> [Int] {
        if (cache[N] != nil) {
            return cache[N]!
        }
        
        var ans = [Int](repeating: 0, count: N)
        
        if (N == 1) {
            ans[0] = 1
        } else {
            var idx = 0
            for x in form((N+1)/2) {
                ans[idx] = 2*x - 1
                idx += 1
            }
            for x in form(N/2) {
                ans[idx] = x*2
                idx += 1
            }
        }
        cache[N] = ans
        
        return ans
    }
}
