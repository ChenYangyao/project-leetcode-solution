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

class Solution {
    private class nodeSum {
        var node: TreeNode
        var sum: Int
        
        init(_ node: TreeNode) {
            self.node = node
            self.sum = node.val
        }
    }
    
    private class item: nodeSum {
        var parent: nodeSum
        var toVisit = true
        
        init(_ node: TreeNode, _ parent: nodeSum) {
            self.parent = parent
            super.init(node)
        }
    }
    
    func findFrequentTreeSum(_ root: TreeNode?) -> [Int] {
        guard let root = root else { return [] }
        
        var dict = [Int:Int]()
        var stack = [item(root, nodeSum(root))]
        
        while !stack.isEmpty {
            let top = stack.last!
            if top.toVisit {
                let tmp = top.node
                if (tmp.right != nil) {
                    stack.append(item(tmp.right!, top))
                }
                if (tmp.left != nil) {
                    stack.append(item(tmp.left!, top))
                }
                top.toVisit = false
            } else {
                top.parent.sum += top.sum
                dict[top.sum, default: 0] += 1
                stack.removeLast(1)
            }
        }
        
        var curMax = Int.min
        var ans = [Int]()
        
        for (sum, freq) in dict {
            if (freq > curMax) {
                ans = [sum]
                curMax = freq
            } else if (freq == curMax) {
                ans.append(sum)
            }
        }
        
        return ans
    }
}
