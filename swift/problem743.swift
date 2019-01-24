class Solution1 {
    typealias link = (target: Int, delay: Int)
    
    private class node {
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
            dict[time[0]]!.next.append((time[1],time[2]))
        }
        
        dict[K]!.distance = 0
        
        while (visited.count != N) {
            var shortestDist = Int.max; var shortestIndex = 0
            for index in visited {
                let tmpNode = dict[index]!
                var counter = 0
                for connectedNodes in tmpNode.next {
                    let tmpIndex = connectedNodes.target
                    //remove link once visited
                    if visited.contains(tmpIndex) {
                        _ = tmpNode.next.remove(at: counter)
                        continue
                    }
                    counter += 1
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

//use linked list to speed up deleting visited link
class Solution2 {
    private class link {
        var target: Int
        var delay: Int
        var next: link?
        
        init(_ target: Int, _ delay: Int) {
            self.target = target
            self.delay = delay
        }
    }
    
    private class node {
        var distance = Int.max
        var linked: link?
    }
    
    func networkDelayTime(_ times: [[Int]], _ N: Int, _ K: Int) -> Int {
        var dict = [Int:node]()
        var visited = Set([K])
        
        for index in 1...N {
            dict[index] = node()
        }
        
        for time in times {
            let pt = link(time[1],time[2])
            pt.next = dict[time[0]]!.linked
            dict[time[0]]!.linked = pt
        }
        
        dict[K]!.distance = 0
        
        while (visited.count != N) {
            var shortestDist = Int.max; var shortestIndex = 0
            for index in visited {
                let tmpNode = dict[index]!
                var links = tmpNode.linked
                while (links != nil) {
                    let tmpIndex = links!.target
                    if visited.contains(tmpIndex) {
                        //ref: problem237
                        if (links!.next == nil) {
                            links = nil
                        } else {
                            let tmpList = links!.next!
                            links!.target = tmpList.target
                            links!.delay = tmpList.delay
                            links!.next = tmpList.next
                        }
                        continue
                    }
                    let tmpDist = links!.delay + tmpNode.distance
                    let prevDist = dict[tmpIndex]!.distance
                    if (tmpDist < prevDist) {
                        dict[tmpIndex]!.distance = tmpDist
                    }
                    if (tmpDist < shortestDist) {
                        shortestDist = tmpDist
                        shortestIndex = tmpIndex
                    }
                    links = links!.next
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
