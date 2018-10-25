#include <iostream>
#include <sstream>
#include <unordered_map>
#include <cstdlib>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int > pairs;
        int pos;
        int ct;
        for( auto const & s: cpdomains ){
            pos = s.find( ' ' );
            ct = stoi( s.substr( 0, pos ) );
            do{
                pairs[ s.substr( pos+1 ) ] += ct;
                pos = s.find('.', pos+1);
            }while( pos != string::npos );
        }
        vector<string> res;
        for( auto const & i: pairs ) res.emplace_back( to_string(i.second) + ' ' + i.first );
        return res;
    }
};
