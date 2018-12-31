class KthLargest {
    private var nums: [Int]
    private let k: Int
    
    init(_ k: Int, _ nums: [Int]) {
        self.k = k
        self.nums = nums.sorted(by: >)
    }
    
    func add(_ val: Int) -> Int {
        nums.insert(val, at: search(val))
        return nums[k-1]
    }
    
    func search(_ target: Int) -> Int {
        var head = 0; var mid = 0; var tail = nums.count - 1
        
        while (head <= tail) {
            mid = (head+tail)/2
            if (nums[mid] == target) {
                return mid
            } else if (nums[mid] > target) {
                head = mid + 1
            } else {
                tail = mid - 1
            }
        }
        return head
    }
}
