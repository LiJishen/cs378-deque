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
    % g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall TestDeque.c++ -o TestDeque -lgtest -lgtest_main -lpthread

To run the test:
    % valgrind TestDeque

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


// TYPED_TEST(TestDeque, Empty) {
//     using namespace std;
//     ALL_OF_IT
    
//     deque_type x;
    
//     const bool b = x.empty();
//     ASSERT_TRUE(b);
// }

// TYPED_TEST(TestDeque, Size) {
//     ALL_OF_IT
//     deque_type x;
//     const size_type s = x.size();
//     ASSERT_EQ(0, s);
// }


//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////

// TEST (my_deque, Resize1) {//shrink
//     my_deque<int> con1 (10, 5);
//     con1.resize(5);
//     for (int i = 0; i < 5; ++i) {
//         ASSERT_TRUE (con1[i] == 5);
//     }
//     ASSERT_TRUE (con1.size() == 5);
// }


// TEST (my_deque, Resize2) {//shrink with same values
//     my_deque<int> con1 (10, 5);
//     con1.resize(15, 5);
//     // for (int i = 0; i < 15; ++i) {
//     //     cout<< "here "<< con1[i] <<endl;

//     //     ASSERT_TRUE (con1[i] == 5);
//     // }
//     ASSERT_TRUE (con1.size() == 15);
// }

// TEST (my_deque, Resize3) {//grow
//     my_deque<int> con1(1);
//     con1.resize(20, 5);
//     // for (int i = 0; i < 20; ++i) {
//     //     ASSERT_TRUE (con1[i] == 5);
//     // }

//     ASSERT_TRUE (con1.size() == 20);
// }

// TEST (my_deque, Resize4) {
//     my_deque<int> con1(10, 5);
//     con1.resize(10);
//     ASSERT_TRUE (con1.size() == 10);
// }


////////////
// push_back
////////////

TYPED_TEST(TestDeque, push_back_1) {

    ALL_OF_IT
    using namespace std;
    deque_type d(1);
    d.push_back(7);
    ASSERT_EQ(d[1], 7);
}

TYPED_TEST(TestDeque, push_back_2) {

    ALL_OF_IT
    using namespace std;
    deque_type d(1);
    d.push_back(9);
    d.push_back(8);
    ASSERT_EQ(d[1], 9);
    ASSERT_EQ(d[2], 8);
}

TYPED_TEST(TestDeque, push_back_3) {
    ALL_OF_IT
    using namespace std;
    deque_type d(1);
    //d.print_deque();
    d.push_back(7);
    d.push_back(6);
    d.push_back(5);
    d.push_back(4);
    d.push_back(3);
    d.push_back(2);
    d.push_back(1);
    ASSERT_EQ(d[1], 7);
    ASSERT_EQ(d[2], 6);
    ASSERT_EQ(d[3], 5);
    ASSERT_EQ(d[4], 4);
    ASSERT_EQ(d[5], 3);
    ASSERT_EQ(d[6], 2);
    ASSERT_EQ(d[7], 1);

}



// /////////////
// // push_front
// /////////////
TYPED_TEST(TestDeque, push_front_1) {
    ALL_OF_IT
    using namespace std;
    deque_type d(1);
    //my_deque<int> d;
    d.push_front(7);
    ASSERT_EQ(d[0], 7);
}


TYPED_TEST(TestDeque, push_front_2) {
    ALL_OF_IT
    using namespace std;
    deque_type d(1);
    //d.print_deque();
    int NUM_OF_PUSH = 100;
    for(int i = NUM_OF_PUSH; i >= 0; --i)
        d.push_front(i);

    for(int i = 0; i <= NUM_OF_PUSH; ++i)
        ASSERT_EQ(d[i], i);
    
    
}

// TYPED_TEST(TestDeque, push_front_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_front(7);
//     d.push_front(6);
//     ASSERT_EQ(d[0], 6);
// }

// TYPED_TEST(TestDeque, push_front_4) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_front(7);
//     d.push_front(6);
//     ASSERT_EQ(d[0], 6);
//     d.push_front(3);
//     ASSERT_EQ(d[0], 3);
// }
// TYPED_TEST(TestDeque, push_front_5) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_front(7);
//     d.push_front(6);
//     ASSERT_EQ(d[0], 6);
//     d.push_front(3);
//     ASSERT_EQ(d[0], 3);
//     d.push_front(2);
//     ASSERT_EQ(d[0], 2);
// }
// TYPED_TEST(TestDeque, push_front_6) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_front(7);
//     d.push_front(6);
//     ASSERT_EQ(d[0], 6);
//     d.push_front(3);
//     ASSERT_EQ(d[0], 3);
//     d.push_front(2);
//     ASSERT_EQ(d[0], 2);
//     d.pop_front();
//     d.push_front(4);
//     ASSERT_EQ(d[0], 4);
// }

