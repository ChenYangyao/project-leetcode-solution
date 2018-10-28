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

//reverse in-order traversal
class Solution {
    func convertBST(_ root: TreeNode?) -> TreeNode? {
        var stack = [TreeNode]()
        var tmp = root
        var sum = 0
        
        while (stack.count > 0 || tmp != nil) {
            while (tmp != nil) {
                stack.append(tmp!)
                tmp = tmp!.right
            }
            tmp = stack.popLast()!
            sum += tmp!.val
            tmp!.val = sum
            tmp = tmp!.left
        }
        
        return root
    }
}

let input = [10,5,15,2,7,13,17]
let root = conversion().a_to_b(input)
let result = conversion().b_to_a(Solution().convertBST(root))

print("input",input,"\nresult",result)
