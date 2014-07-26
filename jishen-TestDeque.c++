// ----------------------------
// projects/deque/TestDeque.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

/*
Google Test Libraries:
    % ls -al /usr/include/gtest/
    ...
    gtest.h
    ...

    % locate libgtest.a
    /usr/lib/libgtest.a

    % locate libpthread.a
    /usr/lib/x86_64-linux-gnu/libpthread.a
    /usr/lib32/libpthread.a

    % locate libgtest_main.a
    /usr/lib/libgtest_main.a

To compile the test:
    % g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Integer.c++ TestInteger.c++ -o TestInteger -lgtest -lgtest_main -lpthread

To run the test:
    % valgrind TestInteger

To obtain coverage of the test:
    % gcov-4.7 -b Integer.c++ TestInteger.c++
*/

// --------
// includes
// --------

#include <algorithm> // equal
#include <cstring>   // strcmp
#include <deque>     // deque
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==

#include "gtest/gtest.h"

#include "Deque.h"


#define ALL_OF_IT       typedef typename TestFixture::deque_type      deque_type; \
                        typedef typename TestFixture::allocator_type  allocator_type; \
                        typedef typename TestFixture::value_type      value_type; \
                        typedef typename TestFixture::size_type       size_type; \
                        typedef typename TestFixture::difference_type difference_type; \
                        typedef typename TestFixture::pointer         pointer; \
                        typedef typename TestFixture::const_pointer   const_pointer; \
                        typedef typename TestFixture::reference       reference; \
                        typedef typename TestFixture::const_reference const_reference;

// ---------
// TestDeque
// ---------

template <typename D>
struct TestDeque : testing::Test {
    // --------
    // typedefs
    // --------

    typedef          D                  deque_type;
    typedef typename D::allocator_type  allocator_type;
    typedef typename D::value_type      value_type;
    typedef typename D::size_type       size_type;
    typedef typename D::difference_type difference_type;
    typedef typename D::pointer         pointer;
    typedef typename D::const_pointer   const_pointer;
    typedef typename D::reference       reference;
    typedef typename D::const_reference const_reference;};

typedef testing::Types<
            std::deque<int>,
            std::deque<double>,
            my_deque<int>,
            my_deque<double> >
        my_types;

TYPED_TEST_CASE(TestDeque, my_types);

/*

TEST(TestDeque, insert_7) {
    //ALL_OF_IT
    using namespace std;
    my_deque<string> d(5,"3");
    
    //ASSERT_EQ(d.size(), 16);
    
    
    
    d.insert(++d.begin(), "77");
    
    //ASSERT_EQ(d.size(), 17);
    
}
TEST(TestDeque, insert_9) {
//ALL_OF_IT
using namespace std;
my_deque<int> d;
d.push_back(7);
d.push_back(9);
ASSERT_EQ(d.size(), 2);
ASSERT_EQ(d[0], 7);
ASSERT_EQ(d[1], 9);


d.insert(++d.begin(), 77);

ASSERT_EQ(d.size(), 3);
ASSERT_EQ(d[0], 7);
ASSERT_EQ(d[1], 77);
ASSERT_EQ(d[2], 9);
    //d.print_deque();
}
TEST(TestDeque, erase_11) {
    //ALL_OF_IT
    using namespace std;
    my_deque<string> d;
    d.push_back("7");
    d.push_back("9");
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], "7");
    ASSERT_EQ(d[1], "9");
    
    d.erase(d.begin());
    ASSERT_EQ(d.size(), 1);
    ASSERT_EQ(d[0], "9");
    
}*/


TYPED_TEST(TestDeque, Empty) {
    using namespace std;
    ALL_OF_IT
    
    deque_type x;
    
    const bool b = x.empty();
    ASSERT_TRUE(b);
}

TYPED_TEST(TestDeque, Size) {
    ALL_OF_IT
    deque_type x;
    const size_type s = x.size();
    ASSERT_EQ(0, s);
}


 
TYPED_TEST(TestDeque, push_back_1) {

    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    ASSERT_EQ(d[0], 7);
}

TYPED_TEST(TestDeque, push_back_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    //d.print_deque();
    d.push_back(7);
    d.push_back(6);
    d.push_back(5);
    d.push_back(4);
    d.push_back(3);
    d.push_back(2);
    d.push_back(1);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 6);
    ASSERT_EQ(d[2], 5);
    ASSERT_EQ(d[3], 4);
    ASSERT_EQ(d[4], 3);
    ASSERT_EQ(d[5], 2);
    ASSERT_EQ(d[6], 1);

}



TYPED_TEST(TestDeque, push_back_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    //pair<int,int> x = make_pair(3, 4);
    d.push_back(789);
    ASSERT_EQ(d[0], 789);
}


TYPED_TEST(TestDeque, push_back_4) {
    
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 8);
}


TYPED_TEST(TestDeque, push_back_5) {
    
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 8);
    d.pop_back();
    d.push_back(4);
    ASSERT_EQ(d[1], 4);
}


TYPED_TEST(TestDeque, push_back_6) {
    
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 8);
    d.pop_back();
    d.push_back(4);
    ASSERT_EQ(d[1], 4);
    d.push_back(2);
    ASSERT_EQ(d[2], 2);
}

TYPED_TEST(TestDeque, push_back_7) {
    
    ALL_OF_IT
    using namespace std;
    deque_type d;
    int NUM_OF_PUSH = 100;
    for(int i = 0; i < NUM_OF_PUSH; ++i)
        d.push_back(i);
    
    for(int i = 0; i < NUM_OF_PUSH; ++i)
        ASSERT_EQ(d[i], i);
}

TYPED_TEST(TestDeque, push_front_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(7);
    ASSERT_EQ(d[0], 7);
}

TYPED_TEST(TestDeque, push_front_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    //d.print_deque();
    int NUM_OF_PUSH = 100;
    for(int i = NUM_OF_PUSH; i >= 0; --i)
        d.push_front(i);

    for(int i = 0; i <= NUM_OF_PUSH; ++i)
        ASSERT_EQ(d[i], i);
    
    
}

TYPED_TEST(TestDeque, push_front_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(7);
    d.push_front(6);
    ASSERT_EQ(d[0], 6);
}

TYPED_TEST(TestDeque, push_front_4) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(7);
    d.push_front(6);
    ASSERT_EQ(d[0], 6);
    d.push_front(3);
    ASSERT_EQ(d[0], 3);
}
TYPED_TEST(TestDeque, push_front_5) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(7);
    d.push_front(6);
    ASSERT_EQ(d[0], 6);
    d.push_front(3);
    ASSERT_EQ(d[0], 3);
    d.push_front(2);
    ASSERT_EQ(d[0], 2);
}
TYPED_TEST(TestDeque, push_front_6) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(7);
    d.push_front(6);
    ASSERT_EQ(d[0], 6);
    d.push_front(3);
    ASSERT_EQ(d[0], 3);
    d.push_front(2);
    ASSERT_EQ(d[0], 2);
    d.pop_front();
    d.push_front(4);
    ASSERT_EQ(d[0], 4);
}


TYPED_TEST(TestDeque, pop_front_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(6);
    d.push_back(5);
    d.pop_front();
    ASSERT_EQ(d.size(), 2);
}

TYPED_TEST(TestDeque, pop_front_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(9);
    d.pop_front();
    ASSERT_EQ(d.size(), 0);
}

TYPED_TEST(TestDeque, pop_front_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(7);
    d.push_front(6);
    d.push_front(5);
    d.pop_front();
    ASSERT_EQ(d.size(), 2);
}
TYPED_TEST(TestDeque, pop_front_4) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    //d.push_back(6);
    d.push_back(5);
    d.pop_front();
    ASSERT_EQ(d.size(), 1);
}
TYPED_TEST(TestDeque, pop_front_5) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(6);
    d.push_back(5);
    d.pop_front();
    ASSERT_EQ(d.size(), 2);
    d.pop_back();
    ASSERT_EQ(d.size(), 1);
}
TYPED_TEST(TestDeque, pop_front_6) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(6);
    d.push_back(5);
    d.pop_front();
    ASSERT_EQ(d.size(), 2);
    d.pop_back();
    ASSERT_EQ(d.size(), 1);
    d.pop_back();
    ASSERT_EQ(d.size(), 0);
}


TYPED_TEST(TestDeque, pop_back_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(6);
    d.push_back(5);
    d.pop_back();
    ASSERT_EQ(d.size(), 2);
}

TYPED_TEST(TestDeque, pop_back_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(9);
    d.pop_back();
    ASSERT_EQ(d.size(), 0);
}

