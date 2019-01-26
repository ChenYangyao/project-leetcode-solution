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

//swift implementation of cpp version
class Solution {
    func findMode(_ root: TreeNode?) -> [Int] {
        if (root == nil) {
            return []
        }
        
        var mode = Int.min; var modeCount = 0; var MaxCount = 0
        var ans = [Int]()
        
        //using closure
        let findMaxCount = { (_ val: Int) -> () in
            if (val == mode) {
                modeCount += 1
            } else {
                MaxCount = max(MaxCount,modeCount)
                mode = val
                modeCount = 1
            }
        }
        inOrder(root,findMaxCount)
        MaxCount = max(MaxCount,modeCount)
        
        mode = Int.min; modeCount = 0
        
        let findAns = { (_ val: Int) -> () in
            if (val == mode) {
                modeCount += 1
            } else {
                if (modeCount == MaxCount) {
                    ans.append(mode)
                }
                mode = val
                modeCount = 1
            }
        }
        inOrder(root,findAns)
        if (modeCount == MaxCount) {
            ans.append(mode)
        }
        
        return ans
    }
    
    func inOrder(_ root: TreeNode?, _ function: (_ val: Int) -> ()) {
        var p = root; var stack = [TreeNode]()
        
        while (p != nil || !stack.isEmpty) {
            while (p != nil) {
                stack.append(p!)
                p = p!.left
            }
            p = stack.removeLast()
            function(p!.val)
            p = p!.right
        }
    }
}
