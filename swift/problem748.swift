import Dispatch

class Solution {
    private let prime: Array<UInt> = [2, 3, 5, 7, 11, 13, 17] //the max length of licensePlate is 7
    private var plate = [Int:UInt]()
    
    func shortestCompletingWord(_ licensePlate: String, _ words: [String]) -> String {
        let eigenvalue = eigenmode(licensePlate)
        var output = String(repeating: " ", count: 16)
        for word in words {
            if (word.count < output.count && eigen(word) % eigenvalue == 0) {
                output = word
            }
        }
        defer {
            plate = [Int:UInt]()
        }
        return output
    }
    
    private func eigenmode(_ licensePlate: String) -> UInt {
        let licensePlate = licensePlate.unicodeScalars
        var count = 0
        var eigenvalue = UInt(1)
        for char in licensePlate {
            let tmp = Int(char.value)
            if (tmp >= 97) {
                if (plate[tmp] == nil) {
                    plate[tmp] = prime[count]
                    count += 1
                }
                eigenvalue *= plate[tmp]!
            } else if (tmp >= 65) {
                if (plate[tmp+32] == nil) {
                    plate[tmp+32] = prime[count]
                    count += 1
                }
                eigenvalue *= plate[tmp+32]!
            }
        }
        return eigenvalue
    }
    
    private func eigen(_ word: String) -> UInt {
        let word = word.unicodeScalars
        var eigenvalue = UInt(1)
        for char in word {
            if let tmp = plate[Int(char.value)] {
                eigenvalue *= tmp
            }
        }
        return eigenvalue
    }
}

let licensePlate = "Ih DTR2351"
let words = ["first","second","third"]

protocol sol {
    func shortestCompletingWord(_ licensePlate: String, _ words: [String]) -> String
}
extension Solution: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.shortestCompletingWord(licensePlate, words)
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

time_consuming(Solution(),"1",1000)
print(Solution().shortestCompletingWord(licensePlate, words))
