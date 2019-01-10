#ifndef ROBANALYSIS_H_
#define ROBANALYSIS_H_
#include "BestRob.h"
#include <my_random.h>
#include <mystats.h>
using namespace MYSTD;


class RobAnalysis{
public:
	RobAnalysis( string rtype, double mean, double sigma, 
		int num = 500000, int nrepeat = 53, 
		int nlink = 1, int ncorr = -1 )
	:_rtype(rtype), _mean(mean), _sigma(sigma), _num(num), _nrepeat(nrepeat),
	_nlink(nlink), _ncorr(ncorr){ }
	~RobAnalysis(){}
	
	vector<int> random_sequence( int seed ){
		vector<int> res;
		if( _rtype == "flat" ){
			MYMATH::RandomsInt<> rg( _mean - _sigma, _mean + _sigma, seed );
			rg( res, _num );
		}else if( _rtype == "normal" ){
			if( _ncorr <= 0 ){
				MYMATH::RandomsFloatN<> rg( _mean, _sigma, seed );
				for (int i = 0; i < _num; ++i){
					res.push_back( std::fabs(rg()) );
				}
			}else{
				MYMATH::RandomsFloatN<> rg( _mean, _sigma, seed ),
					rg_rich( _mean + 2.0*_sigma, _sigma, seed ),
					rg_poor( _mean - 2.0*_sigma, _sigma, seed );
				int cnt_poor = 0, tag = 0;
				double temp;
				for (int i = 0; i < _num; ++i){
					if( tag == 0 ){
						temp = std::fabs(rg());
						if( temp > _mean + 2.0*_sigma ) tag = 1;
					}else if(tag == 1){
						temp = std::fabs(rg_rich());
						++cnt_poor;
						if( cnt_poor == _ncorr ){ cnt_poor = 0; tag = 2; }
					}else{
						temp = std::fabs(rg_poor());
						++cnt_poor;
						if( cnt_poor == _ncorr ){ cnt_poor = 0; tag = 0; }
					}
					res.push_back(temp);
				}
			}
		}else if( _rtype == "log-normal" ){
			MYMATH::RandomsFloatLN<> rg( _mean, _sigma, seed );
			for (int i = 0; i < _num; ++i){
				res.push_back( rg() );
			}
		}else throw std::logic_error(my_tostr(
			SMYLPOS, ": sb! type ", _rtype, " is not valid.\n"
			"... generate randoms failed."
		));
		return res;
	}
	std::pair<double, double> rob_stats( ){
		int seed = 0;
		vector<double> best_robs;
		for (int i = 0; i < _nrepeat; ++i){
			auto nums = random_sequence( seed );
			seed = nums.back();
			best_robs.push_back( BestRob<-1>(_nlink).get(nums)/
				std::accumulate( nums.begin(), nums.end(), 0. ) );
		}
		double mean = MYMATH::mean( best_robs.data(), best_robs.size() ),
			sd = MYMATH::sd( best_robs.data(), best_robs.size() );
		return {mean, sd};
	}
protected:
	string _rtype;
	double _mean, _sigma;
	int _num, _nrepeat;
	int _nlink, _ncorr;
};

#endif