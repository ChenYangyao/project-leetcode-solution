//ref: https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
class MinStack {
    private var stack: [Int]
    private var minElement: Int
    
    init() {
        self.stack = [Int]()
        self.minElement = Int.min
    }
    
    func push(_ x: Int) {
        if stack.isEmpty {
            stack.append(x)
            minElement = x
        } else if (x >= minElement) {
            stack.append(x)
        } else {
            stack.append(2*x-minElement)
            minElement = x
        }
    }
    
    func pop() {
        let tmp = stack.removeLast()
        if (tmp < minElement) {
            minElement = 2*minElement - tmp
        }
    }
    
    func top() -> Int {
        let tmp = stack.last!
        return tmp >= minElement ? tmp : 2*minElement - tmp
    }
    
    func getMin() -> Int {
        return minElement
    }
}
