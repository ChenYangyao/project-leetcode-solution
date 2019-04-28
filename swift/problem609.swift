import Foundation

class Solution {
    func findDuplicate(_ paths: [String]) -> [[String]] {
        var duplicates = [Int:[String]]()
        
        for files in paths {
            let tmp = files.components(separatedBy: " ")
            let path = tmp[0]
            for fileIdx in 1..<tmp.count {
                let file = tmp[fileIdx]
                let sp = file.firstIndex(of: "(")!
                let fullPath = path + "/" + file[..<sp]
                let content = file[sp...].hashValue
                duplicates[content, default: [String]()].append(fullPath)
            }
        }
        
        return duplicates.values.filter{$0.count > 1}
    }
}
