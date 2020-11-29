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
		explicit vector( const allocator_type& alloc = allocator_type() ) : _array( new T[4] ), _size( 0 ), _reserved( 0 ) {

			allocator_type() = alloc;
		}

		explicit vector( size_type n, const value_type& val = value_type() );

		template < class InputIterator >
				vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type() );

		vector( const vector& x );

		~vector() {

			delete [] this->_array;
		}

		vector&	operator=( const vector& x );
	};
}