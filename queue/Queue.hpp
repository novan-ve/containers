/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Queue.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 14:27:29 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/12/04 14:27:31 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../list/List.hpp"

namespace ft {

	template< class T, class Container = ft::list<T> >
	class queue {

		template <class U, class V>
		friend bool operator==(const queue<U,V>& lhs, const queue<U,V>& rhs);

		template <class U, class V>
		friend bool operator< (const queue<U,V>& lhs, const queue<U,V>& rhs);

	public:

		typedef	T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		explicit			queue( const container_type& ctnr = container_type() ) : c( ctnr ) {}

		bool				empty() const { return c.empty(); }

		size_type			size() const { return c.size(); }

		value_type&			front() { return c.front(); }
		const value_type&	front() const { return c.front(); }

		value_type&			back() { return c.back(); }
		const value_type&	back() const { return c.back(); }

		void				push( const value_type& val ) { c.push_back( val ); }

		void				pop() { c.pop_front(); }

	protected:

		Container c;

	};

	template <class T, class Container>
	bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs) { return lhs.c == rhs.c; }

	template <class T, class Container>
	bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) { return !( lhs == rhs ); }

	template <class T, class Container>
	bool operator< (const queue<T,Container>& lhs, const queue<T,Container>& rhs) { return lhs.c < rhs.c; }

	template <class T, class Container>
	bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) { return !( rhs < lhs ); }

	template <class T, class Container>
	bool operator> (const queue<T,Container>& lhs, const queue<T,Container>& rhs) { return rhs < lhs; }

	template <class T, class Container>
	bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs) { return !( lhs < rhs ); }

}