TYPED_TEST(TestDeque, pop_back_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(7);
    d.push_front(6);
    d.push_front(5);
    d.pop_back();
    ASSERT_EQ(d.size(), 2);
}
TYPED_TEST(TestDeque, pop_back_4) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    //d.push_back(6);
    d.push_back(5);
    d.pop_back();
    ASSERT_EQ(d.size(), 1);
}
TYPED_TEST(TestDeque, pop_back_5) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(6);
    d.push_back(5);
    d.pop_back();
    ASSERT_EQ(d.size(), 2);
    d.pop_back();
    ASSERT_EQ(d.size(), 1);
}
TYPED_TEST(TestDeque, pop_back_6) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(6);
    d.push_back(5);
    d.pop_back();
    ASSERT_EQ(d.size(), 2);
    d.pop_back();
    ASSERT_EQ(d.size(), 1);
    d.pop_back();
    ASSERT_EQ(d.size(), 0);
}

TYPED_TEST(TestDeque, front_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    //d.pop_back();
    //d.print_deque();
    //int tt = d.front();
    ASSERT_EQ(d.front(), 1);
}

TYPED_TEST(TestDeque, front_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    //d.pop_back();
    //d.print_deque();

    ASSERT_EQ(d.front(), 3);
    d.pop_front();
    ASSERT_EQ(d.front(), 2);
}

TYPED_TEST(TestDeque, front_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    //d.pop_back();
    //d.print_deque();
    
    ASSERT_EQ(d.front(), 3);
    d.pop_front();
    ASSERT_EQ(d.front(), 2);
    d.push_front(9);
    ASSERT_EQ(d.front(), 9);
}
TYPED_TEST(TestDeque, front_4) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    //d.pop_back();
    //d.print_deque();
    //int tt = d.front();
    ASSERT_EQ(d.front(), 1);
    d.pop_front();
    ASSERT_EQ(d.front(), 2);
}
TYPED_TEST(TestDeque, front_5) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    //d.pop_back();
    //d.print_deque();
    //int tt = d.front();
    ASSERT_EQ(d.front(), 1);
    d.pop_front();
    ASSERT_EQ(d.front(), 2);
    d.pop_front();
    ASSERT_EQ(d.front(), 3);
}
TYPED_TEST(TestDeque, front_6) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    //d.pop_back();
    //d.print_deque();
    //int tt = d.front();
    ASSERT_EQ(d.front(), 1);
    d.pop_front();
    ASSERT_EQ(d.front(), 2);
    d.push_front(7);
    ASSERT_EQ(d.front(), 7);
}



TYPED_TEST(TestDeque, const_front_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    const deque_type e(d);
    ASSERT_EQ(e.front(), 1);
}

TYPED_TEST(TestDeque, const_front_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    //d.pop_back();
    //d.print_deque();
    
    const deque_type e(d);
    
    ASSERT_EQ(e.front(), 3);
    //d.pop_front();
    //ASSERT_EQ(d.front(), 2);
}

TYPED_TEST(TestDeque, const_front_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    //d.pop_back();
    //d.print_deque();
    
    const deque_type e(d);
    
    ASSERT_EQ(d.front(), 3);
}



TYPED_TEST(TestDeque, back_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    ASSERT_EQ(d.back(), 3);
}
TYPED_TEST(TestDeque, back_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    ASSERT_EQ(d.back(), 3);
    d.pop_back();
    ASSERT_EQ(d.back(), 2);
}
TYPED_TEST(TestDeque, back_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    
    ASSERT_EQ(d.back(), 1);
    d.pop_back();
    ASSERT_EQ(d.back(), 2);
}
TYPED_TEST(TestDeque, back_4) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    //d.push_back(3);
    
    ASSERT_EQ(d.back(), 2);
}
TYPED_TEST(TestDeque, back_5) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    ASSERT_EQ(d.back(), 3);
    d.push_back(9);
    ASSERT_EQ(d.back(), 9);
}
TYPED_TEST(TestDeque, back_6) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    ASSERT_EQ(d.back(), 3);
    d.push_back(9);
    ASSERT_EQ(d.back(), 9);
    d.pop_back();
    ASSERT_EQ(d.back(), 3);
}
TYPED_TEST(TestDeque, back_7) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    ASSERT_EQ(d.back(), 3);
    d.push_back(9);
    ASSERT_EQ(d.back(), 9);
    d.pop_back();
    ASSERT_EQ(d.back(), 3);
    d.push_front(66);
    ASSERT_EQ(d.back(), 3);

}



TYPED_TEST(TestDeque, at_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    
    ASSERT_EQ(d.at(0), 3);
    ASSERT_EQ(d.at(1), 2);
}

TYPED_TEST(TestDeque, at_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    ASSERT_EQ(d.at(0), 1);
    ASSERT_EQ(d.at(1), 2);
    
    try {
        d.at(3);
        ASSERT_TRUE(false);
    } catch (std::out_of_range) {
        ASSERT_TRUE(true);
    }
}

TYPED_TEST(TestDeque, at_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    ASSERT_EQ(d.at(0), 1);
    ASSERT_EQ(d.at(1), 2);
    ASSERT_EQ(d.at(2), 3);
    
    d.pop_back();
    d.push_back(5);
    ASSERT_EQ(d.at(2), 5);
    
}

TYPED_TEST(TestDeque, const_at_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.at(0), 3);
    ASSERT_EQ(e.at(1), 2);
}

TYPED_TEST(TestDeque, const_at_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    ASSERT_EQ(d.at(0), 1);
    ASSERT_EQ(d.at(1), 2);
    
    const deque_type e(d);
    
    try {
        e.at(3);
        ASSERT_TRUE(false);
    } catch (std::out_of_range) {
        ASSERT_TRUE(true);
    }
}

TYPED_TEST(TestDeque, const_at_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.at(0), 1);
    ASSERT_EQ(e.at(1), 2);
    ASSERT_EQ(e.at(2), 3);
    
}

////////////
/// []

TYPED_TEST(TestDeque, bracket_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    
    ASSERT_EQ(d[0], 3);
    ASSERT_EQ(d[1], 2);
}

