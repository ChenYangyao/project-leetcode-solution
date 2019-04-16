class Solution1 {
    func scoreOfParentheses(_ S: String) -> Int {
        var stack = [Int](repeating: 0, count: S.count/2); var depth = -1
        var prev = Character("(")
        
        for char in S {
            if (char == "(") {
                depth += 1
            } else {
                if (prev == "(") {
                    stack[depth] += 1
                } else {
                    stack[depth] += stack[depth+1]*2
                    stack[depth+1] = 0
                }
                depth -= 1
            }
            prev = char
        }
        
        return stack[0]
    }
}

//pretty smart Sln
//ref: https://leetcode.com/problems/score-of-parentheses/solution/
//Approach 3
class Solution2 {
    func scoreOfParentheses(_ S: String) -> Int {
        var ans = 0; var exterior = 0
        var prev = Character("(")
        
        for char in S {
            if (char == "(") {
                exterior += 1
            } else {
                exterior -= 1
                if (prev == "(") {
                    ans += (1 << exterior)
                }
            }
            prev = char
        }
        
        return ans
    }
}
