#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("Board Test") {
    Board b;
    CHECK(b.read(0,0,Direction::Horizontal,5) == "_____");
    b.post(0,2,Direction::Vertical,"board");
    /*
       01234    
    0  __b__
    1  __o__
    2  __a__
    3  __r__
    4  __d__
    */
    CHECK(b.read(0,0,Direction::Horizontal,5) == "__b__");
    CHECK(b.read(4,2,Direction::Horizontal,1) == "d");
    CHECK(b.read(0,2,Direction::Vertical,5) == "board");
    b.post(3,1,Direction::Horizontal,"cpp");
    /*
       01234    
    0  __b__
    1  __o__
    2  __a__
    3  _cpp_
    4  __d__
    */
    CHECK(b.read(0,2,Direction::Vertical,5) == "boapd");
    CHECK(b.read(3,0,Direction::Horizontal,5) == "_cpp_");
    b.post(4,0,Direction::Horizontal,"xxxxx");
    /*
       01234    
    0  __b__
    1  __o__
    2  __a__
    3  _cpp_
    4  xxxxx
    */
    CHECK(b.read(0,2,Direction::Vertical,5) == "boapx");
    CHECK(b.read(0,1,Direction::Vertical,5) == "___cx");
    CHECK(b.read(4,0,Direction::Vertical,3) == "x__");
    CHECK(b.read(4,4,Direction::Horizontal,3) == "x__");
    b.post(0,2,Direction::Vertical,"yyyzz");
    /*
       01234    
    0  __y__
    1  __y__
    2  __y__
    3  _czp_
    4  xxzxx
    */
    CHECK(b.read(0,2,Direction::Vertical,5) == "yyyzz");
    CHECK(b.read(3,0,Direction::Horizontal,5) == "_czp_");
    CHECK(b.read(2,0,Direction::Horizontal,3) == "__y");
    CHECK(b.read(4,0,Direction::Horizontal,5) == "xxzxx");
    CHECK(b.read(3,3,Direction::Horizontal,1) == "p");

    b.post(0,0,Direction::Horizontal,"00 11");
    /*
       01234    
    0  00 11
    1  __y__
    2  __y__
    3  _czp_
    4  xxzxx
    */
    CHECK(b.read(0,0,Direction::Vertical,5) == "0___x");
    CHECK(b.read(0,2,Direction::Horizontal,1) == " ");
    CHECK(b.read(3,1,Direction::Horizontal,3) == "czp");
    CHECK(b.read(10,0,Direction::Horizontal,2) == "__");
    CHECK(b.read(1,2,Direction::Vertical,2) == "yy");
}