// TYPED_TEST(TestDeque, iTest) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     ASSERT_EQ(d.size(),0);
// }


// TEST (my_deque, Size1) {
//     my_deque<int> x;
//     ASSERT_TRUE (x[0] == 0);
// }




////////////
// pop_front
////////////
// TYPED_TEST(TestDeque, pop_front_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_back(7);
//     d.push_back(6);
//     d.push_back(5);
//     d.pop_front();
//     ASSERT_EQ(d.size(), 2);
// }

// TYPED_TEST(TestDeque, pop_front_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_back(9);
//     d.pop_front();
//     ASSERT_EQ(d.size(), 0);
// }

// TYPED_TEST(TestDeque, pop_front_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_front(7);
//     d.push_front(6);
//     d.push_front(5);
//     d.pop_front();
//     ASSERT_EQ(d.size(), 2);
// }
// TYPED_TEST(TestDeque, pop_front_4) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_back(7);
//     //d.push_back(6);
//     d.push_back(5);
//     d.pop_front();
//     ASSERT_EQ(d.size(), 1);
// }
// TYPED_TEST(TestDeque, pop_front_5) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_back(7);
//     d.push_back(6);
//     d.push_back(5);
//     d.pop_front();
//     ASSERT_EQ(d.size(), 2);
//     d.pop_back();
//     ASSERT_EQ(d.size(), 1);
// }
// TYPED_TEST(TestDeque, pop_front_6) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_back(7);
//     d.push_back(6);
//     d.push_back(5);
//     d.pop_front();
//     ASSERT_EQ(d.size(), 2);
//     d.pop_back();
//     ASSERT_EQ(d.size(), 1);
//     d.pop_back();
//     ASSERT_EQ(d.size(), 0);
// }



////////////
// pop_back
////////////
// TYPED_TEST(TestDeque, pop_back_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_back(7);
//     d.push_back(6);
//     d.push_back(5);
//     d.pop_back();
//     ASSERT_EQ(d.size(), 2);
// }

// TYPED_TEST(TestDeque, pop_back_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_front(9);
//     d.pop_back();
//     ASSERT_EQ(d.size(), 0);
// }

// TYPED_TEST(TestDeque, pop_back_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_front(7);
//     d.push_front(6);
//     d.push_front(5);
//     d.pop_back();
//     ASSERT_EQ(d.size(), 2);
// }
// TYPED_TEST(TestDeque, pop_back_4) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_back(7);
//     //d.push_back(6);
//     d.push_back(5);
//     d.pop_back();
//     ASSERT_EQ(d.size(), 1);
// }
// TYPED_TEST(TestDeque, pop_back_5) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_back(7);
//     d.push_back(6);
//     d.push_back(5);
//     d.pop_back();
//     ASSERT_EQ(d.size(), 2);
//     d.pop_back();
//     ASSERT_EQ(d.size(), 1);
// }
// TYPED_TEST(TestDeque, pop_back_6) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_back(7);
//     d.push_back(6);
//     d.push_back(5);
//     d.pop_back();
//     ASSERT_EQ(d.size(), 2);
//     d.pop_back();
//     ASSERT_EQ(d.size(), 1);
//     d.pop_back();
//     ASSERT_EQ(d.size(), 0);
// }



/////////
// front
/////////
// TYPED_TEST(TestDeque, front_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(1);
//     d.push_back(2);
//     d.push_back(3);
//     //d.pop_back();
//     //d.print_deque();
//     //int tt = d.front();
//     ASSERT_EQ(d.front(), 1);
// }



///////////////
// const_front
///////////////
// TYPED_TEST(TestDeque, const_front_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(1);
//     d.push_back(2);
//     d.push_back(3);
    
//     const deque_type e(d);
//     ASSERT_EQ(e.front(), 1);
// }


////////
// back
////////
// TYPED_TEST(TestDeque, back_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(1);
//     d.push_back(2);
//     d.push_back(3);
    
//     ASSERT_EQ(d.back(), 3);
// }




//////
// at
//////
// TYPED_TEST(TestDeque, at_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_front(1);
//     d.push_front(2);
//     d.push_front(3);
    
