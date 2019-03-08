//same idea as problem20
class Solution {
    func minAddToMakeValid(_ S: String) -> Int {
        var left = 0; var ans = 0
        
        for parenthesis in S {
            if parenthesis == "(" {
                left += 1
            } else {
                if left == 0 {
                    ans += 1
                } else {
                    left -= 1
                }
            }
        }
        
        return ans + left
    }
}