TYPED_TEST(TestDeque, bracket_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    ASSERT_EQ(d[0], 1);
    ASSERT_EQ(d[1], 2);
    
    try {
        d[3];
        ASSERT_TRUE(true);
    } catch (std::exception) {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestDeque, bracket_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    ASSERT_EQ(d[0], 1);
    ASSERT_EQ(d[1], 2);
    ASSERT_EQ(d[2], 3);
    
    d.pop_back();
    d.push_back(5);
    ASSERT_EQ(d[2], 5);
    
}
TYPED_TEST(TestDeque, const_bracket_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    
    const deque_type e(d);
    
    ASSERT_EQ(e[0], 3);
    ASSERT_EQ(e[1], 2);
}

TYPED_TEST(TestDeque, const_bracket_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    const deque_type e(d);
    
    ASSERT_EQ(e[0], 1);
    ASSERT_EQ(e[1], 2);
    
    try {
        e[3];
        ASSERT_TRUE(true);
    } catch (std::exception) {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestDeque, const_bracket_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.pop_back();
    
    const deque_type e(d);
    
    ASSERT_EQ(e[0], 1);
    ASSERT_EQ(e[1], 2);
    //ASSERT_EQ(d[2], 3);
    
}


TYPED_TEST(TestDeque, begin_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    //my_deque<int>::iterator temp = d.begin();
    ASSERT_EQ(*d.begin(), 1);
    ASSERT_EQ(d[1], 2);
    ASSERT_EQ(d[1], 2);
}

TYPED_TEST(TestDeque, begin_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    //my_deque<int>::iterator temp = d.begin();
    ASSERT_EQ(*d.begin(), 1);
    ASSERT_EQ(d[1], 2);
    ASSERT_EQ(d[1], 2);
    
    d.pop_front();
    ASSERT_EQ(*d.begin(), 2);
}

TYPED_TEST(TestDeque, begin_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    //my_deque<int>::iterator temp = d.begin();
    ASSERT_EQ(*d.begin(), 1);
    ASSERT_EQ(d[1], 2);
    ASSERT_EQ(d[1], 2);
    
    d.pop_front();
    ASSERT_EQ(*d.begin(), 2);
    
    d.push_front(9);
    ASSERT_EQ(*d.begin(), 9);
}

TYPED_TEST(TestDeque, const_begin_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    const deque_type e(d);
    //my_deque<int>::iterator temp = e.begin();
    ASSERT_EQ(*e.begin(), 1);
    ASSERT_EQ(e[1], 2);
}
TYPED_TEST(TestDeque, const_begin_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    d.pop_front();
    
    const deque_type e(d);
    
    ASSERT_EQ(*e.begin(), 2);
    ASSERT_EQ(e[0], 2);
    
    d.pop_front();
    ASSERT_EQ(*e.begin(), 2);
}

TYPED_TEST(TestDeque, const_begin_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    const deque_type e(d);
    
    ASSERT_EQ(*e.begin(), 1);

}


TYPED_TEST(TestDeque, end_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    //my_deque<int>::iterator temp = d.begin();
    ASSERT_EQ(*(--d.end()), 3);
    ASSERT_EQ(d[1], 2);
    //ASSERT_EQ(d[1], 2);
}

TYPED_TEST(TestDeque, end_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(22);
    
    //my_deque<int>::iterator temp = d.begin();
    ASSERT_EQ(*d.begin(), 22);
    ASSERT_EQ(*(--d.end()), 22);
    ASSERT_EQ(d[0], 22);
    //ASSERT_EQ(d[1], 2);
}
TYPED_TEST(TestDeque, end_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(22);
    
    //my_deque<int>::iterator temp = d.begin();
    ASSERT_EQ(*d.begin(), 22);
    ASSERT_EQ(*(--d.end()), 22);
    ASSERT_EQ(d[0], 22);
    d.push_back(9);
    ASSERT_EQ(*(--d.end()), 9);
    ASSERT_EQ(*d.begin(), 22);
    //ASSERT_EQ(d[1], 2);
}

TYPED_TEST(TestDeque, const_end_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    
    const deque_type e(d);
    
    //my_deque<int>::iterator temp = d.begin();
    ASSERT_EQ(*(--e.end()), 3);
    ASSERT_EQ(e[1], 2);
    //ASSERT_EQ(d[1], 2);
}
TYPED_TEST(TestDeque, const_end_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(22);
    
    const deque_type e(d);
    
    //my_deque<int>::iterator temp = d.begin();
    ASSERT_EQ(*e.begin(), 22);
    ASSERT_EQ(*(--e.end()), 22);
    ASSERT_EQ(e[0], 22);
    //ASSERT_EQ(d[1], 2);
}
TYPED_TEST(TestDeque, const_end_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(-1);
    
    const deque_type e(d);
    
    //my_deque<int>::iterator temp = d.begin();
    ASSERT_EQ(*e.begin(), -1);
    ASSERT_EQ(*(--e.end()), -1);
    ASSERT_EQ(e[0], -1);
}


TYPED_TEST(TestDeque, constructor_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    //d.push_back(7);
    ASSERT_EQ(d.size(), 0);
}

TYPED_TEST(TestDeque, constructor_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    ASSERT_EQ(d.size(), 1);
    ASSERT_EQ(d[0], 7);
}

TYPED_TEST(TestDeque, constructor_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_front(7);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
}


TYPED_TEST(TestDeque, constructor_size_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d(20,6);
    d.push_back(7);
    ASSERT_EQ(d.size(), 21);
    ASSERT_EQ(d[0], 6);
    //d.print_deque();
}

TYPED_TEST(TestDeque, constructor_size_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d(1);
    d.push_back(7);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 0);
    ASSERT_EQ(d[1], 7);
    //d.print_deque();
}

TYPED_TEST(TestDeque, constructor_size_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d(45,9);
    d.push_back(7);
    ASSERT_EQ(d.size(), 46);
    ASSERT_EQ(d[0], 9);
    ASSERT_EQ(d[45], 7);
    //d.print_deque();
}


TYPED_TEST(TestDeque, constructor_that_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    deque_type e(d);
    
    e.push_back(8);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    ASSERT_EQ(e[1], 9);
    ASSERT_EQ(e[2], 8);
    
    //d.print_deque();
}

TYPED_TEST(TestDeque, constructor_that_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    deque_type e(d);
    d.push_back(6);
    
    e.push_back(8);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    ASSERT_EQ(e[1], 9);
    ASSERT_EQ(e[2], 8);
    
    //d.print_deque();
}

TYPED_TEST(TestDeque, constructor_that_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    deque_type e(d);
    d.push_back(6);
    
    e.push_back(10);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    ASSERT_EQ(e[1], 9);
    ASSERT_EQ(e[2], 10);
    
    //d.print_deque();
}

TYPED_TEST(TestDeque, assignment_1) {
    ALL_OF_IT
    using namespace std;
    deque_type e;
    {
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    e = (const deque_type)d;
    d.push_back(6);

    }
    e.push_back(10);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    ASSERT_EQ(e[1], 9);
    ASSERT_EQ(e[2], 10);
    
    //d.print_deque();
}

TYPED_TEST(TestDeque, assignment_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    deque_type e = d;
    
    e.push_back(8);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    ASSERT_EQ(e[1], 9);
    ASSERT_EQ(e[2], 8);
    
    //d.print_deque();
}

TYPED_TEST(TestDeque, assignment_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    deque_type e = d;
    d.push_back(6);
    
    e.push_back(8);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    ASSERT_EQ(e[1], 9);
    ASSERT_EQ(e[2], 8);
    
    //d.print_deque();
}

TYPED_TEST(TestDeque, swap_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    deque_type e;
    e.push_back(6);
    e.push_back(8);
    
    ASSERT_EQ(e.size(), 2);
    ASSERT_EQ(e[0], 6);
    ASSERT_EQ(e[1], 8);
    
    e.swap(d);
    
    ASSERT_EQ(e[0], 7);
    ASSERT_EQ(e[1], 9);
    ASSERT_EQ(d[0], 6);
    ASSERT_EQ(d[1], 8);
    
    //d.print_deque();
}

TYPED_TEST(TestDeque, swap_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    d.push_back(11);
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    ASSERT_EQ(d[2], 11);
    
    deque_type e;
    e.push_back(6);
    e.push_back(8);
    
    ASSERT_EQ(e.size(), 2);
    ASSERT_EQ(e[0], 6);
    ASSERT_EQ(e[1], 8);
    
    e.swap(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    ASSERT_EQ(e[1], 9);
    ASSERT_EQ(e[2], 11);
    
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 6);
    ASSERT_EQ(d[1], 8);
    
    //d.print_deque();
}

TYPED_TEST(TestDeque, swap_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(1);
    d.push_back(2);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 1);
    ASSERT_EQ(d[1], 2);
    
    deque_type e;
    e.push_back(6);
    e.push_back(8);
    
    ASSERT_EQ(e.size(), 2);
    ASSERT_EQ(e[0], 6);
    ASSERT_EQ(e[1], 8);
    
    e.swap(d);
    
    ASSERT_EQ(e[0], 1);
    ASSERT_EQ(e[1], 2);
    ASSERT_EQ(d[0], 6);
    ASSERT_EQ(d[1], 8);
    
    //d.print_deque();
}

TYPED_TEST(TestDeque, size_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
}

TYPED_TEST(TestDeque, size_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    d.pop_front();
    ASSERT_EQ(d.size(), 1);
}

TYPED_TEST(TestDeque, size_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    d.push_back(9);
    ASSERT_EQ(d.size(), 3);
}

TYPED_TEST(TestDeque, resize_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    d.resize(5,4);
    ASSERT_EQ(d.size(), 5);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    ASSERT_EQ(d[2], 4);
    ASSERT_EQ(d[3], 4);
    ASSERT_EQ(d[4], 4);
    
}

TYPED_TEST(TestDeque, resize_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    d.resize(15,4);
    ASSERT_EQ(d.size(), 15);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    ASSERT_EQ(d[2], 4);
    ASSERT_EQ(d[3], 4);
    ASSERT_EQ(d[4], 4);
    ASSERT_EQ(d[14], 4);
    
}

TYPED_TEST(TestDeque, resize_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    d.push_back(11);
    d.push_back(13);
    ASSERT_EQ(d.size(), 4);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    d.resize(2,4);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
}

TYPED_TEST(TestDeque, clear_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    d.clear();
    d.clear();
    ASSERT_EQ(d.size(), 0);
    
}

TYPED_TEST(TestDeque, clear_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    d.clear();
    ASSERT_EQ(d.size(), 0);
    d.push_back(5);
    ASSERT_EQ(d.size(), 1);
    ASSERT_EQ(d[0], 5);
    
}

TYPED_TEST(TestDeque, clear_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    d.clear();
    ASSERT_EQ(d.size(), 0);
    d.push_back(5);
    ASSERT_EQ(d.size(), 1);
    ASSERT_EQ(d[0], 5);
    d.clear();
    ASSERT_EQ(d.size(), 0);
    
}

TYPED_TEST(TestDeque, erase_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    d.erase(d.begin());
    ASSERT_EQ(d.size(), 1);
    ASSERT_EQ(d[0], 9);
    
}

TYPED_TEST(TestDeque, erase_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    d.push_back(11);
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    ASSERT_EQ(d[2], 11);
    
    d.erase(d.begin());
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 9);
    ASSERT_EQ(d[1], 11);
    
}

TYPED_TEST(TestDeque, erase_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    d.push_back(11);
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    ASSERT_EQ(d[2], 11);
    
    d.erase(d.begin());
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 9);
    ASSERT_EQ(d[1], 11);
    
    d.erase(d.begin());
    ASSERT_EQ(d.size(), 1);
    ASSERT_EQ(d[0], 11);
    
}

