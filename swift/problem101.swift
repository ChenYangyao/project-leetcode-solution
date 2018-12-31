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

class Solution1 {
    func isSymmetric(_ root: TreeNode?) -> Bool {
        if (root == nil) {
            return true
        }
        
        var queue = [TreeNode]()
        queue.append(root!); queue.append(root!)
        
        while (!queue.isEmpty) {
            let node1 = queue.removeFirst()
            let node2 = queue.removeFirst()
            if (node1.val != node2.val) {
                return false
            }
            if (node1.left != nil && node2.right != nil) {
                queue.append(node1.left!); queue.append(node2.right!)
            } else if !(node1.left == nil && node2.right == nil) {
                return false
            }
            if (node1.right != nil && node2.left != nil) {
                queue.append(node1.right!); queue.append(node2.left!)
            } else if !(node1.right == nil && node2.left == nil) {
                return false
            }
        }
        
        return true
    }
}

//nearly the same as problem100
class Solution2 {
    func isSymmetric(_ root: TreeNode?) -> Bool {
        return isMirror(root, root)
    }
    
    func isMirror(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        return (p == nil && q == nil) || (p?.val == q?.val) && isMirror(p?.left, q?.right) && isMirror(p?.right, q?.left)
    }
}
