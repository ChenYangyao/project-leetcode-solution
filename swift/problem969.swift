//ref: https://leetcode.com/problems/pancake-sorting/solution/
class Solution {
    func pancakeSort(_ A: [Int]) -> [Int] {
        var ans = [Int](); var remaining = A.count
        let idx = A.enumerated().sorted{$0.element > $1.element}.map{$0.offset + 1}
        
        for var index in idx {
            for flip in ans where (index <= flip) {
                index = flip + 1 - index
            }
            if (index != 1) {
                ans.append(index)
            }
            if (remaining != 1) {
                ans.append(remaining)
            }
            remaining -= 1
        }
        
        return ans
    }
}