//     ASSERT_EQ(d.at(0), 3);
//     ASSERT_EQ(d.at(1), 2);
// }


// const_at
// TYPED_TEST(TestDeque, const_at_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_front(1);
//     d.push_front(2);
//     d.push_front(3);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.at(0), 3);
//     ASSERT_EQ(e.at(1), 2);
// }

// []
// TYPED_TEST(TestDeque, bracket_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_front(1);
//     d.push_front(2);
//     d.push_front(3);
    
//     ASSERT_EQ(d[0], 3);
//     ASSERT_EQ(d[1], 2);
// }


//const []
// TYPED_TEST(TestDeque, const_bracket_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_front(1);
//     d.push_front(2);
//     d.push_front(3);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e[0], 3);
//     ASSERT_EQ(e[1], 2);
// }


// begin
// TYPED_TEST(TestDeque, begin_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(1);
//     d.push_back(2);
//     d.push_back(3);
    
//     //my_deque<int>::iterator temp = d.begin();
//     ASSERT_EQ(*d.begin(), 1);
//     ASSERT_EQ(d[1], 2);
//     ASSERT_EQ(d[1], 2);
// }


// const_begin
// TYPED_TEST(TestDeque, const_begin_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(1);
//     d.push_back(2);
//     d.push_back(3);
    
//     const deque_type e(d);
//     //my_deque<int>::iterator temp = e.begin();
//     ASSERT_EQ(*e.begin(), 1);
//     ASSERT_EQ(e[1], 2);
// }

// end
// TYPED_TEST(TestDeque, end_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(1);
//     d.push_back(2);
//     d.push_back(3);
    
//     //my_deque<int>::iterator temp = d.begin();
//     ASSERT_EQ(*(--d.end()), 3);
//     ASSERT_EQ(d[1], 2);
//     //ASSERT_EQ(d[1], 2);
// }

//const end
// TYPED_TEST(TestDeque, const_end_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(1);
//     d.push_back(2);
//     d.push_back(3);
    
//     const deque_type e(d);
    
//     //my_deque<int>::iterator temp = d.begin();
//     ASSERT_EQ(*(--e.end()), 3);
//     ASSERT_EQ(e[1], 2);
//     //ASSERT_EQ(d[1], 2);
// }



// constructor
// TYPED_TEST(TestDeque, constructor_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     //d.push_back(7);
//     ASSERT_EQ(d.size(), 0);
// }

// TYPED_TEST(TestDeque, constructor_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     ASSERT_EQ(d.size(), 1);
//     ASSERT_EQ(d[0], 7);
// }

// TYPED_TEST(TestDeque, constructor_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_front(7);
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
// }

// constructor_size
// TYPED_TEST(TestDeque, constructor_size_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(20,6);
//     d.push_back(7);
//     ASSERT_EQ(d.size(), 21);
//     ASSERT_EQ(d[0], 6);
//     //d.print_deque();
// }

// TYPED_TEST(TestDeque, constructor_size_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(1);
//     d.push_back(7);
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 0);
//     ASSERT_EQ(d[1], 7);
//     //d.print_deque();
// }

// TYPED_TEST(TestDeque, constructor_size_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type a(1);
//     a.push_back(1);// Fucking wrong here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
//     deque_type d(45,9);
//     d.push_back(7);
//     ASSERT_EQ(d.size(), 46);
//     ASSERT_EQ(d[0], 9);
//     ASSERT_EQ(d[45], 7);
//     //d.print_deque();
// }


//constructor_that
// TYPED_TEST(TestDeque, constructor_that_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(9);
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
//     ASSERT_EQ(d[1], 9);
    
//     deque_type e(d);
    
//     e.push_back(8);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
//     ASSERT_EQ(e[1], 9);
//     ASSERT_EQ(e[2], 8);
    
//     //d.print_deque();
// }

// assignment
// TYPED_TEST(TestDeque, assignment_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type e;
//     {
//     deque_type d;
//     d.push_back(7);
//     d.push_back(9);
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
//     ASSERT_EQ(d[1], 9);
    
//     e = (const deque_type)d;
//     d.push_back(6);

//     }
//     e.push_back(10);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
//     ASSERT_EQ(e[1], 9);
//     ASSERT_EQ(e[2], 10);
    
//     //d.print_deque();
// }


// swap
// TYPED_TEST(TestDeque, swap_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(9);
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
//     ASSERT_EQ(d[1], 9);
    