TYPED_TEST(TestDeque, erase_4) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    d.push_back(11);
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    ASSERT_EQ(d[2], 11);
    
    ASSERT_EQ(*(d.erase(++d.begin())), 11);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 11);
    

    
}

TYPED_TEST(TestDeque, insert_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    d.insert(d.begin(), 77);
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 77);
    ASSERT_EQ(d[1], 7);
    ASSERT_EQ(d[2], 9);
    
}

TYPED_TEST(TestDeque, insert_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    d.push_back(10);
    d.push_back(11);
    d.push_back(12);
    ASSERT_EQ(d.size(), 5);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    d.insert(d.begin(), 77);
    ASSERT_EQ(d.size(), 6);
    ASSERT_EQ(d[0], 77);
    ASSERT_EQ(d[1], 7);
    ASSERT_EQ(d[2], 9);
    
}

TYPED_TEST(TestDeque, insert_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    

    d.insert(++d.begin(), 77);

    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 77);
    ASSERT_EQ(d[2], 9);
    
}

TYPED_TEST(TestDeque, insert_4) {
    ALL_OF_IT
    using namespace std;
    deque_type d(16,3);

    ASSERT_EQ(d.size(), 16);

    
    
    d.insert(++d.begin(), 77);
    
    ASSERT_EQ(d.size(), 17);
    
}

TYPED_TEST(TestDeque, equals_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    

    deque_type e;
    e.push_back(7);
    e.push_back(9);
    ASSERT_EQ(e.size(), 2);
    ASSERT_EQ(e, d);
}

TYPED_TEST(TestDeque, equals_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    deque_type e;
    e.push_front(9);
    e.push_front(7);
    e.push_front(6);
    e.pop_front();
    ASSERT_EQ(e.size(), 2);
    ASSERT_EQ(e, d);
}

TYPED_TEST(TestDeque, equals_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    deque_type e;
    e.push_front(9);
    e.push_front(7);
    e.push_front(6);
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e == d, false);
}

TYPED_TEST(TestDeque, compare_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    deque_type e;
    e.push_back(6);
    e.push_back(9);
    ASSERT_EQ(e.size(), 2);
    ASSERT_TRUE(e < d);
}

TYPED_TEST(TestDeque, compare_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(9);
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    ASSERT_EQ(d[1], 9);
    
    deque_type e;
    e.push_back(6);
    e.push_back(9);
    ASSERT_EQ(e.size(), 2);
    ASSERT_FALSE(d < e);
}

TYPED_TEST(TestDeque, compare_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(6);
    d.push_back(9);
    d.push_back(1);
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 6);
    ASSERT_EQ(d[1], 9);
    
    deque_type e;
    e.push_back(6);
    e.push_back(9);
    ASSERT_EQ(e.size(), 2);
    ASSERT_TRUE(e < d);
}

TYPED_TEST(TestDeque, empty_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(6);
    d.push_back(9);
    d.push_back(1);
    ASSERT_FALSE(d.empty());
    ASSERT_EQ(d[0], 6);
    ASSERT_EQ(d[1], 9);

}
TYPED_TEST(TestDeque, empty_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    ASSERT_TRUE(d.empty());
    d.push_back(6);
    d.push_back(9);
    d.push_back(1);
    ASSERT_FALSE(d.empty());
    ASSERT_EQ(d[0], 6);
    ASSERT_EQ(d[1], 9);
    
}
TYPED_TEST(TestDeque, empty_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    ASSERT_TRUE(d.empty());
    d.push_back(6);
    d.push_back(9);
    d.push_back(1);
    ASSERT_FALSE(d.empty());
    ASSERT_EQ(d[0], 6);
    ASSERT_EQ(d[1], 9);
    d.clear();
    ASSERT_TRUE(d.empty());
}

TYPED_TEST(TestDeque, destruct_1) {
    ALL_OF_IT
    using namespace std;
    {
    deque_type d;
    d.push_back(6);
    d.push_back(9);
    d.push_back(1);
    ASSERT_FALSE(d.empty());
    ASSERT_EQ(d[0], 6);
    ASSERT_EQ(d[1], 9);
    }
    ASSERT_TRUE(true);
}

TYPED_TEST(TestDeque, destruct_2) {
    ALL_OF_IT
    using namespace std;
    {
    deque_type d;
    }
    ASSERT_TRUE(true);
}
TYPED_TEST(TestDeque, destruct_3) {
    ALL_OF_IT
    using namespace std;
    {
        deque_type d;
        const deque_type e;
    }
    ASSERT_TRUE(true);
}


////////////////////////////////////////////////////////////////////////////
//////      iterator tests
////////////////////////////////////////////////////////////////////////////

TYPED_TEST(TestDeque, it_equals_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);

    ASSERT_EQ(d.begin() == d.begin(), true);
}

TYPED_TEST(TestDeque, it_equals_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);

    ASSERT_EQ(d.begin() == --d.end(), true);
}

TYPED_TEST(TestDeque, it_equals_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    
    ASSERT_EQ(++d.begin() == --d.end(), true);
}



TYPED_TEST(TestDeque, it_notequals_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    
    ASSERT_EQ(d.begin() != d.end(), true);
}
TYPED_TEST(TestDeque, it_notequals_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    
    ASSERT_EQ(d.begin() != --d.end(), false);
}
TYPED_TEST(TestDeque, it_notequals_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    
    ASSERT_EQ(++d.begin() != --d.end(), false);
}



TYPED_TEST(TestDeque, plus_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    
    ASSERT_EQ((d.begin() + 1) == --d.end(), true);
}
TYPED_TEST(TestDeque, plus_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    
    ASSERT_EQ((d.begin() + 2) == d.end(), true);
}
TYPED_TEST(TestDeque, plus_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    
    ASSERT_EQ((d.begin() + 1) != --d.end(), false);
}



TYPED_TEST(TestDeque, subtract_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    
    ASSERT_EQ((d.begin() + 1) == (d.end() - 1), true);
}
TYPED_TEST(TestDeque, subtract_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    
    ASSERT_EQ(d.begin() == (d.end() - 2), true);
}
TYPED_TEST(TestDeque, subtarct_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    
    ASSERT_EQ((d.begin() + 1) != (d.end() - 1), false);
}



TYPED_TEST(TestDeque, star_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d(45);
    d.push_back(7);
    //my_deque<int>::iterator ttt = d.begin();
    *d.begin() = 8;
    
    ASSERT_EQ(d.size(), 46);
    ASSERT_EQ(d[0], 8);
    //d.print_deque();
}

TYPED_TEST(TestDeque, star_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d(45,8);
    d.push_back(7);
    //my_deque<int>::iterator ttt = d.begin();
    
    
    ASSERT_EQ(d.size(), 46);
    ASSERT_EQ(*d.begin(), 8);
    //d.print_deque();
}

TYPED_TEST(TestDeque, star_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d(45,8);
    d.push_back(7);
    //my_deque<int>::iterator ttt = d.begin();
    
    ASSERT_EQ(d.size(), 46);
    ASSERT_EQ(*d.begin(), 8);
    ASSERT_EQ(*(--d.end()), 7);
    //d.print_deque();
}



TYPED_TEST(TestDeque, inc_pre_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(++d.begin()), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, inc_pre_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(++d.begin()), 3);
    ASSERT_EQ(*(++++d.begin()), 2);
    //d.print_deque();
}
TYPED_TEST(TestDeque, inc_pre_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(++d.begin()), 5);
    ASSERT_EQ(*(++++d.begin()), 1);
    //d.print_deque();
}



TYPED_TEST(TestDeque, inc_post_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()++), 7);
    //d.print_deque();
}

TYPED_TEST(TestDeque, inc_post_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(d.begin()++), 7);
    ASSERT_EQ(*((++d.begin())++), 3);
    //d.print_deque();
}

TYPED_TEST(TestDeque, inc_post_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(d.begin()++), 7);
    ASSERT_EQ(*((++d.begin())++), 5);
    //d.print_deque();
}
              
              

TYPED_TEST(TestDeque, dec_pre_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(--d.end()), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, dec_pre_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(--d.end()), 2);
    ASSERT_EQ(*(----d.end()), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, dec_pre_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(--d.end()), 1);
    ASSERT_EQ(*(----d.end()), 5);
    //d.print_deque();
}



TYPED_TEST(TestDeque, dec_post_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()--), 7);
    //d.print_deque();
}
TYPED_TEST(TestDeque, dec_post_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    //ASSERT_EQ(*(d.end()--), 7);
    ASSERT_EQ(*((--d.end())--), 2);
    //d.print_deque();
}
TYPED_TEST(TestDeque, dec_post_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(d.begin()--), 7);
    ASSERT_EQ(*((--d.end())--), 1);
    //d.print_deque();
}



