/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 13:15:53 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/11/08 13:15:54 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <list>

bool single_digit (const int& value) { return (value<10); }

template< typename T >
void 	printContainer( const T & con ) {

	for ( typename T::const_iterator it = con.begin(); it != con.end(); ++it ) {

		std::cout << *it;
		if ( it != --con.end() )
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int		main() {

	// Member functions
	std::list<int>	first;
	std::list<int>	second( 4, 80 );
	std::list<int>	third( second.begin(), second.end() );
	std::list<int>	fourth( third );

	int 	myInts[] = { 16, 22, 77, 29 };
	std::list<int>	fifth( myInts, myInts + sizeof( myInts ) / sizeof( int ) );


	// Iterators

	std::cout << "Iterators ( begin, end )" << std::endl;
	std::cout << "fifth: ";
	for ( std::list<int>::const_iterator it1 = fifth.begin(); it1 != fifth.end(); ++it1 )
		std::cout << *it1 << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Reverse iterators ( rbegin, rend )" << std::endl;
	std::cout << "fifth: ";
	for ( std::list<int>::const_reverse_iterator it2 = fifth.rbegin(); it2 != fifth.rend(); ++it2 )
		std::cout << *it2 << " ";
	std::cout << std::endl << std::endl;


	// Capacity

	std::cout << "first.empty():\t" << first.empty() << std::endl;
	std::cout << "fifth.empty():\t" << fifth.empty() << std::endl << std::endl;

	std::cout << "first.size():\t" << first.size() << std::endl;
	std::cout << "fifth.size():\t" << fifth.size() << std::endl << std::endl;

	std::cout << "first.max_size():\t" << first.max_size() << std::endl;
	std::cout << "fifth.max_size():\t" << fifth.max_size() << std::endl << std::endl;


	// Element access

	std::cout << "fifth.front():\t" << fifth.front() << std::endl;
	std::cout << "fifth.back():\t" << fifth.back() << std::endl << std::endl;


	// Modifiers

	std::cout << std::setw( 28 ) << std::left << "second:";
	printContainer( second );

	std::cout << std::setw( 28 ) << std::left << "third:";
	printContainer( third );

	std::cout << std::setw( 28 ) << std::left << "second.assign( 4, 100 ):";
	second.assign( 4, 100 );
	printContainer( second );

	std::cout << std::setw( 28 ) << std::left << "second.push_front( 25 ):";
	second.push_front( 25 );
	printContainer( second );

	std::cout << std::setw( 28 ) << std::left << "second.pop_front():";
	second.pop_front();
	printContainer( second );

	std::cout << std::setw( 28 ) << std::left << "second.push_back( 125 ):";
	second.push_back( 125 );
	printContainer( second );

	std::cout << std::setw( 28 ) << std::left << "second.pop_back():";
	second.pop_back();
	printContainer( second );

	std::list<int>::iterator	it = second.begin();
	advance( it, 1 );
	// it points to the second 100

	std::cout << std::setw( 28 ) << std::left << "second.insert( it, 10 ):";
	second.insert( it, 10 );
	printContainer( second );

	// it still points to the second 100
	std::cout << std::setw( 28 ) << std::left << "second.insert( it, 2, 20 ):";
	second.insert( it, 2, 20 );
	printContainer( second );

	--it;
	// it now points to the second 20
	std::cout << "second.insert( it, third.begin(), third.end() ):\t";
	second.insert( it, third.begin(), third.end() );
	printContainer( second );

	std::cout << std::setw( 28 ) << std::left << "second.erase( it ):";
	second.erase( it );
	printContainer( second );

	std::list<int>::iterator	it1 = second.begin();
	std::list<int>::iterator 	it2 = it1;
	advance( it1, 3 );
	advance( it2, 9 );

	std::cout << "\t\t\t\t\t\t\t\t\t\t ^it1\t\t\t\t\t   ^it2" << std::endl;
	std::cout << std::setw( 28 ) << std::left << "second.erase( it1, it2 ):";
	second.erase( it1, it2 );
	printContainer( second );

	std::cout << std::setw( 28 ) << std::left << "fifth:";
	printContainer( fifth );

	std::cout << std::setw( 28 ) << std::left << "second.swap( fifth ):";
	second.swap( fifth );
	printContainer( second );

	std::cout << std::setw( 28 ) << std::left << "second.resize( 2 )";
	second.resize( 2 );
	printContainer( second );

	std::cout << std::setw( 28 ) << std::left << "second.resize( 4, 100 )";
	second.resize( 4, 100 );
	printContainer( second );

	std::cout << std::setw( 28 ) << std::left << "second.resize( 6 )";
	second.resize( 6 );
	printContainer( second );

	std::cout << "second.clear()" << std::endl;
	second.clear();
	std::cout << "second.push_back( 1101 )" << std::endl;
	second.push_back( 1101 );
	std::cout << "second.push_back( 2202 )" << std::endl;
	second.push_back( 2202 );
	std::cout << std::setw( 28 ) << std::left << "second:";
	printContainer( second );
	std::cout << std::endl;


	// Operations

	for ( int i = 1; i <= 4; ++i )
		first.push_back( i );
	second.clear();
	for ( int i = 1; i <= 3; ++i )
		second.push_back( i * 10 );

	std::cout << "first:\t";
	printContainer( first );
	std::cout << "\t\t   ^it" << std::endl;
	std::cout << "second:\t";
	printContainer( second );

	it = first.begin();
	it++;

	std::cout << std::endl << "first.splice( it, second )" << std::endl;
	first.splice( it, second );
	std::cout << "first:\t";
	printContainer( first );
	std::cout << "\t\t\t\t\t   ^it" << std::endl;
	std::cout << "second:\t";
	printContainer( second );

	std::cout << std::endl << "second.splice( second.begin(), first, it )" << std::endl;
	second.splice( second.begin(), first, it );
	std::cout << "first:\t";
	printContainer( first );
	std::cout << "it invalid" << std::endl;
	std::cout << "second:\t";
	printContainer( second );

	it = first.begin();
	std::advance( it, 3 );
	std::cout << std::endl << "it == 30" << std::endl;
	std::cout << "first.splice( first.begin(), first, it, first.end()" << std::endl;
	first.splice( first.begin(), first, it, first.end() );
	std::cout << "first:\t";
	printContainer( first );
	std::cout << "\t\t^it" << std::endl << std::endl;

	std::cout << "first.remove( 3 ):\t\t\t\t\t";
	first.remove( 3 );
	printContainer( first );

	std::cout << "first.remove_if( single_digit ):\t";
	first.remove_if( single_digit );
	printContainer( first );

	std::cout << std::endl << "first.push_back( 20 ):\t";
	first.push_back( 20 );
	printContainer( first );

	std::cout << "first.unique():\t\t\t";
	first.unique();
	printContainer( first );

	std::cout << "first.push_back( 10 ):\t";
	first.push_back( 10 );
	printContainer( first );

	std::cout << "first.unique():\t\t\t";
	first.unique();
	printContainer( first );


}
