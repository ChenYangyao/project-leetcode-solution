#include <mystd.h>
#include <my_random.h>
#include <mytime.h>

using namespace MYSTD;

string generate_moves( size_t n  ){
    std::default_random_engine e(std::clock());
    std::uniform_int_distribution<int> d(0,3);
    string moves;
    for (size_t i = 0; i < n; ++i){
        int temp = d( e );
        if( temp == 0 ){ moves += 'L'; }
        else if( temp == 1 ){ moves += 'R'; }
        else if( temp == 2 ){ moves += 'D'; }
        else{ moves += 'U'; }
    }
    return moves;
}

bool judge_circle_count( const string & moves ){
    if( std::count( moves.begin(), moves.end(), 'L' ) == std::count( moves.begin(), moves.end(), 'R' )
        && std::count( moves.begin(), moves.end(), 'D' ) == std::count( moves.begin(), moves.end(), 'U' )
    ){
        return true;
    }else{
        return false;
    }
}

size_t mycount( const string & s, char t ){
    size_t n = 0;
    for( const auto & i: s ){
        if( i == t ){ ++n; }
    }
    return n;
}

bool judge_circle_mycount( const string & moves ){
    if( mycount( moves, 'L' ) == mycount( moves, 'R' )
        && mycount( moves, 'D' ) == mycount( moves, 'U' )
    ){
        return true;
    }else{
        return false;
    }
}

bool judge_circle_xy( const string & moves ){
    int x = 0, y = 0;
    for( const auto & i : moves ){
        switch( i ){
            case 'L': x -= 1; break;
            case 'R': x += 1; break;
            case 'D': y -= 1; break;
            default: y += 1; break;
        }
    }
    return (x || y) ? false: true;
}

bool judge_circle_xy2( const string & moves ){
    int x = 0, y = 0;
    for( const auto & i : moves ){
        if( i == 'L' ){ x -= 1; }
        else if( i == 'R' ){ x += 1; }
        else if( i == 'D' ){ y -= 1; }
        else{ y += 1; }
    }
    return (x || y) ? false: true;
}

int main(int argc, char const *argv[]){


    size_t n[] = {100,10000,1000000};
    for( auto i: n ){
        cout << "length of moves = " << i << endl;
        cout << "loop times 10 for each moves" << endl;
        auto s = generate_moves( i );
        MYTIME::TimeRecord timer;
        timer.record_call_repeated( "count", judge_circle_count, 10, std::ref( s )  );
        //timer.record_call_repeated( "mycount", judge_circle_mycount, 10, std::ref( s )  );
        timer.record_call_repeated( "xy switch", judge_circle_xy, 10, std::ref( s )  );
        timer.record_call_repeated( "xy if", judge_circle_xy2, 10, std::ref( s )  );
        timer.show_info();
    }
    return 0;
}
