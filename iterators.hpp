/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterators.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 16:28:57 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/11/29 16:28:58 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "listNode.hpp"
#include <iostream>
#include <cstddef>		// Linux ptrdiff_t dependency

namespace ft {

	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};

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
	class ft_bidirectional_iterator {

	public:

		typedef		U							value_type;
		typedef		ptrdiff_t					difference_type;
		typedef		U*							pointer;
		typedef		U&							reference;
		typedef		bidirectional_iterator_tag	iterator_category;


		ft_bidirectional_iterator() : _node( 0 ) {}
		ft_bidirectional_iterator( listNode<U>* p ) : _node( p ) {}
		ft_bidirectional_iterator( const ft_bidirectional_iterator& src ) {
			*this = src;
		}
		ft_bidirectional_iterator&	operator=( const ft_bidirectional_iterator& rhs ) {

			if ( this != &rhs )
				this->_node = rhs._node;

			return *this;
		}
		virtual ~ft_bidirectional_iterator() {}

		reference			operator*() { return this->_node->data; }
		pointer				operator->() { return &( this->_node->data ); }
		bool				operator!=( const ft_bidirectional_iterator& rhs ) const { return this->_node != rhs._node; }
		bool 				operator==( const ft_bidirectional_iterator& rhs ) const { return this->_node == rhs._node; }
		ft_bidirectional_iterator	operator++( int ) {

			if ( !this->_node )
				return *this;

			ft_bidirectional_iterator<U>	tmp( *this );
			this->_node = this->_node->next;
			return tmp;
		}
		ft_bidirectional_iterator	operator++() {

			if ( !this->_node )
				return *this;
			this->_node = this->_node->next;
			return *this;
		}
		ft_bidirectional_iterator	operator--( int ) {

			if ( !this->_node )
				return *this;
			ft_bidirectional_iterator<U> tmp( *this );
			this->_node = this->_node->prev;
			return tmp;
		}
		ft_bidirectional_iterator	operator--() {

			this->_node = this->_node->prev;
			return *this;
		}
		listNode<U>*		getNode() const { return this->_node; }

	private:

		listNode<U>*	_node;
	};

	template < typename U >
	class ft_const_bidirectional_iterator {

	public:

		typedef		U							value_type;
		typedef		ptrdiff_t					difference_type;
		typedef		const U*					pointer;
		typedef		const U&					reference;
		typedef		bidirectional_iterator_tag	iterator_category;

		ft_const_bidirectional_iterator() : _node( 0 ) {}
		ft_const_bidirectional_iterator( const listNode<U>* p ) : _node( p ) {}
		ft_const_bidirectional_iterator( const ft_bidirectional_iterator<U>& x ) : _node( x.getNode() ) {}
		ft_const_bidirectional_iterator( const ft_const_bidirectional_iterator& src ) {
			*this = src;
		}
		ft_const_bidirectional_iterator&	operator=( const ft_const_bidirectional_iterator& rhs ) {

			if ( this != &rhs )
				this->_node = rhs._node;

			return *this;
		}
		virtual	~ft_const_bidirectional_iterator() {}

		reference				operator*() const { return this->_node->data; }
		pointer					operator->() const { return &( this->_node->data ); }
		bool					operator!=( const ft_const_bidirectional_iterator& rhs ) const { return this->_node != rhs._node; }
		bool 					operator==( const ft_const_bidirectional_iterator& rhs ) const { return this->_node == rhs._node; }
		ft_const_bidirectional_iterator	operator++( int ) {

			if ( !this->_node )
				return *this;

			ft_const_bidirectional_iterator<U>	tmp( *this );
			this->_node = this->_node->next;
			return tmp;
		}
		ft_const_bidirectional_iterator	operator++() {

			if ( !this->_node )
				return *this;
			this->_node = this->_node->next;
			return *this;
		}
		ft_const_bidirectional_iterator	operator--( int ) {

			if ( !this->_node )
				return *this;
			ft_const_bidirectional_iterator<U> tmp( *this );
			this->_node = this->_node->prev;
			return tmp;
		}
		ft_const_bidirectional_iterator	operator--() {

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
}
