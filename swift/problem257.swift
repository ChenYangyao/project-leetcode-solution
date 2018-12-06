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

//pre-order traversal
class Solution {
    func binaryTreePaths(_ root: TreeNode?) -> [String] {
        var ans = [String]()
        if (root == nil) {
            return ans
        }
        
        var node = [TreeNode](); var path = [String]()
        node.append(root!); path.append(String(root!.val))
        
        while (!node.isEmpty) {
            let tmp_node = node.removeLast()
            let tmp_path = path.removeLast()
            if (tmp_node.left != nil || tmp_node.right != nil) {
                if (tmp_node.left != nil) {
                    node.append(tmp_node.left!)
                    path.append(tmp_path + "->" + String(tmp_node.left!.val))
                }
                if (tmp_node.right != nil) {
                    node.append(tmp_node.right!)
                    path.append(tmp_path + "->" + String(tmp_node.right!.val))
                }
            } else {
                ans.append(tmp_path)
            }
        }
        
        return ans
    }
}
