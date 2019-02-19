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

//swift implementation of cpp version
class Solution {
    private var l = 0
    
    func longestUnivaluePath(_ root: TreeNode?) -> Int {
        _ = longest(root)
        defer {
            l = 0
        }
        return l
    }
    
    private func longest(_ root: TreeNode?) -> Int {
        guard let root = root else {
            return 0
        }
        
        var childLegnth = 0; var length = 0; var tmp = 0
        
        childLegnth = longest(root.left)
        if (childLegnth != 0 && root.val == root.left?.val) {
            tmp += childLegnth
            length = childLegnth
        }
        
        childLegnth = longest(root.right)
        if (childLegnth != 0 && root.val == root.right?.val) {
            tmp += childLegnth
            length = max(length,childLegnth)
        }
        
        l = max(l,tmp)
        return (length + 1)
    }
}
