class MyStack {
    private var queue: [Int]
    private var queueBk: [Int]
    private var topElm: Int
    
    init() {
        self.queue = [Int]()
        self.queueBk = [Int]()
        self.topElm = 0
    }
    
    func push(_ x: Int) {
        queue.append(x)
        topElm = x
    }
    
    func pop() -> Int {
        var tmp = 0
        while (queue.count > 1) {
            topElm = queue.removeFirst()
            queueBk.append(topElm)
        }
        tmp = queue.removeFirst()
        swap(&queue,&queueBk)
        return tmp
    }
    
    func top() -> Int {
        return topElm
    }
    
    func empty() -> Bool {
        return queue.isEmpty
    }
}
