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

//recursive sln
//ref: https://leetcode.com/problems/distribute-coins-in-binary-tree/solution/
class Solution1 {
    private var ans = 0
    
    func distributeCoins(_ root: TreeNode?) -> Int {
        ans = 0
        dfs(root)
        return ans
    }
    
    @discardableResult
    private func dfs(_ node: TreeNode?) -> Int {
        guard let node = node else { return 0 }
        
        let L = dfs(node.left); let R = dfs(node.right)
        ans += (abs(L) + abs(R))
        return node.val + L + R - 1
    }
}

//iterative sln
class Solution2 {
    private class sum {
        var coins = -1
    }
    
    private class item: sum {
        var node: TreeNode
        var toVisit = true
        var parent: sum
        
        init(_ node: TreeNode, _ parent: sum) {
            self.node = node
            self.parent = parent
        }
    }
    
    func distributeCoins(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        
        var stack = [item(root,sum())]
        var ans = 0
        
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
                let tmp = top.node.val + top.coins
                ans += abs(tmp)
                top.parent.coins += tmp
                stack.removeLast(1)
            }
        }
        
        return ans
    }
}
