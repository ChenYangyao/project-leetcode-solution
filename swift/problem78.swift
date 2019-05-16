class Solution {
    private var nums = [Int]()
    private var length = 0
    private var ans = [[Int]]()
    private var cur = [Int]()
    
    func subsets(_ nums: [Int]) -> [[Int]] {
        self.nums = nums
        self.length = nums.count
        self.ans = [[Int]]()
        self.cur = [Int]()
        
        dfs(0)
        
        return self.ans
    }
    
    private func dfs(_ head: Int) {
        ans.append(cur)
        for idx in head..<length {
            cur.append(nums[idx])
            dfs(idx+1)
            cur.removeLast(1)
        }
    }
}
