// ----------------------
// projects/deque/Deque.h
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------

#ifndef Deque_h
#define Deque_h
#define ARRAY_SIZE 36
#define HEAD_SPACE 6
#define TAIL_SPACE 6

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
        typedef typename allocator_type::value_type     value_type;    

        typedef typename allocator_type::size_type          size_type;
        typedef typename allocator_type::difference_type    difference_type;

        typedef typename allocator_type::pointer            pointer;    
        typedef typename allocator_type::const_pointer      const_pointer;

        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        
        typedef typename allocator_type::template rebind<T*>::other pointer_allocator_type;
        typedef typename pointer_allocator_type::pointer    pointer_pointer; 

    public:
        // -----------
        // operator ==
        // -----------

        /**
         * @param lhs my_deque to compare to rhs
         * @param rhs my_deque to test equality with lhs
         * @return True if my_deques are the same size and have the same contents
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
         *  * @param lhs my_deque to compare to rhs
         * @param rhs my_deque to test order with lhs
         * @return True if lhs comes before rhs in the lexicographical compare
    
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
        pointer_allocator_type outer_alloc; // outer array allocator
        pointer_pointer outer_front;    // front of outer array 
        pointer head;     // head of allocated space
        pointer tail;      // tail of allocated space
        pointer _begin;     // beginning of used space
        pointer _end;       // end of used space



    //valid
    private:
        // -----
        // valid
        // -----

        bool valid () const {
            // <your code>
            return (!head && !_begin && !_end && !tail) ||
            ((head <= _begin) && (_begin <= _end) && (_end <= tail));
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
                * @return true if both iterators are indexing the same my_deque and pointing to the same element

                 */
                friend bool operator == (const iterator& lhs, const iterator& rhs) {
                    // <your code>
                    return (lhs.idx == rhs.idx) && (lhs._d == rhs._d);
                }

                /**
                @return true if operator == returns false
                */
                friend bool operator != (const iterator& lhs, const iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                * NEEDS UPDATING WITH ARRAY OF ARRAYS IMPLEMENTATION
                */
                friend iterator operator + (iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * * NEEDS UPDATING WITH ARRAY OF ARRAYS IMPLEMENTATION
        
                 */
                friend iterator operator - (iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}
            private:
                // ----
                // data
                // ----

                // <your data>
                my_deque* _d;
                std::size_t idx;

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    // <your code>
                    return idx >= 0;
                }

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * Two-arg constructor for the read/write iterator
                 * @param p a pointer to the my_deque this iterator is associated with
                 * @param i an int value which represents the zero-based index this iterator should point at in the my_deque
                 */
                iterator (my_deque* d, std::size_t i = 0) {
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
         * @return a reference to the element this iterator is pointing at
         */
                reference operator * () const {
                    // <your code>
                    return _d->operator[](idx);
                }

                // -----------
                // operator ->
                // -----------

                /**
         * @return the address of the element this iterator is pointing at
         */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
         * @return the reference to this iterator after its index has been incremented
         */
                iterator& operator ++ () {
                    // <your code>
                    ++idx;
                    assert(valid());
                    return *this;}

                 /**
         * @return a copy of this iterator, the original having had its index incremented
         */                iterator operator ++ (int) {
                    iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator --
                // -----------

                /**
                 *       * @return the reference to this iterator after its index has been decremented

                 */
                iterator& operator -- () {
                    // <your code>
                    --idx;
                    assert(valid());
                    return *this;}

                /**
                 * * @return a copy of this iterator, the original having had its index decremented
        
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
                * @param d a difference_type value which represents the change in the index of the iterator
                * @return a reference to this iterator after it has had its index updated
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
                * @param d a difference_type value which represents the change in the index of the iterator
                 * @return a reference to this iterator after it has had its index updated
                 */
                iterator& operator -= (difference_type d) {
                    // <your code>
                    idx -= d; 
                    assert(valid());
                    return *this;}
                };
    public:
        // --------------------
        // const_iterator class
        // --------------------

        class const_iterator {
            public:
                // --------
                // typedefs
                // --------

                typedef std::bidirectional_iterator_tag   iterator_category;
                typedef typename my_deque::value_type      value_type;
                typedef typename my_deque::difference_type difference_type;
                typedef typename my_deque::const_pointer   pointer;
                typedef typename my_deque::const_reference reference;

            public:
                // -----------
                // operator ==
                // -----------

                /**
             * ==operator
             * @param lhs an iterator to compare
             * @param rhs an iterator to compare
             * @return whether the iterators are equal
             */
                friend bool operator == (const const_iterator& lhs, const const_iterator& rhs) {
                    // <your code>
                    return (lhs.idx == rhs.idx) && (lhs._d == rhs._d);
                }

                /**
                * @return true if the operator == returns false
                         */
                friend bool operator != (const const_iterator& lhs, const const_iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

               /**
             * !=operator
             * @param lhs an iterator to compare
             * @param rhs an iterator to compare
             * @return whether the iterators are not equal
             */
                friend const_iterator operator + (const_iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
             * +operator for iterator and number
             * @param lhs an iterator
             * @param rhs integral type to change the position of the iterator
             * @return lhs + rhs
             */
                friend const_iterator operator - (const_iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}

            private:
                // ----
                // data
                // ----

                // <your data>
                const my_deque* _d;
                std::size_t idx;
                

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    // <your code>
                    return idx >= 0;
                }

            public:
                // -----------
                // constructor
                // -----------

                /**
             * default constructor
             */
                const_iterator (const my_deque* d, std::size_t i){
                    _d = d; 
                    idx = i; 
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
             * deference operator
             * @return a reference to the current element the iterator at
             */
                reference operator * () const {
                    // <your code>
                    return _d->operator[](idx);

                }

                // -----------
                // operator ->
                // -----------

                /**
             * structure dereference operator
             * @return the desired member of the current element the iterator at 
             */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
             * increment operator (pre)
             * @return reference of the iterator after incrementation
             */
                const_iterator& operator ++ () {
                    // <your code>
                    ++idx;
                    assert(valid());
                    return *this;
                }

                /**
             * increment operator (post)
             * @return reference of the iterator before incrementation
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
             * decrement operator (pre)
             * @return reference of the iterator after decrementation
             */
                const_iterator& operator -- () {
                    // <your code>
                    --idx;
                    assert(valid());
                    return *this;}

                /**
             * decrement operator (post)
             * @return reference of the iterator before decrementation
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
             * += operator
             * @param d the number of incrememtation
             * @return reference of the iterator after incrementation
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
             * -= operator
             * @param d the number of decrememtation
             * @return reference of the iterator after decrementation
             */
                const_iterator& operator -= (difference_type d) {
                    // <your code>
                    idx -= d;
                    assert(valid());
                    return *this;
                }
            };
 
    public:
        // ------------
        // constructors
        // ------------

        /**
         * @param a the allocator the deque used
         * default constructor or constructor that takes in an allocator
         */
        
        explicit my_deque (const allocator_type& a = allocator_type() ){
            outer_alloc = a ;_a = a;  outer_front=0; head=0; _begin=0; _end=0; tail=0;
            assert(valid() );
        }

        /**
         * fill constructor that optionally takes in an allocator
         * @param s the number of elements
         */
        explicit my_deque (std::size_t s, const_reference v = value_type(), const allocator_type& a = allocator_type())
        {
            // <your code>
            _a = a;
            unsigned int num_arrays;
            if(s % ARRAY_SIZE != 0)
                num_arrays = s / ARRAY_SIZE + 1;
            num_arrays = s / ARRAY_SIZE;

            outer_front= outer_alloc.allocate(num_arrays);
            for (unsigned int i = 0; i < num_arrays; ++i)
                outer_front[i] = _a.allocate(ARRAY_SIZE);
            _begin = _a.allocate(s);
            _end  = _begin + s;
            head = _begin;
            tail = _end;
            uninitialized_fill(_a, begin(), end(), v);
            assert(valid());
        }

        /**
         * copy constructor
         * @param that my_deque to be get copied
         */
        my_deque (const my_deque& that) {
            // <your code>
            _a = that._a;
            outer_alloc = that.outer_alloc;
            _begin = _a.allocate(that._end - that._begin);
            _end =  _begin + (that._end - that._begin);            
            uninitialized_copy(_a, that.begin(), that.end(), begin());             
            head = _begin;
            tail  = _end;
            assert(valid());
        }

        // ----------
        // destructor
        // ----------
        /**
         * destructor
         */
        ~my_deque () {
            // <your code>
            int capacity = tail - head;

            if (_begin) {
                clear();
                _a.deallocate(head, capacity);
            }
            assert(valid() );
        }

        // ----------
        // operator =
        // ----------

        /**
         * = operator
         * @param that constant reference to that
         * @return the copy my_deque
         */
         
        my_deque& operator = (const my_deque& rhs) {
            // <your code>
           unsigned int filled_space  =  _end - _begin;
           unsigned int begin_to_back = tail - _begin;
           if (this == &rhs)
                return *this;
            if (rhs.size() == filled_space)
                std::copy(rhs.begin(), rhs.end(), begin());

            else if (rhs.size() < filled_space) {
                std::copy(rhs.begin(), rhs.end(), begin());
                resize(rhs._end - rhs._begin);
            }   

            else if (rhs.size() <= begin_to_back) {
                std::copy(rhs.begin(), rhs.begin() + begin_to_back, begin());
                _end = &(*uninitialized_copy(_a, rhs.begin() + begin_to_back, rhs.end(), end()));
            }
            else {
                clear();
                my_deque x(rhs);
                swap(x);
            }
            assert(valid() );
            return *this;
        }

        // -----------
        // operator []
        // -----------

        /**
         * @param index a std::size_t
         * @return a reference to an element in the my_deque
         * Will navigate to the correct position in the two-d container from a single
         * index and return a reference to the object located there. No bounds checking
         */
        reference operator [] (std::size_t index) {
            // <your code>
            pointer r = _begin + index;
            return *r;
        }

        /**
         * @param index a std::size_t
         * @return a const_reference to an element in the my_deque
         * Will navigate to the correct position in the two-d container from a single
         * index and return a reference to the object located there. No bounds checking
         */
        const_reference operator [] (std::size_t index) const {
            return const_cast<my_deque*>(this)->operator[](index);}

        // --
        // at
        // --

        /**
         * @param index a std::size_t
         * @return a reference to an element in the my_deque
         * Will navigate to the correct position in the two-d container from a single
         * index and return a reference to the object located there. Does bounds checking
         * and will throw an out_ofirst_range exception if trying to access out of range.
         */
        reference at (std::size_t index) {
            // <your code>
            if (index >= size() )
                throw std::out_of_range("out_of_range");
            return (*this)[index];
        }

        /**
         * @param index a std::size_t
         * @return a const_reference to an element in the my_deque
         * Will navigate to the correct position in the two-d container from a single
         * index and return a read only reference to the object located there. Does 
         * bounds checking and will throw an out_ofirst_range exception if trying to 
         * access out of range.
         */
        const_reference at (std::size_t index) const {
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
            return (_end - _begin <= 0);
        }

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
            return iterator(this, _end - _begin);}

        /**
         * @return a const_iterator
         * Will create and return a read only iterator to the end
         * of the deque
         */
        const_iterator end () const {
            // <your code>
            return const_iterator(this, _end - _begin);}

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
            iterator it(pos);
            std::copy(pos +1, end(), pos);
            resize(_end - _begin - 1);
            assert(valid());
            return it;
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
                iterator it(i);
                resize(_end - _begin + 1);
                std::copy_backward(i, end() -1, end());
                *it = v;
                assert(valid());
                return it;
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
            resize(_end - _begin - 1);
            assert(valid());
        }

        /**
         * Will remove the element at the front of the deque,
         * and decrement the size by one
         */
        void pop_front () {
            // <your code>
            assert(!empty());
            _a.destroy(_begin);
            ++_begin;
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
            resize(size() + 1);
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
            if (head == _begin) {
                 resize(size() + 1);
                 pop_back();
             }    
             --_begin;
             _a.construct(&*begin(), v); 
             assert(valid());
        }

        // ------
        // resize
        // ------

        /**
         * @param s a std::size_t
         * @param v a const_reference(optional)
         * Will resize the deque to the given size. If it is less than the current size
         * then the deque will shrink, destroying the elements that are removed from the
         * end. If the size to resize is greater than the current size it will grow the
         * the capacity where necessary and fill with the given default value. 
         */
        void resize (std::size_t s, const_reference v = value_type()) {
            // <your code>

            if (s < size())
                _end = &*destroy(_a, begin() + s, end() );

            else if ((unsigned)s == (unsigned)(size()) && (unsigned)s <= (unsigned)(tail - _begin))
                _end = &*uninitialized_fill(_a, end(), begin() + s, v);

            else {      // need more capacity
                unsigned new_capacity = s;
                my_deque x(new_capacity + HEAD_SPACE + TAIL_SPACE , v);
                std::copy(begin(), end(), x.begin() + HEAD_SPACE);
                destroy(x._a, x.begin(), x.begin() + HEAD_SPACE);
                destroy(x._a, x.end()-TAIL_SPACE, x.end());
                x._begin += HEAD_SPACE;
                x._end -= TAIL_SPACE;
                swap(x);

            }
            assert(valid() );
        }

        // ----
        // size
        // ----

        /**
         * @return a std::size_t
         * Returns the size of the deque, not the capacity
         */
        std::size_t size () const {
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
                std::swap(head, that.head);
                std::swap(_begin, that._begin);
                std::swap(_end, that._end);
                std::swap(tail, that.tail);}
            else {
                my_deque x(*this);
                *this = that;
                that = x;}
            assert(valid() );
        }


    };

#endif // Deque_h
