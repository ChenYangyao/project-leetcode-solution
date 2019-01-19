class Solution {
    func licenseKeyFormatting(_ S: String, _ K: Int) -> String {
        var ans = String(); var counter = 0
        
        for char in S.uppercased().reversed() {
            if (char != "-") {
                if (counter == K) {
                    ans += "-"
                    counter = 0
                }
                ans += String(char)
                counter += 1
            }
        }
        
        return String(ans.reversed())
    }
}
