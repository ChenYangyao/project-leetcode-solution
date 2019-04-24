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

//post-order traversal
class Solution {
    private class dp {
        var ans: TreeNode
        var node: TreeNode
        var depth = 0
        
        init(_ node: TreeNode) {
            self.ans = node
            self.node = node
        }
    }
    
    private class item: dp {
        var toVisit = true
        var parent: dp
        
        init(_ node: TreeNode, _ parent: dp) {
            self.parent = parent
            super.init(node)
        }
    }
    
    func subtreeWithAllDeepest(_ root: TreeNode?) -> TreeNode? {
        guard let root = root else { return nil }
        
        var stack = [item(root,dp(root))]
        var ans = root
        
        while !stack.isEmpty {
            let top = stack.last!
            if top.toVisit {
                let tmp = top.node
                if (tmp.right != nil) {
                    stack.append(item(tmp.right!,top))
                }
                if (tmp.left != nil) {
                    stack.append(item(tmp.left!,top))
                }
                top.toVisit = false
            } else {
                if (top.depth == 0) {
                    top.depth += 1
                } else {
                    if (top.depth + 1 > top.parent.depth) {
                        top.parent.ans = top.ans
                        top.parent.depth = top.depth + 1
                    } else if (top.depth + 1 == top.parent.depth) {
                        top.parent.ans = top.parent.node
                    }
                    ans = top.parent.ans
                    stack.removeLast(1)
                }
            }
        }
        
        return ans
    }
}
