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
    func minDepth(_ root: TreeNode?) -> Int {
        guard let root = root else {
            return 0
        }
        
        typealias nodeDepth = (node: TreeNode, depth: Int)
        
        var queue = [nodeDepth]()
        
        queue.append((root, 1))
        
        while !queue.isEmpty {
            let tmp = queue.removeFirst()
            if (tmp.node.left == nil && tmp.node.right == nil) {
                return tmp.depth
            }
            if (tmp.node.left != nil) {
                queue.append((tmp.node.left!, tmp.depth+1))
            }
            if (tmp.node.right != nil) {
                queue.append((tmp.node.right!, tmp.depth+1))
            }
        }
        
        return -1
    }
}