//     deque_type e;
//     e.push_back(6);
//     e.push_back(8);
    
//     ASSERT_EQ(e.size(), 2);
//     ASSERT_EQ(e[0], 6);
//     ASSERT_EQ(e[1], 8);
    
//     e.swap(d);
    
//     ASSERT_EQ(e[0], 7);
//     ASSERT_EQ(e[1], 9);
//     ASSERT_EQ(d[0], 6);
//     ASSERT_EQ(d[1], 8);
    
//     //d.print_deque();
// }

// size
// TYPED_TEST(TestDeque, size_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(9);
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
//     ASSERT_EQ(d[1], 9);
// }


// resize
// TYPED_TEST(TestDeque, resize_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(9);
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
//     ASSERT_EQ(d[1], 9);
    
//     d.resize(5,4);
//     ASSERT_EQ(d.size(), 5);
//     ASSERT_EQ(d[0], 7);
//     ASSERT_EQ(d[1], 9);
//     ASSERT_EQ(d[2], 4);
//     ASSERT_EQ(d[3], 4);
//     ASSERT_EQ(d[4], 4);
// }

// clear
// TYPED_TEST(TestDeque, clear_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(9);
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
//     ASSERT_EQ(d[1], 9);
    
//     d.clear();
//     d.clear();
//     ASSERT_EQ(d.size(), 0);
// }

// erase
// TYPED_TEST(TestDeque, erase_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(9);
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
//     ASSERT_EQ(d[1], 9);
    
//     d.erase(d.begin());
//     ASSERT_EQ(d.size(), 1);
//     ASSERT_EQ(d[0], 9);   
// }

// insert
// TYPED_TEST(TestDeque, insert_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(9);
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
//     ASSERT_EQ(d[1], 9);
    
//     d.insert(d.begin(), 77);
//     ASSERT_EQ(d.size(), 3);
//     ASSERT_EQ(d[0], 77);
//     ASSERT_EQ(d[1], 7);
//     ASSERT_EQ(d[2], 9);  
// }

// equals
// TYPED_TEST(TestDeque, equals_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(9);
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
//     ASSERT_EQ(d[1], 9);
    

//     deque_type e;
//     e.push_back(7);
//     e.push_back(9);
//     ASSERT_EQ(e.size(), 2);
//     ASSERT_EQ(e, d);
// }

// compare
// TYPED_TEST(TestDeque, compare_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(9);
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
//     ASSERT_EQ(d[1], 9);
    
//     deque_type e;
//     e.push_back(6);
//     e.push_back(9);
//     ASSERT_EQ(e.size(), 2);
//     ASSERT_TRUE(e < d);
// }

// empty
// TYPED_TEST(TestDeque, empty_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(6);
//     d.push_back(9);
//     d.push_back(1);
//     ASSERT_FALSE(d.empty());
//     ASSERT_EQ(d[0], 6);
//     ASSERT_EQ(d[1], 9);
// }


// // destruct
// TYPED_TEST(TestDeque, destruct_1) {
//     ALL_OF_IT
//     using namespace std;
//     {
//     deque_type d;
//     d.push_back(6);
//     d.push_back(9);
//     d.push_back(1);
//     ASSERT_FALSE(d.empty());
//     ASSERT_EQ(d[0], 6);
//     ASSERT_EQ(d[1], 9);
//     }
//     ASSERT_TRUE(true);
// }



////////////////////////////////////////////////////////////////////////////
//////      iterator tests
////////////////////////////////////////////////////////////////////////////

// it_equals
// TYPED_TEST(TestDeque, it_equals_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);

//     ASSERT_EQ(d.begin() == d.begin(), true);
// }

// it_notequals
// TYPED_TEST(TestDeque, it_notequals_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
    
//     ASSERT_EQ(d.begin() != d.end(), true);
// }

// plus
// TYPED_TEST(TestDeque, plus_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(8);
    
//     ASSERT_EQ((d.begin() + 1) == --d.end(), true);
// }

// subtract
// TYPED_TEST(TestDeque, subtract_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(8);
    
//     ASSERT_EQ((d.begin() + 1) == (d.end() - 1), true);
// }


// star
// TYPED_TEST(TestDeque, star_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(45);
//     d.push_back(7);
//     //my_deque<int>::iterator ttt = d.begin();
//     *d.begin() = 8;
    
//     ASSERT_EQ(d.size(), 46);
//     ASSERT_EQ(d[0], 8);
//     //d.print_deque();
// }

