//direct simulation
class Solution {
    func validateStackSequences(_ pushed: [Int], _ popped: [Int]) -> Bool {
        if pushed.isEmpty {
            return true
        }
        
        var stack = [Int](); let length = popped.count
        var pushIdx = 0; var popIdx = 0
        
        //or using this control flow
        /**
        while (popIdx != length) {
            if (stack.last != popped[popIdx]) {
        **/
        while true {
            if (stack.isEmpty || stack.last! != popped[popIdx]) {
                if (pushIdx == length) {
                    break
                } else {
                    stack.append(pushed[pushIdx])
                    pushIdx += 1
                }
            } else {
                stack.removeLast(1)
                popIdx += 1
            }
        }
        
        return (popIdx == length)
    }
}
