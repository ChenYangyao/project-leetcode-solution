#ifndef BESTROB_H_
#define BESTROB_H_
#include <mystd.h>
using namespace std;

/**
 * -------------------------------------------------------------------------
 * As suggested by Ziyang, there is a more elegant implementation.
 * For houses that conntected to 1 neighbor, we only need to keep
 * record of the last two best results ever found during iteration.
 * (see Swift solution for the detail.)
 * 
 * Here is a more general solution, although it might be a little bit 
 * inefficient. The template argument NLink represent how many neighbor
 * houses are connected by the security system.
 * The solution for Leetcode problem (NLink = 1) can be obtained by 
 *          BestRob<1>().get(nums);
 * Solution with other link-length NLink can be obtained by
 *          BestRob<NLink>.get(nums);
 *
 * The template version is fast due to the compiling-time determination
 * of NLink. For flexibility we also provide a run-time version, with 
 * template argument to be -1, but NLink passed through constructor at 
 * run-time. The calling can be like (where NLink now can be a run-time 
 * variable):
 *          BestRob<-1>(NLink).get(nums);
 *
 * Author: Yangyao, 2019/01/07
 * Copied from /cpp/problem198.cpp
 * -------------------------------------------------------------------------
 */
template<int NLink = 1>
class BestRob{
public:
    int get( vector<int> &nums ){
        int cur;
        for (int i = 0, n = nums.size(); i < n; ++i){
            cur = max( best[ (i+1)%(NLink+1) ] + nums[i], best[ (i)%(NLink+1) ] );
            best[ (i+1)%(NLink+1) ] = cur;
        }
        return *max_element(best, best+NLink+1);
    }
protected:
    int best[ NLink + 1 ] = {};
};

template<>
class BestRob<-1>
{
public:
    BestRob(int _NLink): NLink(_NLink), best(NLink + 1, 0){}
    int get( vector<int> &nums ){
        int cur;
        for (int i = 0, n = nums.size(); i < n; ++i){
            cur = max( best[ (i+1)%(NLink+1) ] + nums[i], best[ (i)%(NLink+1) ] );
            best[ (i+1)%(NLink+1) ] = cur;
        }
        return *max_element(best.data(), best.data()+NLink+1);
    }
protected:
    int NLink;
    vector<int> best;
};


#endif