TYPED_TEST(TestDeque, plus_eq_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin() += 1), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, plus_eq_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(d.begin() += 1), 3);
    ASSERT_EQ(*(d.begin() += 2), 2);
    //d.print_deque();
}
TYPED_TEST(TestDeque, plus_eq_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(d.begin() += 1), 5);
    ASSERT_EQ(*(d.begin() += 2), 1);
    //d.print_deque();
}



TYPED_TEST(TestDeque, minus_eq_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.end() -= 1), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, minus_eq_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(d.end() -= 1), 2);
    ASSERT_EQ(*(d.end() -= 2), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, minus_eq_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(d.end() -= 1), 1);
    ASSERT_EQ(*(d.end() -= 2), 5);
    //d.print_deque();
}



TYPED_TEST(TestDeque, it_cons_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(d.end() -= 1), 1);
    ASSERT_EQ(*(d.end() -= 2), 5);
    //d.print_deque();
}
TYPED_TEST(TestDeque, it_cons_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(d.end() -= 1), 2);
    ASSERT_EQ(*(d.end() -= 2), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, it_cons_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    ASSERT_EQ(d.size(), 3);
    ASSERT_EQ(d[0], 7);
    
    ASSERT_EQ(*(d.begin()), 7);
    ASSERT_EQ(*(d.end() -= 1), 1);
    ASSERT_EQ(*(d.end() -= 2), 5);
    //d.print_deque();
}

////////////////////////////////////////////////////////////////////////////
//////      const iterator tests
////////////////////////////////////////////////////////////////////////////


TYPED_TEST(TestDeque, const_it_equals_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    const deque_type e(d);
    
    ASSERT_EQ(e.begin() == e.begin(), true);
}
TYPED_TEST(TestDeque, const_it_equals_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    const deque_type e(d);
    
    ASSERT_EQ(d.begin() == --d.end(), true);
}
TYPED_TEST(TestDeque, const_it_equals_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    const deque_type e(d);
    
    ASSERT_EQ(++e.begin() == --e.end(), true);
}



TYPED_TEST(TestDeque, const_it_notequals_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    const deque_type e(d);
    
    ASSERT_EQ(e.begin() != e.end(), true);
}
TYPED_TEST(TestDeque, const_it_notequals_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    const deque_type e(d);
    
    ASSERT_EQ(d.begin() != --d.end(), false);
}
TYPED_TEST(TestDeque, const_it_notequals_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    const deque_type e(d);
    
    ASSERT_EQ(++e.begin() != --e.end(), false);
}



TYPED_TEST(TestDeque, const_plus_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    const deque_type e(d);
    
    ASSERT_EQ((e.begin() + 1) == --e.end(), true);
}

TYPED_TEST(TestDeque, const_plus_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    const deque_type e(d);
    
    ASSERT_EQ((e.begin() + 2) == e.end(), true);
}
TYPED_TEST(TestDeque, const_plus_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    const deque_type e(d);
    
    ASSERT_EQ((e.begin() + 1) != --e.end(), false);
}



TYPED_TEST(TestDeque, const_subtract_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    const deque_type e(d);
    
    ASSERT_EQ((e.begin() + 1) == (e.end() - 1), true);
}

TYPED_TEST(TestDeque, const_subtract_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    const deque_type e(d);
    
    ASSERT_EQ(e.begin() == (e.end() - 2), true);
}
TYPED_TEST(TestDeque, const_subtract_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(8);
    const deque_type e(d);
    
    ASSERT_EQ((e.begin() + 1) != (e.end() - 1), false);
}



TYPED_TEST(TestDeque, const_star_1) {
    ALL_OF_IT
    using namespace std;
    deque<int> d(45,3);
    
    const deque<int> e(d);

    
    ASSERT_EQ(e.size(), 45);
    ASSERT_EQ(*e.begin(), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, const_star_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d(45,8);
    //d.push_back(7);
    //my_deque<int>::iterator ttt = d.begin();
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 45);
    ASSERT_EQ(*e.begin(), 8);
    //d.print_deque();
}
TYPED_TEST(TestDeque, const_star_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d(45,8);
    d.push_back(7);
    d.pop_back();
    //my_deque<int>::iterator ttt = d.begin();
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 45);
    ASSERT_EQ(*e.begin(), 8);
    ASSERT_EQ(*(--e.end()), 8);
    //d.print_deque();
}



TYPED_TEST(TestDeque, const_inc_pre_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 2);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(++e.begin()), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, const_inc_pre_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*(++e.begin()), 3);
    ASSERT_EQ(*(++++e.begin()), 2);
    //d.print_deque();
}
TYPED_TEST(TestDeque, const_inc_pre_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*(++e.begin()), 5);
    ASSERT_EQ(*(++++e.begin()), 1);
    //d.print_deque();
}



TYPED_TEST(TestDeque, const_inc_post_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 2);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()++), 7);
    //d.print_deque();
}
TYPED_TEST(TestDeque, const_inc_post_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*(e.begin()++), 7);
    ASSERT_EQ(*((++e.begin())++), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, const_inc_post_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*(e.begin()++), 7);
    ASSERT_EQ(*((++e.begin())++), 5);
    //d.print_deque();
}

TYPED_TEST(TestDeque, const_dec_pre_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 2);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(--e.end()), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, const_dec_pre_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*(--e.end()), 2);
    ASSERT_EQ(*(----e.end()), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, const_dec_pre_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*(--e.end()), 1);
    ASSERT_EQ(*(----e.end()), 5);
    //d.print_deque();
}



TYPED_TEST(TestDeque, const_dec_post_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 2);
    ASSERT_EQ(e[0], 7);
    ASSERT_EQ(e[1], 3);
    e.end()--;
    ASSERT_EQ(*(++e.begin()), 3);
}
TYPED_TEST(TestDeque, const_dec_post_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*((--e.end())--), 2);
}
TYPED_TEST(TestDeque, const_dec_post_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*((--e.end())--), 1);
}



TYPED_TEST(TestDeque, const_plus_eq_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 2);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin() += 1), 3);
}
TYPED_TEST(TestDeque, const_plus_eq_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*(e.begin() += 1), 3);
    ASSERT_EQ(*(e.begin() += 2), 2);
}
TYPED_TEST(TestDeque, const_plus_eq_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*(e.begin() += 1), 5);
    ASSERT_EQ(*(e.begin() += 2), 1);
    //d.print_deque();
}



TYPED_TEST(TestDeque, const_minus_eq_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 2);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.end() -= 1), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, const_minus_eq_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*(e.end() -= 1), 2);
    ASSERT_EQ(*(e.end() -= 2), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, const_minus_eq_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*(e.end() -= 1), 1);
    ASSERT_EQ(*(e.end() -= 2), 5);
    //d.print_deque();
}



TYPED_TEST(TestDeque, const_it_cons_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 2);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.end() -= 1), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, const_it_cons_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(3);
    d.push_back(2);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*(e.end() -= 2), 3);
    //d.print_deque();
}
TYPED_TEST(TestDeque, const_it_cons_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d;
    d.push_back(7);
    d.push_back(5);
    d.push_back(1);
    
    const deque_type e(d);
    
    ASSERT_EQ(e.size(), 3);
    ASSERT_EQ(e[0], 7);
    
    ASSERT_EQ(*(e.begin()), 7);
    ASSERT_EQ(*(e.end() -= 1), 1);
}
 
TYPED_TEST(TestDeque, Const_Iterator_EqualEqual_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(10);

  typename deque_type::const_iterator b1 = x.begin();
  typename deque_type::const_iterator b2 = x.begin();

  ASSERT_TRUE(b1 == b2);
  b1 += 9;
  b2 += 5;
  b2 += 4;
  ASSERT_TRUE(b1 == b2);
}

TYPED_TEST(TestDeque, Const_Iterator_EqualEqual_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(10);

  typename deque_type::const_iterator b1 = x.end();
  typename deque_type::const_iterator b2 = x.end();

  ASSERT_TRUE(b1 == b2);
  while(b1 != x.begin()) {
    ASSERT_TRUE(b1 == b2);
    b1--;
    b2--;
  }
}

TYPED_TEST(TestDeque, Const_Iterator_EqualEqual_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(10);

  typename deque_type::const_iterator b1 = x.begin();
  typename deque_type::const_iterator b2 = x.end();
  
  while(b1 != x.end()) {
    b1++;
  }   
  ASSERT_TRUE(b1 == b2);
}

TYPED_TEST(TestDeque, Const_Iterator_NotEqual_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(10);
  const deque_type y(10);

  typename deque_type::const_iterator b1 = x.begin();
  typename deque_type::const_iterator b2 = y.begin();

  ASSERT_TRUE(b1 != b2);
}

TYPED_TEST(TestDeque, Const_Iterator_NotEqual_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(300);
  int count = 0;
  typename deque_type::const_iterator b = x.begin();
  typename deque_type::const_iterator e = x.end();

  while (b != e) {
    ++count;
    ++b;
  }
  ASSERT_EQ(count, 300);
}

