import Foundation

//brute force
class Solution1 {
    func rotateString(_ A: String, _ B: String) -> Bool {
        if (A.count != B.count) {
            return false
        } else if (A == "") {
            return true
        }
        
        var index_A = A.startIndex
        var index_B_ref = B.startIndex
        var index_B_mov = B.startIndex
        
        while (index_B_ref != B.endIndex) {
            if (B[index_B_ref] == A.first!) {
                index_A = A.startIndex
                index_B_mov = index_B_ref
                while (index_A != A.endIndex) {
                    if (index_B_mov == B.endIndex) {
                        index_B_mov = B.startIndex
                    }
                    if (A[index_A] != B[index_B_mov]) {
                        break
                    }
                    index_A = A.index(after: index_A)
                    index_B_mov = B.index(after: index_B_mov)
                }
                if (index_A == A.endIndex) {
                    return true
                }
            }
            index_B_ref = B.index(after: index_B_ref)
        }
        return false
    }
}

//using built-in contains method in Foundation
class Solution2 {
    func rotateString(_ A: String, _ B: String) -> Bool {
        return (A.count == B.count && (A + A).contains(B))
    }
}
