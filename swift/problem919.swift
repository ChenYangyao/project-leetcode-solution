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

//trivial breadth-first traversal
class CBTInserter {
    private var deque: [TreeNode]
    private let root: TreeNode
    private var cur = TreeNode(0)

    init(_ root: TreeNode?) {
        self.root = root!
        self.deque = [self.root]
        
        while !deque.isEmpty {
            cur = deque.removeFirst()
            if (cur.left != nil) {
                deque.append(cur.left!)
            } else {
                break
            }
            
            if (cur.right != nil) {
                deque.append(cur.right!)
            } else {
                break
            }
        }
    }
    
    func insert(_ v: Int) -> Int {
        defer {
            if (cur.left == nil) {
                cur.left = TreeNode(v)
                deque.append(cur.left!)
            } else {
                cur.right = TreeNode(v)
                deque.append(cur.right!)
                cur = deque.removeFirst()
            }
        }
        
        return cur.val
    }
    
    func get_root() -> TreeNode? {
        return root
    }
}
