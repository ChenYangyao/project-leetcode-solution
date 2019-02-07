//brute force
class NumArray1 {
    var nums: [Int]
    
    init(_ nums: [Int]) {
        self.nums = nums
    }
    
    func sumRange(_ i: Int, _ j: Int) -> Int {
        return nums[i...j].reduce(0,+)
    }
}

//precalculation
class NumArray2 {
    var nums: [Int]
    private var sum: [Int]
    
    init(_ nums: [Int]) {
        self.nums = nums
        self.sum = [Int](repeating: 0, count: nums.count+1)
        for i in 0..<nums.count {
            sum[i+1] = sum[i] + nums[i]
        }
    }
    
    func sumRange(_ i: Int, _ j: Int) -> Int {
        return sum[j+1]-sum[i]
    }
}
