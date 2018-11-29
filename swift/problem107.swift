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

//Breadth-first traversal
class Solution {
    func levelOrderBottom(_ root: TreeNode?) -> [[Int]] {
        if (root == nil) {
            return [[Int]]()
        }
        typealias node_dp = (node: TreeNode?, dp: Int)
        var queue = [node_dp]()
        var ans = [[Int]]()
        
        queue.append((root,0))
        
        while !queue.isEmpty {
            let tmp = queue.removeFirst()
            if (tmp.dp >= ans.count) {
                ans.append([tmp.node!.val])
            } else {
                ans[tmp.dp].append(tmp.node!.val)
            }
            if (tmp.node!.left != nil) {
                queue.append((tmp.node!.left,tmp.dp+1))
            }
            if (tmp.node!.right != nil) {
                queue.append((tmp.node!.right,tmp.dp+1))
            }
        }
        
        ans.reverse()
        return ans
    }
}