TYPED_TEST(TestDeque, Const_Iterator_NotEqual_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(25);
  typename deque_type::const_iterator b = x.begin();
  typename deque_type::const_iterator e = x.begin();
  ASSERT_FALSE(b != e);
}

TYPED_TEST(TestDeque, Const_Iterator_Dereference_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(20);
  x[0] = 5;
  const deque_type y = x;
  typename deque_type::const_iterator p = y.begin();

  ASSERT_EQ(*p, 5);
  p++;
  ASSERT_EQ(*p, 0);
  p--;
  ASSERT_EQ(*p, 5);
}

TYPED_TEST(TestDeque, Const_Iterator_Dereference_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  for(value_type i = 0; i < 56; ++i) {
    x.push_back(i);
  }
  const deque_type y(x);
  typename deque_type::const_iterator p = y.begin();
  for(value_type j = 0; j < 56; ++j) {
    ASSERT_EQ(*(p + j), x[j]);
  }
}

TYPED_TEST(TestDeque, Const_Iterator_Dereference_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  typename deque_type::const_iterator b = x.begin();
  typename deque_type::const_iterator e = x.end();
  value_type c = 0;

  while(--e != b) {
    ASSERT_EQ(*e, 4);
    c++;
  }
  ASSERT_EQ(c, x.size() - 1);
}




TYPED_TEST(TestDeque, Const_Iterator_PrePlusPlus_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for (int i = 0; i < 100; ++i) {
    x[i] = i;
  }
  const deque_type y = x;
  typename deque_type::const_iterator p = y.begin();

  for (int i = 0; i < 100; ++i) {
    ASSERT_EQ(*p, i);
    ++p;
  }
}

TYPED_TEST(TestDeque, Const_Iterator_PrePlusPlus_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  for(value_type i = 0; i < 15; ++i) {
    x.push_back(i); 
  }
  const deque_type y(x);
  typename deque_type::const_iterator p = y.begin();
  ASSERT_EQ(*(++p), x[1]);
}

TYPED_TEST(TestDeque, Const_Iterator_PrePlusPlus_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  typename deque_type::const_iterator p = x.begin();
  value_type c = 0;
  while(++p != x.end()) {
    c++;
  }
  ASSERT_EQ(c, x.size() - 1);
}


TYPED_TEST(TestDeque, Const_Iterator_PostPlusPlus_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for (value_type i = 0; i < 100; ++i) {
    x[i] = i;
  }
  const deque_type y = x;
  typename deque_type::const_iterator p = y.begin();

  for (value_type i = 0; i < 100; ++i) {
    ASSERT_EQ(*p, i);
    value_type temp = *(p++);
    ASSERT_EQ(temp, i);
  }
}

TYPED_TEST(TestDeque, Const_Iterator_PostPlusPlus_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  for(value_type i = 0; i < 100; ++i) {
    x.push_back(i);
  }
  const deque_type y(x);
  typename deque_type::const_iterator p = y.begin();
  ASSERT_EQ(*(p++), y[0]);
  ASSERT_EQ(*p, y[1]);
}

TYPED_TEST(TestDeque, Const_Iterator_PostPlusPlus_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;
  deque_type x;
  for(value_type i = 0; i < 50; ++i) {
    x.push_back(i);
  }
  const deque_type y(x);
  typename deque_type::const_iterator p = y.begin() + 5;
  value_type j = 5;
  for(value_type i = 0; i < 10; ++i) {
    ASSERT_EQ(*(p++), j + i);
  }
}


TYPED_TEST(TestDeque, Const_Iterator_PreMinusMinus_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for (value_type i = 0; i < 100; ++i) {
    x[i] = i;
  }
  const deque_type y = x;
  typename deque_type::const_iterator p = y.begin();
  p += 99;

  for (value_type i = 0; i < 100; ++i) {
    ASSERT_EQ(*p, 99 - i);
    --p;
  }
}

TYPED_TEST(TestDeque, Const_Iterator_PreMinusMinus_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  for(value_type i = 0; i < 50; ++i) {
    x.push_back(i);
  }
  const deque_type y(x);

  typename deque_type::const_iterator e = y.end();
  typename deque_type::const_iterator b = y.begin();

  value_type i = x.size() - 1;
  while((--e) != b) {
    ASSERT_EQ(*e, y[i--]);
  }
}

TYPED_TEST(TestDeque, Const_Iterator_PreMinusMinus_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 40);
  typename deque_type::const_iterator e = x.end();
  value_type c = 0;
  while((--e) != x.begin()) {
    c++;
  }
  ASSERT_EQ(c, x.size() - 1);  
}

TYPED_TEST(TestDeque, Const_Iterator_PostMinusMinus_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for (value_type i = 0; i < 100; ++i) {
    x[i] = i;
  }
  const deque_type y = x;
  typename deque_type::const_iterator p = y.begin();
  p += 99;

  for (value_type i = 0; i < 100; ++i) {
    ASSERT_EQ(*p, 99 - i);
    value_type temp = *(p--);
    ASSERT_EQ(temp, 99 - i);
  }
}

TYPED_TEST(TestDeque, Const_Iterator_PostMinusMinus_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for (value_type i = 0; i < 100; ++i) {
    x[i] = i;
  }
  const deque_type y = x;
  typename deque_type::const_iterator p = y.end();
  p--;
  ASSERT_EQ(*(p--), x[x.size() - 1]);
  ASSERT_EQ(*p, x[x.size() - 2]);
}

TYPED_TEST(TestDeque, Const_Iterator_PostMinusMinus_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100);
  typename deque_type::const_iterator p = x.end();
  value_type c = 0;
  while(p != x.begin()) {
    c++;
    p--;
  }
  ASSERT_EQ(c, x.size());
}

TYPED_TEST(TestDeque, Const_Iterator_PlusEq_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for (value_type i = 0; i < 100; ++i) {
    x[i] = i;
  }
  const deque_type y = x;
  typename deque_type::const_iterator i = y.begin();
  ASSERT_EQ(*i, 0);
  i += 10;
  ASSERT_EQ(*i, 10);
  i += 33;
  ASSERT_EQ(*i, 43);
  i += 27;
  ASSERT_EQ(*i, 70);
  i += 11;
  ASSERT_EQ(*i, 81);
  i += 18;
  ASSERT_EQ(*i, 99);
}

TYPED_TEST(TestDeque, Const_Iterator_PlusEq_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100);
  typename deque_type::const_iterator b1 = x.begin();
  typename deque_type::const_iterator b2 = x.begin();
  while(b1 != x.end()) {
    b1++;
    b2 += 1; 
    ASSERT_TRUE(b1 == b2);
  }
}

TYPED_TEST(TestDeque, Const_Iterator_PlusEq_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100);
  typename deque_type::const_iterator b1 = x.begin();
  value_type i = 0;
  while(b1 != x.end()) {
    ASSERT_EQ(*b1, x[i++]); 
    b1 += 1;
  }
}

TYPED_TEST(TestDeque, Const_Iterator_MinusEq_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for (value_type i = 0; i < 100; ++i) {
    x[i] = i;
  }
  const deque_type y = x;
  typename deque_type::const_iterator i = y.begin();

  i += 99;
  ASSERT_EQ(*i, 99);
  i -= 30;
  ASSERT_EQ(*i, 69);
  i -= 19;
  ASSERT_EQ(*i, 50);
  i -= 25;
  ASSERT_EQ(*i, 25);
  i -= 25;
  ASSERT_EQ(*i, 0);
}

TYPED_TEST(TestDeque, Const_Iterator_MinusEq_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  typename deque_type::const_iterator b1 = x.end();
  typename deque_type::const_iterator b2 = x.end();
  while(b1 != x.end()) {
    b1--;
    b2 -= 1; 
    ASSERT_TRUE(b1 == b2);
  }
}

TYPED_TEST(TestDeque, Const_Iterator_MinusEq_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100);
  typename deque_type::const_iterator b1 = x.end();
  b1--;
  value_type i = x.size() - 1;
  while(b1 != x.begin()) {
    ASSERT_EQ(*b1, x[i--]); 
    b1 -= 1;
  }
}

TYPED_TEST(TestDeque, Resize_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(10);
  for(int i = 10; i < 15; ++i) {
    x.push_back(10);
    ASSERT_EQ(x[i], 10);
  }

  for(int i = 3; i < 15; ++i) {
    x.push_back(15);
  }

  ASSERT_EQ(x[10], 10);
}

TYPED_TEST(TestDeque, Const_Iterator_Plus_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  typename deque_type::const_iterator b = x.begin();

  for(size_type i = 0; i < x.size(); ++i) {
    ASSERT_EQ(*(b + 1), 4);
  }
}


