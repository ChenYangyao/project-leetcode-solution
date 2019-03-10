class Solution {
    private var cache = [Int:[[Int]]]()
    private var length = 0
    
    func allPathsSourceTarget(_ graph: [[Int]]) -> [[Int]] {
        var graph = graph; length = graph.count - 1
        cache[length] = [[Int]]()
        defer {
            cache = [Int:[[Int]]]()
        }
        return middleTarget(0,&graph)
    }
    
    private func middleTarget(_ start: Int, _ graph: inout [[Int]]) -> [[Int]] {
        if (cache[start] == nil) {
            var tmpAns = [[Int]]()
            for next in graph[start] {
                if (next == length) {
                    tmpAns.append([start,next])
                } else {
                    for path in middleTarget(next,&graph) {
                        tmpAns.append([start]+path)
                    }
                }
            }
            cache[start] = tmpAns
        }
        return cache[start]!
    }
}
