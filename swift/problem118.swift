class Solution {
    func generate(_ numRows: Int) -> [[Int]] {
        var ans = [[Int]]()
        if (numRows == 0) {
            return ans
        }
        
        ans.append([1])
        
        for i in 1..<numRows {
            var tmp = [1]
            for j in 1..<i {
                tmp.append(ans[i-1][j-1]+ans[i-1][j])
            }
            tmp.append(1)
            ans.append(tmp)
        }
        
        return ans
    }
}
