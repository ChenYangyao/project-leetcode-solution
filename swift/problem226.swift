//Definition for a binary tree node.
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
    func invertTree(_ root: TreeNode?) -> TreeNode? {
        let output = root
        var stack_node = [TreeNode?]()
        stack_node.append(output)
        while (stack_node.count > 0) {
            let temp = stack_node.popLast()
            let temp_node = temp??.left
            temp??.left = temp??.right
            temp??.right = temp_node
            if (temp??.left != nil) {
                stack_node.append(temp!!.left)
            }
            if (temp??.right != nil) {
                stack_node.append(temp!!.right)
            }
        }
        return output
    }
}

//mutual conversion between binary tree and array
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

let test = conversion()
let input = [1,2,3,nil,4,5,6,7,nil,nil,8,9,10]
print("before inversion:", input)
print("after inversion:",test.b_to_a(Solution().invertTree(test.a_to_b(input))))

