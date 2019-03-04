public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}

class Solution {
    func constructMaximumBinaryTree(_ nums: [Int]) -> TreeNode? {
        let end = nums.count
        if (end == 0) {
            return nil
        }
        var nums = nums
        return construct(&nums, 0, end-1)
    }
    
    func construct(_ nums: inout [Int], _ start: Int, _ end: Int) -> TreeNode {
        var maxNumber = Int.min; var maxIndex = 0
        
        for i in start...end {
            if (nums[i] >= maxNumber) {
                maxNumber = nums[i]
                maxIndex = i
            }
        }
        
        let head = TreeNode(maxNumber)
        
        if (start != end) {
            switch maxIndex {
            case start:
                head.right = construct(&nums, start+1, end)
            case end:
                head.left = construct(&nums, start, end-1)
            default:
                head.left = construct(&nums, start, maxIndex-1)
                head.right = construct(&nums, maxIndex+1, end)
            }
        }
        
        return head
    }
    
}
