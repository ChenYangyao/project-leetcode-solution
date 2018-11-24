#include "mystd.h"
using namespace MYSTD;

/**
 * The solution is almost the same as problem706 for hash map.
 * Adaptive increcement of bucket number is used when a bucket is full.
 */
class MyHashSet {
protected:
    static const int _max_n_prime = 63, _max_loading_factor = 11;
    static const int _primes[_max_n_prime];
public:
    /** Initialize your data structure here. */
    MyHashSet(): _cur_n_prime(0), _hash_set(_primes[_cur_n_prime]) { }

    void add(int key) {
        int id = key % _primes[ _cur_n_prime ];
        if( _hash_set[id].size() >= _max_loading_factor - 1 && _cur_n_prime != _max_n_prime - 1 ){
            reload();
            add(key);
        }else{
            for(auto & i: _hash_set[id])
                if( i == key ) return;
            _hash_set[id].push_back( key);
        }
    }

    void remove(int key) {
        int id = key % _primes[ _cur_n_prime ];
        auto & v = _hash_set[id];
        for( auto it = v.begin(); it != v.end(); ++it ){
            if( *it == key ){
                v.erase( it ); return;
            }
        }
    }
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int id = key % _primes[ _cur_n_prime ];
        for(const auto & i: _hash_set[id]){
            if( i == key ) return true;
        }
        return false;
    }
protected:
    typedef vector<vector< int> > set_type;
    int _cur_n_prime;
    set_type _hash_set;

    void reload(){
        int new_n_prime = _cur_n_prime + 1;
         set_type new_set( _primes[ new_n_prime ] );
         for( const auto & v: _hash_set){
            for(const auto & i: v){
                new_set[ i % _primes[ new_n_prime ] ].push_back(i);
            }
         }
         _hash_set = std::move( new_set );
         _cur_n_prime = new_n_prime;
    }
};

const int MyHashSet::_primes[MyHashSet::_max_n_prime] = {
        3, 5, 7, 11,
        13, 17, 19, 23, 29,
        31, 37, 41, 43, 47,
        53, 59, 61, 67, 71,
        73, 79, 83, 89, 97,
        101,103,113,127,131,
        149,151,179,193,197,
        199,241,251,277,293,
        307,337,353,383,389,
        433,439,443,487,503,
        547,593,601,631,647,
        653,683,691,809,829,
        839,953,991,997};



/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
