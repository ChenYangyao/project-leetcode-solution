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

//in-order traversal
class Solution1 {
    func rangeSumBST(_ root: TreeNode?, _ L: Int, _ R: Int) -> Int {
        var stack = [TreeNode](); var tmp = root; var ans = 0
        
        while (!stack.isEmpty || tmp != nil) {
            while (tmp != nil) {
                stack.append(tmp!)
                tmp = tmp!.left
            }
            tmp = stack.removeLast()
            let tmpVal = tmp!.val
            if (tmpVal <= R) {
                if (tmpVal >= L) {
                    ans += tmpVal
                }
            } else {
                break
            }
            tmp = tmp!.right
        }
        
        return ans
    }
}

//pre-order traversal
//ref: https://leetcode.com/problems/range-sum-of-bst/solution/
class Solution2 {
    func rangeSumBST(_ root: TreeNode?, _ L: Int, _ R: Int) -> Int {
        guard let root = root else {
            return 0
        }
        
        var stack = [root]; var ans = 0
        
        while !stack.isEmpty {
            let tmp = stack.removeLast()
            let tmpVal = tmp.val
            if (tmpVal >= L && tmpVal <= R) {
                ans += tmpVal
            }
            if (tmpVal > L && tmp.left != nil) {
                stack.append(tmp.left!)
            }
            if (tmpVal < R && tmp.right != nil) {
                stack.append(tmp.right!)
            }
        }
        
        return ans
    }
}
