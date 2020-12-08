/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 13:13:55 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/12/03 17:40:23 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterators/iterators.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class list {

	private:

		listNode<T>*		_front;
		listNode<T>*		_back;
		listNode<T>*		_pte;

		size_t 				_size;

		Alloc				_alloc;


		template < typename U >
		struct	_check_type {};

		template <>
		struct	_check_type< ft_bidirectional_iterator< T > > {
			typedef int check;
		};

		template <>
		struct	_check_type< ft_const_bidirectional_iterator< T > > {
			typedef int check;
		};

		template< typename U >
		struct	_check_type< U* > {
			typedef int check;
		};

	public:


		typedef				T											value_type;
		typedef				Alloc										allocator_type;
		typedef typename	allocator_type::reference					reference;
		typedef typename 	allocator_type::const_reference 			const_reference;
		typedef typename	allocator_type::pointer						pointer;
		typedef typename	allocator_type::const_pointer				const_pointer;
		typedef				ft::ft_bidirectional_iterator< T >			iterator;
		typedef				ft::ft_const_bidirectional_iterator< T >	const_iterator;
		typedef				ft::reverse_iterator< iterator >			reverse_iterator;
		typedef				ft::reverse_iterator< const_iterator >		const_reverse_iterator;
		typedef				ptrdiff_t 									difference_type;
		typedef				size_t 										size_type;


		// Constructors
		explicit	list( const allocator_type& alloc = allocator_type() ) : _front( NULL ), _back( NULL ), _pte( 0 ), _size( 0 ), _alloc( alloc ) {

			this->_pte = new listNode<T>( value_type() );
			this->_pte->next = this->_front;
			this->_pte->prev = this->_back;
		}

		explicit	list( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() ) :
		_front( NULL ), _back( NULL ), _pte( 0 ), _size( 0 ), _alloc( alloc ) {

			this->_pte = new listNode<T>( value_type() );
			this->_pte->next = this->_front;
			this->_pte->prev = this->_back;

			for ( size_type i = 0; i < n; i++ )
				this->push_back( val );
		}

		template < class InputIterator >
		list ( InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename _check_type<InputIterator>::check = 0 ) : _front( NULL ), _back( NULL ), _pte( 0 ), _size( 0 ), _alloc( alloc ) {

			this->_pte = new listNode<T>( value_type() );
			this->_pte->next = this->_front;
			this->_pte->prev = this->_back;

			while ( first != last ) {

				this->push_back( *first );
				first++;
			}
		}

		list( const list& x ) : _front( NULL ), _back( NULL ), _pte( 0 ), _size( 0 ) {

			this->_pte = new listNode<T>( value_type() );
			this->_pte->next = this->_front;
			this->_pte->prev = this->_back;

			this->_alloc = x._alloc;

			if ( x._front ) {

				for ( const_iterator it = x.begin(); it != x.end(); ++it )
					this->push_back( *it );
			}
		}


		// Destructor
		virtual ~list() {

			if ( this->_front ) {

				listNode<T>	*current( this->_front );

				while ( current != this->_pte ) {

					listNode<T>	*next( current->next );

					delete current;
					current = next;
				}
			}
			delete this->_pte;
		}


		// Operator=
		list&	operator=(const list& x) {

			if ( this != &x ) {

				this->clear();

				this->_alloc = x._alloc;

				if ( x._front ) {

					for ( const_iterator it = x.begin(); it != x.end(); ++it )
						this->push_back( *it );
				}
			}

			return *this;
		}


		// Iterators
		iterator				begin() { return iterator( this->_front ); }
		const_iterator			begin() const { return const_iterator( this->_front ); }

		iterator 				end() { return iterator( this->_pte ); }
		const_iterator			end() const { return const_iterator( this->_pte ); }

		reverse_iterator		rbegin() { return reverse_iterator( this->_pte ); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator( this->_pte ); }

		reverse_iterator 		rend() { return reverse_iterator( this->_front ); }
		const_reverse_iterator	rend() const { return const_reverse_iterator( this->_front ); }


		// Capacity
		bool 					empty() const { return !this->_size; }
		size_type				size() const { return this->_size; }
		size_type				max_size() const {

			return allocator_type().max_size() / 2;
		}


		// Element access
		reference 				front() {

			if ( this->_front )
				return this->_front->data;
			return this->_pte->data;
		}
		const_reference 		front() const {
			if ( this->_front )
				return this->_front->data;
			return this->_pte->data;
		}

		reference 				back() {

			if ( this->_back )
				return this->_back->data;
			return this->_pte->data;
		}
		const_reference 		back() const { return this->_back->data; }


		// Modifiers

		template < class InputIterator >
		void	 				assign( InputIterator first, InputIterator last, typename _check_type<InputIterator>::check = 0 ) {

			this->clear();

			for ( ; first != last; ++first )
				this->push_back( *first );

		}
		void 					assign( size_type n, const value_type& val ) {

			this->clear();

			for ( size_type i = 0; i < n; i++ )
				this->push_back( val );
		}

		void					push_front( const value_type& val ) {

			listNode<T>*	n = new listNode<T>( val );

			n->next = this->_front;

			n->prev = this->_pte;

			if ( this->_front )
				this->_front->prev = n;
			else {

				this->_back = n;
				this->_pte->prev = this->_back;
			}

			this->_front = n;
			this->_pte->next = this->_front;

			this->_size++;
			this->_pte->data = this->_size;
		}

		void 					pop_front() {

			if ( this->_front ) {

				listNode<T>*	tmp = this->_front->next;
				if ( this->_front->next )
					this->_front->next->prev = this->_pte;
				else
					this->_back = this->_pte;
				delete this->_front;
				this->_front = tmp;
				this->_size--;
				this->_pte->data = this->_size;
			}
		}

		void 					push_back( const value_type& val ) {

			listNode<T>*	n = new listNode<T>( val );

			n->next = this->_pte;

			if ( this->_back )
				n->prev = this->_back;
			else
				n->prev = this->_pte;

			if ( this->_back )
				this->_back->next = n;
			else {

				this->_front = n;
				this->_pte->next = this->_front;
			}

			this->_back = n;
			this->_pte->prev = this->_back;

			this->_size++;
			this->_pte->data = this->_size;
		}

		void 					pop_back() {

			if ( this->_back ) {

				listNode<T>*	tmp = this->_back->prev;
				if ( this->_back->prev )
					this->_back->prev->next = this->_pte;
				else
					this->_front = this->_pte;
				delete this->_back;
				this->_back = tmp;
				this->_size--;
				this->_pte->data = this->_size;
			}
		}

		iterator 				insert( iterator position, const value_type& val ) {

			listNode<T>	*n = new listNode<T>( val );

			this->_size++;
			this->_pte->data++;

			if ( position != 0 ) {

				n->next = position.getNode();
				n->prev = position.getNode()->prev;
				position.getNode()->prev->next = n;
				position.getNode()->prev = n;

				if ( n->prev == this->_pte )
					this->_front = n;

				return --position;
			}
			else {

				n->next = this->_pte;
				n->prev = this->_pte;

				this->_front = n;
				this->_back = n;

				this->_pte->next = this->_front;
				this->_pte->prev = this->_back;

				return 0;
			}
		}

		void 					insert( iterator position, size_type n, const value_type& val ) {

			for ( size_type i = 0; i < n; i++ )
				position = insert( position, val );
		}

		template < class InputIterator >
		void	 				insert( iterator position, InputIterator first, InputIterator last, typename _check_type<InputIterator>::check = 0 ) {

			last--;
			first--;
			while ( last != first ) {
				position = insert( position, *last );
				last--;
			}
		}

		iterator 				erase( iterator position ) {

			iterator tmp = position.getNode()->next;

			position.getNode()->next->prev = position.getNode()->prev;
			position.getNode()->prev->next = position.getNode()->next;

			if ( position.getNode()->next == this->_pte )
				this->_back = position.getNode()->prev;

			if ( position.getNode()->prev == this->_pte )
				this->_front = position.getNode()->next;

			delete position.getNode();

			this->_size--;


			return tmp;
		}

		iterator 				erase( iterator first, iterator last ) {

			while ( first != last )
				first = erase( first );

			return last;
		}

		void 					swap( list& x ) {

			listNode<T>	*b = this->_back;
			listNode<T> *f = this->_front;
			listNode<T> *p = this->_pte;
			int 		s  = this->_size;

			this->_back = x._back;
			this->_front = x._front;
			this->_pte = x._pte;
			this->_size = x._size;

			x._back = b;
			x._front = f;
			x._pte = p;
			x._size = s;
		}

		void 					resize( size_type n, value_type val = value_type() ) {

			while ( n < this->_size )
				this->pop_back();
			while( n > this->_size )
				this->push_back( val );
		}

		void 					clear() {

			if ( !this->_front )
				return;

			listNode<T>	*current( this->_front );

			while ( current != this->_pte ) {

				listNode<T>	*next( current->next );

				delete current;
				current = next;
			}
			this->_front = 0;
			this->_back = 0;
			this->_size = 0;

			this->_pte->data = value_type();
			this->_pte->next = this->_front;
			this->_pte->prev = this->_back;
		}


		// Operations
		void 					splice( iterator position, list& x ) {

			for ( iterator it = --x.end(); it != --x.begin(); --it )
				position = this->insert( position, *it );

			x.clear();
		}
		void 					splice( iterator position, list& x, iterator i ) {

			this->insert( position, *i );
			x.erase( i );
		}
		void 					splice( iterator position, list& x, iterator first, iterator last ) {

			iterator 	tmp = first;

			static_cast<void>( x );

			while ( first != last ) {

				this->insert( position, *first );
				first++;
			}

			while ( tmp != last ) {

				first = tmp;
				tmp++;
				this->erase( first );
			}
		}

		void 					remove( const value_type& val ) {

			for ( iterator it = this->begin(); it != this->end(); ++it ) {

				if ( *it == val ) {

					it = this->erase( it );
					it--;
				}
			}
		}

		template < class Predicate >
		void 					remove_if( Predicate pred ) {

			for ( iterator it = this->begin(); it != this->end(); ++it ) {

				if ( pred( *it ) ) {

					it = this->erase( it );
					it--;
				}
			}
		}

		void 					unique() {

			iterator it2;

			for ( iterator it = this->begin(); it != this->end(); ++it ) {

				it2 = it;
				it2++;

				if ( *it == *it2 )
					this->erase( it2 );
			}
		}

		template < class BinaryPredicate >
		void 					unique( BinaryPredicate binary_pred ) {

			iterator it2;

			for ( iterator it = this->begin(); it != this->end(); ++it ) {

				it2 = it;
				it2++;

				if ( binary_pred( *it2, *it ) )
					this->erase( it2 );
			}
		}

		void 					merge( list& x ) {

			if ( &x == this )
				return;

			this->splice( this->end(), x );
			this->sort();
		}

		template < class Compare >
		void 					merge( list& x, Compare comp ) {

			if ( &x == this )
				return;

			this->splice( this->end(), x );
			this->sort( comp );
		}

		void 					sort() {

			ft::list<T>	tmp = *this;
			value_type	smallest;

			this->clear();

			while ( tmp.size() ) {

				smallest = tmp.front();
				for ( iterator it = tmp.begin(); it != tmp.end(); ++it ) {
					if ( *it < smallest )
						smallest = *it;
				}
				this->push_back( smallest );
				for ( iterator it = tmp.begin(); it != tmp.end(); ++it ) {
					if ( *it == smallest ) {

						it = tmp.erase( it );
						continue;
					}
				}
			}
		}

		template < class Compare >
		void 					sort( Compare comp ) {

			ft::list<T>	tmp = *this;
			value_type	smallest;

			this->clear();

			while ( tmp.size() ) {

				smallest = tmp.front();
				for ( iterator it = tmp.begin(); it != tmp.end(); ++it ) {
					if ( comp( *it, smallest ) )
						smallest = *it;
				}
				this->push_back( smallest );
				for ( iterator it = tmp.begin(); it != tmp.end(); ++it ) {
					if ( *it == smallest ) {

						it = tmp.erase( it );
						continue;
					}
				}
			}
		}

		void 					reverse() {

			ft::list<T>	tmp = *this;

			this->clear();

			for ( reverse_iterator it = tmp.rbegin(); it != tmp.rend(); ++it )
				this->push_back( *it );
		}
	};

	template < class T, class Alloc >
	bool	operator==( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs ) {

		if ( lhs.size() == rhs.size() ) {

			ft::ft_const_bidirectional_iterator<T>	it2 = rhs.begin();

			for ( ft::ft_const_bidirectional_iterator<T> it = lhs.begin(); it != lhs.end(); ++it ) {

				if ( *it != *it2 )
					return false;
				++it2;
			}
			return true;
		}
		return false;
	}

	template < class T, class Alloc >
	bool	operator!=( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs ) { return !(lhs == rhs); }

	template < class T, class Alloc >
	bool	operator< ( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs ) {

		ft::ft_const_bidirectional_iterator<T>	first1 = lhs.begin();
		ft::ft_const_bidirectional_iterator<T>	first2 = rhs.begin();

		while ( first1 != lhs.end() ) {

			if ( first2 == rhs.end() || *first2 < *first1 )
				return false;
			else if ( *first1 < *first2 )
				return true;

			++first1;
			++first2;
		}
		return ( first2 != rhs.end() );
	}

	template < class T, class Alloc >
	bool	operator<=( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs ) { return !( rhs < lhs ); }

	template < class T, class Alloc >
	bool	operator> ( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs ) { return rhs < lhs; }

	template < class T, class Alloc >
	bool	operator>=( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs ) { return !( lhs < rhs ); }

	template <class T, class Alloc>
	void	swap( list<T,Alloc>& x, list<T,Alloc>& y ) { x.swap( y ); }
}