// inc_pre
// TYPED_TEST(TestDeque, inc_pre_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
    
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
    
//     ASSERT_EQ(*(++d.begin()), 3);
//     //d.print_deque();
// }

// inc_post
// TYPED_TEST(TestDeque, inc_post_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
    
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
    
//     ASSERT_EQ(*(d.begin()++), 7);
//     //d.print_deque();
// }


// dec_pre
// TYPED_TEST(TestDeque, dec_pre_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
    
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
    
//     ASSERT_EQ(*(--d.end()), 3);
//     //d.print_deque();
// }


// TYPED_TEST(TestDeque, plus_eq_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
    
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
    
//     ASSERT_EQ(*(d.begin() += 1), 3);
//     //d.print_deque();
// }

// TYPED_TEST(TestDeque, minus_eq_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
    
//     ASSERT_EQ(d.size(), 2);
//     ASSERT_EQ(d[0], 7);
    
//     ASSERT_EQ(*(d.end() -= 1), 3);
//     //d.print_deque();
// }


// TYPED_TEST(TestDeque, it_cons_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(5);
//     d.push_back(1);
    
//     ASSERT_EQ(d.size(), 3);
//     ASSERT_EQ(d[0], 7);
    
//     ASSERT_EQ(*(d.begin()), 7);
//     ASSERT_EQ(*(d.end() -= 1), 1);
//     ASSERT_EQ(*(d.end() -= 2), 5);
//     //d.print_deque();
// }



// ////////////////////////////////////////////////////////////////////////////
// //////      const iterator tests
// ////////////////////////////////////////////////////////////////////////////


// TYPED_TEST(TestDeque, const_it_equals_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     const deque_type e(d);
    
//     ASSERT_EQ(e.begin() == e.begin(), true);
// }
// TYPED_TEST(TestDeque, const_it_equals_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     const deque_type e(d);
    
//     ASSERT_EQ(d.begin() == --d.end(), true);
// }
// TYPED_TEST(TestDeque, const_it_equals_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(8);
//     const deque_type e(d);
    
//     ASSERT_EQ(++e.begin() == --e.end(), true);
// }



// TYPED_TEST(TestDeque, const_it_notequals_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     const deque_type e(d);
    
//     ASSERT_EQ(e.begin() != e.end(), true);
// }
// TYPED_TEST(TestDeque, const_it_notequals_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     const deque_type e(d);
    
//     ASSERT_EQ(d.begin() != --d.end(), false);
// }
// TYPED_TEST(TestDeque, const_it_notequals_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(8);
//     const deque_type e(d);
    
//     ASSERT_EQ(++e.begin() != --e.end(), false);
// }



// TYPED_TEST(TestDeque, const_plus_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(8);
//     const deque_type e(d);
    
//     ASSERT_EQ((e.begin() + 1) == --e.end(), true);
// }

// TYPED_TEST(TestDeque, const_plus_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(8);
//     const deque_type e(d);
    
//     ASSERT_EQ((e.begin() + 2) == e.end(), true);
// }
// TYPED_TEST(TestDeque, const_plus_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(8);
//     const deque_type e(d);
    
//     ASSERT_EQ((e.begin() + 1) != --e.end(), false);
// }



// TYPED_TEST(TestDeque, const_subtract_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(8);
//     const deque_type e(d);
    
//     ASSERT_EQ((e.begin() + 1) == (e.end() - 1), true);
// }

// TYPED_TEST(TestDeque, const_subtract_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(8);
//     const deque_type e(d);
    
//     ASSERT_EQ(e.begin() == (e.end() - 2), true);
// }
// TYPED_TEST(TestDeque, const_subtract_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(8);
//     const deque_type e(d);
    
//     ASSERT_EQ((e.begin() + 1) != (e.end() - 1), false);
// }



// TYPED_TEST(TestDeque, const_star_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque<int> d(45,3);
    
//     const deque<int> e(d);

    
//     ASSERT_EQ(e.size(), 45);
//     ASSERT_EQ(*e.begin(), 3);
//     //d.print_deque();
// }
// TYPED_TEST(TestDeque, const_star_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(45,8);
//     //d.push_back(7);
//     //my_deque<int>::iterator ttt = d.begin();
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 45);
//     ASSERT_EQ(*e.begin(), 8);
//     //d.print_deque();
// }
// TYPED_TEST(TestDeque, const_star_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d(45,8);
//     d.push_back(7);
//     d.pop_back();
//     //my_deque<int>::iterator ttt = d.begin();
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 45);
//     ASSERT_EQ(*e.begin(), 8);
//     ASSERT_EQ(*(--e.end()), 8);
//     //d.print_deque();
// }



