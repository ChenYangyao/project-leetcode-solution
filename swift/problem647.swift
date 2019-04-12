//ref: https://leetcode.com/problems/palindromic-substrings/discuss/258917/Java-Simple-Code%3A-DP-short
class Solution1 {
    func countSubstrings(_ s: String) -> Int {
        let s = s.map{$0}; let length = s.count
        var cache = [Bool](repeating: false, count: length*(length+1)/2)
        
        //flat the lower triangle. col <= row
        let idx = {(row,col) in (1+row)*row/2+col}
        
        var ans = 0
        for depth in 0..<length {
            for col in 0..<(length - depth) {
                let row = col + depth
                
                if (depth == 0) {
                    cache[idx(row,col)] = true
                } else if (s[row] == s[col]) {
                    if (depth == 1) {
                        cache[idx(row,col)] = true
                    } else {
                        cache[idx(row,col)] = cache[idx(row-1,col+1)]
                    }
                }
                
                if cache[idx(row,col)] {
                    ans += 1
                }
            }
        }
        
        return ans
    }
}

//ref: https://leetcode.com/problems/palindromic-substrings/solution/
//Approach 1
//the idea is generally the same as Sln1, but instead of iterating over depths, here we simply shift the centre
class Solution2 {
    func countSubstrings(_ s: String) -> Int {
        let s = s.map{$0}; let length = s.count
        var ans = 0
        
        for centre in 0..<(2*length-1) {
            var left = centre/2; var right = left+centre%2
            while (left >= 0 && right < length && s[left] == s[right]) {
                ans += 1; left -= 1; right += 1
            }
        }
        
        return ans
    }
}
