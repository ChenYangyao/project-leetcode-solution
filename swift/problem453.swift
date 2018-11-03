//summation and min could have been performed within one loop to speed up this solution
//pure math problem
class Solution {
    func minMoves(_ nums: [Int]) -> Int {
        return nums.reduce(0,+) - nums.count * nums.min()!
    }
}
