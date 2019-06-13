public struct blocks {
    public var left: Character
    public var right: Character
    
    public init(_ left: Character, _ right: Character) {
        self.left = left
        self.right = right
    }
}

extension blocks: Hashable {
    public var hashValue: Int {
        var hasher = Hasher()
        hash(into: &hasher)
        return hasher.finalize()
    }
    
    public func hash(into hasher: inout Hasher) {
        hasher.combine(self.left)
        hasher.combine(self.right)
    }
}

class Solution {
    private var allowedDict = [blocks:Set<Character>]()
    private var false_cache = Set<String>()
    
    func pyramidTransition(_ bottom: String, _ allowed: [String]) -> Bool {
        allowedDict = [blocks:Set<Character>]()
        false_cache = Set<String>()
        
        for entry in allowed {
            let entry = entry.map{$0}
            allowedDict[blocks(entry[0], entry[1]), default: Set<Character>()].insert(entry[2])
        }
        
        return pyramidTransition(bottom)
    }
    
    private func pyramidTransition(_ bottom: String) -> Bool {
        if (bottom.count == 1) {
            return true
        }
        
        if false_cache.contains(bottom) {
            return false
        }
        
        var nextLayers = [""]
        let thisLayer = bottom.map{$0}
        
        for idx in 0..<(bottom.count-1) {
            guard let allowed = allowedDict[blocks(thisLayer[idx], thisLayer[idx+1])] else {
                false_cache.insert(bottom)
                return false
            }
            var tmp = [String]()
            while !nextLayers.isEmpty {
                let cur = nextLayers.removeLast()
                for block in allowed {
                    tmp.append(cur + String(block))
                }
            }
            nextLayers = tmp
        }
        
        for nextLayer in nextLayers {
            if pyramidTransition(nextLayer) {
                return true
            }
        }
        
        false_cache.insert(bottom)
        return false
    }
}
