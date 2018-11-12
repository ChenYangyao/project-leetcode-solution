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

//recursive solution
//ref: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/discuss/189998/Java-Simple-Sol.-0ms
class Solution {
    private var num = [Int]()
    func sortedArrayToBST(_ nums: [Int]) -> TreeNode? {
        num = nums
        return createNode(0, num.count - 1)
    }
    
    func createNode(_ deb: Int, _ fin: Int) -> TreeNode? {
        if (deb > fin) {
            return nil
        }
        let mil = (deb+fin)/2
        let node = TreeNode(num[mil])
        node.left = createNode(deb,mil - 1)
        node.right = createNode(mil+1,fin)
        return node
    }
}
