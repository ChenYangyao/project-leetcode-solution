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

//recursive
class Solution1 {
    func tree2str(_ t: TreeNode?) -> String {
        if (t == nil) {
            return ""
        }
        if (t!.right != nil) {
            return (String(t!.val)+"("+tree2str(t!.left)+")("+tree2str(t!.right)+")")
        } else if (t!.left == nil) {
            return String(t!.val)
        }
        return (String(t!.val)+"("+tree2str(t!.left)+")")
    }
}

//swift implementation of problem606.cpp. instead of using another set to record visit history, we can attach a Bool variable to the TreeNode stack
class Solution2 {
    typealias record = (node: TreeNode?, visited: Bool)
    
    func tree2str(_ t: TreeNode?) -> String {
        var s = String()
        var stack = [record]()
        var tmp = t
        var index = 0
        
        while (tmp != nil || stack.count > 0) {
            while (tmp != nil) {
                s += String(tmp!.val)
                if (tmp!.left != nil || tmp!.right != nil) {
                    s += "("
                }
                stack.append((tmp,false))
                tmp = tmp!.left
            }
            index = stack.endIndex - 1
            tmp = stack[index].node
            if (stack[index].visited) {
                if (tmp!.right != nil) {
                    s += ")"
                }
                _ = stack.popLast()
                tmp = nil
            } else {
                if (tmp!.right != nil) {
                    s += ")("
                    stack[index].visited = true
                    tmp = tmp!.right
                } else if (tmp!.left != nil) {
                    s += ")"
                    _ = stack.popLast()
                    tmp = nil
                } else {
                    _ = stack.popLast()
                    tmp = nil
                }
            }
        }
        return s
    }
}
