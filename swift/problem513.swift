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

//trivial breadth-first traversal
class Solution {
    func findBottomLeftValue(_ root: TreeNode?) -> Int {
        typealias nodeDepth = (node: TreeNode, depth: Int)
        
        var queue = [nodeDepth(root!, 0)]
        var ans = root!.val; var currentDepth = 0

        while !queue.isEmpty {
            let tmp = queue.removeFirst()
            
            if (tmp.depth > currentDepth) {
                currentDepth = tmp.depth
                ans = tmp.node.val
            }
            
            if (tmp.node.left != nil) {
                queue.append((tmp.node.left!, tmp.depth+1))
            }
            if (tmp.node.right != nil) {
                queue.append((tmp.node.right!, tmp.depth+1))
            }
        }

        return ans
    }
}
