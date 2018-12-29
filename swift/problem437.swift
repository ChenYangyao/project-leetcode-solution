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

//swift implementation of following ref.
//ref: https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method
class Solution {
    func pathSum(_ root: TreeNode?, _ sum: Int) -> Int {
        var sumCount = [0:1]
        return helper(root,0,sum,&sumCount)
    }
    
    func helper(_ root: TreeNode?, _ currentSum: Int, _ sum: Int, _ sumCount: inout [Int:Int]) -> Int {
        if (root == nil) {
            return 0
        }
        
        var currentSum = currentSum
        currentSum += root!.val
        var ans = sumCount[currentSum - sum, default: 0]
        sumCount[currentSum, default: 0] += 1
        
        ans += (helper(root!.left, currentSum, sum, &sumCount) + helper(root!.right, currentSum, sum, &sumCount))
        
        sumCount[currentSum]! -= 1
        
        return ans
    }
}
