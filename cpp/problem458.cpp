#include <mystd.h>
using namespace MYSTD;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    	int tot_num_pigs = getTotNumPigs( buckets ),
    		num_turn = (minutesToTest - 1) / minutesToDie;
    	return (tot_num_pigs + num_turn - 1) / num_turn + 1;
    }
    int getTotNumPigs(int buckets){
    	int num_buckets = 2, tot_num_pigs = 1;
    	while( num_buckets < buckets ){
    		++tot_num_pigs;
    		num_buckets <<= 1;
    	}
    	return tot_num_pigs;
    }
};

int main(int argc, char const *argv[]){
	Solution sol;
	cout << sol.poorPigs( 1000, 15, 60 ) << endl;
	cout << sol.poorPigs( 1024, 15, 60 ) << endl;
	return 0;
}