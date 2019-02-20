class Solution {
    func strWithout3a3b(_ A: Int, _ B: Int) -> String {
        var ans = ""
        var AChar = Character("a"); var BChar = Character("b")
        var ALeft = A; var BLeft = B
        
        while (BLeft > 0) {
            if (ALeft - BLeft > 1) {
                ans.append(AChar); ans.append(AChar)
                ans.append(BChar)
                ALeft -= 2; BLeft -= 1
            } else if (ALeft >= BLeft) {
                ans.append(AChar)
                ans.append(BChar)
                ALeft -= 1; BLeft -= 1
            } else {
                swap(&ALeft,&BLeft)
                swap(&AChar,&BChar)
            }
        }
        
        while (ALeft > 0) {
            ans.append(AChar); ALeft -= 1
        }
        return ans
    }
}
