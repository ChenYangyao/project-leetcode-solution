//trivial problem. should be easy not medium
class Solution {
    func complexNumberMultiply(_ a: String, _ b: String) -> String {
        let a = parser(a); let b = parser(b)
        return String(a.re*b.re-a.im*b.im)+String("+")+String(a.re*b.im+a.im*b.re)+String("i")
    }
    
    private func parser(_ complex: String) -> (re: Int, im: Int) {
        var pair = (re: 0, im: 0); var part = 0; var sign = 1
        
        for char in complex.unicodeScalars {
            if (char != "+") {
                if (char == "-") {
                    sign = -1
                } else if (char != "i") {
                    part *= 10
                    part += (Int(char.value) - 48)
                }
            } else {
                pair.re = sign*part
                sign = 1; part = 0
            }
        }
        
        pair.im = sign*part
        
        return pair
    }
}
