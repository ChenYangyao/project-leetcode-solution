class Solution {
    func minimumDeleteSum(_ s1: String, _ s2: String) -> Int {
        let s1 = s1.map{Int($0.asciiValue!)}; let s2 = s2.map{Int($0.asciiValue!)}
        let l1 = s1.count; let l2 = s2.count
        var dp = [[Int]](repeating: [Int](repeating: 0, count: l2 + 1), count: l1 + 1)

        for idx1 in 1...l1 {
            dp[idx1][0] = dp[idx1 - 1][0] + s1[idx1 - 1]
            for idx2 in 1...l2 {
                dp[0][idx2] = dp[0][idx2 - 1] + s2[idx2 - 1]
                if (s1[idx1 - 1] == s2[idx2 - 1]) {
                    dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1]
                } else {
                    dp[idx1][idx2] = min(dp[idx1 - 1][idx2] + s1[idx1 - 1], dp[idx1][idx2 - 1] + s2[idx2 - 1])
                }
            }
        }
        
        return dp[l1][l2]
    }
}
