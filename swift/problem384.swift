//Fisher-Yates shuffle algorithm
class Solution {
    private var randomArray: [Int]
    private let nums: [Int]
    private let length: Int
    
    init(_ nums: [Int]) {
        self.randomArray = nums
        self.nums = nums
        self.length = nums.count
    }
    
    func reset() -> [Int] {
        randomArray = nums
        return randomArray
    }
    
    //or using built-in function shuffled()
    func shuffle() -> [Int] {
        for idx in 0..<length {
            randomArray.swapAt(idx, Int.random(in: idx..<length))
        }
        
        return randomArray
    }
}