TYPED_TEST(TestDeque, Const_Iterator_Plus_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  typename deque_type::const_iterator b1 = x.begin();
  typename deque_type::const_iterator b2 = x.begin();

  for(size_type i = 0; i < x.size(); ++i) {
    ASSERT_TRUE((b1 + i) == b2);
    b2++;
  }
}

TYPED_TEST(TestDeque, Const_Iterator_Plus_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  typename deque_type::const_iterator b1 = x.begin();
  typename deque_type::const_iterator b2 = x.begin();

  for(size_type i = 0; i < x.size(); ++i) {
    ASSERT_TRUE((b1 + i) == b2);
    b2 += 1;
  }
}

TYPED_TEST(TestDeque, Const_Iterator_Minus_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  typename deque_type::const_iterator b = x.end();

  for(size_type i = 1; i < x.size(); ++i) {
    ASSERT_EQ(*(b - i), 4);
  }
}

TYPED_TEST(TestDeque, Const_Iterator_Minus_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(50, 4);
  typename deque_type::const_iterator b1 = x.end();
  typename deque_type::const_iterator b2 = x.end();
  b1--;
  b2--;

  for(size_type i = 0; i < x.size(); ++i) {
    ASSERT_TRUE((b1 - i) == b2);
    b2--;
  }
}

TYPED_TEST(TestDeque, Const_Iterator_Minus_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  typename deque_type::const_iterator b1 = x.end();
  typename deque_type::const_iterator b2 = x.end();

  b1--;
  b2--;

  for(size_type i = 0; i < x.size(); ++i) {
    ASSERT_TRUE((b1 - i) == b2);
    b2 -= 1;
  }
}

TYPED_TEST(TestDeque, Const_Iterator_Constructor) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  typename deque_type::const_iterator b1 = x.end();
  typename deque_type::const_iterator b2 = x.end();
  ASSERT_TRUE(b1 == b2);
}

TYPED_TEST(TestDeque, Const_Iterator_Constructor_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  const deque_type y(100, 4);
  typename deque_type::const_iterator b1 = x.end();
  typename deque_type::const_iterator b2 = y.end();
  ASSERT_FALSE(b1 == b2);
}

TYPED_TEST(TestDeque, Const_Iterator_Constructor_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  typename deque_type::const_iterator b1 = x.begin();
  typename deque_type::const_iterator b2 = x.begin();
  while(b1 != x.end()) {
    ASSERT_TRUE(b1 == b2);
    b1++;
    b2++;
  }
}

TYPED_TEST(TestDeque, Const_Iterator_Constructor_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(27, 4);
  typename deque_type::const_iterator b1 = x.begin();
  typename deque_type::const_iterator b2 = x.begin();
  while(b1 != x.end()) {
    ASSERT_TRUE(*b1 == *b2);
    b1++;
    b2++;
  }
}

TYPED_TEST(TestDeque, Const_Iterator_Copy_Constructor_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  typename deque_type::const_iterator b1 = x.end();
  typename deque_type::const_iterator b2 = b1;
  ASSERT_TRUE(b1 == b2);
}

TYPED_TEST(TestDeque, Const_Iterator_Copy_Constructor_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(27, 4);
  typename deque_type::const_iterator b1 = x.begin();
  typename deque_type::const_iterator b2 = b1;
  while(b1 != x.end()) {
    ASSERT_TRUE(*b1 == *b2);
    b1++;
    b2++;
  }
}

TYPED_TEST(TestDeque, Const_Iterator_Copy_Constructor_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  const deque_type x(100, 4);
  const deque_type y(100, 4);
  typename deque_type::const_iterator b1 = x.end();
  typename deque_type::const_iterator b2 = b1;
  ASSERT_TRUE(b1 == b2);
}


TYPED_TEST(TestDeque, Resize_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(1); 
  ASSERT_EQ(x.size(), 1);
  x.resize(25);
  ASSERT_EQ(x.size(), 25);
  // cout << "here1" << endl;
  x[0] = 5;
  // cout << "here2" << endl;
  ASSERT_EQ(x[0], 5);
}

TYPED_TEST(TestDeque, Resize_4) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x; 
  ASSERT_EQ(x.size(), 0);
  x.resize(94);
  ASSERT_EQ(x.size(), 94);
  x[0] = 5;
  ASSERT_EQ(x[0], 5);
}

TYPED_TEST(TestDeque, Resize_5) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(337); 
  x[0] = 5;
  ASSERT_EQ(x.size(), 337);
  x.resize(1);
  ASSERT_EQ(x.size(), 1);
  ASSERT_EQ(x[0], 5);
}

TYPED_TEST(TestDeque, Copy_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x; 
  for(value_type i = 0; i < 10; ++i) {
    x.push_back(i);
    ASSERT_EQ(x[i], i);
  }

  deque_type y = x;
  for(value_type i = 0; i < 10; ++i) {
    y.push_back(i);
    ASSERT_EQ(y[i], i);
  }
}

TYPED_TEST(TestDeque, Insert_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;
  //0 1 2 3 4 5 6 7 8 9
  //0 1 2 2 3 4 5 6 7 8 9

  deque_type x;
  for(int i = 0; i < 10; ++i) {
    x.push_back(i);
    ASSERT_EQ(x[i], i);
  } 
  ASSERT_EQ(x.size(), 10);
  typename deque_type::iterator y = x.begin();
  y++;
  y++;
  x.insert(y, 2);
  ASSERT_EQ(x[2], x[3]);
  ASSERT_EQ(x[x.size() - 1], 9);
  ASSERT_EQ(x.size(), 11);
}

TYPED_TEST(TestDeque, Insert_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;
  deque_type x;
  typename deque_type::iterator y = x.begin();
  x.insert(y, 10);
  ASSERT_EQ(x[0], 10);
  ASSERT_EQ(x.size(), 1);
}

TYPED_TEST(TestDeque, Insert_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;
  deque_type x(10); 
  ASSERT_EQ(x.size(), 10);
  typename deque_type::iterator y = x.end();
  x.insert(y, 3);
  ASSERT_EQ(x.size(), 11);
  ASSERT_EQ(x[x.size() - 1], 3);
}

TYPED_TEST(TestDeque, Insert_4) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;
  deque_type x(15);
  ASSERT_EQ(x.size(), 15);
  typename deque_type::iterator y = x.begin();
  x.insert(y + 7, -333);
  ASSERT_EQ(x.size(), 16); 
  ASSERT_EQ(x[7], -333);
}

TYPED_TEST(TestDeque, Less_Than_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  for(value_type i = 0; i < 5; ++i) {
    x.push_back(i);
  }
  deque_type y; 
  for(value_type j = 10; j > 5; --j) {
    y.push_back(j);
  }
  ASSERT_EQ(*x.begin(), 0);
  ASSERT_EQ(*(x.end() - 1), 4);

  ASSERT_EQ(*y.begin(), 10);
  ASSERT_EQ(*(y.end() - 1), 6);

  ASSERT_TRUE(x < y);
}

TYPED_TEST(TestDeque, Less_Than_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(40); 
  deque_type y(x);
  ASSERT_FALSE(x < y);
}

TYPED_TEST(TestDeque, Less_Than_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(40); 
  deque_type y(45);

  ASSERT_TRUE(x < y);
}

TYPED_TEST(TestDeque, Push_Front_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  for(value_type i = 0; i < 5; ++i) {
    x.push_front(i);
  }
  ASSERT_EQ(x[0], 4);
  ASSERT_EQ(x[1], 3);
  ASSERT_EQ(x[2], 2);
  ASSERT_EQ(x[3], 1);
  ASSERT_EQ(x[4], 0);
}

TYPED_TEST(TestDeque, Push_Front_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(12);
  for(size_type i = 0; i < 1000; ++i) {
    x.push_front(i);
  }
  for(size_type j = 0; j < 1000; ++j) {
    ASSERT_EQ(x[j], 999 - j);
  }
}

TYPED_TEST(TestDeque, Push_Front_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  x.push_front(1);
  x.pop_front();
  x.push_front(2);
  ASSERT_EQ(x[0], 2); 
}


TYPED_TEST(TestDeque, Iterator_EqualEqual_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(10);

  typename deque_type::iterator b1 = x.begin();
  typename deque_type::iterator b2 = x.begin();

  ASSERT_TRUE(b1 == b2);
  b1 += 9;
  b2 += 5;
  b2 += 4;
  ASSERT_TRUE(b1 == b2);
}

TYPED_TEST(TestDeque, Iterator_EqualEqual_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;

  typename deque_type::iterator b1 = x.begin();
  typename deque_type::iterator b2 = x.begin();
  ASSERT_TRUE(b1 == b2);
}

TYPED_TEST(TestDeque, Iterator_EqualEqual_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  deque_type y;

  typename deque_type::iterator b1 = x.begin();
  typename deque_type::iterator b2 = y.begin();
  ASSERT_FALSE(b1 == b2);
}

