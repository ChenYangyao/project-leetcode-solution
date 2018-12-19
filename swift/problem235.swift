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

class conversion {
    func a_to_b(_ value: [Int?]) -> TreeNode? {
        if (value[0] == nil) {
            return nil
        }
        
        var deque = [TreeNode?]()
        var index = 1
        let output = TreeNode(value[0]!)
        
        if (value.count == 1) {
            return output
        }
        
        deque.append(output)
        while (index < value.count) {
            let tmp = deque.removeFirst()
            if let val = value[index] {
                tmp?.left = TreeNode(val)
                deque.append(tmp?.left)
            }
            index += 1
            
            if let val = value[index] {
                tmp?.right = TreeNode(val)
                deque.append(tmp?.right)
            }
            index += 1
        }
        return output
    }
    
    func b_to_a(_ root: TreeNode?) -> [Int?] {
        if (root == nil) {
            return [nil as Int?]
        }
        var output = [Int?]()
        var deque = [TreeNode?]()
        
        deque.append(root)
        while (deque.count != 0) {
            let tmp = deque.removeFirst()
            if (tmp == nil) {
                output.append(nil)
            } else {
                output.append(tmp?.val)
                if (tmp?.left != nil || tmp?.right != nil) {
                    deque.append(tmp?.left)
                    deque.append(tmp?.right)
                }
            }
        }
        return output
    }
}

//ref: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/
class Solution {
    func lowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode, _ q: TreeNode) -> TreeNode? {
        var node = root; let p1 = p.val; let p2 = q.val
        
        while (node != nil) {
            let value = node!.val
            if (p1 < value && p2 < value) {
                node = node!.left
            } else if (p1 > value && p2 > value) {
                node = node!.right
            } else {
                return node
            }
        }
        
        return node
    }
}

let conv = conversion()

let root = conv.a_to_b([6,2,8,1,4,7,9,nil,nil,3,5])
let p = conv.a_to_b([1])
let q = conv.a_to_b([9])

let ans = Solution().lowestCommonAncestor(root,p!,q!)
print(ans?.val as Any)
