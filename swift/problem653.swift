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

//convert BST to increasing order array first
class Solution1 {
    func in_order(_ root: TreeNode?) -> [Int] {
        var value = [Int]()
        var stack = [TreeNode]()
        var tmp = root
        
        while (stack.count > 0 || tmp != nil) {
            while (tmp != nil) {
                stack.append(tmp!)
                tmp = tmp?.left
            }
            tmp = stack.popLast()!
            value.append(tmp!.val)
            tmp = tmp?.right
        }
        
        return value
    }
    
    func findTarget(_ root: TreeNode?, _ k: Int) -> Bool {
        let value = in_order(root)
        var s = 0
        var l = value.count - 1
        var sum = 0
        
        while (s < l) {
            sum = value[s] + value[l]
            if (sum < k) {
                s += 1
            } else if (sum > k) {
                l -= 1
            } else {
                return true
            }
        }
        
        return false
    }
}

//swift implementation of problem653.cpp using two stacks
class Solution2 {
    private var stack = [TreeNode]()
    private var r_stack = [TreeNode]()
    private var cur: TreeNode? = nil
    private var r_cur: TreeNode? = nil
    
    private func next() -> TreeNode? {
        if (stack.count > 0 || cur != nil) {
            var tmp = cur
            while (tmp != nil) {
                stack.append(tmp!)
                tmp = tmp?.left
            }
            tmp = stack.popLast()!
            cur = tmp?.right
            return tmp
        }
        return nil
    }
    
    private func r_next() -> TreeNode? {
        if (r_stack.count > 0 || r_cur != nil) {
            var tmp = r_cur
            while (tmp != nil) {
                r_stack.append(tmp!)
                tmp = tmp?.right
            }
            tmp = r_stack.popLast()!
            r_cur = tmp?.left
            return tmp
        }
        return nil
    }
    
    func findTarget(_ root: TreeNode?, _ k: Int) -> Bool {
        cur = root; r_cur = root
        var l = next(); var r = r_next()
        var sum = 0
        
        while (l != nil && r != nil && l!.val != r!.val) {
            sum = l!.val + r!.val
            if (sum < k) {
                l = next()
            } else if (sum > k) {
                r = r_next()
            } else {
                return true
            }
        }
        return false
    }
}

let root = conversion().a_to_b([8,3,10,1,6,nil,14,nil,nil,4,7,13,nil])
print(Solution1().findTarget(root,14))
print(Solution2().findTarget(root,14))
