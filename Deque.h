// ----------------------
// projects/deque/Deque.h
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------

#ifndef Deque_h
#define Deque_h
#define WIDTH 50 
// --------
// includes
// --------

#include <algorithm> // copy, equal, lexicographical_compare, max, swap
#include <cassert>   // assert
#include <iterator>  // iterator, bidirectional_iterator_tag
#include <memory>    // allocator
#include <stdexcept> // out_ofirst_range
#include <utility>   // !=, <=, >, >=
#include <iostream>
// -----
// using
// -----

using std::rel_ops::operator!=;
using std::rel_ops::operator<=;
using std::rel_ops::operator>;
using std::rel_ops::operator>=;
//using namespace std;

// -------
// destroy
// -------

template <typename A, typename BI>
BI destroy (A& a, BI b, BI e) {
    while (b != e) {
        --e;
        a.destroy(&*e);}
    return b;}

// ------------------
// uninitialized_copy
// ------------------

template <typename A, typename II, typename BI>
BI uninitialized_copy (A& a, II b, II e, BI x) {
    BI p = x;
    try {
        while (b != e) {
            a.construct(&*x, *b);
            ++b;
            ++x;}}
    catch (...) {
        destroy(a, p, x);
        throw;}
    return x;}

// ------------------
// uninitialized_fill
// ------------------

template <typename A, typename BI, typename U>
BI uninitialized_fill (A& a, BI b, BI e, const U& v) {
    BI p = b;
    try {
        while (b != e) {
            a.construct(&*b, v);
            ++b;}}
    catch (...) {
        destroy(a, p, b);
        throw;}
    return e;}

// -------
// my_deque
// -------

template < typename T, typename A = std::allocator<T> >
class my_deque {
    // typedefs
    public:
        // --------
        // typedefs
        // --------

        typedef A                                       allocator_type;
        typedef typename allocator_type::value_type     value_type; // T        

        typedef typename allocator_type::size_type          size_type;
        typedef typename allocator_type::difference_type    difference_type;

        typedef typename allocator_type::pointer            pointer;    // T*
        typedef typename allocator_type::const_pointer      const_pointer;

        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        
        typedef typename allocator_type::template rebind<T*>::other pointer_allocator_type;
        typedef typename pointer_allocator_type::pointer    pointer_pointer; // T**

    public:
        // -----------
        // operator ==
        // -----------

        /**
         * <your documentation>
         */
        friend bool operator == (const my_deque& lhs, const my_deque& rhs) {
            // <your code>
            // you must use std::equal()
            return (lhs.size() == 0 && rhs.size() == 0) || ((lhs.size() == rhs.size()) && 
                std::equal(lhs.begin(), lhs.end(), rhs.begin()));
        }        

        // ----------
        // operator <
        // ----------