// TYPED_TEST(TestDeque, const_inc_pre_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 2);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(++e.begin()), 3);
//     //d.print_deque();
// }
// TYPED_TEST(TestDeque, const_inc_pre_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
//     d.push_back(2);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*(++e.begin()), 3);
//     ASSERT_EQ(*(++++e.begin()), 2);
//     //d.print_deque();
// }
// TYPED_TEST(TestDeque, const_inc_pre_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(5);
//     d.push_back(1);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*(++e.begin()), 5);
//     ASSERT_EQ(*(++++e.begin()), 1);
//     //d.print_deque();
// }



// TYPED_TEST(TestDeque, const_inc_post_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 2);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()++), 7);
//     //d.print_deque();
// }
// TYPED_TEST(TestDeque, const_inc_post_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
//     d.push_back(2);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*(e.begin()++), 7);
//     ASSERT_EQ(*((++e.begin())++), 3);
//     //d.print_deque();
// }
// TYPED_TEST(TestDeque, const_inc_post_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(5);
//     d.push_back(1);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*(e.begin()++), 7);
//     ASSERT_EQ(*((++e.begin())++), 5);
//     //d.print_deque();
// }

// TYPED_TEST(TestDeque, const_dec_pre_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 2);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(--e.end()), 3);
//     //d.print_deque();
// }
// TYPED_TEST(TestDeque, const_dec_pre_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
//     d.push_back(2);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*(--e.end()), 2);
//     ASSERT_EQ(*(----e.end()), 3);
//     //d.print_deque();
// }
// TYPED_TEST(TestDeque, const_dec_pre_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(5);
//     d.push_back(1);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*(--e.end()), 1);
//     ASSERT_EQ(*(----e.end()), 5);
//     //d.print_deque();
// }



// TYPED_TEST(TestDeque, const_dec_post_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 2);
//     ASSERT_EQ(e[0], 7);
//     ASSERT_EQ(e[1], 3);
//     e.end()--;
//     ASSERT_EQ(*(++e.begin()), 3);
// }
// TYPED_TEST(TestDeque, const_dec_post_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
//     d.push_back(2);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*((--e.end())--), 2);
// }
// TYPED_TEST(TestDeque, const_dec_post_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(5);
//     d.push_back(1);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*((--e.end())--), 1);
// }



// TYPED_TEST(TestDeque, const_plus_eq_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 2);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin() += 1), 3);
// }
// TYPED_TEST(TestDeque, const_plus_eq_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
//     d.push_back(2);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*(e.begin() += 1), 3);
//     ASSERT_EQ(*(e.begin() += 2), 2);
// }
// TYPED_TEST(TestDeque, const_plus_eq_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(5);
//     d.push_back(1);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*(e.begin() += 1), 5);
//     ASSERT_EQ(*(e.begin() += 2), 1);
//     //d.print_deque();
// }



// TYPED_TEST(TestDeque, const_minus_eq_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 2);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.end() -= 1), 3);
//     //d.print_deque();
// }
// TYPED_TEST(TestDeque, const_minus_eq_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
//     d.push_back(2);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*(e.end() -= 1), 2);
//     ASSERT_EQ(*(e.end() -= 2), 3);
//     //d.print_deque();
// }
// TYPED_TEST(TestDeque, const_minus_eq_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(5);
//     d.push_back(1);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*(e.end() -= 1), 1);
//     ASSERT_EQ(*(e.end() -= 2), 5);
//     //d.print_deque();
// }



// TYPED_TEST(TestDeque, const_it_cons_1) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 2);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.end() -= 1), 3);
//     //d.print_deque();
// }
// TYPED_TEST(TestDeque, const_it_cons_2) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(3);
//     d.push_back(2);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*(e.end() -= 2), 3);
//     //d.print_deque();
// }
// TYPED_TEST(TestDeque, const_it_cons_3) {
//     ALL_OF_IT
//     using namespace std;
//     deque_type d;
//     d.push_back(7);
//     d.push_back(5);
//     d.push_back(1);
    
//     const deque_type e(d);
    
//     ASSERT_EQ(e.size(), 3);
//     ASSERT_EQ(e[0], 7);
    
//     ASSERT_EQ(*(e.begin()), 7);
//     ASSERT_EQ(*(e.end() -= 1), 1);
// }
 




