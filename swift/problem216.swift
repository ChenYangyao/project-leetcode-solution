//ref: https://leetcode.com/problems/combination-sum-iii/discuss/283425/Java0ms-100
class Solution {
    private lazy var ans = [[Int]]()
    
    func combinationSum3(_ k: Int, _ n: Int) -> [[Int]] {
        if (n < (1+k)*k/2 || n > (19-k)*k/2) {
            return []
        }
        
        dfs(k, n, 1, [Int]())
        return ans
    }
    
    func dfs(_ k: Int, _ n: Int, _ cur: Int, _ tmp: [Int]) {
        if (k == tmp.count) {
            if (n == 0) {
                ans.append(tmp)
            }
            return
        }
        
        var cur = cur
        var tmp = tmp
        
        while (cur <= 9) {
            if (n - cur < 0) {
                return
            }
            tmp.append(cur)
            dfs(k, n-cur, cur+1, tmp)
            tmp.removeLast(1)
            cur += 1
        }
    }
}
