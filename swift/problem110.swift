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

//similar to problem572
class Solution {
    private class height {
        var leftHeight: Int = 0
        var rightHeight: Int = 0
    }
    
    private class stackItem: height {
        let p: TreeNode
        var visited: Bool = false
        var direction: Bool
        var parent: height
        
        init(_ p: TreeNode, _ parent: height, _ direction: Bool) {
            self.p = p
            self.parent = parent
            self.direction = direction
        }
    }
    
    func isBalanced(_ root: TreeNode?) -> Bool {
        if (root == nil) {
            return true
        }
        
        var stack = [stackItem]()
        stack.append(stackItem(root!,height(),false))
        
        while !stack.isEmpty {
            let top = stack.last!
            if top.visited {
                if ((top.leftHeight - top.rightHeight) > 1 || (top.rightHeight - top.leftHeight) > 1) {
                    return false
                }
                let parentHeight = max(top.leftHeight,top.rightHeight) + 1
                if top.direction {
                    top.parent.rightHeight = parentHeight
                } else {
                    top.parent.leftHeight = parentHeight
                }
                stack.removeLast(1)
            } else {
                if (top.p.left != nil) {
                    stack.append(stackItem(top.p.left!,top,false))
                }
                if (top.p.right != nil) {
                    stack.append(stackItem(top.p.right!,top,true))
                }
                top.visited = true
            }
        }
        return true
    }
}
