/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 13:13:55 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/11/08 13:13:56 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft {

	template < typename T >
	struct listNode {

		listNode( const T &e ) : data( e ), next(0), prev(0) {}

		T			data;
		listNode<T>	*next;
		listNode<T>	*prev;
	};

	template < class T, class Alloc = std::allocator<T> >
	class list {

		template < typename Tp >
		class _iterator {

		public:

			_iterator() : _node( 0 ) {}
			_iterator( listNode<Tp>* p = 0 ) : _node( p ) {}
			_iterator( const _iterator& src ) { *this = src; }
			_iterator&	operator=( const _iterator& rhs ) {

				if ( this != &rhs )
					this->_node = rhs._node;
				return *this;
			}
			virtual ~_iterator() {}

			Tp &		operator*() { return this->_node->data; }
			Tp *		operator->() { return &( this->_node->_data ); }
			bool		operator!=( const _iterator& rhs ) { return this->_node != rhs._node; }
			bool 		operator==( const _iterator& rhs ) { return this->_node == rhs._node; }
			_iterator	operator++( int ) {

				_iterator	tmp = *this;
				this->_node = this->_node->next;
				return tmp;
			}
			_iterator	operator++() {

				this->_node = this->_node->next;
				return *this;
			}
			_iterator	operator--( int ) {

				_iterator	tmp = *this;
				this->_node = this->_node->prev;
				return	tmp;
			}
			_iterator	operator--() {

				this->_node = this->_node->prev;
				return *this;
			}
			listNode<Tp>*	getNode() const { return this->_node; }

		private:

			listNode<Tp>*	_node;
		};

		template < typename Tp >
		class _const_iterator {

		public:

			_const_iterator() : _node( 0 ) {}
			_const_iterator( const listNode<Tp>* p ) : _node( p ) {}
			_const_iterator( const _iterator<Tp>& x ) : _node( x.getNode() ) {}
			_const_iterator( const _const_iterator& src ) { *this = src; }
			_const_iterator&	operator=( const _const_iterator& rhs ) {

				if ( this != &rhs )
					this->_node = rhs._node;
				return *this;
			}
			virtual ~_const_iterator() {}

			const Tp&		operator*() const { return this->_node->data; }
			const Tp*		operator->() const { return &( this->_node->data ); }
			bool			operator!=( const _const_iterator& rhs ) { return this->_node != rhs._node; }
			bool 			operator==( const _const_iterator& rhs ) { return this->_node == rhs._node; }
			_const_iterator	operator++( int ) {

				_const_iterator	tmp = *this;
				this->_node = this->_node->next;
				return tmp;
			}
			_const_iterator	operator++() {

				this->_node = this->_node->next;
				return *this;
			}
			_const_iterator	operator--( int ) {

				_const_iterator	tmp = *this;
				this->_node = this->_node->prev;
				return tmp;
			}
			_const_iterator	operator--() {

				this->_node = this->_node->prev;
				return *this;
			}

		private:

			const listNode<Tp>*	_node;
		};


		template < typename Iterator >
		class _reverse_iterator {

		private:

			template < class Iterator2 >
			class _iterator_traits {

			public:

				typedef	typename	Iterator2::difference_type		difference_type;
				typedef typename	Iterator2::value_type			value_type;
				typedef typename	Iterator2::pointer				pointer;
				typedef typename	Iterator2::reference			reference;
				typedef typename	Iterator2::iterator_category	iterator_category;
			};

			struct _random_access_iterator_tag {};

			template < class U >
			class _iterator_traits<U*> {

			public:

				typedef				ptrdiff_t					difference_type;
				typedef				U							value_type;
				typedef				U*							pointer;
				typedef				U&							reference;
				typedef				_random_access_iterator_tag	iterator_category;
			};

			template < class U >
			class _iterator_traits< const U* > {

			public:

				typedef				ptrdiff_t					difference_type;
				typedef				U							value_type;
				typedef				const U*					pointer;
				typedef				const U&					reference;
				typedef				_random_access_iterator_tag	iterator_category;
			};

		protected:

			Iterator			_current;

		public:

			typedef				Iterator										iterator_type;
			typedef typename	_iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename	_iterator_traits<Iterator>::value_type			value_type;
			typedef typename	_iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename	_iterator_traits<Iterator>::pointer				pointer;
			typedef typename	_iterator_traits<Iterator>::reference			reference;

			_reverse_iterator() {}
			explicit _reverse_iterator( iterator_type it ) : _current( it ) {}
			_reverse_iterator( const _reverse_iterator& src ) : _current( src.current ) {}
			template < class Iter >
			_reverse_iterator( const _reverse_iterator< Iter >& rev_it ) : _current( rev_it.base() ) {}

			iterator_type		base() const { return _current; }

			reference			operator*() const {
				_reverse_iterator	tmp = this->_current;
				return tmp;
			}
			_reverse_iterator	operator+( difference_type n ) const { return reverse_iterator( this->_current - n ); }
			_reverse_iterator&	operator++() {
				this->_current--;
				return *this;
			}
			_reverse_iterator	operator++( int ) {

				_reverse_iterator	tmp = *this;
				this->_current--;
				return tmp;
			}
			_reverse_iterator&	operator+=( difference_type n ) {

				this->_current -= n;
				return *this;
			}
			_reverse_iterator	operator-( difference_type n ) const { return reverse_iterator( this->_current + n ); }
			_reverse_iterator&	operator--() {

				this->_current++;
				return *this;
			}
			_reverse_iterator	operator--( int ) {

				_reverse_iterator	tmp = *this;
				this->_current++;
				return *this;
			}
			_reverse_iterator&	operator-=( difference_type n ) {

				this->_current += n;
				return *this;
			}
			pointer				operator->() const {
				_reverse_iterator	tmp = this->_current;
				return &tmp;
			}
			reference			operator[]( difference_type n ) const { return this + n; }

		};

		listNode<T>*	_front;
		listNode<T>*	_back;

		int 			_size;

	public:


		typedef				T									value_type;
		typedef				Alloc								allocator_type;
		typedef typename	allocator_type::reference			reference;
		typedef typename 	allocator_type::const_reference 	const_reference;
		typedef typename	allocator_type::pointer				pointer;
		typedef typename	allocator_type::const_pointer		const_pointer;
		typedef				_iterator< T >						iterator;
		typedef				_const_iterator< T >				const_iterator;
		typedef				_reverse_iterator< iterator >		reverse_iterator;
		typedef				_reverse_iterator< const_iterator >	const_reverse_iterator;
		typedef				ptrdiff_t 							difference_type;
		typedef				size_t 								size_type;


		// Constructors
		explicit	list( const allocator_type& alloc = allocator_type() ) : _front( 0 ), _back( 0 ), _size( 0 ) {

			allocator_type() = alloc;
		}
		explicit	list( size_type n, const value_type& val = value_type() );

		template < class InputIterator >
		list ( InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type() );

		list( const list& x );


		// Destructor
		virtual ~list() {

			listNode<T>	*current( this->_front );

			while ( current ) {

				listNode<T>	*next( current->next );

				delete current;
				current = next;
			}
		}


		// Operator=
		list&	operator=(const list& x);


		// Iterators
		iterator				begin() { return iterator( this->_front ); }
		const_iterator			begin() const { return iterator( this->_front ); }

		iterator 				end() { return iterator( 0 ); }
		const_iterator			end() const { return iterator( 0 ); }

		reverse_iterator		rbegin() { return reverse_iterator( this->_front ); }
		const_reverse_iterator	rbegin() const { return reverse_iterator( this->_front ); }

		reverse_iterator 		rend() { return reverse_iterator( 0 ); }
		const_reverse_iterator	rend() const { return reverse_iterator( 0 ); }


		// Capacity
		bool 					empty() const;
		size_type				size() const;
		size_type				max_size() const;


		// Element access
		reference 				front() { return this->_front->data; }
		const_reference 		front() const { return this->_front->data; }

		reference 				back() { return this->_back->data; }
		const_reference 		back() const { return this->_back->data; }

		// Modifiers
		template < class InputIterator >
		void	 				assign( InputIterator first, InputIterator last );
		void 					assign( size_type n, const value_type& val );

		void					push_front( const value_type& val ) {

			listNode<T>*	n = new ( std::nothrow ) listNode<T>( val );

			if ( !n )
				throw std::bad_alloc();

			n->next = this->_front;

			n->prev = 0;

			if ( this->_front )
				this->_front->prev = n;
			else
				this->_back = n;

			this->_front = n;

			this->_size++;
		}

		void 					pop_front() {

			if ( this->_front ) {

				listNode<T>*	tmp = this->_front->next;
				if ( this->_front->next )
					this->_front->next->prev = 0;
				else
					this->_back = 0;
				delete this->_front;
				this->_front = tmp;
				this->_size--;
			}
		}

		void 					push_back( const value_type& val ) {

			listNode<T>*	n = new ( std::nothrow ) listNode<T>( val );

			if ( !n )
				throw std::bad_alloc();

			n->next = 0;

			n->prev = this->_back;

			if ( this->_back )
				this->_back->next = n;
			else
				this->_front = n;

			this->_back = n;

			this->_size++;
		}

		void 					pop_back() {

			if ( this->_back ) {

				listNode<T>*	tmp = this->_back->prev;
				if ( this->_back->prev )
					this->_back->prev->next = 0;
				else
					this->_front = 0;
				delete this->_back;
				this->_back = tmp;
				this->_size--;
			}
		}

		iterator 				insert( iterator position, const value_type& val );
		void 					insert( iterator position, size_type n, const value_type& val );
		template < class InputIterator >
		void	 				insert( iterator position, InputIterator first, InputIterator last );

		iterator 				erase( iterator position );
		iterator 				erase( iterator first, iterator last );

		void 					swap( list& x );

		void 					resize( size_type n, value_type val = value_type() );

		void 					clear();


		// Operations
		void 					splice( iterator position, list& x );
		void 					splice( iterator position, list& x, iterator i );
		void 					splice( iterator position, list& x, iterator first, iterator last );

		void 					remove( const value_type& val );

		template < class Predicate >
		void 					remove_if( Predicate pred );

		void 					unique();
		template < class BinaryPredicate >
		  void 					unique( BinaryPredicate binary_pred );

		void 					merge( list& x );
		template < class Compare >
		void 					merge( list& x, Compare comp );

		void 					sort();
		template < class Compare >
		void 					sort( Compare comp );

		void 					reverse();
	};

	template < class T, class Alloc >
	bool	operator==( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs );
	template < class T, class Alloc >
	bool	operator!=( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs );
	template < class T, class Alloc >
	bool	operator< ( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs );
	template < class T, class Alloc >
	bool	operator<=( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs );
	template < class T, class Alloc >
	bool	operator> ( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs );
	template < class T, class Alloc >
	bool	operator>=( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs );

	template <class T, class Alloc>
	void	swap( list<T,Alloc>& x, list<T,Alloc>& y );
}

// List
// https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a00588.html
// Iterator
// https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a00345.html
// Const iterator
// https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a00344.html
// Reverse iterator
// https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a00693.html
// Implementation
// https://codefreakr.com/how-is-c-stl-list-implemented-internally/
