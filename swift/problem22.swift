//ref: sample 16 ms submission
class Solution {
    private var ans = [String]()
    
    func generateParenthesis(_ n: Int) -> [String] {
        ans = []
        
        generator(n, n, "")
        
        return ans
    }
    
    private func generator(_ left: Int, _ right: Int, _ currentPath: String) {
        if (left == 0 && right == 0) {
            ans.append(currentPath)
        } else {
            if (left > 0) {
                generator(left - 1, right, currentPath + "(")
            }
            if (right > left) {
                generator(left, right - 1, currentPath + ")")
            }
        }
    }
}
