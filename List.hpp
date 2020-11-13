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
		struct _iterator {

		public:

			explicit _iterator( listNode<Tp>* p = 0 ) : _pos( p ) {}

			Tp &		operator*() { return this->_pos->data; }
			Tp *		operator->() { return &( this->_pos->_data ); }
			bool		operator!=( const _iterator& rhs ) { return this->_pos != rhs._pos; }
			bool 		operator==( const _iterator& rhs ) { return this->_pos == rhs._pos; }
			_iterator	operator++( int ) {

				_iterator	tmp = *this;
				this->_pos = this->_pos->next;
				return tmp;
			}
			_iterator	operator++() {

				this->_pos = this->_pos->next;
				return *this;
			}
			_iterator	operator--( int ) {

				_iterator	tmp = *this;
				this->_pos = this->_pos->prev;
				return	tmp;
			}
			_iterator	operator--() {

				this->_pos = this->_pos->prev;
				return *this;
			}

		private:

			listNode<Tp>*	_pos;
		};

		template < typename Tp >
		struct _const_iterator {

			explicit _const_iterator( const listNode<Tp>* p ) : _pos( p ) {}
			_const_iterator( const _iterator<Tp>& x ) : _pos( x.pos ) {}

			const Tp&		operator*() const { return this->_pos->data; }
			const Tp*		operator->() const { return &( this->_pos->data ); }
			bool			operator!=( const _const_iterator& rhs ) { return this->_pos != rhs._pos; }
			bool 			operator==( const _const_iterator& rhs ) { return this->_pos == rhs._pos; }
			_const_iterator	operator++( int ) {

				_const_iterator	tmp = *this;
				this->_pos = this->_pos->next;
				return tmp;
			}
			_const_iterator	operator++() {

				this->_pos = this->_pos->next;
				return *this;
			}
			_const_iterator	operator--( int ) {

				_const_iterator	tmp = *this;
				this->_pos = this->_pos->prev;
				return tmp;
			}
			_const_iterator	operator--() {

				this->_pos = this->_pos->prev;
				return *this;
			}

		private:

			const listNode<Tp>*	_pos;
		};

		template < typename _Iterator>
		class _reverse_iterator {};

		listNode<T>*	_head;
		listNode<T>*	_tail;

		int 			_size;

		void	insertInternal( const T& e, listNode<T>* pos ) {

			listNode<T>	*n = new listNode<T>( e );

			this->_size++;

			n->next = pos;

			if ( pos ) {
				n->prev = pos->prev;
				pos->prev = n;
			}
			else {
				n->prev = this->_tail;
				this->_tail = n;
			}

			if ( n->prev )
				n->prev->next = n;
			else
				this->_head = n;
		}

		void 			removeInternal( listNode<T>* pos ) {

			if ( pos ) {

				if ( pos->prev )
					pos->prev->next = pos->next;
				if ( pos->next )
					pos->next->prev = pos->prev;
				if ( pos == this->_head )
					this->_head = pos->next;
				if ( pos == this->_tail )
					this->_tail = pos->prev;

				delete pos;

				this->_size--;
			}
		}

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
		explicit	list( const allocator_type& alloc = allocator_type() ) : _head( 0 ), _tail( 0 ), _size( 0 ) {

			allocator_type() = alloc;
		}
		explicit	list( size_type n, const value_type& val = value_type() );

		template < class InputIterator >
		list ( InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type() );

		list( const list& x );


		// Destructor
		~list() {

			listNode<T>	*current( this->_head );

			while ( current ) {

				listNode<T>	*next( current->next );

				delete current;
				current = next;
			}
		}


		// Operator=
		list&	operator=(const list& x);


		// Iterators
		iterator				begin() { return iterator( this->_head ); }
		const_iterator			begin() const { return iterator( this->_head ); }

		iterator 				end() { return iterator( 0 ); }
		const_iterator			end() const { return iterator( 0 ); }

		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;

		reverse_iterator 		rend();
		const_reverse_iterator	rend() const;


		// Capacity
		bool 					empty() const;
		size_type				size() const;
		size_type				max_size() const;


		// Element access
		reference 				front() { return this->_head->data; }
		const_reference 		front() const { return this->_head->data; }

		reference 				back() { return this->_tail->data; }
		const_reference 		back() const { return this->_tail->data; }


		// Modifiers
		template < class InputIterator >
		void	 				assign( InputIterator first, InputIterator last );
		void 					assign( size_type n, const value_type& val );

		void					push_front( const value_type& val ) {

			insertInternal( val, this->_head );
		}
		void 					pop_front() {

			removeInternal( this->_head );
		}

		void 					push_back( const value_type& val ) {

			insertInternal( val, 0 );
		}

		void 					pop_back() {

			removeInternal( this->_tail );
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
