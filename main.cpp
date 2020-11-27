/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 14:00:59 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/11/20 14:36:40 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <iostream>
#include <list>

template< typename T >
void	printContainer( const T & con ) {

	std::cout << "myList:";
	for ( typename T::const_iterator it = con.begin(); it != con.end(); ++it )
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

void 	iterators() {

	std::cout << "************************* iterators *************************" << std::endl;

	ft::list<int>	myList;

	for ( int i = 0; i < 10; i++ )
		myList.push_back( i );

	printContainer( myList );

	ft::list<int>::iterator		from( myList.begin() );
	ft::list<int>::iterator 	until( myList.end() );

	ft::list<int>::iterator		from2( from );
	ft::list<int>::iterator 	until2( until );

	std::cout << "myList:";
	while ( from != until ) {
		std::cout << ' ' << *from;
		from++;
	}
	std::cout << std::endl;

	std::cout << "myList:";
	while ( from2 != until2 ) {
		std::cout << ' ' << *from2;
		from2++;
	}
	std::cout << std::endl;

	ft::list<int>::iterator		it = myList.begin();

	std::cout << "begin:\t\t" << *it << std::endl;
	it++;
	std::cout << "begin++:\t" << *it << std::endl;
	it--;
	std::cout << "begin--:\t" << *it << std::endl;

	ft::list<int>::iterator		compare = myList.begin();

	if ( compare == it )
		std::cout << "Equal" << std::endl;
	else
		std::cout << "Not equal" << std::endl;

	compare++;

	if ( compare == it )
		std::cout << "Equal" << std::endl;
	else
		std::cout << "Not equal" << std::endl;

	std::cout << "myList:";
	for ( ft::list<int>::const_iterator it2( it ); it2 != myList.end(); it2++ )
		std::cout << ' ' << *it2;
	std::cout << std::endl << std::endl << std::endl;
}

void 	reverse_iterators() {

	std::cout << "******************** Reverse iterators **********************" << std::endl;

	// ******************** Constructors ********************

	ft::list<int>	myList;

	for ( int i = 0; i < 10; i++ )
		myList.push_back( i );

	typedef ft::list<int>::iterator iter_type;

	iter_type							from( myList.begin() );
	iter_type							until( myList.end() );

	ft::reverse_iterator<iter_type>	rev_until( from );
	ft::reverse_iterator<iter_type>	rev_from( until );

	std::cout << "myList:";
	while ( rev_from != rev_until )
		std::cout << ' ' << *rev_from++;
	std::cout << std::endl;

	// ******************** base ********************

	ft::reverse_iterator<iter_type>	rev_end( myList.begin() );
	ft::reverse_iterator<iter_type>	rev_begin( myList.end() );

	std::cout << "myList:";
	for ( iter_type it = rev_end.base(); it != rev_begin.base(); ++it )
		std::cout << ' ' << *it;
	std::cout << std::endl;

	from = myList.begin();
	until = myList.end();

	// ******************** operator * ********************
	ft::reverse_iterator<iter_type>	rev_until2( from );
	ft::reverse_iterator<iter_type> rev_from2( until );

	std::cout << "myList:";
	while ( rev_from2 != rev_until2 )
		std::cout << ' ' << *rev_from2++;
	std::cout << std::endl;


	// ******************** operator -- ********************

	ft::reverse_iterator<iter_type>	rev_iterator = myList.rbegin();
	ft::reverse_iterator<iter_type>	rev_begin2( myList.end() );
	ft::reverse_iterator<iter_type>	rev_end2( myList.begin() );

	rev_iterator = rev_begin2;

	while ( rev_iterator != rev_end )
		std::cout << *rev_iterator++ << ' ';
	std::cout << std::endl;

	while ( rev_iterator != rev_begin )
		std::cout << *(--rev_iterator) << ' ';
	std::cout << std::endl;


	// ******************** relational operators ********************

	ft::reverse_iterator<iter_type>	rev_iterator1 = myList.rend();
	ft::reverse_iterator<iter_type>	rev_iterator2 = myList.rbegin();
	ft::reverse_iterator<iter_type>	rev_iterator3 = myList.rend();

	std::cout << "rev_iterator1 =\t" << *rev_iterator1 << std::endl;
	std::cout << "rev_iterator2 =\t" << *rev_iterator2 << std::endl;
	std::cout << "rev_iterator3 =\t" << *rev_iterator3 << std::endl << std::endl;

	std::cout << std::boolalpha;
	std::cout << "rev_iterator1 != rev_iterator2:\t" << (rev_iterator1 != rev_iterator2) << std::endl;
	std::cout << "rev_iterator1 == rev_iterator2:\t" << (rev_iterator1 == rev_iterator2) << std::endl;
	std::cout << "rev_iterator2 == rev_iterator3:\t" << (rev_iterator2 == rev_iterator3) << std::endl << std::endl;

}

void 	push_pop_front_back() {

	std::cout << "******************** push_pop_front_back ********************" << std::endl;

	ft::list<int>	myList;

	myList.push_back( 15 );
	myList.push_back( 28 );
	myList.push_back( 42 );

	printContainer( myList );

	myList.push_front( 7 );
	myList.push_front( 5 );
	myList.push_front( 3 );

	printContainer( myList );
	std::cout << std::endl;

	std::cout << "front:  " << myList.front() << std::endl;
	std::cout << "back:   " << myList.back() << std::endl << std::endl;

	myList.pop_back();
	printContainer( myList );

	myList.pop_back();
	printContainer( myList );

	myList.pop_back();
	printContainer( myList );

	myList.pop_back();
	printContainer( myList );

	myList.pop_back();
	printContainer( myList );

	myList.push_back( 3 );
	myList.push_back( 5 );
	myList.push_back( 7 );
	myList.push_back( 15 );
	myList.push_back( 28 );
	myList.push_back( 42 );

	myList.pop_front();
	printContainer( myList );

	myList.pop_front();
	printContainer( myList );

	myList.pop_front();
	printContainer( myList );

	myList.pop_front();
	printContainer( myList );

	myList.pop_front();
	printContainer( myList );

	myList.pop_front();
	printContainer( myList );
	std::cout << std::endl << std::endl;
}

void	capacity() {

	std::cout << "************************* Capacity **************************" << std::endl;

	// empty
	ft::list<int>	myList;
	int				sum = 0;

	for ( int i = 1; i <= 10; ++i )
		myList.push_back( i );
	while ( !myList.empty() ) {

		sum += myList.front();
		myList.pop_front();
	}
	std::cout << "total: " << sum << std::endl;

	// size
	ft::list<int>	myInts;
	std::cout << "0. size: " << myInts.size() << std::endl;

	for ( int i = 0; i < 10; i++ )
		myInts.push_back( i );
	std::cout << "1. size: " << myInts.size() << std::endl;

	myInts.pop_back();
	std::cout << "2. size: " << myInts.size() << std::endl;

	// max_size

	std::cout << "myInts: " << myInts.max_size() << std::endl;
	std::cout << "myList: " << myList.max_size() << std::endl << std::endl;
}

void	modifiers() {

	std::cout << "************************* Modifiers *************************" << std::endl;

	// clear
	ft::list<int>	myList;

	myList.push_back( 100 );
	myList.push_back( 200 );
	myList.push_back( 300 );

	printContainer( myList );

	myList.clear();
	myList.push_back( 1101 );
	myList.push_back( 2202 );

	printContainer( myList );

	// assign
	ft::list<int>	first;
	ft::list<int>	second;

	first.assign( 7, 100 );

	second.assign( first.begin(), first.end() );

	int 	myints[] = { 1776, 7, 4 };
	first.assign( myints, myints + 3 );

	std::cout << "Size of first: " << int ( first.size() ) << std::endl;
	std::cout << "Size of second: " << int( second.size() ) << std::endl << std::endl;

	// insert

	myList.clear();

	for ( int i = 1; i <= 5; ++i )
		myList.push_back( i );

	printContainer( myList );

	ft::list<int>::iterator it = myList.begin();

	++it;

	myList.insert( it, 10 );
	printContainer( myList );

	myList.insert( it, 2, 20 );
	printContainer( myList );

	--it;

	ft::list<int>	myList2;

	myList2.push_back( 30 );
	myList2.push_back( 30 );

	myList.insert( it, myList2.begin(), myList2.end() );
	printContainer( myList );
	std::cout << std::endl;

	// erase
	myList.clear();

	for ( int i = 1; i < 10; ++i )
		myList.push_back( i * 10 );

	ft::list<int>::iterator	it2 = myList.begin();
	it = myList.begin();

	for ( int i = 0; i < 6; ++i )
		++it2;
	++it;

	it = myList.erase( it );
	it2 = myList.erase( it2 );
	printContainer( myList );

	++it;
	--it2;

	std::cout << *myList.erase( it, it2 ) << std::endl;
	printContainer( myList );

	std::cout << myList.size() << std::endl;

	std::cout << std::endl;

	// swap
	first.clear();
	second.clear();

	for ( int i = 0; i < 3; ++i )
		first.push_back( 100 );

	for ( int i = 0; i < 5; ++i )
		second.push_back( 200 );

	first.swap( second );

	std::cout << "first contains:";
	for ( it = first.begin(); it != first.end(); it++ )
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "second contains:";
	for ( it = second.begin(); it != second.end(); it++ )
		std::cout << ' ' << *it;
	std::cout << std::endl;

	// resize
	myList.clear();

	for ( int i = 1; i < 10; ++i )
		myList.push_back( i );

	myList.resize( 5 );
	myList.resize( 8, 100 );
	myList.resize( 12 );

	printContainer( myList );
	std::cout << std::endl;
}

void	operations() {

	std::cout << "************************ Operations *************************" << std::endl;

	// splice
	ft::list<int>	myList, myList2;

	for ( int i = 1; i <= 4; ++i )
		myList.push_back( i );

	for ( int i = 1; i <= 3; ++i )
		myList2.push_back( i * 10 );

	ft::list<int>::iterator	it = myList.begin();
	++it;

	myList.splice( it, myList2 );
	printContainer( myList );

	myList2.splice( myList2.begin(), myList, it );
	printContainer( myList );

	it = myList.begin();
	for ( int i = 0; i < 3; i++ )
		it++;

	myList.splice( myList.begin(), myList, it, myList.end() );
	printContainer( myList );
}

int 	main() {

	iterators();
	reverse_iterators();
	push_pop_front_back();
	capacity();
	modifiers();
	operations();

	return 0;
}
