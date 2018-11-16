class Solution {
    func missingNumber(_ nums: [Int]) -> Int {
        let dernier = nums.count
        return (dernier*(dernier+1)/2 - nums.reduce(0,+))
    }
}
