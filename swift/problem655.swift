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

//https://leetcode.com/problems/print-binary-tree/discuss/263075/Java-1ms-beats-100
class Solution {
    func printTree(_ root: TreeNode?) -> [[String]] {
        let row = height(root)
        let col = (1 << row) - 1 //2^{height}-1
        
        var ans = [[String]](repeating: [String](repeating: "", count: col), count: row)
        var queue = [root]
        
        var interval = col + 1
        var pos = col/2
        var breadth = 1
        
        for r in 0..<row {
            let prevPos = pos
            for _ in 0..<breadth {
                let cur = queue.removeFirst()
                if let cur = cur {
                    queue.append(cur.left); queue.append(cur.right)
                    ans[r][pos] = String(cur.val)
                } else {
                    queue.append(nil); queue.append(nil)
                    //ingenious technique for determing the output position of every non-empty nodes
                }
                pos += interval
            }
            
            breadth *= 2
            interval /= 2
            pos = prevPos/2
        }
        
        return ans
    }
    
    private func height(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        
        return max(height(root.left), height(root.right)) + 1
    }
}
