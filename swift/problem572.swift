import Dispatch

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
}

class Solution1 {
    //define a class to store the number of nodes of left and right subtrees resp.
    //class is passed as reference
    private class countNumber {
        var lNum: Int = 0
        var rNum: Int = 0
    }
    
    private class stackItem: countNumber {
        let p: TreeNode
        var visited: Bool = false
        var direction: Bool //true: right; false: left
        var parent: countNumber
        
        //we need to modify parent's countNumber class later
        init(_ p: TreeNode, _ parent: countNumber, _ direction: Bool) {
            self.p = p
            self.parent = parent
            self.direction = direction
        }
    }
    
    //https://github.com/ChenYangyao/project-leetcode-solution/blob/master/swift/problem100.swift
    func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        return (p == nil && q == nil) || (p?.val == q?.val) && isSameTree(p!.right, q!.right) && isSameTree(p!.left, q!.left)
    }
    
    func nodeNumber(_ p: TreeNode?) -> Int {
        if (p == nil) {
            return 0
        }
        
        var stkNode = [TreeNode]()
        var tmpNode = p!
        var number = 0
        
        stkNode.append(tmpNode)
        while !stkNode.isEmpty {
            tmpNode = stkNode.removeLast()
            if (tmpNode.left != nil) {
                stkNode.append(tmpNode.left!)
            }
            if (tmpNode.right != nil) {
                stkNode.append(tmpNode.right!)
            }
            number += 1
        }
        return number
    }
    
    //we first determine the number of nodes with repect to root node p. If it is the same as t's, we then judge whether p and s are the same tree.
    //we count the number of nodes w.r.t every nodes in s reversely using stack.
    //swift implementation of cpp version.
    //https://github.com/ChenYangyao/project-leetcode-solution/blob/master/cpp/problem572.cpp
    func isSubtree(_ s: TreeNode?, _ t: TreeNode?) -> Bool {
        if (s == nil) {
            return (t == nil)
        }
        
        var stack = [stackItem]()
        
        let tNum = nodeNumber(t)
        
        stack.append(stackItem(s!, countNumber(), false))

        //post-order traversal
        while !stack.isEmpty {
            let top = stack.last!

            if top.visited {
                let tmp = top.lNum + top.rNum + 1
                if top.direction {
                    top.parent.rNum = tmp
                } else {
                    top.parent.lNum = tmp
                }
                if (tmp == tNum && isSameTree(top.p,t)) {
                    return true
                }
                stack.removeLast(1)
            } else {
                top.visited = true
                if (top.p.left != nil) {
                    stack.append(stackItem(top.p.left!,top, false))
                    //passing subclass instance to superclass is allowed
                }
                if (top.p.right != nil) {
                    stack.append(stackItem(top.p.right!,top, true))
                }
            }
        }
        return false
    }
}

//ref: sample 172 ms submission
class Solution2 {
    func isSubtree(_ s: TreeNode?, _ t: TreeNode?) -> Bool {
        return (s == nil && t == nil) || ( s != nil && t != nil && (isSameTree(s,t) || isSubtree(s!.left,t) || isSubtree(s!.right,t)))
    }
    
    func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        return (p == nil && q == nil) || (p?.val == q?.val) && isSameTree(p!.right, q!.right) && isSameTree(p!.left, q!.left)
    }
}

protocol sol {
    func isSubtree(_ s: TreeNode?, _ t: TreeNode?) -> Bool
}
extension Solution1: sol{}
extension Solution2: sol{}

var sInput = [Int](repeating: 0, count: 16383)
var tInput = [Int](repeating: 0, count: 8191)

for i in 0..<16383 {
    sInput[i] = Int.random(in: 0...100)
}

for i in 0..<8191 {
    tInput[i] = Int.random(in: 0...100)
}

let s = conversion().a_to_b(sInput)
let t = conversion().a_to_b(tInput)

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.isSubtree(s,t)
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

time_consuming(Solution1(),"optimised",100)
time_consuming(Solution2(),"brute force",100)

/*
 brute force method is faster than optimised one on my mac =_=
 
    optimised 692 ms for 100 times
    brute force 433 ms for 100 times
 
 but it is just the opposite on Leetcode's website.
    128 ms vs 352 ms
 
 I have no idea about this.
*/
