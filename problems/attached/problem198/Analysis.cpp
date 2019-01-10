#include "RobAnalysis.h"

void var_distribution(){
	string fname = "dist.dat";
	FILE_OF( fout, fname )
	for(auto i: {69,99}){
		for(auto j: {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000}){
			RobAnalysis robal("flat", 100, i, 500000, 53, j);
			auto rob_stats = robal.rob_stats();
			fout << "0 100 " << i << " " << j << " "
				<< rob_stats.first << " " << rob_stats.second << endl;
		}
	}
	for(auto i: {10.,20.,30.}){
		for(auto j: {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000}){
			RobAnalysis robal("normal", 100, i, 500000, 53, j);
			auto rob_stats = robal.rob_stats();
			fout << "1 100 " << i << " " << j << " "
				<< rob_stats.first << " " << rob_stats.second << endl;
		}
	}
	for(auto i: {.2, .3, .5}){
		for(auto j: {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000}){
			RobAnalysis robal("log-normal", .1, i, 500000, 53, j);
			auto rob_stats = robal.rob_stats();
			fout << "2 0.1 " << i << " "  << j << " "
				<< rob_stats.first << " " << rob_stats.second << endl;
		}
	}
}


void var_ncorr(){
	string fname = "ncorr.dat";
	FILE_OF(fout, fname)
	for(auto i: {-1,100,200,500,1000,2000,5000,10000}){
	for(auto j: {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000}){
			RobAnalysis robal("normal", 100, 33, 500000, 53, j, i);
			auto rob_stats = robal.rob_stats();
			fout << i << " " << j << " "
				<< rob_stats.first << " " << rob_stats.second << endl;
	}}
}

int main(int argc, char const *argv[]){
	//var_distribution();
	var_ncorr();
	return 0;
}