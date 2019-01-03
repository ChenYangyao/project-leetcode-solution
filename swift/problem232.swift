//swift implementation of cpp version
//https://github.com/ChenYangyao/project-leetcode-solution/blob/master/cpp/problem232.cpp
class MyQueue {
    private var queue: [Int]
    private var revQueue: [Int]
    private func transform(_ input: inout [Int], _ output: inout [Int]) {
        while !input.isEmpty {
            output.append(input.removeLast())
        }
    }
    
    init() {
        self.queue = [Int]()
        self.revQueue = [Int]()
    }
    
    func push(_ x: Int) {
        if !revQueue.isEmpty {
            transform(&revQueue, &queue)
        }
        queue.append(x)
    }
    
    func pop() -> Int {
        if !queue.isEmpty {
            transform(&queue, &revQueue)
        }
        return revQueue.removeLast()
    }
    
    func peek() -> Int {
        if !queue.isEmpty {
            transform(&queue, &revQueue)
        }
        return revQueue.last!
    }
    
    func empty() -> Bool {
        return queue.isEmpty && revQueue.isEmpty
    }
}
