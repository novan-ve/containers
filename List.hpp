/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 13:13:55 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/11/20 14:32:39 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstddef>		// Linux ptrdiff_t dependency

namespace ft {

	template < typename T >
	struct listNode {

		listNode( const T &e ) : data( e ), next(0), prev(0) {}

		T			data;
		listNode<T>	*next;
		listNode<T>	*prev;
	};

	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};
	template< class >
	struct check_type { typedef void type; };

	template < class Iterator >
	class ft_iterator_traits {

	public:

		typedef	typename	Iterator::difference_type	difference_type;
		typedef typename	Iterator::value_type		value_type;
		typedef typename	Iterator::pointer			pointer;
		typedef typename	Iterator::reference			reference;
		typedef typename	Iterator::iterator_category	iterator_category;
	};

	template < class U >
	class ft_iterator_traits<U*> {

	public:

		typedef				ptrdiff_t					difference_type;
		typedef				U							value_type;
		typedef				U*							pointer;
		typedef				U&							reference;
		typedef				random_access_iterator_tag	iterator_category;
	};

	template < class U >
	class ft_iterator_traits< const U* > {

	public:

		typedef				ptrdiff_t					difference_type;
		typedef				U							value_type;
		typedef				const U*					pointer;
		typedef				const U&					reference;
		typedef				random_access_iterator_tag	iterator_category;
	};

	template < typename U >
	class ft_list_iterator {

	public:

		typedef		U							value_type;
		typedef		ptrdiff_t					difference_type;
		typedef		U*							pointer;
		typedef		U&							reference;
		typedef		bidirectional_iterator_tag	iterator_category;

		int			foo;


		ft_list_iterator() : _node( 0 ) {}
		ft_list_iterator( listNode<U>* p ) : _node( p ) {}
		ft_list_iterator( const ft_list_iterator& src ) {
			*this = src;
		}
		ft_list_iterator&	operator=( const ft_list_iterator& rhs ) {

			if ( this != &rhs )
				this->_node = rhs._node;

			return *this;
		}
		virtual ~ft_list_iterator() {}

		reference			operator*() { return this->_node->data; }
		pointer				operator->() { return &( this->_node->data ); }
		bool				operator!=( const ft_list_iterator& rhs ) const { return this->_node != rhs._node; }
		bool 				operator==( const ft_list_iterator& rhs ) const { return this->_node == rhs._node; }
		ft_list_iterator	operator++( int ) {

			if ( !this->_node )
				return *this;

			ft_list_iterator<U>	tmp( *this );
			this->_node = this->_node->next;
			return tmp;
		}
		ft_list_iterator	operator++() {

			if ( !this->_node )
				return *this;
			this->_node = this->_node->next;
			return *this;
		}
		ft_list_iterator	operator--( int ) {

			if ( !this->_node )
				return *this;
			ft_list_iterator<U> tmp( *this );
			this->_node = this->_node->prev;
			return tmp;
		}
		ft_list_iterator	operator--() {

			this->_node = this->_node->prev;
			return *this;
		}
		listNode<U>*		getNode() const { return this->_node; }

	private:

		listNode<U>*	_node;
	};

	template < typename U >
	class ft_list_const_iterator {

	public:

		int 		foo;

		typedef		U							value_type;
		typedef		ptrdiff_t					difference_type;
		typedef		const U*					pointer;
		typedef		const U&					reference;
		typedef		bidirectional_iterator_tag	iterator_category;

		ft_list_const_iterator() : _node( 0 ) {}
		ft_list_const_iterator( const listNode<U>* p ) : _node( p ) {}
		ft_list_const_iterator( const ft_list_iterator<U>& x ) : _node( x.getNode() ) {}
		ft_list_const_iterator( const ft_list_const_iterator& src ) {
			*this = src;
		}
		ft_list_const_iterator&	operator=( const ft_list_const_iterator& rhs ) {

			if ( this != &rhs )
				this->_node = rhs._node;

			return *this;
		}
		virtual	~ft_list_const_iterator() {}

		reference				operator*() const { return this->_node->data; }
		pointer					operator->() const { return &( this->_node->data ); }
		bool					operator!=( const ft_list_const_iterator& rhs ) const { return this->_node != rhs._node; }
		bool 					operator==( const ft_list_const_iterator& rhs ) const { return this->_node == rhs._node; }
		ft_list_const_iterator	operator++( int ) {

			if ( !this->_node )
				return *this;

			ft_list_const_iterator<U>	tmp( *this );
			this->_node = this->_node->next;
			return tmp;
		}
		ft_list_const_iterator	operator++() {

			if ( !this->_node )
				return *this;
			this->_node = this->_node->next;
			return *this;
		}
		ft_list_const_iterator	operator--( int ) {

			if ( !this->_node )
				return *this;
			ft_list_const_iterator<U> tmp( *this );
			this->_node = this->_node->prev;
			return tmp;
		}
		ft_list_const_iterator	operator--() {

			this->_node = this->_node->prev;
			return *this;
		}

	private:

		const listNode<U>*	_node;
	};

	template < typename Iterator >
	class reverse_iterator {

	public:

		typedef					Iterator											iterator_type;
		typedef typename		ft_iterator_traits<Iterator>::iterator_category		iterator_category;
		typedef typename		ft_iterator_traits<Iterator>::value_type			value_type;
		typedef typename		ft_iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename		ft_iterator_traits<Iterator>::pointer				pointer;
		typedef typename		ft_iterator_traits<Iterator>::reference				reference;

		reverse_iterator() : current() {}
		explicit reverse_iterator( iterator_type it ) : current( it ) {}
		template < class Iter >
			reverse_iterator( const reverse_iterator<Iter>& rev_it ) : current( rev_it.current ) {}

		iterator_type			base() const { return this->current; }

		reference				operator*() const {

			Iterator tmp = this->current;
			return *--tmp;
		}
		reverse_iterator		operator+( difference_type n ) const {

			return reverse_iterator( this->current - n );
		}
		reverse_iterator&	operator++() {

			this->current--;
			return *this;
		}
		reverse_iterator		operator++( int ) {

			reverse_iterator	temp = *this;
			this->current--;
			return temp;
		}
		reverse_iterator&	operator+=( difference_type n ) {

			this->_current -= n;
			return *this;
		}
		reverse_iterator		operator-( difference_type n ) const {

			return reverse_iterator( this->current + n );
		}
		reverse_iterator		operator--() {

			this->current++;
			return *this;
		}
		reverse_iterator		operator--( int ) {

			reverse_iterator	temp = *this;
			this->current++;
			return temp;
		}
		reverse_iterator&	operator-=( difference_type n ) {

			this->current += n;
			return *this;
		}
		pointer					operator->() const {

			return &(operator*());
		}
		reference				operator[]( difference_type n ) const {

			Iterator	temp = this->current;

			for ( int i = n; i > 0; i-- )
				temp--;
			return *--temp;
		}

	protected:

		Iterator			current;
	};

	// Reverse iterator relational operations
	template < class Iterator >
		bool operator==( const reverse_iterator<Iterator>& lhs,
						 const reverse_iterator<Iterator>& rhs ) {

			return lhs.base() == rhs.base();
		}

	template < class Iterator >
	bool operator!=( const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs ) {

		return lhs.base() != rhs.base();
	}

	template < class Iterator >
	bool operator<( const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs ) {

		return lhs.base() > rhs.base();
	}

	template < class Iterator >
	bool operator<=( const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs ) {

		return lhs.base() >= rhs.base();
	}

	template < class Iterator >
	bool operator>( const reverse_iterator<Iterator>& lhs,
				 	const reverse_iterator<Iterator>& rhs ) {

		return lhs.base() < rhs.base();
	}

	template < class Iterator >
	bool operator>=( const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs ) {

		return lhs.base() <= rhs.base();
	}

	template < class Iterator >
		reverse_iterator<Iterator>	operator+(
				typename reverse_iterator<Iterator>::difference_type n,
				const reverse_iterator<Iterator>& rev_it ) {

			return reverse_iterator<Iterator>( rev_it.base() - n );
		}

	template < class Iterator >
		typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs) {

			return rhs.base() - lhs.base();
		}

	template < class T, class Alloc = std::allocator<T> >
	class list {

		listNode<T>*	_front;
		listNode<T>*	_back;
		listNode<T>*	_pte;

		int 			_size;
		

	public:


		typedef				T										value_type;
		typedef				Alloc									allocator_type;
		typedef typename	allocator_type::reference				reference;
		typedef typename 	allocator_type::const_reference 		const_reference;
		typedef typename	allocator_type::pointer					pointer;
		typedef typename	allocator_type::const_pointer			const_pointer;
		typedef				ft_list_iterator< T >					iterator;
		typedef				ft_list_const_iterator< T >				const_iterator;
		typedef				ft::reverse_iterator< iterator >		reverse_iterator;
		typedef				ft::reverse_iterator< const_iterator >	const_reverse_iterator;
		typedef				ptrdiff_t 								difference_type;
		typedef				size_t 									size_type;


		// Constructors
		explicit	list( const allocator_type& alloc = allocator_type() ) : _front( NULL ), _back( NULL ), _pte( 0 ), _size( 0 ) {

			allocator_type() = alloc;

			this->_pte = new listNode<T>( 0 );
			this->_pte->next = this->_front;
			this->_pte->prev = this->_back;
		}
		explicit	list( size_type n, const value_type& val = value_type() );

		template < class InputIterator >
		list ( InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type() );

		list( const list& x );


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
		list&	operator=(const list& x);


		// Iterators
		iterator				begin() { return iterator( this->_front ); }
		const_iterator			begin() const { return iterator( this->_front ); }

		iterator 				end() { return iterator( this->_pte ); }
		const_iterator			end() const { return iterator( this->_pte ); }

		reverse_iterator		rbegin() { return reverse_iterator( this->_pte ); }
		const_reverse_iterator	rbegin() const { return reverse_iterator( this->_pte ); }

		reverse_iterator 		rend() { return reverse_iterator( this->_front ); }
		const_reverse_iterator	rend() const { return reverse_iterator( this->_front ); }


		// Capacity
		bool 					empty() const { return !this->_size; }
		size_type				size() const { return this->_size; }
		size_type				max_size() const {

			int		size = sizeof( value_type ) <= 8 ? 24 : 40;

			return size_type( -1 ) / size;
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
		void	 				assign( InputIterator first, InputIterator last, typename InputIterator::value_type = 0) {

			this->clear();
			for ( ; first != last; ++first )
				this->push_back( *first );

		}
		void 					assign( size_type n, const value_type& val ) {

			std::cout << "Normal assign" << std::endl;
			this->clear();

			for ( size_type i = 0; i < n; i++ )
				this->push_back( val );
		}

		void					push_front( const value_type& val ) {

			listNode<T>*	n = new ( std::nothrow ) listNode<T>( val );

			if ( !n )
				throw std::bad_alloc();

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

			listNode<T>*	n = new ( std::nothrow ) listNode<T>( val );

			if ( !n )
				throw std::bad_alloc();

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

		iterator 				insert( iterator position, const value_type& val );
		void 					insert( iterator position, size_type n, const value_type& val );
		template < class InputIterator >
		void	 				insert( iterator position, InputIterator first, InputIterator last );

		iterator 				erase( iterator position );
		iterator 				erase( iterator first, iterator last );

		void 					swap( list& x );

		void 					resize( size_type n, value_type val = value_type() );

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

			this->_pte->data = this->_size;
			this->_pte->next = this->_front;
			this->_pte->prev = this->_back;
		}


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
