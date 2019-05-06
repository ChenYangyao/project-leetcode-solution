//ref: https://leetcode.com/problems/beautiful-arrangement/solution/
class Solution1 {
    private var toVisit = [Bool]()
    private var ans = 0
    
    func countArrangement(_ N: Int) -> Int {
        self.toVisit = [Bool](repeating: true, count: N + 1)
        self.ans = 0
        backTracking(N, 1)
        return ans
    }
    
    private func backTracking(_ N: Int, _ pos: Int) {
        if (pos > N) {
            ans += 1
        }
        for idx in 1...N {
            if (toVisit[idx] && (pos % idx == 0 || idx % pos == 0)) {
                toVisit[idx] = false
                backTracking(N, pos + 1)
                toVisit[idx] = true
            }
        }
    }
}

class Solution2 {
    private var nums = [Int]()
    
    func countArrangement(_ N: Int) -> Int {
        self.nums = [Int](1...N)
        return permutate(N)
    }
    
    func permutate(_ N: Int) -> Int
    {
        if (N == 0) { return 1 }
        
        var ans = 0
        
        for idx in 0..<N {
            if (N % nums[idx] == 0 || nums[idx] % N == 0) {
                nums.swapAt(idx, N - 1)
                ans += permutate(N - 1)
                nums.swapAt(idx, N - 1)
            }
        }
        
        return ans
    }
}