TYPED_TEST(TestDeque, Iterator_NotEqual_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(10);
  deque_type y(10);

  typename deque_type::iterator b1 = x.begin();
  typename deque_type::iterator b2 = y.begin();

  ASSERT_TRUE(b1 != b2);
}

TYPED_TEST(TestDeque, Iterator_NotEqual_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(300);
  int count = 0;
  typename deque_type::iterator b = x.begin();
  typename deque_type::iterator e = x.end();

  while (b != e) {
    ++count;
    ++b;
  }
  ASSERT_EQ(count, 300);
}

TYPED_TEST(TestDeque, Iterator_NotEqual_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(4);
  int count = 0;
  typename deque_type::iterator b = x.begin();
  typename deque_type::iterator e = x.end();

  while (b != e) {
    ++count;
    ++b;
    --e;
  }
  ASSERT_EQ(count, 2);
}

TYPED_TEST(TestDeque, Iterator_Dereference_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(20);
  typename deque_type::iterator p = x.begin();
  x[0] = 5;
  ASSERT_EQ(*p, 5);
  p++;
  ASSERT_EQ(*p, 0);
  p--;
  ASSERT_EQ(*p, 5);
}

TYPED_TEST(TestDeque, Iterator_Dereference_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  for(size_type i = 0; i < 15; ++i) {
    x.push_back(i);
  } 

  typename deque_type::iterator p = x.begin();
  for(size_type j = 0; j < 15; ++j) {
    ASSERT_EQ(*p, x[j]);
    p++;
  }
}

TYPED_TEST(TestDeque, Iterator_Dereference_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(1000, 2);
  deque_type y(1000, 2);
  typename deque_type::iterator b1 = x.begin();
  typename deque_type::iterator b2 = y.begin();
  while(b1 != x.end()) {
    ASSERT_EQ(*b1, *b2);
    ++b1;
    ++b2;
  }
}



TYPED_TEST(TestDeque, Iterator_PrePlusPlus_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for (int i = 0; i < 100; ++i) {
    x[i] = i;
  }
  typename deque_type::iterator p = x.begin();

  for (int i = 0; i < 100; ++i) {
    ASSERT_EQ(*p, i);
    ++p;
  }
}

TYPED_TEST(TestDeque, Iterator_PrePlusPlus_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(45, 7);
  typename deque_type::iterator p = x.begin();
  while((++p) != x.end()) {
    *p = 15;
  }
  ASSERT_EQ(*x.begin(), 7);
  ASSERT_EQ(x[4], 15);
}

TYPED_TEST(TestDeque, Iterator_PrePlusPlus_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for(size_type i = 0; i < 100; ++i) {
    x[i] = i;
  }
  typename deque_type::iterator p = x.begin();
  value_type c = 0;
  while((++p) != x.end() - 1) {
    *p = c;
    c++;
  }
  for(size_type j = 1; j < 99; ++j) {
    ASSERT_EQ(x[j], j - 1);
  }
}

TYPED_TEST(TestDeque, Iterator_PostPlusPlus_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  typename deque_type::iterator p = x.begin();
  for(size_type i = 0; i < 150; ++i) {
    x.push_back(i);
    ASSERT_EQ(*(p++), i);
  }
}

TYPED_TEST(TestDeque, Iterator_PostPlusPlus_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  typename deque_type::iterator p = x.begin();
  ASSERT_TRUE(p == x.end());
  for(size_type i = 0; i < 43; ++i) {
    x.push_back(i);
    ASSERT_EQ(*p, x[i]);
    p++; 
  }
}

TYPED_TEST(TestDeque, Iterator_PostPlusPlus_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  for(size_type i = 0; i < 50; ++i) {
    x.push_back(i);
  }
  deque_type y(x);

  typename deque_type::iterator b1 = x.begin();
  typename deque_type::iterator b2 = y.begin();

  while(b1 != x.end()) {
    ASSERT_FALSE(b1 == b2);
    ASSERT_TRUE(*b1 == *b2);
    b1++;
    b2++;
  }
}

TYPED_TEST(TestDeque, Iterator_PreMinusMinus_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for (int i = 0; i < 100; ++i) {
    x[i] = i;
  }
  typename deque_type::iterator p = x.begin();
  p += 99;

  for (int i = 0; i < 100; ++i) {
    ASSERT_EQ(*p, 99 - i);
    --p;
  }
}

TYPED_TEST(TestDeque, Iterator_PreMinusMinus_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  for(size_type i = 0; i < 125; ++i) {
    x.push_back(i);
  }
  typename deque_type::iterator p = x.end();
  while(p != x.begin()) {
    x.erase(--p);
  }
  ASSERT_TRUE(x.empty());
}

TYPED_TEST(TestDeque, Iterator_PreMinusMinus_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x; 
  for(size_type i = 0; i < 135; ++i) {
    x.push_front(i);
  }

  typename deque_type::iterator p = x.end(); 
  size_type c = 0;
  while((--p) != x.begin()) {
    ASSERT_EQ(*p, c++);
  }
}

TYPED_TEST(TestDeque, Iterator_PostMinusMinus_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for (int i = 0; i < 100; ++i) {
    x[i] = i;
  }
  typename deque_type::iterator p = x.begin();
  p += 99;

  for (int i = 0; i < 100; ++i) {
    ASSERT_EQ(*p, 99 - i);
    value_type temp = *(p--);
    ASSERT_EQ(temp, 99 - i);
  }
}

TYPED_TEST(TestDeque, Iterator_PostMinusMinus_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(400, 15);
  typename deque_type::iterator p = x.end(); 
  size_type c = 0;
  while(p != x.begin()) {
    c++;
    p--;
  }
  ASSERT_EQ(x.size(), c);
}

TYPED_TEST(TestDeque, Iterator_PostMinusMinus_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x; 
  x.push_back(0);
  typename deque_type::iterator p = x.end();
  p--;
  ASSERT_TRUE(p == x.begin());
}

TYPED_TEST(TestDeque, Iterator_PlusEq_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for (int i = 0; i < 100; ++i) {
    x[i] = i;
  }
  typename deque_type::iterator i = x.begin();
  ASSERT_EQ(*i, 0);
  i += 10;
  ASSERT_EQ(*i, 10);
  i += 33;
  ASSERT_EQ(*i, 43);
  i += 27;
  ASSERT_EQ(*i, 70);
  i += 11;
  ASSERT_EQ(*i, 81);
  i += 18;
  ASSERT_EQ(*i, 99);
}

TYPED_TEST(TestDeque, Iterator_PlusEq_2) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  for(size_type i = 0; i < 55; ++i) {
    x.push_back(i);
  }
  typename deque_type::iterator p = x.begin();
  for(size_type i = 0; i < 55; ++i) {
    ASSERT_EQ(*p, x[i]);
    p += 1;
  }
}

TYPED_TEST(TestDeque, Iterator_PlusEq_3) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  typename deque_type::iterator b1 = x.begin();
  typename deque_type::iterator b2 = x.begin();
  while(b1 != x.end()) {
    ASSERT_TRUE(b1 == b2); 
    b1 += 1;
    b2++;
  }
}

TYPED_TEST(TestDeque, Iterator_MinusEq_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x(100);
  for (int i = 0; i < 100; ++i) {
    x[i] = i;
  }
  typename deque_type::iterator i = x.begin();
  i += 99;
  ASSERT_EQ(*i, 99);
  i -= 10;
  ASSERT_EQ(*i, 89);
  i -= 9;
  ASSERT_EQ(*i, 80);
  i -= 45;
  ASSERT_EQ(*i, 35);
  i -= 35;
  ASSERT_EQ(*i, 0);
}

TYPED_TEST(TestDeque, Iterator_Plus_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  for(size_type i = 0; i < 45; ++i) {
    x.push_back(i);
  }
  typename deque_type::iterator b = x.begin();

  for(size_type i = 0; i < 45; ++i) {
    ASSERT_EQ(*(b + i), x[i]);
  }
}

TYPED_TEST(TestDeque, Iterator_Minus_1) {
  typedef typename TestFixture::deque_type      deque_type;
  typedef typename TestFixture::allocator_type  allocator_type;
  typedef typename TestFixture::value_type      value_type;
  typedef typename TestFixture::size_type       size_type;
  typedef typename TestFixture::difference_type difference_type;
  typedef typename TestFixture::pointer         pointer;
  typedef typename TestFixture::const_pointer   const_pointer;
  typedef typename TestFixture::reference       reference;
  typedef typename TestFixture::const_reference const_reference;

  deque_type x;
  for(size_type i = 0; i < 45; ++i) {
    x.push_back(i);
  }
  typename deque_type::iterator e = x.end();
  while(e != x.begin()) {
    e -= 1;
  }
  ASSERT_TRUE(e == x.begin());
}




























