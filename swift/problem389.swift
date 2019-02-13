import Dispatch

extension String {
    func sum() -> UInt32 {
        var summation = UInt32(0)
        for char in self.unicodeScalars {
            summation += char.value
        }
        return summation
    }
    
    //much slower than sum() since sum2() converts String.UnicodeScalarView to [UInt32] before summation
    func sum2() -> UInt32 {
        return self.unicodeScalars.map{$0.value}.reduce(0,+)
    }
}

class Solution1 {
    func findTheDifference(_ s: String, _ t: String) -> Character {
        return Character(Unicode.Scalar((t.sum() - s.sum()))!)
    }
}

//about 30 times slower than Solution1. Sorting is time-consuming.
class Solution2 {
    func findTheDifference(_ s: String, _ t: String) -> Character {
        let s_array = s.sorted()
        let t_array = t.sorted()
        for index in 0..<s_array.count {
            if s_array[index] != t_array[index] {
                return t_array[index]
            }
        }
        return t_array.last!
    }
}

protocol sol {
    func findTheDifference(_ s: String, _ t: String) -> Character
}
extension Solution1: sol{}
extension Solution2: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.findTheDifference("sjdklfwequirojaiunjkdbnakjlhquiewhtuashlkjdbvjakldshquiehgqwiglhaajksdbnvakldnvjnqiluhtqiuwehqilheaksjdbkqlehqui","sjdklfwequirojdaiunjkdbnakjlhquiewhtuashlkjdbvjakldshquiehgqwiglhaajksdbnvakldnvjnqiluhtqiuwehqilheaksjdbkqlehqui")
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

time_consuming(Solution1(),"1",10000000)
time_consuming(Solution2(),"2",10000000)
