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
		mapNode<Key, T>*	_back;

		size_t				_size;

		Compare				_comp;
		Alloc				_alloc;

	public:

		typedef				Key													key_type;
		typedef 			T													mapped_type;
		typedef				ft::pair<const key_type, mapped_type>				value_type;
		typedef				Compare												key_compare;
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

		public:

			Compare comp;

			value_compare (Compare c) : comp(c) {}

			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;

			bool operator() (const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
		};

		// constructors

		explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) :
		_pte( 0 ), _root( 0 ), _front( 0 ), _back( 0 ), _size( 0 ), _comp( comp ), _alloc( alloc ) {

			this->_pte = new mapNode<Key, T>();
			this->_pte->left = this->_pte;
			this->_pte->right = 0;
			this->_pte->up = 0;
		}

		template< class InputIterator >
			map( InputIterator first, InputIterator last,
				 const key_compare& comp = key_compare(),
				 const allocator_type& alloc = allocator_type() ) :
				 _pte( 0 ), _root( 0 ), _front( 0 ), _back( 0 ), _size( 0 ), _comp( comp ), _alloc( alloc ) {

			this->_pte = new mapNode<Key, T>();
			this->_pte->left = this->_pte;
			this->_pte->right = 0;
			this->_pte->up = 0;

			this->insert( first, last );
		}

		map( const map& x ) : _pte( 0 ), _root( 0 ), _front( 0 ), _back( 0 ), _size( 0 ), _comp( x._comp ), _alloc( x._alloc ) {

			this->_pte = new mapNode<Key, T>();
			this->_pte->left = this->_pte;
			this->_pte->right = 0;
			this->_pte->up = 0;

			if ( x._front ) {

				for ( const_iterator it = x.begin(); it != x.end(); it++ )
					this->insert( it.getNode()->data );
			}
		}

		// destructor

		~map() {

			if ( this->_front ) {

				iterator			it( this->_front );

				this->_pte->up = 0;

				mapNode<Key, T>*	tmp;

				while ( it != this->end() ) {

					tmp = it.getNode();
					it++;
					if ( it == this->end() ) {
						break;
					}
					it.getNode()->left = 0;
					if ( this->_comp( tmp->data.first, it->first ) && it.getNode()->up != NULL && tmp->up != NULL && it.getNode() != tmp->up )
						it.getNode()->up = tmp->up;

					delete tmp;
				}
				delete tmp;
			}
			delete this->_pte;
		}

		// operator =

		map&					operator=( const map& x ) {

			if ( this != &x ) {

				this->clear();

				this->_comp = x._comp;
				this->_alloc = x._alloc;

				if ( x._front ) {

					for ( const_iterator it = x.begin(); it != x.end(); it++ )
						this->insert( it.getNode()->data );
				}
			}
			return *this;
		}

		// iterators

		iterator				begin() { return this->_front ? iterator( this->_front ) : iterator( this->_pte ); }
		const_iterator			begin() const { return this->_front ? const_iterator( this->_front ) : const_iterator( this->_pte ); }

		iterator				end() { return iterator( this->_pte ); }
		const_iterator			end() const { return const_iterator( this->_pte ); }

		reverse_iterator		rbegin() { return reverse_iterator( this->_pte ); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator( this->_pte ); }

		reverse_iterator		rend() { return this->_front ? reverse_iterator( this->_front ) : reverse_iterator( this->_pte ); }
		const_reverse_iterator	rend() const { return this->_front ? const_reverse_iterator( this->_front ) : const_reverse_iterator( this->_pte ); }

		// capacity

		bool					empty() const { return !this->_size; }

		size_type				size() const { return this->_size; }

		size_type				max_size() const {

			return ( allocator_type().max_size() / 2 );
		}

		// element access

		mapped_type&			operator[]( const key_type& k ) {
			return ( *( (this->insert( ft::make_pair<Key, T>( k, mapped_type() ) ) ).first ) ).second;
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
				this->_back = this->_root;

				this->_size++;

				return ft::make_pair<iterator, bool>( iterator( this->_root ), true );
			}

			mapNode<Key, T>*	tmp( this->_root );
			mapNode<Key, T>*	prev( 0 );

			while ( true ) {

				if ( tmp == NULL ) {

					tmp = new mapNode<Key, T>( val );
					tmp->left = 0;

					if ( this->_comp( this->_back->data.first, tmp->data.first ) ) {

						tmp->right = this->_pte;
						this->_pte->up = tmp;
					}
					else
						tmp->right = 0;

					tmp->up = prev;

					this->_size++;

					if ( this->_comp( tmp->data.first, this->_front->data.first ) )
						this->_front = tmp;

					if ( this->_comp( this->_back->data.first, tmp->data.first ) )
						this->_back = tmp;

					if ( this->_comp( prev->data.first, tmp->data.first ) )
						prev->right = tmp;
					else
						prev->left = tmp;

					return ft::make_pair<iterator, bool>( iterator( tmp ), true );
				}
				if ( tmp == this->_pte ) {

					mapNode<Key, T>*	up;
					up = tmp->up;

					tmp = new mapNode<Key, T>( val );
					tmp->left = 0;
					tmp->right = this->_pte;
					tmp->up = prev;

					this->_pte->up = tmp;

					up->right = tmp;

					if ( this->_comp( tmp->data.first, this->_front->data.first ) )
						this->_front = tmp;

					if ( this->_comp( this->_back->data.first, tmp->data.first ) )
						this->_back = tmp;

					if ( this->_comp( prev->data.first, tmp->data.first ) )
						prev->right = tmp;
					else
						prev->left = tmp;

					this->_size++;
					return ft::make_pair<iterator, bool>( iterator( tmp ), true );
				}
				if ( val.first == tmp->data.first )
					return ft::make_pair<iterator, bool>( iterator( tmp ), false );
				else if ( this->_comp( val.first, tmp->data.first ) ) {
					prev = tmp;
					tmp = tmp->left;
				}
				else {
					prev = tmp;
					tmp = tmp->right;
				}
			}
		}

		iterator				insert( iterator position, const value_type& val ) {

			static_cast<void>( position );
			return this->insert( val ).first;
		}

		template< class InputIterator >
			void				insert( InputIterator first, InputIterator last ) {

			while ( first != last ) {
				this->insert( *first );
				first++;
			}
		}

		void					erase( iterator position ) {

			if ( position.getNode() == NULL || position.getNode() == this->_pte )
				return;

			if ( find( position->first ) == this->end() )
				return;

			mapNode<Key, T>*	pos = position.getNode();

			// No child
			if ( pos->left == NULL && pos->right == NULL ) {

				if ( this->_comp( pos->up->data.first, pos->data.first ) )
					pos->up->right = NULL;
				else
					pos->up->left = NULL;

				if ( pos == this->_front )
					this->_front = (++position).getNode();
				else if ( pos == this->_back )
					this->_back = (--position).getNode();

				delete pos;
			}
			// One child on the right
			else if ( pos->left == NULL ) {

				if ( pos->right == this->_pte && pos == this->_root ) {

					this->_pte->up = 0;
					this->_front = 0;
					this->_back = 0;
					this->_root = 0;
				}
				else {

					if ( pos->up != NULL )
						pos->up->right = pos->right;
					else
						this->_root = pos->right;

					if ( pos == this->_front )
						this->_front = (++position).getNode();
					else if ( pos == this->_back )
						this->_back = (--position).getNode();

					pos->right->up = pos->up;
				}
				delete pos;
			}
			// one child on the left
			else if ( pos->right == NULL ) {

				if ( this->_comp( pos->up->data.first, pos->data.first ) )
					pos->up->right = pos->left;
				else
					pos->up->left = pos->left;

				if ( pos == this->_back )
					this->_back = (--position).getNode();

				pos->left->up = pos->up;
				delete pos;
			}
			// Child on both sides
			else {

				if ( pos->right == this->_pte && pos == this->_root ) {

					pos->left->up = NULL;
					this->_back = (--position).getNode();
					this->_back->right = this->_pte;
					this->_pte->up = this->_back;
					this->_root = pos->left;
				}
				else if ( pos->right == this->_pte ) {

					pos->up->right = pos->left;
					this->_back = (--position).getNode();
					this->_back->right = this->_pte;
					this->_pte->up = this->_back;
				}
				else {

					pos->data = (++position).getNode()->data;
					position--;
					this->erase( iterator( pos->right ) );
				}
			}
			this->_size--;
		}

		size_type				erase( const key_type& k ) {

			size_type	size = this->_size;

			this->erase( find( k ) );

			if ( size == this->_size )
				return 0;
			else
				return 1;
		}

		void					erase( iterator first, iterator last ) {

			iterator tmp;
			while ( first != last ) {

				tmp = first;
				first++;
				erase( tmp );
			}
		}

		void					swap( map& x ) {

			if ( this == &x )
				return;

			mapNode<Key, T>	*r = this->_root;
			mapNode<Key, T>	*f = this->_front;
			mapNode<Key, T>	*b = this->_back;
			mapNode<Key, T>	*p = this->_pte;
			size_type		s = this->_size;

			this->_root = x._root;
			this->_front = x._front;
			this->_back = x._back;
			this->_pte = x._pte;
			this->_size = x._size;

			x._root = r;
			x._front = f;
			x._back = b;
			x._pte = p;
			x._size = s;
		}

		void					clear() {

			if ( !this->_front )
				return;

			iterator			it( this->_front );

			this->_pte->up = 0;

			mapNode<Key, T>*	tmp;

			while ( it != this->end() ) {

				tmp = it.getNode();
				it++;
				if ( it == this->end() ) {
					break;
				}
				it.getNode()->left = 0;
				if ( this->_comp( tmp->data.first, it->first ) && it.getNode()->up != NULL && tmp->up != NULL && it.getNode() != tmp->up )
					it.getNode()->up = tmp->up;

				delete tmp;
			}
			delete tmp;

			this->_root = NULL;
			this->_front = NULL;
			this->_back = NULL;
			this->_size = 0;
		}

		// observers

		key_compare				key_comp() const { return key_compare(); }

		value_compare			value_comp() const { return value_compare( key_compare() ); }

		// operations

		iterator				find( const key_type& k ) {

			iterator	it( this->_root );

			while ( it != this->end() && it.getNode() ) {

				if ( this->_comp( k, it->first ) )
					it = it.getNode()->left;
				else if ( this->_comp( it->first, k ) )
					it = it.getNode()->right;
				else
					return iterator( it );
			}
			return this->end();
		}
		const_iterator			find( const key_type& k ) const {

			const_iterator	it( this->_root );

			while ( it != this->end() && it.getNode() ) {

				if ( this->_comp( k, it->first ) )
					it = it.getNode()->left;
				else if ( this->_comp( it->first, k ) )
					it = it.getNode()->right;
				else
					return const_iterator( it );
			}
			return this->end();
		}

		size_type				count( const key_type& k ) const {

			if ( this->find( k ) == this->end() )
				return 0;
			return 1;
		}

		iterator				lower_bound( const key_type& k ) {

			iterator	it = this->_root;

			while ( it != this->end() && it.getNode() ) {

				if ( this->_comp( k, it->first ) )
					it = it.getNode()->left;
				else if ( this->_comp( it->first, k ) )
					it = it.getNode()->right;
				else
					return iterator( it );
			}
			return this->end();
		}
		const_iterator			lower_bound( const key_type& k ) const {

			iterator	it = this->_root;

			while ( it != this->end() && it.getNode() ) {

				if ( this->_comp( k, it->first ) )
					it = it.getNode()->left;
				else if ( this->_comp( it->first, k ) )
					it = it.getNode()->right;
				else
					return const_iterator( it );
			}
			return this->end();
		}

		iterator				upper_bound( const key_type& k ) {

			iterator	it = this->_root;

			while ( it != this->end() && it.getNode() ) {

				if ( this->_comp( k, it->first ) )
					it = it.getNode()->left;
				else if ( this->_comp( it->first, k ) )
					it = it.getNode()->right;
				else
					return iterator( ++it );
			}
			return this->end();
		}
		const_iterator			upper_bound( const key_type& k ) const {

			iterator	it = this->_root;

			while ( it != this->end() && it.getNode() ) {

				if ( this->_comp( k, it->first ) )
					it = it.getNode()->left;
				else if ( this->_comp( it->first, k ) )
					it = it.getNode()->right;
				else
					return const_iterator( ++it );
			}
			return this->end();
		}

		pair<iterator, iterator>				equal_range( const key_type& k ) {

			return ft::make_pair<iterator, iterator>( this->find( k ), ++this->find( k ) );
		}
		pair<const_iterator, const_iterator>	equal_range( const key_type& k ) const {

			return ft::make_pair<const_iterator, const_iterator>( this->find( k ), ++this->find( k ) );
		}

	};
}
