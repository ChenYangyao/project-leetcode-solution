class Solution {
    struct link {
        var target: Int
        var delay: Int
        
        init(_ target: Int, _ delay: Int) {
            self.target = target
            self.delay = delay
        }
    }
    
    struct node {
        var distance = Int.max
        var next = [link]()
    }
    
    func networkDelayTime(_ times: [[Int]], _ N: Int, _ K: Int) -> Int {
        var dict = [Int:node]()
        var visited = Set([K])
        
        for index in 1...N {
            dict[index] = node()
        }
        
        for time in times {
            dict[time[0]]!.next.append(link(time[1],time[2]))
        }
        
        dict[K]!.distance = 0
        
        while (visited.count != N) {
            var shortestDist = Int.max; var shortestIndex = 0
            for index in visited {
                let tmpNode = dict[index]!
                for connectedNodes in tmpNode.next {
                    let tmpIndex = connectedNodes.target
                    if visited.contains(tmpIndex) {
                        continue
                    }
                    let tmpDist = connectedNodes.delay + tmpNode.distance
                    let prevDist = dict[tmpIndex]!.distance
                    if (tmpDist < prevDist) {
                        dict[tmpIndex]!.distance = tmpDist
                    }
                    if (tmpDist < shortestDist) {
                        shortestDist = tmpDist
                        shortestIndex = tmpIndex
                    }
                }
            }
            if (shortestIndex == 0) {
                return -1
            }
            visited.insert(shortestIndex)
        }
        
        var maxDelay = 0
        
        for nodes in dict.values where (nodes.distance > maxDelay) {
            maxDelay = nodes.distance
        }
        
        return maxDelay
    }
}
