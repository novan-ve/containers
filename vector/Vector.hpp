/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 17:20:40 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/12/03 17:45:39 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterators/iterators.hpp"
#include <exception>

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

	private:

		T*		_array;
		size_t	_size;
		size_t	_reserved;

		template < typename U >
		struct	_check_type {};

		template <>
		struct	_check_type< ft_random_access_iterator< T > > {
			typedef int check;
		};

		template <>
		struct	_check_type< ft_const_random_access_iterator< T > > {
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
		typedef				ft::ft_random_access_iterator< T >			iterator;
		typedef				ft::ft_const_random_access_iterator< T >	const_iterator;
		typedef				ft::reverse_iterator< iterator >			reverse_iterator;
		typedef				ft::reverse_iterator< const_iterator >		const_reverse_iterator;
		typedef				ptrdiff_t 									difference_type;
		typedef				size_t 										size_type;


		// Constructors
		explicit vector( const allocator_type& alloc = allocator_type() ) : _array( new T[1] ), _size( 0 ), _reserved( 0 ) {

			allocator_type() = alloc;
			this->_array[0] = value_type();
		}

		explicit vector( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() ) :
		_array( new T[1] ), _size( 0 ), _reserved( 0 ) {

			allocator_type() = alloc;
			this->_array[0] = value_type();

			this->reserve( n );

			for ( size_type i = 0; i < n; ++i )
				this->push_back( val );
		}

		template < class InputIterator >
				vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
						typename _check_type<InputIterator>::check = 0 ) : _array( new T[1] ), _size( 0 ), _reserved( 0 ) {

			allocator_type() = alloc;
			this->_array[0] = value_type();

			while ( first != last ) {

				this->push_back( *first );
				first++;
			}
		}

		vector( const vector& x ) : _array( new T[1] ), _size( 0 ), _reserved( 0 ) {

			this->_array[0] = value_type();

			for ( const_iterator it = x.begin(); it != x.end(); ++it )
				this->push_back( *it );
		}

		~vector() {

			delete [] this->_array;
		}

		vector&	operator=( const vector& x ) {

			if ( this != &x ) {

				this->clear();

				for ( const_iterator it = x.begin(); it != x.end(); ++it )
					this->push_back( *it );
			}

			return *this;
		}

		// Iterators

		iterator				begin() { return iterator( this->_array ); }
		const_iterator			begin() const { return const_iterator( this->_array ); }

		iterator 				end() { return iterator( &this->_array[this->_size] ); }
		const_iterator			end() const { return const_iterator( &this->_array[this->_size] ); }

		reverse_iterator		rbegin() { return reverse_iterator( &this->_array[this->_size] ); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator( &this->_array[this->_size] ); }

		reverse_iterator 		rend() { return reverse_iterator( this->_array ); }
		const_reverse_iterator	rend() const { return const_reverse_iterator( this->_array ); }

		// Capacity
		size_type				size() const { return this->_size; }
		size_type				max_size() const {

			return size_type( -1 ) / sizeof( value_type );
		}

		void	resize( size_type n, value_type val = value_type() ) {

			T*	array = new T[ n + 1 ];

			for ( size_type i = 0; i < n; i++ ) {

				if ( i < this->_size )
					array[i] = this->_array[i];
				else
					array[i] = val;
			}
			delete [] this->_array;

			this->_array = array;
			this->_reserved = n;

			this->_size = n;
			this->_array[this->_size] = this->_size;
		}

		size_type	capacity() const { return this->_reserved; }

		bool 		empty() const { return !this->_size; }

		void		reserve( size_type n ) {

			if ( n > this->_reserved ) {

				size_t	tmp = this->_size;
				this->resize( n );
				this->_array[this->_size] = value_type();
				this->_size = tmp;
				this->_array[this->_size] = this->_size;
			}
		}

		// Element access

		reference		operator[]( size_type n ) { return this->_array[n]; }

		reference		at( size_type n ) {

			if ( n >= 0 && n < this->_size )
				return this->_array[n];
			else
				throw std::out_of_range("out_of_range");
		}

		const_reference	at( size_type n ) const {

			if ( n >= 0 && n < this->_size )
				return this->_array[n];
			else
				throw std::out_of_range("out_of_range");
		}

		reference		front() { return this->_array[0]; };
		const_reference	front() const { return this->_array[0]; }

		reference		back() { return this->_array[this->_size - 1]; }
		const_reference	back() const { return this->_array[this->_size - 1]; }

		// Modifiers

		template < class InputIterator >
		void	 	assign( InputIterator first, InputIterator last, typename _check_type<InputIterator>::check = 0 ) {

			this->clear();

			for ( ; first != last; ++first )
				this->push_back( *first );

		}
		void 		assign( size_type n, const value_type& val ) {

			this->clear();

			for ( size_type i = 0; i < n; i++ )
				this->push_back( val );
		}

		void	push_back( const value_type& val ) {

			if ( this->_reserved == 0 ) {

				resize( 1 );
				this->_size = 0;
			}

			if ( this->_size == this->_reserved ) {

				size_t	tmp = this->_size;
				resize( this->_size * 2 );
				this->_array[this->_size] = value_type();
				this->_size = tmp;
				this->_array[this->_size] = this->_size;
			}

			this->_array[this->_size + 1] = this->_array[this->_size];
			this->_array[this->_size] = val;

			this->_size++;

			this->_array[this->_size]++;
		}

		void	pop_back() {

			this->resize( this->_size - 1 );
		}

		iterator 	insert( iterator position, const value_type& val ) {

			size_t	pos = 0;

			for ( iterator it = this->begin(); it != this->end(); ++it ) {

				if ( it == position )
					break;
				pos++;
			}

			T		*tmp;
			tmp = new T[this->_size];

			for ( size_t i = 0; i < this->_size; i++ )
				tmp[i] = this->_array[i];

			this->push_back( value_type() );

			size_t i = 0;
			size_t j = 0;

			while ( i < this->_size ) {

				if ( i == pos ) {

					this->_array[i] = val;
					i++;
				}
				this->_array[i] = tmp[j];

				i++;
				j++;
			}
			delete [] tmp;

			return iterator( &this->_array[pos] );
		}

		void 		insert( iterator position, size_type n, const value_type& val ) {

			for ( size_type i = 0; i < n; i++ )
				position = insert( position, val );
		}

		template < class InputIterator >
		void	 	insert( iterator position, InputIterator first, InputIterator last, typename _check_type<InputIterator>::check = 0 ) {

			last--;
			first--;
			while ( last != first ) {
				position = insert( position, *last );
				last--;
			}
		}

		iterator	erase( iterator position ) {

			size_t	pos = 0;

			for ( iterator it = this->begin(); it != this->end(); ++it ) {

				if ( it == position )
					break;
				pos++;
			}

			T		*tmp;
			tmp = new T[this->_size];

			for ( size_t i = 0; i < this->_size; i++ )
				tmp[i] = this->_array[i];

			this->pop_back();

			size_t i = 0;
			size_t j = 0;

			while ( j < this->_size + 1 ) {

				if ( i == pos )
					j++;
				this->_array[i] = tmp[j];

				i++;
				j++;
			}
			delete [] tmp;

			return iterator( &this->_array[pos] );
		}

		iterator 				erase( iterator first, iterator last ) {

			size_t len = 0;

			for ( iterator it = first; it != last; it++ )
				len++;

			if ( last != first )
				last--;

			while ( len > 0 ) {

				last = erase(last);
				len--;
				if ( len > 0 )
					last--;
			}

			return last;
		}

		void	swap( vector& x ) {

			T*		a = this->_array;
			size_t	s = this->_size;
			size_t	r = this->_reserved;

			this->_array = x._array;
			this->_size = x._size;
			this->_reserved = x._reserved;

			x._array = a;
			x._size = s;
			x._reserved = r;
		}

		void	clear() {

			delete [] this->_array;

			this->_size = 0;
			this->_reserved = 0;

			this->_array = new T[1];
			this->_array[0] = value_type();
		}
	};

	template < class T, class Alloc >
	bool	operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {

		if ( lhs.size() == rhs.size() ) {

			ft::ft_const_random_access_iterator<T>	it2 = rhs.begin();

			for ( ft::ft_const_random_access_iterator<T> it = lhs.begin(); it != lhs.end(); ++it ) {

				if ( *it != *it2 )
					return false;
				++it2;
			}
			return true;
		}
		return false;
	}

	template < class T, class Alloc >
	bool	operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return !(lhs == rhs); }

	template < class T, class Alloc >
	bool	operator< ( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {

		ft::ft_const_random_access_iterator<T>	first1 = lhs.begin();
		ft::ft_const_random_access_iterator<T>	first2 = rhs.begin();

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
	bool	operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return !( rhs < lhs ); }

	template < class T, class Alloc >
	bool	operator> ( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return rhs < lhs; }

	template < class T, class Alloc >
	bool	operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) { return !( lhs < rhs ); }

	template <class T, class Alloc>
	void	swap( vector<T,Alloc>& x, vector<T,Alloc>& y ) { x.swap( y ); }
}
