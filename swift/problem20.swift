class Solution {
    private let pair: [Character:Character] = ["(": ")",
                                               "[": "]",
                                               "{": "}"]
    
    func isValid(_ s: String) -> Bool {
        var stack = [Character]()
        
        for char in s {
            let cur = pair[char]
            if (cur != nil) {
                stack.append(char)
            } else {
                if (stack.isEmpty || pair[stack.removeLast()] != char) {
                    return false
                }
            }
        }
        
        return stack.isEmpty
    }
}
