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

//ref: https://leetcode.com/problems/all-possible-full-binary-trees/solution/
class Solution {
    private var cache = [Int:[TreeNode]]()
    
    func allPossibleFBT(_ N: Int) -> [TreeNode?] {
        if (cache[N] == nil) {
            var tmpAns = [TreeNode]()
            if (N == 1) {
                tmpAns.append(TreeNode(0))
            } else if (N % 2 == 1) {
                for countOne in 1...(N/2) {
                    for childOne in allPossibleFBT(countOne) {
                        let countTwo = N - countOne - 1
                        for childTwo in allPossibleFBT(countTwo) {
                            var root = TreeNode(0)
                            root.left = childOne; root.right = childTwo
                            tmpAns.append(root)
                            if (countOne != countTwo) {
                                root = TreeNode(0)
                                root.left = childTwo; root.right = childOne
                                tmpAns.append(root)
                            }
                        }
                    }
                }
            }
            cache[N] = tmpAns
        }
        
        return cache[N]!
    }
}
