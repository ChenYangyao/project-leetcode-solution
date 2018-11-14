import Accelerate

class Solution {
    func imageSmoother(_ M: [[Int]]) -> [[Int]] {
        let row = M.count
        let col = M[0].count
        
        if (row > 2 && col > 2) {
            let c1: Float = 1.0/9.0
            let c2: Float = 1.0/6.0
            let c3: Float = 3.0/2.0
            var M = M.compactMap{$0.compactMap{Float($0)}}
            var ans = M
            
            //sum every row with adjacent row(s)
            for r in 0..<(row-1) {
                catlas_saxpby(Int32(col),1.0,M[r+1],1,1.0,&ans[r][0],1)
            }
            for r in 1..<row {
                catlas_saxpby(Int32(col),1.0,M[r-1],1,1.0,&ans[r][0],1)
            }
            
            //transport ans
            var M_1D = [Float](repeating: 0.0, count: col*row)
            vDSP_mtrans(ans.flatMap{$0},1,&M_1D,1,vDSP_Length(col),vDSP_Length(row))
            M = generator(&M_1D, col, row); ans = M
            
            //sum every column with adjacent column(s)
            for r in 0..<(col-1) {
                catlas_saxpby(Int32(row),1.0,M[r+1],1,1.0,&ans[r][0],1)
            }
            for r in 1..<col {
                catlas_saxpby(Int32(row),1.0,M[r-1],1,1.0,&ans[r][0],1)
            }
            
            //take average of leftmost and rightmost columns
            cblas_sscal(Int32(row),c3,&ans[0][0],1)
            cblas_sscal(Int32(row),c3,&ans[col-1][0],1)
            
            //transport ans
            vDSP_mtrans(ans.flatMap{$0},1,&M_1D,1,vDSP_Length(row),vDSP_Length(col))
            M = generator(&M_1D, row, col); ans = M
            
            //take average of inner part rows
            for r in 1..<(row-1) {
                cblas_sscal(Int32(col),c1,&ans[r][0],1)
            }
            
            //take average of uppermost and lowermost rows
            cblas_sscal(Int32(col),c2,&ans[0][0],1)
            cblas_sscal(Int32(col),c2,&ans[row-1][0],1)
            
            return ans.compactMap{$0.compactMap{Int($0)}}
        }
        
        if (row < 3 && col < 3) {
            if (row*col == 0) {
                return M
            }
            return Array(repeating: Array(repeating: M.flatMap{$0}.reduce(0,+)/(row*col), count: col), count: row)
        }
        
        return small(M, row, col)
    }
    
    //generate matrix from 1D array
    private func generator(_ M_1D: inout [Float], _ row: Int, _ col: Int) -> [[Float]] {
        var M = [[Float]](repeating: [Float](repeating: 0.0, count: col), count: row)
        for r in 0..<row {
            for c in 0..<col {
                M[r][c] = M_1D[r*col+c]
            }
        }
        return M
    }
    
    private func small(_ M: [[Int]], _ row: Int, _ col: Int) -> [[Int]] {
        var ans = M
        if (row == 1 || col == 1) {
            if (col == 1) {
                for r in 1..<(row-1) {
                    ans[r][0] = (M[r-1][0]+M[r][0]+M[r+1][0])/3
                }
                ans[0][0] = (M[0][0]+M[1][0])/2
                ans[row-1][0] = (M[row-2][0]+M[row-1][0])/2
            } else {
                for c in 1..<(col-1) {
                    ans[0][c] = (M[0][c-1]+M[0][c]+M[0][c+1])/3
                }
                ans[0][0] = (M[0][0]+M[0][1])/2
                ans[0][col-1] = (M[0][col-2]+M[0][col-1])/2
            }
            return ans
        }

        if (row == 2) {
            for r in 0...1 {
                for c in 1..<(col-1) {
                    ans[r][c] = M[r][c-1]+M[r][c]+M[r][c+1]
                }
                ans[r][0] = M[r][0]+M[r][1]
                ans[r][col-1] = M[r][col-2]+M[r][col-1]
            }
            for c in 1..<(col-1) {
                ans[0][c] = (ans[0][c]+ans[1][c])/6
                ans[1][c] = ans[0][c]
            }
            ans[0][0] = (ans[0][0]+ans[1][0])/4
            ans[1][0] = ans[0][0]
            ans[0][col-1] = (ans[0][col-1]+ans[1][col-1])/4
            ans[1][col-1] = ans[0][col-1]
        } else {
            for c in 0...1 {
                for r in 1..<(row-1) {
                    ans[r][c] = M[r-1][c]+M[r][c]+M[r+1][c]
                }
                ans[0][c] = M[0][c]+M[1][c]
                ans[row-1][c] = M[row-2][c]+M[row-1][c]
            }
            for r in 1..<(row-1) {
                ans[r][0] = (ans[r][0]+ans[r][1])/6
                ans[r][1] = ans[r][0]
            }
            ans[0][0] = (ans[0][0]+ans[0][1])/4
            ans[0][1] = ans[0][0]
            ans[row-1][0] = (ans[row-1][0]+ans[row-1][1])/4
            ans[row-1][1] = ans[row-1][0]
        }
        
        return ans
    }
}

protocol sol {
    func imageSmoother(_ M: [[Int]]) -> [[Int]]
}
extension Solution: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    var M = Array(repeating: Array(repeating: 0, count: 1920), count: 1080)
    for i in 0..<1080 {
        for j in 0..<1920 {
            M[i][j] = Int.random(in: 0...255)
        }
    }
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.imageSmoother(M)
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

time_consuming(Solution(),"1080p",100)

//1080p 8680 ms for 100 times
