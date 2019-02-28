class Solution {
    private let A = Unicode.Scalar("A").value
    
    func convertToTitle(_ n: Int) -> String {
        var n = UInt32(n); var ans = String()
        
        while (n > 0) {
            n -= 1
            ans = String(Unicode.Scalar(A + n%26)!) + ans
            n /= 26
        }
        
        return ans
    }
}
