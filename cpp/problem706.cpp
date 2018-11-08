#include "mystd.h"
using namespace MYSTD;


class MyHashMap {
protected:
    static const int _max_n_prime = 24, _max_loading_factor = 10;
    static const int _primes[_max_n_prime];
public:
    /** Initialize your data structure here. */
    MyHashMap(): _cur_n_prime(0), _hash_map(_primes[_cur_n_prime]) { }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int id = key % _primes[ _cur_n_prime ];
        if( _hash_map[id].size() == _max_loading_factor - 1 && _cur_n_prime != _max_n_prime - 1 ){
            reload();
            put(key, value);
        }else{
            for(auto & i: _hash_map[id]){
                if( i.first == key ){
                    i.second = value;
                    return;
                }
            }
            _hash_map[id].emplace_back( key, value );
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int id = key % _primes[ _cur_n_prime ];
        for(const auto & i: _hash_map[id]){
            if( i.first == key ) return i.second;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int id = key % _primes[ _cur_n_prime ];
        auto & v = _hash_map[id];
        for( auto it = v.begin(); it != v.end(); ++it ){
            if( it->first == key ){
                v.erase( it ); return;
            }
        }
    }
protected:
    typedef std::pair<int, int> pair_type;
    typedef vector<vector< pair_type> > map_type;

    int _cur_n_prime;
    map_type _hash_map;

    void reload(){
        int new_n_prime = _cur_n_prime + 1;
         map_type new_map( _primes[ new_n_prime ] );
         for( const auto & v: _hash_map){
            for(const auto & i: v){
                new_map[ i.first % _primes[ new_n_prime ] ].emplace_back( i.first, i.second );
            }
         }
         _hash_map = std::move( new_map );
         _cur_n_prime = new_n_prime;
    }
};

const int MyHashMap::_primes[MyHashMap::_max_n_prime] = {3, 5, 7, 11,
        13, 17, 19, 23, 29,
        31, 37, 41, 43, 47,
        53, 59, 61, 67, 71,
        73, 79, 83, 89, 97};
