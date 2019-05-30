//ref: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/discuss/247626/JavaPythonC%2B%2B-Stack-Solution-O(N)
class Solution {
    func isValid(_ S: String) -> Bool {
        var stack = [Character]()
        
        for char in S {
            if (char == "c") {
                if (stack.isEmpty || stack.removeLast() != "b") {
                    return false
                }
                if (stack.isEmpty || stack.removeLast() != "a") {
                    return false
                }
            } else {
                stack.append(char)
            }
        }
        
        return stack.isEmpty
    }
}
