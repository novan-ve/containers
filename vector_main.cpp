/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_main.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 15:18:23 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/12/01 15:18:39 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>

template< typename T >
void	printContainer( const T & con, const char* str ) {

	std::cout << str << ":";
	for ( typename T::const_iterator it = con.begin(); it != con.end(); ++it )
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

void 	iterators_vector() {

	std::cout << "************************* iterators *************************" << std::endl;

	ft::vector<int>	myVector;

	for ( int i = 0; i < 10; i++ )
		myVector.push_back( i );

	printContainer( myVector, "myVector" );

	ft::vector<int>::iterator	from( myVector.begin() );
	ft::vector<int>::iterator 	until( myVector.end() );

	ft::vector<int>::iterator	from2( from );
	ft::vector<int>::iterator 	until2( until );

	std::cout << "myVector:";
	while ( from != until ) {
		std::cout << ' ' << *from;
		from++;
	}
	std::cout << std::endl;

	std::cout << "myVector:";
	while ( from2 != until2 ) {
		std::cout << ' ' << *from2;
		from2++;
	}
	std::cout << std::endl;

	ft::vector<int>::iterator		it = myVector.begin();

	std::cout << "begin:\t\t" << *it << std::endl;
	it++;
	std::cout << "begin++:\t" << *it << std::endl;
	it--;
	std::cout << "begin--:\t" << *it << std::endl;

	ft::vector<int>::iterator		compare = myVector.begin();

	if ( compare == it )
		std::cout << "Equal" << std::endl;
	else
		std::cout << "Not equal" << std::endl;

	compare++;

	if ( compare == it )
		std::cout << "Equal" << std::endl;
	else
		std::cout << "Not equal" << std::endl;

	std::cout << "myVector:";
	for ( ft::vector<int>::const_iterator it2( it ); it2 != myVector.end(); it2++ )
		std::cout << ' ' << *it2;
	std::cout << std::endl << std::endl << std::endl;
}

void 	push_pop_front_back_vector() {

	std::cout << "******************** push_pop_front_back ********************" << std::endl;

	ft::vector<int>	myVector;

	myVector.push_back( 15 );
	myVector.push_back( 28 );
	myVector.push_back( 42 );

	printContainer( myVector, "myVector" );

	myVector.push_back( 7 );
	myVector.push_back( 5 );
	myVector.push_back( 3 );

	printContainer( myVector, "myVector" );
	std::cout << std::endl;

	std::cout << "front:  " << myVector.front() << std::endl;
	std::cout << "back:   " << myVector.back() << std::endl << std::endl;

	myVector.pop_back();
	printContainer( myVector, "myVector" );

	myVector.pop_back();
	printContainer( myVector, "myVector" );

	myVector.pop_back();
	printContainer( myVector, "myVector" );

	myVector.pop_back();
	printContainer( myVector, "myVector" );

	myVector.pop_back();
	printContainer( myVector, "myVector" );

}

int		vector_main() {

	iterators_vector();
	push_pop_front_back_vector();

	return 0;
}