        /**
         * <your documentation>
         */
        friend bool operator < (const my_deque& lhs, const my_deque& rhs) {
            // <your code>
            // you must use std::lexicographical_compare()
            return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
    // data
    private:
        // ----
        // data
        // ----

        allocator_type _a;      //inner allocator
        pointer_allocator_type _pa; // T* allocator (outer array allocator )
        
        pointer_pointer _fr;    // front of outer array (dFro)
        pointer_pointer _ba;    // back of outer array  (dEnd)


        pointer _front;     // front of allocated space
        pointer _begin;     // beginning of used space
        pointer _end;       // end of used space
        pointer _back;      // back of allocated space



    //valid
    private:
        // -----
        // valid
        // -----

        bool valid () const {
            // <your code>
return (!_front && !_begin && !_end && !_back) ||
        ((_front <= _begin) && (_begin <= _end) && (_end <= _back));
      }

    //iterator class
    public:
        // --------
        // iterator
        // --------

        class iterator {
            // typedefs
            public:
                // --------
                // typedefs
                // --------

                typedef std::bidirectional_iterator_tag   iterator_category;
                typedef typename my_deque::value_type      value_type;
                typedef typename my_deque::difference_type difference_type;
                typedef typename my_deque::pointer         pointer;
                typedef typename my_deque::reference       reference;

            // == != + -
            public:
                // -----------
                // operator ==
                // -----------

                /**
                 * <your documentation>
                 */
                friend bool operator == (const iterator& lhs, const iterator& rhs) {
                    // <your code>
                    return (lhs.idx == rhs.idx) && (lhs._d == rhs._d);
                }

                /**
                 * <your documentation>
                 */
                friend bool operator != (const iterator& lhs, const iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * <your documentation>
                 */
                friend iterator operator + (iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * <your documentation>
                 */
                friend iterator operator - (iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}
            // data
            private:
                // ----
                // data
                // ----

                // <your data>
                my_deque* _d;
                size_type idx;
                //std::size_t idx;

            // valid()
            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    // <your code>
                    return idx >= 0;
                }
            // ###iterator construtor###
            // operator * -> ++ -- += -= 
            public:
                // -----------
                // constructor
                // -----------

                /**
                 * <your documentation>
                 */
                iterator (my_deque* d, size_type i = 0) {
                    // <your code>
                    idx = i;
                    _d = d;
                    assert(valid());
                }

                // Default copy, destructor, and copy assignment.
                // iterator (const iterator&);
                // ~iterator ();
                // iterator& operator = (const iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * <your documentation>
                 */
                reference operator * () const {
                    // <your code>
                    return (*_d)[idx];
                    //return x->at(index);
                }

                // -----------
                // operator ->
                // -----------

                /**
                 * <your documentation>
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * <your documentation>
                 */
                iterator& operator ++ () {
                    // <your code>
                    ++idx;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
                 */
                iterator operator ++ (int) {
                    iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator --
                // -----------

                /**
                 * <your documentation>
                 */
                iterator& operator -- () {
                    // <your code>
                    --idx;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
                 */
                iterator operator -- (int) {
                    iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator +=
                // -----------

                /**
                 * <your documentation>
                 */
                iterator& operator += (difference_type d) {
                    // <your code>
                    idx += d;
                    assert(valid());
                    return *this;
                }

                // -----------
                // operator -=
                // -----------

                /**
                 * <your documentation>
                 */
                iterator& operator -= (difference_type d) {
                    // <your code>
                    idx -= d; 
                    assert(valid());
                    return *this;}
                };//end of iterator class
    // const_iterator class
    public:
        // --------------------
        // const_iterator class
        // --------------------

        class const_iterator {
            // typedefs
            public:
                // --------
                // typedefs
                // --------

                typedef std::bidirectional_iterator_tag   iterator_category;
                typedef typename my_deque::value_type      value_type;
                typedef typename my_deque::difference_type difference_type;
                typedef typename my_deque::const_pointer   pointer;
                typedef typename my_deque::const_reference reference;

            //== != + -
            public:
                // -----------
                // operator ==
                // -----------

                /**
                 * <your documentation>
                 */
                friend bool operator == (const const_iterator& lhs, const const_iterator& rhs) {
                    // <your code>
                    return (lhs.idx == rhs.idx) && (lhs._d == rhs._d);
                }

                /**
                 * <your documentation>
                 */
                friend bool operator != (const const_iterator& lhs, const const_iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * <your documentation>
                 */
                friend const_iterator operator + (const_iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * <your documentation>
                 */
                friend const_iterator operator - (const_iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}
            
            //data
            private:
                // ----
                // data
                // ----

                // <your data>
                const my_deque* _d;
                size_type idx;
                //std::size_t idx;
                
            //valid()
            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    // <your code>
                    return idx >= 0;
                }//valid()

            //###const_iterator constructor###
            //* -> ++ -- += -= 
            public:
                // -----------
                // constructor
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator (const my_deque* d, size_type i){
                    _d = d; idx = i; 
                    assert(valid());}

                /**
                 * constructor talking a non constant iterator
                 */

                // Default copy, destructor, and copy assignment.
                // const_iterator (const const_iterator&);
                // ~const_iterator ();
                // const_iterator& operator = (const const_iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * <your documentation>
                 */
                reference operator * () const {
                    // <your code>
                    return (*_d)[idx];// return x->at(index);
                    
                }

                // -----------
                // operator ->
                // -----------

                /**
                 * <your documentation>
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator& operator ++ () {
                    // <your code>
                    ++idx;
                    assert(valid());
                    return *this;
                }

                /**
                 * <your documentation>
                 */
                const_iterator operator ++ (int) {
                    const_iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator --
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator& operator -- () {
                    // <your code>
                    --idx;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
                 */
                const_iterator operator -- (int) {
                    const_iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator +=
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator& operator += (difference_type d) {
                    // <your code>
                    idx += d;
                    assert(valid());
                    return *this;
                }

                // -----------
                // operator -=
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator& operator -= (difference_type d) {
                    // <your code>
                    idx -= d;
                    assert(valid());
                    return *this;
                }
            };
    // ###my_deque constructor and destructor###
    // operator: = [] at back begin clear empty end front insert 
    // popback popfront pushback pushfront resize size swap
    public:
        // ------------
        // constructors
        // ------------

        /**
         * @param a the allocator the deque used
         * default constructor or constructor that takes in an allocator
         */
         /**
         * @param a an allocator_type (optional)
         * Constructs the my_deque class with the given allocator or the standard allocator
         * by default. Will initialize the size and capacity to 0 and the pointers to the
         * beginning and the end to 0.
         */
        explicit my_deque (const allocator_type& a = allocator_type() ):_pa(){
            _a = a;  _fr=0; _ba=0; _front=0; _begin=0; _end=0; _back=0;
            assert(valid() );
        }

        /**
         * fill constructor that optionally takes in an allocator
         * @param s the number of elements
         */
         /**
         * @param s a size_type 
         * @param v a const_reference (optional)
         * @param a an allocator_type (optional)
         * Will create an instance of my_deque with the given size and fill the deque with the
         * given value. If no value is given, then it will use the default constructor for the
         * type of the contents of the deque. It will also use the standard allocator if none is
         * given.
         */
        explicit my_deque (size_type s, const_reference v = value_type(), const allocator_type& a = allocator_type()): _pa() {
            // <your code>
            _a = a;
            // we need s / WIDTH(50) full arrays, and possibly 1 partial array
            size_type num_arrays = s / WIDTH + (s % WIDTH? 1 : 0);//ok
            //size_t outer_size = s/50 + (s%50 1: 0);
            // allocate outer array and save pointer to front
            _fr = _pa.allocate(num_arrays);//ok
            // allocate inner arrays
            for (size_type i = 0; i < num_arrays; ++i) {
                _fr[i] = _a.allocate(WIDTH);//ok
            }
            // set pointer to back
            
            _ba = _fr + num_arrays;
            // set pointer to beginning of data
            //_b = _fr[0];
            // offset < WIDTH if we have a partial array
            size_type offset = WIDTH - (WIDTH * num_arrays - s); 
            assert  (0 < offset and offset <= WIDTH);
            // set pointer to end of data
            //_e = _fr[num_arrays - 1] + offset;
            // fill inner arrays with default value
            for (size_type i = 0; i < num_arrays; ++i) {
                _a.deallocate(_fr[i], WIDTH);//??why deallocate
            }
            _pa.deallocate(_fr, num_arrays);
            _front = _begin = _a.allocate(s);
            _end = _back = _begin + s;
            uninitialized_fill(_a, begin(), end(), v);
            assert(valid());
        }

        /**
         * copy constructor
         * @param that my_deque to be get copied
         */
         /**
         * @param that is a my_deque reference with which we will make a copy
         * The copy constructor will make a new my_deque instance copying the content 
         * of that into the newly created instance.
         */
        my_deque (const my_deque& that) {
            // <your code>
            _a = that._a;
            _pa = pointer_allocator_type();
            _fr = _ba = 0;
            //_b = _e;
            _front = _begin = _a.allocate(that.size());
            _end = _back = _begin + that.size();
            uninitialized_copy(_a, that.begin(), that.end(), begin()); 
            assert(valid());
        }

        // ----------
        // destructor
        // ----------

        /**
         * <your documentation>
         */
        ~my_deque () {
            // <your code>
            if (_front) {
                clear();
                _a.deallocate(_front, (_back - _front));}
            assert(valid() );

            // if (_begin) {
            //     clear();
            //     int rowsDeall = _obegin - _oend + 1;

            //     for (int i = 0; i < rowsDeall; ++i) {
            //         _a.deallocate(*_obegin, _arraySize);
            //         ++_obegin;
            //     }
            //     _oa.deallocate(_ofirst, _olast - _ofirst);
            // }
            // //assert(valid());
        }

        // ----------
        // operator =
        // ----------

        /**
         * = operator
         * @param that constant reference to that
         * @return the copy my_deque
         */
         /**
         * @param rhs a const my_deque reference
         * @return a my_deque reference
         * Will copy assign a my_deque instance to another
         */
        my_deque& operator = (const my_deque& rhs) {
            // <your code>
           if (this == &rhs)
                return *this;
            if (rhs.size() == size())
                std::copy(rhs.begin(), rhs.end(), begin());
            else if (rhs.size() < size()) {
                std::copy(rhs.begin(), rhs.end(), begin());
                resize(rhs.size());}    
            else if ((unsigned)rhs.size() <= (unsigned)(_back - _begin)) {
                std::copy(rhs.begin(), rhs.begin() + size(), begin());
                _end = &(*uninitialized_copy(_a, rhs.begin() + size(), rhs.end(), end()));}
            else {
                clear();
                my_deque x(rhs);
                swap(x);}
            assert(valid() );
            return *this;
        }

        // -----------
        // operator []
        // -----------

        /**
         * @param index a size_type
         * @return a reference to an element in the my_deque
         * Will navigate to the correct position in the two-d container from a single
         * index and return a reference to the object located there. No bounds checking
         */
        reference operator [] (size_type index) {
            // <your code>
            pointer r = _begin + index;
            return *r;
        }

        /**
         * @param index a size_type
         * @return a const_reference to an element in the my_deque
         * Will navigate to the correct position in the two-d container from a single
         * index and return a reference to the object located there. No bounds checking
         */
        const_reference operator [] (size_type index) const {
            return const_cast<my_deque*>(this)->operator[](index);}

        // --
        // at
        // --

        /**
         * @param index a size_type
         * @return a reference to an element in the my_deque
         * Will navigate to the correct position in the two-d container from a single
         * index and return a reference to the object located there. Does bounds checking
         * and will throw an out_ofirst_range exception if trying to access out of range.
         */
        reference at (size_type index) {
            // <your code>
            if (index >= size() )
                throw std::out_of_range("deque::_M_range_check");
            return (*this)[index];
        }

        /**
         * @param index a size_type
         * @return a const_reference to an element in the my_deque
         * Will navigate to the correct position in the two-d container from a single
         * index and return a read only reference to the object located there. Does 
         * bounds checking and will throw an out_ofirst_range exception if trying to 
         * access out of range.
         */
        const_reference at (size_type index) const {
            return const_cast<my_deque*>(this)->at(index);}

        // ----
        // back
        // ----

        /**
         * @return a reference
         * Will return a read/write reference to the last element in the deque.
         */
        reference back () {
            // <your code>
            // assert(!empty());
            // return *(end() - 1);
            assert(! empty());
            return *(_end - 1);
        }

        /**
         * @return a const_reference
         * Will return a read only reference to the last element in the deque.
         */
        const_reference back () const {
            return const_cast<my_deque*>(this)->back();}

        // -----
        // begin
        // -----

        /**
         * @return a iterator
         * Will create and return a read/write iterator to the front of the deque
         */
        iterator begin () {
            // <your code>
            return iterator(this, 0);}

        /**
         * @return a const_iterator
         * Will create and return a read only iterator to the front of the deque
         */
        const_iterator begin () const {
            // <your code>
            return const_iterator(this, 0);}

        // -----
        // clear
        // -----

        /**
         * Will remove all elements from the deque by leveraging the resize method.
         */
        void clear () {
            // <your code>
            resize(0);
            assert(valid());
        }

        // -----
        // empty
        // -----

        /**
         * @return a bool
         * Will return true if the deque is empty and false otherwise.
         */
        bool empty () const {
            return !size();}

        // ---
        // end
        // ---

        /**
         * @return a iterator
         * Will create and return a read/write iterator to the end
         * of the deque
         */
        iterator end () {
            // <your code>
            return iterator(this, size());}

        /**
         * @return a const_iterator
         * Will create and return a read only iterator to the end
         * of the deque
         */
        const_iterator end () const {
            // <your code>
            return const_iterator(this, size());}

        // -----
        // erase
        // -----

        /**
         * @param pos an iterator
         * @return an interator
         * Will remove the value at the given iterator position and
         * move all the following elements forward. 
         */
        iterator erase (iterator pos) {
            // <your code>
        }

        // -----
        // front
        // -----

        /**
         * @return a reference
         * Will return a read/write reference to the value at the front
         * of the deque.
         */
        reference front () {
            // <your code>
            return *(_begin);
            // assert(!empty());
            // return *begin();
            //return at(0);
            
        }

        /**
         * @return a const_reference
         * Will return a read only reference to the value at the front
         * of the deque.
         */
        const_reference front () const {
            return const_cast<my_deque*>(this)->front();}

        // ------
        // insert
        // ------

        /**
         * @param i an iterator
         * @param v a const_reference
         * @return an iterator
         * Will insert the given value into the deque at the iterator
         * position and move all the elements after that position down in the deque.
         */
        iterator insert (iterator pos, const_reference v) {
            // <your code>
                    if(pos == end() )
                push_back(v);
            else {
                resize(size()+1);
                std::copy(pos, end(), pos+1);
                *pos = v;}
            assert(valid());
            return iterator(this); 
   
        }

        // ---
        // pop
        // ---

        /**
         * Will remove the element at the back of the deque,
         * and decrement the size by one
         */
        void pop_back () {
            // <your code>
            assert(!empty());
            resize(size() - 1);
            assert(valid());
        }

        /**
         * Will remove the element at the front of the deque,
         * and decrement the size by one
         */
        void pop_front () {
            // <your code>
            destroy(_a, begin(), begin()+1);
            ++_begin;
            assert(valid() );
            //cout << "here >> "<< _size <<endl;
            // assert(!empty());
            // _a.destroy(_begin);
            // _begin = &at(1);
            // --_size;
            //cout << "here >> "<< _size <<endl;
            assert(valid());    
        }

        // ----
        // push
        // ----

        /**
         * @param val a const_reference
         * Will push the given value onto the back of the deque
         * and increment the size by one
         */
        void push_back (const_reference v) {
            // <your code>
            // resize(size() + 1, v);
            // assert(valid());
            resize(_size + 1);
            *(end() - 1) = v;
            assert(valid());
        }

        /**
         * @param val a const_reference
         * Will push the given value onto the front of the deque
         * and increment the size by one
         */
        void push_front (const_reference v) {
            // <your code>
            using namespace std;
            if (*_obegin != _begin) {
            //space available on this row
                --_begin;
                *begin() = v;
                ++_size;
            }
            else if (_obegin != _ofirst) {
                //space available for a new row
                --_obegin;
                *_obegin = _a.allocate(_arraySize);
                _begin = *_obegin + _arraySize - 1;
                *begin() = v;
                ++_size;
            }
        }

        // ------
        // resize
        // ------

        /**
         * @param s a size_type
         * @param v a const_reference(optional)
         * Will resize the deque to the given size. If it is less than the current size
         * then the deque will shrink, destroying the elements that are removed from the
         * end. If the size to resize is greater than the current size it will grow the
         * the capacity where necessary and fill with the given default value. If no 
         * default value is given, the default constructor for the deque's value type will
         * be used. 
         */
        void resize (size_type s, const_reference v = value_type()) {
            // <your code>
                if(endRowNum == (_oend - _obegin)) {
                   // cout<<"3_1 "<<endl;
                    _size = s;
                    eIter = uninitialized_fill(_a, end(), begin() + difference_type(s), v);
                    _end = &*eIter;
                    // _oe stays the same
                } 
                else if (endRowNum < (_olast - _obegin)) {
                    //cout<<"3_2 "<<endl;

                    _size = s;          
                    int moreRows = endRowNum - (_oend - _obegin);

                    for (int i = 0; i < moreRows; ++i) {
                        ++_oend;
                        *_oend = _a.allocate(_arraySize);       
                    }

                    eIter = uninitialized_fill(_a, end(), begin() + difference_type(s), v);
                    _end = &*eIter;
                } 
                else{
                    //cout<<"3_3 "<<endl;

                    int moreRows = endRowNum - (_olast - _obegin) + 1;
                    int totalRows = _olast - _ofirst + moreRows;
                    my_deque x(*this, totalRows);
                    swap(x);
                    resize(s, v);
        }

        // ----
        // size
        // ----

        /**
         * @return a size_type
         * Returns the size of the deque, not the capacity
         */
        size_type size () const {
            // <your code>
            return _end - _begin;
        }

        // ----
        // swap
        // ----

        /**
         * @param that a my_deque reference
         * Will swap this deque with the one given as a parameter.
         */
        void swap (my_deque& that) {
            // <your code>
            if (_a == that._a) {
                std::swap(_front, that._front);
                std::swap(_begin, that._begin);
                std::swap(_end, that._end);
                std::swap(_back, that._back);}
            else {
                my_deque x(*this);
                *this = that;
                that = x;}
            assert(valid() );
        }


    };

#endif // Deque_h
