/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 17:20:40 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/11/29 17:20:44 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterators.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

	private:

		T*		_array;
		size_t	_size;
		size_t	_reserved;

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
		explicit vector( const allocator_type& alloc = allocator_type() ) : _array( new T[5] ), _size( 0 ), _reserved( 4 ) {

			allocator_type() = alloc;
			this->_array[0] = value_type();
		}

		explicit vector( size_type n, const value_type& val = value_type() );

		template < class InputIterator >
				vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() );

		vector( const vector& x );

		~vector() {

			delete [] this->_array;
		}

		vector&	operator=( const vector& x );

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

			if ( n < this->_size )
				this->_size = n;
			this->_array[this->_size] = this->_size;
		}

		// Modifiers

		void	push_back( const value_type& val ) {

			if ( this->_size == this->_reserved )
				resize( this->_size + 4 );

			this->_array[this->_size + 1] = this->_array[this->_size];
			this->_array[this->_size] = val;

			this->_size++;

			this->_array[this->_size]++;
		}

		void	pop_back() {

			this->resize( this->_size - 1 );
		}

		// Element access

		reference		front() { return this->_array[0]; };
		const_reference	front() const { return this->_array[0]; }

		reference		back() { return this->_array[this->_size - 1]; }
		const_reference	back() const { return this->_array[this->_size - 1]; }
	};
}
