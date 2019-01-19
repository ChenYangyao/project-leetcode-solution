class Solution {
    func isPerfectSquare(_ num: Int) -> Bool {
        var root = 1
        
        while (root*root < num) {
            root += 1
        }
        
        return root*root == num
    }
}
