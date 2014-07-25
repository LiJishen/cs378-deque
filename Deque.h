// ----------------------
// projects/deque/Deque.h
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------

#ifndef Deque_h
#define Deque_h

// --------
// includes
// --------

#include <algorithm> // copy, equal, lexicographical_compare, max, swap
#include <cassert>   // assert
#include <iterator>  // iterator, bidirectional_iterator_tag
#include <memory>    // allocator
#include <stdexcept> // out_ofirst_range
#include <utility>   // !=, <=, >, >=

// -----
// using
// -----

using std::rel_ops::operator!=;
using std::rel_ops::operator<=;
using std::rel_ops::operator>;
using std::rel_ops::operator>=;
using namespace std;

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

        typedef A                                        allocator_type;
        typedef typename allocator_type::value_type      value_type;

        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;

        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;

        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;
    
        typedef typename allocator_type::template rebind<T*>::other outer_allocator;
        typedef typename allocator_type::template rebind<T*>::other::pointer outer_pointer;


    // two friend functions // done
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
            return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
    // data
    private:
        // ----
        // data
        // ----

        allocator_type _a;      //inner allocator
        outer_allocator _oa;    //outer allocator

        pointer _begin;
        pointer _end;

        size_type _size;
  
        outer_pointer _ofirst;  //outer first
        outer_pointer _obegin;  //outer begin
        outer_pointer _oend;    //outer end
        outer_pointer _olast;   //outer last

        size_type _arraySize;



    //valid
    private:
        // -----
        // valid
        // -----

        bool valid () const {
            // <your code>
            return (!_begin && !_end && !_ofirst && !_obegin && !_oend && !_olast) || 
                 (((_ofirst <= _obegin) && (_obegin <= _oend) && (_oend <= _olast)) && 
                 ((*_obegin <= _begin) && (*_oend <= _end)));
        }
        my_deque (const my_deque& that, int n){
            _a = that._a;
            _size = that._size;
            _oa = that._oa;
            _arraySize = that._arraySize;
            
            _ofirst = _oa.allocate(n);
            _obegin = _ofirst + (that._obegin - that._ofirst);
            _oend = _ofirst + (that._oend - that._ofirst);
            _olast = _ofirst + n;

            for(int i = 0; i <= (_oend - _obegin); ++i) {
                    *(_obegin+i) = _a.allocate(_arraySize); 
            }
            _begin = *_obegin + (that._begin - *(that._obegin));
            _end = *_oend + (that._end - *(that._oend));

            uninitialized_copy(_a, that.begin(), that.end(), begin());
            assert(valid());
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
                    return (lhs.index == rhs.index) && (lhs.x == rhs.x);
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
                my_deque* x;
                std::size_t index;
            // valid()
            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    // <your code>
                    return true;
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
                iterator (my_deque* p, std::size_t i) {
                    // <your code>
                    index = i;
                    x = p;
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
                    return x->at(index);
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
                    ++index;
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
                    --index;
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
                    index += d;
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
                    index -= d; 
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
                    return (lhs.index == rhs.index) && (lhs.x == rhs.x);
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
                const my_deque* x;
                std::size_t index;
            //valid()
            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    // <your code>
                    return true;
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
                const_iterator (const my_deque* p, std::size_t i){
                    x = p; index = i; 
                    assert(valid());}

                /**
                 * constructor talking a non constant iterator
                 */
                // const_iterator(iterator it) 
                // {
                //     current_beginlock = const_cast<pointer*>(it.get_beginlock_address());
                //     current_beginlock_index = it.get_beginlock_index();
                //     assert(valid());
                // }

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
                    return x->at(index);}

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
                    ++index;
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
                    --index;
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
                    index += d;
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
                    index -= d;
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
         * Constructs the mydeque class with the given allocator or the standard allocator
         * by default. Will initialize the size and capacity to 0 and the pointers to the
         * beginning and the end to 0.
         */
        explicit my_deque (const allocator_type& a = allocator_type()) {
            // <your code>
            _a = a;
            _begin = 0; 
            _end = 0; 
            _size = 0;
            _oa = a;
            _ofirst = 0; 
            _obegin = 0; 
            _oend = 0; 
            _olast = 0; 
            _arraySize = 0; 
            assert(valid());}

        /**
         * fill constructor that optionally takes in an allocator
         * @param s the number of elements
         */
         /**
         * @param s a size_type 
         * @param v a const_reference (optional)
         * @param a an allocator_type (optional)
         * Will create an instance of mydeque with the given size and fill the deque with the
         * given value. If no value is given, then it will use the default constructor for the
         * type of the contents of the deque. It will also use the standard allocator if none is
         * given.
         */
        explicit my_deque (size_type s, const_reference v = value_type(), const allocator_type& a = allocator_type()) {
            // <your code>
            _a = a; _size = s; _oa = a;
            _ofirst = _oa.allocate(3);
            _obegin = _ofirst + 1;
            _oend = _obegin;
            _olast = _ofirst + 3;

            *_obegin = _a.allocate(3 * s);
            _begin = *_obegin + s;
            _end = *_obegin + 2*s;
       
            _arraySize = 3*s;
            uninitialized_fill(_a, begin(), end(), v);
            assert(valid());}

        /**
         * copy constructor
         * @param that MyDeque to be get copied
         */
         /**
         * @param that is a MyDeque reference with which we will make a copy
         * The copy constructor will make a new MyDeque instance copying the content 
         * of that into the newly created instance.
         */
        my_deque (const my_deque& that) {
            // <your code>
            _a = that._a; _size = that._size;
            _oa = that._oa; _arraySize = that._arraySize; 
            
            _ofirst = _oa.allocate(that._olast - that._ofirst);
            _obegin = _ofirst + (that._obegin - that._ofirst);
            _oend = _ofirst + (that._oend - that._ofirst);
            _olast = _ofirst + (that._olast - that._ofirst);

            for(int i = 0; i <= (_oend - _obegin); ++i) {
                *(_obegin+i) = _a.allocate(_arraySize); 
            }
            _begin = *_obegin + (that._begin - *(that._obegin));
            _end = *_oend + (that._end - *(that._oend));

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
            if (_begin) {
                clear();
                int rowsDeall = _obegin - _oend + 1;

                for (int i = 0; i < rowsDeall; ++i) {
                    _a.deallocate(*_obegin, _arraySize);
                    ++_obegin;
                }
                _oa.deallocate(_ofirst, _olast - _ofirst);
            }
            //assert(valid());
        }

        // ----------
        // operator =
        // ----------

        /**
         * = operator
         * @param that constant reference to that
         * @return the copy MyDeque
         */
         /**
         * @param rhs a const MyDeque reference
         * @return a MyDeque reference
         * Will copy assign a MyDeque instance to another
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
            else {
                clear();
                resize(rhs.size());
                iterator eIter = std::copy(rhs.begin(), rhs.end(), begin());
                _end = &(*eIter);
            }
            assert(valid());
            return *this;
        }

        // -----------
        // operator []
        // -----------

        /**
         * @param index a size_type
         * @return a reference to an element in the MyDeque
         * Will navigate to the correct position in the two-d container from a single
         * index and return a reference to the object located there. No bounds checking
         */
        reference operator [] (size_type index) {
            // <your code>
            int row = (index + (_begin - *_obegin)) / _arraySize;
            int col = (index + (_begin - *_obegin)) % _arraySize;
            return *(*(_obegin + row) + col);
        }

        /**
         * @param index a size_type
         * @return a const_reference to an element in the MyDeque
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
         * @return a reference to an element in the MyDeque
         * Will navigate to the correct position in the two-d container from a single
         * index and return a reference to the object located there. Does bounds checking
         * and will throw an out_ofirst_range exception if trying to access out of range.
         */
        reference at (size_type index) {
            // <your code>
            if ( index > _size || index < 0 ) {
                throw std::out_of_range("my_deque::at(index)");
            }
            return (this)->operator[](index);
        }

        /**
         * @param index a size_type
         * @return a const_reference to an element in the MyDeque
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
            assert(!empty());
            return *(end() - 1);
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
            assert(_begin == _end); 
            assert(_obegin == _oend);
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
            return iterator(this, _size);}

        /**
         * @return a const_iterator
         * Will create and return a read only iterator to the end
         * of the deque
         */
        const_iterator end () const {
            // <your code>
            return const_iterator(this, _size);}

        // -----
        // erase
        // -----

        /**
         * @param pos an iterator
         * @return an interator
         * Will remove the value at the given iterator position and
         * move all the following elements forward. 
         */
        iterator erase (iterator i) {
            // <your code>
            // assert(valid());
            // return iterator();
            iterator i_copy(i);
            std::copy(i +1, end(), i);
            resize(_size - 1);
            assert(valid());
            return i_copy;
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
            assert(!empty());
            return *begin();
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
        iterator insert (iterator i, const_reference v) {
            // <your code>
            if (i == begin()) {
                push_front(v);
                return begin();
            }
            else if (i == end()) {
                push_back(v);
                return --(end());
            }
            else {
                iterator i_copy(i);
                resize(_size + 1);
                std::copy_backward(i, end() -1, end());
                *i_copy = v;
                assert(valid());
                return i_copy;
            }    
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
            //cout << "here >> "<< _size <<endl;
            assert(!empty());
            _a.destroy(_begin);
            _begin = &at(1);
            --_size;
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
            resize(_size + 1);
            *(end() - 1) = v;
            assert(valid());}

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
            else {
                //need to resize outer array
                my_deque x(*this, _olast - _ofirst + 2);
                swap(x);
                std::copy_backward(_obegin, _olast - 2, _olast);
                _oend += 2;
                ++_obegin;
                *_obegin = _a.allocate(_arraySize);
                _begin = *_obegin + _arraySize - 1;
                *begin() = v;
                ++_size;
            }
            assert(valid());
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
            return _size;}

        // ----
        // swap
        // ----

        /**
         * @param that a MyDeque reference
         * Will swap this deque with the one given as a parameter.
         */
        void swap (my_deque& that) {
            // <your code>
            if (_a == that._a) {

                std::swap(_begin, that._begin);
                std::swap(_end, that._end);
                std::swap(_ofirst, that._ofirst);
                std::swap(_obegin, that._obegin);
                std::swap(_oend, that._oend);
                std::swap(_olast, that._olast);
                std::swap(_arraySize, that._arraySize);
                std::swap(_size, that._size);
            } 
            else {
                    my_deque x(*this);
                    *this = that;
                    that = x;
            }
                assert(valid());
        }


    };

#endif // Deque_h
