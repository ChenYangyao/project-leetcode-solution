//should be easy problem
class Solution {
    func clumsy(_ N: Int) -> Int {
        var N = N
        
        if (N < 4) {
            return res[N]
        }
        
        var ans = calc(&N) + (N+1)*2
        
        while (N >= 4) {
            ans -= calc(&N)
        }
        
        return ans - res[N]
    }
    
    private let res = [0, 1, 2, 6]
    
    private func calc(_ start: inout Int) -> Int {
        defer {
            start -= 4
        }
        return start*(start-1)/(start-2)-(start-3)
    }
}
