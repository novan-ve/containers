/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 17:20:49 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/12/04 17:20:52 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterators/iterators.hpp"
#include "mapNode.hpp"

namespace ft {

	template< class T >
	struct less : std::binary_function<T, T, bool> {
		bool	operator() ( const T& x, const T& y ) const { return x < y; }
	};

	template < class Key,
			   class T,
			   class Compare = ft::less<Key>,
			   class Alloc = std::allocator<std::pair<const Key, T> > >
	class map {

	private:

		mapNode<Key, T>*	_pte;
		mapNode<Key, T>*	_root;
		mapNode<Key, T>*	_front;

		size_t				_size;

	public:

		typedef				Key													key_type;
		typedef 			T													mapped_type;
		typedef				ft::pair<const key_type, mapped_type>				value_type;
		typedef				ft::less<key_type>									key_compare;
		typedef				Alloc												allocator_type;
		typedef typename	allocator_type::reference							reference;
		typedef typename	allocator_type::const_reference						const_reference;
		typedef typename	allocator_type::pointer								pointer;
		typedef typename	allocator_type::const_pointer						const_pointer;
		typedef				ft::ft_map_iterator< Key, T >						iterator;
		typedef				ft::ft_const_map_iterator< Key, T >					const_iterator;
		typedef				ft::reverse_iterator< iterator >					reverse_iterator;
		typedef				ft::reverse_iterator< const_iterator >				const_reverse_iterator;
		typedef	typename	ft::ft_iterator_traits< iterator >::difference_type	difference_type;
		typedef				size_t												size_type;

		class value_compare : std::binary_function<value_type, value_type, bool> {

			friend class map;

		protected:

			Compare comp;

			value_compare (Compare c) : comp(c) {}

		public:

			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;

			bool operator() (const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
		};

		// constructors

		explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) : _pte( 0 ), _root( 0 ), _front( 0 ), _size( 0 ) {

			allocator_type() = alloc;
			key_compare() = comp;

			this->_pte = new mapNode<Key, T>( value_type() );
			this->_pte->left = 0;
			this->_pte->right = 0;
			this->_pte->up = 0;
		}

		template< class InputIterator >
			map( InputIterator first, InputIterator last,
				 const key_compare& comp = key_compare(),
				 const allocator_type& alloc = allocator_type() );

		map( const map& x );

		// destructor

		~map() {

			delete this->_pte;
		}

		// operator =

		map&					operator=( const map& x );

		// iterators

		iterator				begin() { return iterator( this->_front ); }
		const_iterator			begin() const { return const_iterator( this->_front ); }

		iterator				end() { return iterator( this->_pte ); }
		const_iterator			end() const { return const_iterator( this->_pte ); }

		reverse_iterator		rbegin() { return reverse_iterator( this->_pte ); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator( this->_pte ); }

		reverse_iterator		rend() { return reverse_iterator( this->_front ); }
		const_reverse_iterator	rend() const { return const_reverse_iterator( this->_front ); }

		// capacity

		bool					empty() const { return !this->_size; }

		size_type				size() const { return this->_size; }

		size_type				max_size() const {

			int		size = sizeof( value_type ) <= 8 ? 24 : 40;

			return size_type( -1 ) / size;
		}

		// element access

		mapped_type&			operator[]( const key_type& k ) {
			return ( *( (this->insert( make_pair( k, mapped_type() ) ) ).first ) ).second;
		}

		// modifiers

		pair<iterator, bool>	insert( const value_type& val ) {

			if ( this->_root == NULL ) {

				this->_root = new mapNode<Key, T>( val );
				this->_root->left = 0;
				this->_root->right = this->_pte;
				this->_root->up = 0;

				this->_pte->up = this->_root;
				this->_front = this->_root;

				this->_size++;

				return make_pair( iterator( this->_root ), true );
			}

			mapNode<Key, T>*	tmp( this->_root );
			mapNode<Key, T>*	prev( 0 );
			while ( true ) {

				if ( tmp == NULL ) {

					tmp = new mapNode<Key, T>( val );
					tmp->left = 0;
					tmp->right = this->_pte;
					tmp->up = prev;

					this->_pte->up = tmp;

					this->_size++;

					if ( this->_front->data.first > tmp->data.first )
						this->_front = tmp;

					if ( prev->data.first < tmp->data.first )
						prev->right = tmp;
					else
						prev->left = tmp;

					return make_pair( iterator( tmp ), true );
				}
				if ( tmp == this->_pte ) {

					mapNode<Key, T>*	up;
					up = tmp->up;

					tmp = new mapNode<Key, T>( val );
					tmp->left = 0;
					tmp->right = this->_pte;
					tmp->up = prev;

					up->right = tmp;

					if ( this->_front->data.first > tmp->data.first )
						this->_front = tmp;

					if ( prev->data.first < tmp->data.first )
						prev->right = tmp;
					else
						prev->left = tmp;

					this->_size++;
					return make_pair( iterator( tmp ), true );
				}
				if ( tmp->data.first == val.first )
					return make_pair( iterator( tmp ), false );
				else if ( val.first < tmp->data.first ) {
					prev = tmp;
					tmp = tmp->left;
				}
				else {
					prev = tmp;
					tmp = tmp->right;
				}
			}
		}

		iterator				insert( iterator position, const value_type& val );

		template< class InputIterator >
			void				insert( InputIterator first, InputIterator last );

		void					erase( iterator position );

		size_type				erase( const key_type& k );

		void					erase( iterator first, iterator last );

		void					swap( map& x );

		void					clear();

		// observers

		key_compare				key_comp() const;

		value_compare			value_comp() const;

		// operations

		iterator				find( const key_type& k );
		const_iterator			find( const key_type& k ) const;

		size_type				count( const key_type& k ) const {

			if ( this->_root == NULL ) {
				return false;
			}
			else if ( this->_root->data->first == k ) {
				return true;
			}
			else if ( k <= this->_root->data->first ) {
				return search( this->_root->left, k );
			}
			else {
				return search( this->_root->right, k );
			}
		}

		iterator				lower_bound( const key_type& k );
		const_iterator			lower_bound( const key_type& k ) const;

		iterator				upper_bound( const key_type& k );
		const_iterator			upper_bound( const key_type& k ) const;

		pair<iterator, iterator>				equal_range( const key_type& k );
		pair<const_iterator, const_iterator>	equal_range( const key_type& k ) const;

		void test() {

			std::cout << "Size: " << this->_size << std::endl;
			std::cout << "Root first: " << this->_root->data.first << std::endl;
			std::cout << "Root second: " << this->_root->data.second << std::endl;
		}
	};
}
