class Solution {
    private let nums: [Int]
    
    init(_ nums: [Int]) {
        self.nums = nums
    }
    
    func pick(_ target: Int) -> Int {
        var candidate = [Int]()
        
        for idx in 0..<nums.count {
            if (nums[idx] == target) {
                candidate.append(idx)
            }
        }
        
        return candidate[Int.random(in: 0..<candidate.count)]
    }
}
