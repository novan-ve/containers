/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 17:00:40 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/11/29 17:01:52 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list/List.hpp"
#include "vector/Vector.hpp"
#include "stack/Stack.hpp"
#include "queue/Queue.hpp"
#include "map/Map.hpp"
#include <cmath>


template< typename T >
void	printContainer_list( const T & con, const char* str ) {

	std::cout << str << ":";
	for ( typename T::const_iterator it = con.begin(); it != con.end(); ++it )
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

void 	iterators() {

	std::cout << "************************* iterators *************************" << std::endl;

	ft::list<int>	myList;

	for ( int i = 0; i < 10; i++ )
		myList.push_back( i );

	printContainer_list( myList, "myList" );

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

void	constructors() {

	std::cout << "*********************** Constructors ************************" << std::endl;

	ft::list<int> first;
	ft::list<int> second( 4, 100 );
	ft::list<int> third( second.begin(), second.end() );
	ft::list<int> fourth( third );

	int	myInts[] = { 16, 2, 77, 29 };
	ft::list<int> fifth( myInts, myInts + sizeof( myInts ) / sizeof( int ) );

	ft::list<int> sixth;
	sixth = fifth;

	first.push_back( 15 );
	first.push_back( 42 );

	printContainer_list( first, "the contents of the first are" );
	printContainer_list( second, "the contents of the second are" );
	printContainer_list( third, "the contents of the third are" );

	third.clear();

	printContainer_list( fourth, "the contents of the fourth are" );
	printContainer_list( fifth, "the contents of the fifth are" );

	fifth.clear();

	printContainer_list( sixth, "the contents of the sixth are" );
	std::cout << std::endl;
}

void 	push_pop_front_back() {

	std::cout << "******************** push_pop_front_back ********************" << std::endl;

	ft::list<int>	myList;

	myList.push_back( 15 );
	myList.push_back( 28 );
	myList.push_back( 42 );

	printContainer_list( myList, "myList" );

	myList.push_front( 7 );
	myList.push_front( 5 );
	myList.push_front( 3 );

	printContainer_list( myList, "myList" );
	std::cout << std::endl;

	std::cout << "front:  " << myList.front() << std::endl;
	std::cout << "back:   " << myList.back() << std::endl << std::endl;

	myList.pop_back();
	printContainer_list( myList, "myList" );

	myList.pop_back();
	printContainer_list( myList, "myList" );

	myList.pop_back();
	printContainer_list( myList, "myList" );

	myList.pop_back();
	printContainer_list( myList, "myList" );

	myList.pop_back();
	printContainer_list( myList, "myList" );

	myList.push_back( 3 );
	myList.push_back( 5 );
	myList.push_back( 7 );
	myList.push_back( 15 );
	myList.push_back( 28 );
	myList.push_back( 42 );

	myList.pop_front();
	printContainer_list( myList, "myList" );

	myList.pop_front();
	printContainer_list( myList, "myList" );

	myList.pop_front();
	printContainer_list( myList, "myList" );

	myList.pop_front();
	printContainer_list( myList, "myList" );

	myList.pop_front();
	printContainer_list( myList, "myList" );

	myList.pop_front();
	printContainer_list( myList, "myList" );
	std::cout << std::endl << std::endl;
}

void	capacity_list() {

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

	ft::list<int>	numbers;

	if ( numbers.max_size() > 1000 ) {

		for ( int i = 0; i < 1000; i++ )
			numbers.push_back( 0 );
		std::cout << "The list contains 1000 elements." << std::endl;
	}
	else
		std::cout << "The list could not hold 1000 elements." << std::endl;
	std::cout << std::endl;
}

void	modifiers() {

	std::cout << "************************* Modifiers *************************" << std::endl;

	// clear
	ft::list<int>	myList;

	myList.push_back( 100 );
	myList.push_back( 200 );
	myList.push_back( 300 );

	printContainer_list( myList, "myList" );

	myList.clear();
	myList.push_back( 1101 );
	myList.push_back( 2202 );

	printContainer_list( myList, "myList" );

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

	printContainer_list( myList, "myList" );

	ft::list<int>::iterator it = myList.begin();

	++it;

	myList.insert( it, 10 );
	printContainer_list( myList, "myList" );

	myList.insert( it, 2, 20 );
	printContainer_list( myList, "myList" );

	--it;

	ft::list<int>	myList2;

	myList2.push_back( 30 );
	myList2.push_back( 30 );

	myList.insert( it, myList2.begin(), myList2.end() );
	printContainer_list( myList, "myList" );
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
	printContainer_list( myList, "myList" );

	++it;
	--it2;

	std::cout << *myList.erase( it, it2 ) << std::endl;
	printContainer_list( myList, "myList" );

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

	printContainer_list( first, "first contains" );
	printContainer_list( second, "second contains" );

	// resize
	myList.clear();

	for ( int i = 1; i < 10; ++i )
		myList.push_back( i );

	myList.resize( 5 );
	myList.resize( 8, 100 );
	myList.resize( 12 );

	printContainer_list( myList, "myList" );
	std::cout << std::endl;
}

// Comparisons for operations()
bool	single_digit( const int& value ) { return ( value < 10 ); }

struct	is_odd {
	bool operator() ( const int& value ) { return ( value % 2 ) == 1; }
};

bool	compare_nocase( const std::string& first, const std::string& second ) {

	unsigned int i = 0;

	while ( ( i < first.length() ) && ( i < second.length() ) ) {

		if ( tolower( first[i] ) < tolower( second[i] ) )
			return true;
		else if ( tolower( first[i] ) > tolower( second[i] ) )
			return false;
		++i;
	}
	return ( first.length() < second.length() );
}

bool	same_integral_part( double first, double second ) {
	return ( int( first ) == int( second ) );
}

struct	is_near {
	bool operator() ( double first, double second ) {
		return ( fabs( first - second ) < 5.0 );
	}
};

bool	mycomparison( double first, double second ) {
	return ( int( first ) < int( second ) );
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
	printContainer_list( myList, "myList" );

	myList2.splice( myList2.begin(), myList, it );
	printContainer_list( myList, "myList" );

	it = myList.begin();
	for ( int i = 0; i < 3; i++ )
		it++;

	myList.splice( myList.begin(), myList, it, myList.end() );
	printContainer_list( myList, "myList" );
	printContainer_list( myList2, "myList2" );
	std::cout << std::endl;

	// remove
	int		myInts[] = { 17, 89, 7, 89, 14 };

	myList.clear();
	for ( int i = 0; i < 5; i++ )
		myList.push_back( myInts[i] );

	myList.remove( 89 );
	printContainer_list( myList, "myList" );
	std::cout << std::endl;

	// remove_if
	int		myInts2[] = { 15, 36, 7, 17, 20, 39, 4, 1 };

	myList.clear();
	for ( int i = 0; i < 8; i++ )
		myList.push_back( myInts2[i] );

	myList.remove_if( single_digit );

	myList.remove_if( is_odd() );

	printContainer_list( myList, "myList" );
	std::cout << std::endl;

	// sort
	ft::list<std::string>	mySlist;

	mySlist.push_back( "one" );
	mySlist.push_back( "two" );
	mySlist.push_back( "Three" );

	printContainer_list( mySlist, "myList" );

	mySlist.sort();
	printContainer_list( mySlist, "myList" );

	mySlist.sort( compare_nocase );
	printContainer_list( mySlist, "myList" );
	std::cout << std::endl;

	// unique

	double	myDoubles[] = { 12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25 };
	ft::list<double>	myDlist;

	for ( int i = 0; i < 10; i++ )
		myDlist.push_back( myDoubles[i] );

	myDlist.sort();

	myDlist.unique();
	printContainer_list( myDlist, "myList" );

	myDlist.unique( same_integral_part );
	printContainer_list( myDlist, "myList" );

	myDlist.unique( is_near() );
	printContainer_list( myDlist, "myList" );
	std::cout << std::endl;

	// merge
	myDlist.clear();
	ft::list<double>	myDlist2;

	myDlist.push_back( 3.1 );
	myDlist.push_back( 2.2 );
	myDlist.push_back( 2.9 );

	myDlist2.push_back( 3.7 );
	myDlist2.push_back( 7.1 );
	myDlist2.push_back( 1.4 );

	myDlist.sort();
	myDlist2.sort();

	myDlist.merge( myDlist2 );
	printContainer_list( myDlist, "myList" );

	myDlist2.push_back( 2.1 );

	myDlist.merge( myDlist2, mycomparison );
	printContainer_list( myDlist, "myList" );
	std::cout << std::endl;

	// reverse
	myList.clear();

	for ( int i = 1; i < 10; i++ )
		myList.push_back( i );

	myList.reverse();

	printContainer_list( myList, "myList" );
	std::cout << std::endl;
}

void	non_member() {

	std::cout << "************************ Non_member *************************" << std::endl;

	// relational operators
	int	myInts[] = { 10, 20, 30 };
	int myInts2[] = { 30, 20, 10 };

	ft::list<int> a( myInts, myInts + sizeof( myInts ) / sizeof( int ) );
	ft::list<int> b( myInts, myInts + sizeof( myInts ) / sizeof( int ) );
	ft::list<int> c( myInts2, myInts2 + sizeof( myInts2 ) / sizeof( int ) );

	printContainer_list( a, "a" );
	printContainer_list( b, "b" );
	printContainer_list( c, "c" );

	std::cout << std::endl;

	if ( a == b ) std::cout << "a and b are equal"				 << std::endl;
	if ( b != c ) std::cout << "b and c are not equal"			 << std::endl;
	if ( b <  c ) std::cout << "b is less than c"				 << std::endl;
	if ( c >  b ) std::cout << "c is greater than b"			 << std::endl;
	if ( a <= b ) std::cout << "a is less than or equal to b"	 << std::endl;
	if ( a >= b ) std::cout << "a is greater than or equal to b" << std::endl;

	std::cout << std::endl;

	// swap

	ft::list<int>	foo( 3, 100 );
	ft::list<int>	bar( 5, 200 );

	ft::swap( foo, bar );

	printContainer_list( foo, "foo" );
	printContainer_list( bar, "bar" );

	std::cout << std::endl;
}

template< typename T >
void	printContainer_vector( const T & con, const char* str = "myVector" ) {

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

	printContainer_vector( myVector );

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

void	reverse_iterators_vector() {

	std::cout << "******************** Reverse iterators ********************" << std::endl;

	// ******************** Constructors ********************

	ft::vector<int>	myVector;

	for ( int i = 0; i < 10; i++ )
		myVector.push_back( i );

	typedef ft::vector<int>::iterator iter_type;

	iter_type							from( myVector.begin() );
	iter_type							until( myVector.end() );

	ft::reverse_iterator<iter_type>	rev_until( from );
	ft::reverse_iterator<iter_type>	rev_from( until );

	std::cout << "myVector:";
	while ( rev_from != rev_until )
		std::cout << ' ' << *rev_from++;
	std::cout << std::endl;

	// ******************** base ********************

	ft::reverse_iterator<iter_type>	rev_end( myVector.begin() );
	ft::reverse_iterator<iter_type>	rev_begin( myVector.end() );

	std::cout << "myVector:";
	for ( iter_type it = rev_end.base(); it != rev_begin.base(); ++it )
		std::cout << ' ' << *it;
	std::cout << std::endl;

	from = myVector.begin();
	until = myVector.end();

	// ******************** operator * ********************
	ft::reverse_iterator<iter_type>	rev_until2( from );
	ft::reverse_iterator<iter_type> rev_from2( until );

	std::cout << "myVector:";
	while ( rev_from2 != rev_until2 )
		std::cout << ' ' << *rev_from2++;
	std::cout << std::endl;

	// ******************** operator + ********************

	ft::reverse_iterator<iter_type>	rev_it;

	rev_it = myVector.rbegin() + 3;
	std::cout << "The fourth element from the end is: " << *rev_it << std::endl;

	// ******************** operator += ********************

	ft::reverse_iterator<iter_type>	rev_iterator = myVector.rbegin();

	rev_iterator += 2;

	std::cout << "The third element from the end is: " << *rev_iterator << std::endl;

	// ******************** operator - ********************

	rev_iterator = myVector.rend() - 3;

	std::cout << "myVector.rend()-3 points to: " << *rev_iterator << std::endl;

	// ******************** operator -- ********************

	ft::reverse_iterator<iter_type>	rev_begin2( myVector.end() );
	ft::reverse_iterator<iter_type>	rev_end2( myVector.begin() );

	rev_iterator = rev_begin2;

	while ( rev_iterator != rev_end )
		std::cout << *rev_iterator++ << ' ';
	std::cout << std::endl;

	while ( rev_iterator != rev_begin )
		std::cout << *(--rev_iterator) << ' ';
	std::cout << std::endl;

	// ******************** operator -= ********************

	rev_iterator = myVector.rend();

	rev_iterator -= 4;

	std::cout << "rev_iterator now points to: " << *rev_iterator << std::endl;

	// ******************** operator [] ********************

	rev_iterator = myVector.rbegin();

	std::cout << "The fourth element from the end is: " << rev_iterator[3] << std::endl << std::endl;

	// ******************** relational operators ********************

	ft::reverse_iterator<iter_type>	rev_iterator1 = myVector.rend() - 5;
	ft::reverse_iterator<iter_type>	rev_iterator2 = myVector.rbegin() + 4;
	ft::reverse_iterator<iter_type>	rev_iterator3 = myVector.rend() - 3;

	std::cout << "rev_iterator1 =\t" << *rev_iterator1 << std::endl;
	std::cout << "rev_iterator2 =\t" << *rev_iterator2 << std::endl;
	std::cout << "rev_iterator3 =\t" << *rev_iterator3 << std::endl << std::endl;

	std::cout << std::boolalpha;
	std::cout << "rev_iterator1 != rev_iterator2:\t" << (rev_iterator1 != rev_iterator2) << std::endl;
	std::cout << "rev_iterator1 == rev_iterator2:\t" << (rev_iterator1 == rev_iterator2) << std::endl;
	std::cout << "rev_iterator2 == rev_iterator3:\t" << (rev_iterator2 == rev_iterator3) << std::endl;
	std::cout << "rev_iterator1 <  rev_iterator2:\t" << (rev_iterator1 <  rev_iterator2) << std::endl;
	std::cout << "rev_iterator1 <= rev_iterator2:\t" << (rev_iterator1 <= rev_iterator2) << std::endl;
	std::cout << "rev_iterator1 >  rev_iterator2:\t" << (rev_iterator1 >  rev_iterator2) << std::endl;
	std::cout << "rev_iterator1 >= rev_iterator2:\t" << (rev_iterator1 >= rev_iterator2) << std::endl;
	std::cout << "rev_iterator2 <= rev_iterator3:\t" << (rev_iterator2 <= rev_iterator3) << std::endl;
	std::cout << "rev_iterator2 >= rev_iterator3:\t" << (rev_iterator2 >= rev_iterator3) << std::endl;
	std::cout << "rev_iterator2 <  rev_iterator3:\t" << (rev_iterator2 <  rev_iterator3) << std::endl;
	std::cout << "rev_iterator2 >  rev_iterator3:\t" << (rev_iterator2 >  rev_iterator3) << std::endl << std::endl;

	// ******************** operator + (non member) ********************

	rev_it = 3 + myVector.rbegin();

	std::cout << "The fourth element from the end is: " << *rev_it << std::endl << std::endl;

	// ******************** operator - (non member) ********************

	rev_from = myVector.rbegin();
	rev_until = myVector.rend();

	std::cout << "myVector has " << (rev_until - rev_from) << " elements." << std::endl << std::endl;
}

void	constructors_vector() {

	std::cout << "*********************** Constructors ************************" << std::endl;

	ft::vector<int> first;
	ft::vector<int> second( 4, 100 );
	ft::vector<int> third( second.begin(), second.end() );
	ft::vector<int> fourth( third );

	int	myInts[] = { 16, 2, 77, 29 };
	ft::vector<int> fifth( myInts, myInts + sizeof( myInts ) / sizeof( int ) );

	ft::vector<int> sixth;
	sixth = fifth;

	first.push_back( 15 );
	first.push_back( 42 );

	printContainer_vector( first, "the contents of the first are" );
	printContainer_vector( second, "the contents of the second are" );
	printContainer_vector( third, "the contents of the third are" );

	third.clear();

	printContainer_vector( fourth, "the contents of the fourth are" );
	printContainer_vector( fifth, "the contents of the fifth are" );

	fifth.clear();

	printContainer_vector( sixth, "the contents of the sixth are" );
	std::cout << std::endl;
}

void 	push_pop_front_back_vector() {

	std::cout << "******************** push_pop_front_back ********************" << std::endl;

	ft::vector<int>	myVector;

	myVector.push_back( 15 );
	myVector.push_back( 28 );
	myVector.push_back( 42 );

	printContainer_vector( myVector );

	myVector.push_back( 7 );
	myVector.push_back( 5 );
	myVector.push_back( 3 );

	printContainer_vector( myVector );
	std::cout << std::endl;

	std::cout << "front:  " << myVector.front() << std::endl;
	std::cout << "back:   " << myVector.back() << std::endl << std::endl;

	myVector.pop_back();
	printContainer_vector( myVector );

	myVector.pop_back();
	printContainer_vector( myVector );

	myVector.pop_back();
	printContainer_vector( myVector );

	myVector.pop_back();
	printContainer_vector( myVector );

	myVector.pop_back();
	printContainer_vector( myVector );
}

void	capacity_vector() {

	std::cout << "************************* Capacity **************************" << std::endl;

	// empty
	ft::vector<int>	myVector;
	int				sum = 0;

	for ( int i = 1; i <= 10; ++i )
		myVector.push_back( i );
	while ( !myVector.empty() ) {

		sum += myVector.back();
		myVector.pop_back();
	}
	std::cout << "total: " << sum << std::endl;

	// size
	ft::vector<int>	myInts;
	std::cout << "0. size: " << myInts.size() << std::endl;

	for ( int i = 0; i < 10; i++ )
		myInts.push_back( i );
	std::cout << "1. size: " << myInts.size() << std::endl;

	myInts.pop_back();
	std::cout << "2. size: " << myInts.size() << std::endl;

	// max_size

	ft::vector<int>	numbers;

	if ( numbers.max_size() > 1000 ) {

		for ( int i = 0; i < 1000; i++ )
			numbers.push_back( 0 );
		std::cout << "The vector contains 1000 elements." << std::endl;
	}
	else
		std::cout << "The vector could not hold 1000 elements." << std::endl;
	std::cout << std::endl;

	// capacity
	ft::vector<int>	myVector2;

	for ( int i = 0; i < 100; i++ )
		myVector2.push_back( i );

	std::cout << "size: " << myVector2.size() << std::endl;
	std::cout << "capacity: " << myVector2.capacity() << std::endl;

	// resize
	ft::vector<int>	myVector3;

	for ( int i = 1; i <= 10; ++i )
		myVector3.push_back( i );
	std::cout << std::endl;

	myVector3.resize( 5 );
	myVector3.resize( 8, 100 );
	myVector3.resize( 12 );

	printContainer_vector( myVector3 );

	// reserve
	ft::vector<int>::size_type	sz;

	ft::vector<int>	foo;
	sz = foo.capacity();

	std::cout << "Making foo grow:" << std::endl;
	for ( int i = 0; i < 100; ++i ) {
		foo.push_back(i);
		if ( sz != foo.capacity() ) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << std::endl;
		}
	}

	ft::vector<int>	bar;
	sz = bar.capacity();

	bar.reserve( 100 );

	std::cout << "Making bar grow:" << std::endl;
	for ( int i = 0; i < 100; ++i ) {
		bar.push_back(i);
		if ( sz != bar.capacity() ) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << std::endl;
		}
	}
	std::cout << std::endl;
}

void	element_access_vector() {

	std::cout << "*********************** element_access **********************" << std::endl;

	// operator[]
	ft::vector<int>	myVector( 10 );

	ft::vector<int>::size_type	sz = myVector.size();

	for ( size_t i = 0; i < sz; i++ )
		myVector[i] = i;

	for ( size_t i = 0; i < sz / 2; i++ ) {

		int	temp;
		temp = myVector[sz-1-i];
		myVector[sz-1-i] = myVector[i];
		myVector[i] = temp;
	}
	printContainer_vector( myVector );
	std::cout << std::endl;

	// at
	for ( size_t i = 0; i < myVector.size(); i++ )
		myVector.at( i ) = i;

	printContainer_vector( myVector );
	std::cout << std::endl;

	// front
	ft::vector<int>	myVector2;

	myVector2.push_back( 78 );
	myVector2.push_back( 16 );

	myVector2.front() -= myVector2.back();

	std::cout << "myVector.front() is now " << myVector2.front() << std::endl << std::endl;

	// back
	myVector2.pop_back();
	myVector2.pop_back();

	myVector2.push_back( 10 );

	while ( myVector2.back() != 0 )
		myVector2.push_back( myVector2.back() - 1 );

	printContainer_vector( myVector2 );
	std::cout << std::endl;
}

void	modifiers_vector() {

	std::cout << "************************* Modifiers *************************" << std::endl;

	// clear
	ft::vector<int> myVector;

	myVector.push_back(100);
	myVector.push_back(200);
	myVector.push_back(300);

	printContainer_vector( myVector );

	myVector.clear();
	myVector.push_back(1101);
	myVector.push_back(2202);

	printContainer_vector( myVector );
	std::cout << std::endl;

	// assign
	ft::vector<int>	first;
	ft::vector<int>	second;
	ft::vector<int>	third;

	first.assign( 7, 100 );

	ft::vector<int>::iterator it;
	it = first.begin() + 1;

	second.assign( it, first.end() - 1 );

	int 	myints[] = { 1776, 7, 4 };
	third.assign( myints, myints + 3 );

	std::cout << "Size of first: " << int ( first.size() ) << std::endl;
	std::cout << "Size of second: " << int( second.size() ) << std::endl;
	std::cout << "Size of third: " << int( third.size() ) << std::endl << std::endl;

	// insert
	ft::vector<int>	myVector2( 3, 100 );

	it = myVector2.begin();
	it = myVector2.insert( it, 200 );

	myVector2.insert( it, 2, 300 );
	it = myVector2.begin();

	ft::vector<int>	anotherVector( 2, 400 );
	myVector2.insert( it + 2, anotherVector.begin(), anotherVector.end() );

	int	myInts[] = { 501, 502, 503 };
	myVector2.insert( myVector2.begin(), myInts, myInts + 3 );

	printContainer_vector( myVector2 );
	std::cout << std::endl;

	// erase
	myVector.clear();

	for ( int i = 1; i <= 10; i++ )
		myVector.push_back( i );

	myVector.erase( myVector.begin() + 5 );
	printContainer_vector( myVector );

	it = myVector.erase( myVector.begin(), myVector.begin() + 3 );
	printContainer_vector( myVector );
	std::cout << std::endl;

	// swap
	ft::vector<int>	foo( 3, 100 );
	ft::vector<int>	bar( 5, 200 );

	foo.swap( bar );

	printContainer_vector( foo, "foo" );
	printContainer_vector( bar, "bar" );
}

void	non_member_vector() {

	std::cout << "************************ Non_member *************************" << std::endl;

	// relational operators
	ft::vector<int> foo (3,100);
	ft::vector<int> bar (2,200);

	if (foo==bar) std::cout << "foo and bar are equal" << std::endl;
	if (foo!=bar) std::cout << "foo and bar are not equal" << std::endl;
	if (foo< bar) std::cout << "foo is less than bar" << std::endl;
	if (foo> bar) std::cout << "foo is greater than bar" << std::endl;
	if (foo<=bar) std::cout << "foo is less than or equal to bar" << std::endl;
	if (foo>=bar) std::cout << "foo is greater than or equal to bar" << std::endl;

	std::cout << std::endl;

	// swap
	ft::swap( foo, bar );

	printContainer_vector( foo, "foo contains" );
	printContainer_vector( bar, "bar contains" );
	std::cout << std::endl;
}

void	empty_stack() {

	ft::stack<int>	myStack;
	int 			sum = 0;

	for ( int i = 1; i <= 10; i++ )
		myStack.push( i );

	while ( !myStack.empty() ) {

		sum += myStack.top();
		myStack.pop();
	}

	std::cout << "total: " << sum << std::endl << std::endl;
}

void	size_stack() {

	ft::stack<int>	myInts;

	std::cout << "0. size: " << myInts.size() << std::endl;

	for ( int i = 0; i < 5; i++ )
		myInts.push( i );

	std::cout << "1. size: " << myInts.size() << std::endl;

	myInts.pop();
	std::cout << "2. size: " << myInts.size() << std::endl << std::endl;
}

void	top_stack() {

	ft::stack<int>	myStack;

	myStack.push( 10 );
	myStack.push( 20 );

	myStack.top() -= 5;

	std::cout << "myStack.top() is now " << myStack.top() << std::endl << std::endl;
}

void	push_pop_stack() {

	ft::stack<int>	myStack;

	for ( int i = 0; i < 5; i++ )
		myStack.push( i );

	std::cout << "Popping out elements...";
	while ( !myStack.empty() ) {

		std::cout << ' ' << myStack.top();
		myStack.pop();
	}
	std::cout << std::endl << std::endl;
}

void	non_member_stack() {

	ft::stack<int> foo;
	ft::stack<int> bar;

	for ( int i = 0; i < 3; i++ )
		foo.push( 100 );

	bar.push( 200 );
	bar.push( 200 );

	if (foo==bar) std::cout << "foo and bar are equal" << std::endl;
	if (foo!=bar) std::cout << "foo and bar are not equal" << std::endl;
	if (foo< bar) std::cout << "foo is less than bar" << std::endl;
	if (foo> bar) std::cout << "foo is greater than bar" << std::endl;
	if (foo<=bar) std::cout << "foo is less than or equal to bar" << std::endl;
	if (foo>=bar) std::cout << "foo is greater than or equal to bar" << std::endl;
	std::cout << std::endl;
}

void	empty_queue() {

	ft::queue<int>	myQueue;

	int 			sum = 0;

	for ( int i = 1; i <= 10; i++ ) {
		myQueue.push( i );
	}


	while ( !myQueue.empty() ) {

		sum += myQueue.front();
		myQueue.pop();
	}

	std::cout << "total: " << sum << std::endl << std::endl;
}

void	size_queue() {

	ft::queue<int>	myInts;

	std::cout << "0. size: " << myInts.size() << std::endl;

	for ( int i = 0; i < 5; i++ )
		myInts.push( i );
	std::cout << "1. size: " << myInts.size() << std::endl;

	myInts.pop();
	std::cout << "2. size: " << myInts.size() << std::endl << std::endl;
}

void	front_queue() {

	ft::queue<int>	myQueue;

	myQueue.push( 77 );
	myQueue.push( 16 );

	myQueue.front() -= myQueue.back();

	std::cout << "myQueue.front() is now " << myQueue.front() << std::endl << std::endl;
}

void	back_queue() {

	ft::queue<int>	myQueue;

	myQueue.push( 12 );
	myQueue.push( 75 );

	myQueue.back() -= myQueue.front();

	std::cout << "myQueue.back() is now " << myQueue.back() << std::endl << std::endl;
}

void	push_pop_queue() {

	ft::queue<int>	myQueue;

	for ( int i = 1; i <= 10; i++ )
		myQueue.push( i );

	std::cout << "myQueue contains:";
	while ( !myQueue.empty() ) {

		std::cout << ' ' << myQueue.front();
		myQueue.pop();
	}
	std::cout << std::endl << std::endl;
}

void	non_member_queue() {

	int	myInts[] = { 10, 20, 30 };
	int myInts2[] = { 30, 20, 10 };

	ft::queue<int> a;
	ft::queue<int> b;
	ft::queue<int> c;

	for ( int i = 0; i < 3; i++ ) a.push( myInts[i] );
	for ( int i = 0; i < 3; i++ ) b.push( myInts[i] );
	for ( int i = 0; i < 3; i++ ) c.push( myInts2[i] );

	if ( a == b ) std::cout << "a and b are equal"				 << std::endl;
	if ( b != c ) std::cout << "b and c are not equal"			 << std::endl;
	if ( b <  c ) std::cout << "b is less than c"				 << std::endl;
	if ( c >  b ) std::cout << "c is greater than b"			 << std::endl;
	if ( a <= b ) std::cout << "a is less than or equal to b"	 << std::endl;
	if ( a >= b ) std::cout << "a is greater than or equal to b" << std::endl;
	std::cout << std::endl;
}


template< typename T >
void	printContainer_map( const T & con, const char* str = "myMap" ) {

	std::cout << str << ":";
	for ( typename T::const_iterator it = con.begin(); it != con.end(); ++it )
		std::cout << ' ' << it->first << ':' << it->second << ' ';
	std::cout << std::endl;
}

void	pair() {

	std::cout << "*************************** Pair ****************************" << std::endl;

	// constructors
	ft::pair<std::string, double>	product1;
	ft::pair<std::string, double>	product2( "pears", 2.30 );
	ft::pair<std::string, double>	product3( product2 );

	product1 = ft::make_pair( std::string( "soap" ), 0.99 );

	product2.first = "pants";
	product2.second = 39.90;

	std::cout << "The price of " << product1.first << " is $" << product1.second << std::endl;
	std::cout << "The price of " << product2.first << " is $" << product2.second << std::endl;
	std::cout << "The price of " << product3.first << " is $" << product3.second << std::endl << std::endl;

	// operator=
	ft::pair<std::string, int>		planet;
	ft::pair<std::string, int>		homePlanet;

	planet = ft::make_pair( "Earth", 6371 );

	homePlanet = planet;

	std::cout << "Home planet: " << homePlanet.first << std::endl;
	std::cout << "Planet size: " << homePlanet.second << std::endl << std::endl;

	// relational operators
	ft::pair<int, char>	foo( 10, 'z' );
	ft::pair<int, char>	bar( 90, 'a' );

	if ( foo == bar ) std::cout << "foo and bar are equal" << std::endl;
	if ( foo != bar ) std::cout << "foo and bar are not equal" << std::endl;
	if ( foo <  bar ) std::cout << "foo is less than bar" << std::endl;
	if ( foo >  bar ) std::cout << "foo is greater than bar" << std::endl;
	if ( foo <= bar ) std::cout << "foo is less than or equal to bar" << std::endl;
	if ( foo >= bar ) std::cout << "foo is greater than or equal to bar" << std::endl << std::endl;
}

bool	fnComp( char lhs, char rhs ) { return lhs < rhs; }

struct	classComp {
	bool	operator() ( const char& lhs, const char& rhs ) const { return lhs < rhs; }
};

void	constructors_map() {

	std::cout << "*********************** Constructors ************************" << std::endl;

	ft::map<char, int>	first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	ft::map<char, int>	second( first.begin(), first.end() );
	ft::map<char, int>	third( second );

	ft::map<char, int, classComp>	fourth;

	fourth['a'] = 10;
	fourth['b'] = 30;
	fourth['c'] = 50;
	fourth['d'] = 70;

	bool( *fn_ptr )( char, char ) = fnComp;
	ft::map<char, int, bool(*)( char, char )>	fifth( fn_ptr );

	fifth['a'] = 10;
	fifth['b'] = 30;
	fifth['c'] = 50;
	fifth['d'] = 70;

	ft::map<char, int>	sixth;
	sixth = third;

	printContainer_map( first, "first" );
	printContainer_map( second, "second" );

	second.clear();

	printContainer_map( third, "third" );
	printContainer_map( fourth, "fourth" );
	printContainer_map( fifth, "fifth" );

	third.clear();

	printContainer_map( sixth, "sixth" );

	std::cout << std::endl;
}

void	iterator_print( ft::map<int, char> &myMap ) {

	std::cout << "myMap:";
	for ( ft::map<int, char>::const_iterator it = myMap.begin(); it != myMap.end(); it++ ) {
		std::cout << ' ' << it->first << ':' << it->second << ' ';
	}
	std::cout << std::endl;

	std::cout << "myMap:";
	for ( ft::map<int, char>::const_iterator it = --myMap.end(); it != myMap.begin(); it-- )
		std::cout << ' ' << it->first << ':' << it->second << ' ';
	std::cout << std::endl;

	std::cout << "myMap:";
	for ( ft::map<int, char>::iterator it = myMap.begin(); it != myMap.end(); it++ ) {
		std::cout << ' ' << it->first << ':' << it->second << ' ';
	}
	std::cout << std::endl;

	std::cout << "myMap:";
	for ( ft::map<int, char>::iterator it = --myMap.end(); it != myMap.begin(); it-- )
		std::cout << ' ' << it->first << ':' << it->second << ' ';
	std::cout << std::endl << std::endl;
}

void	iterators_map() {

	std::cout << "************************* iterators *************************" << std::endl;

	ft::map<int, char>	myMap;

	std::cout << "myMap:";
	for ( ft::map<int, char>::const_iterator it = myMap.begin(); it != myMap.end(); it++ ) {
		std::cout << ' ' << it->first << ':' << it->second << ' ';
	}
	std::cout << std::endl << std::endl;


/* 			 15
 * 			/  \
*/

	myMap.insert( ft::pair<int, char>( 15, 'm' ) );
	iterator_print( myMap );

/* 			 15
 * 		   /    \
 * 		  10
*/

	myMap.insert( ft::pair<int, char>( 10, 'o' ) );
	iterator_print( myMap );

/* 			 15
 * 		   /    \
 * 		  10
 * 		 /
 *		8
*/

	myMap.insert( ft::pair<int, char>( 8, 'g' ) );
	iterator_print( myMap );

/* 			 15
 * 		   /    \
 * 		  10
 * 		    \
 *		     12
*/

	ft::map<int, char>	myMap2;
	myMap2.insert( ft::pair<int, char>( 15, 'm' ) );
	myMap2.insert( ft::pair<int, char>( 10, 'o' ) );
	myMap2.insert( ft::pair<int, char>( 12, 'e' ) );
	iterator_print( myMap2 );



/* 			 15
 * 		   /    \
 * 		  10
 * 		 /  \
 *		8    12
*/

	myMap.insert( ft::pair<int, char>( 12, 'e' ) );
	iterator_print( myMap );

/* 			 15
 * 		   /    \
 * 		  10     20
*/

	ft::map<int, char>	myMap3;
	myMap3.insert( ft::pair<int, char>( 15, 'm' ) );
	myMap3.insert( ft::pair<int, char>( 10, 'o' ) );
	myMap3.insert( ft::pair<int, char>( 20, 'h' ) );
	iterator_print( myMap3 );

/* 			 15
 * 		   /    \
 * 		         20
*/

	ft::map<int, char>	myMap4;
	myMap4.insert( ft::pair<int, char>( 15, 'm' ) );
	myMap4.insert( ft::pair<int, char>( 20, 'h' ) );
	iterator_print( myMap4 );

/* 			 15
 * 		   /    \
 * 		         20
 * 	               \
 *		            25
*/

	myMap4.insert( ft::pair<int, char>( 25, 'b' ) );
	iterator_print( myMap4 );

/* 			 15
 * 		   /    \
 * 		         20
 * 		       /
 *		      18
*/

	ft::map<int, char>	myMap5;
	myMap5.insert( ft::pair<int, char>( 15, 'm' ) );
	myMap5.insert( ft::pair<int, char>( 20, 'h' ) );
	myMap5.insert( ft::pair<int, char>( 18, 'i' ) );
	iterator_print( myMap5 );


/* 			 15
 * 		   /    \
 * 		         20
 * 		       /    \
 *		      18     25
*/

	myMap4.insert( ft::pair<int, char>( 18, 'i' ) );
	iterator_print( myMap4 );

/* 			   15
 * 		    /     \
 * 		  10       20
 * 		 /  \     /  \
 *		8    12 18    25
*/

	myMap.insert( ft::pair<int, char>( 20, 'h' ) );
	myMap.insert( ft::pair<int, char>( 18, 'i' ) );
	myMap.insert( ft::pair<int, char>( 25, 'b' ) );
	iterator_print( myMap );

	// Extra


	ft::map<int, char>::iterator	from( myMap.begin() );
	ft::map<int, char>::iterator 	until( myMap.end() );

	ft::map<int, char>::iterator	from2( from );
	ft::map<int, char>::iterator 	until2( until );

	std::cout << "myMap:";
	while ( from != until ) {
		std::cout << ' ' << from->first;
		from++;
	}
	std::cout << std::endl;

	std::cout << "myMap:";
	while ( from2 != until2 ) {
		std::cout << ' ' << from2->first;
		from2++;
	}
	std::cout << std::endl;

	ft::map<int, char>::iterator		it = myMap.begin();

	std::cout << "begin:\t\t" << it->first << std::endl;
	it++;
	std::cout << "begin++:\t" << it->first << std::endl;
	it--;
	std::cout << "begin--:\t" << it->first << std::endl;

	ft::map<int, char>::iterator		compare = myMap.begin();

	if ( compare == it )
		std::cout << "Equal" << std::endl;
	else
		std::cout << "Not equal" << std::endl;

	compare++;

	if ( compare == it )
		std::cout << "Equal" << std::endl;
	else
		std::cout << "Not equal" << std::endl;

	std::cout << "myMap:";
	for ( ft::map<int, char>::const_iterator it2( it ); it2 != myMap.end(); it2++ )
		std::cout << ' ' << it2->first;
	std::cout << std::endl << std::endl;
}

void 	reverse_iterators_map() {

	std::cout << "******************** Reverse iterators **********************" << std::endl;

	// ******************** Constructors ********************

	ft::map<int, char>	myMap;

	myMap.insert( ft::pair<int, char>( 15, 'm' ) );
	myMap.insert( ft::pair<int, char>( 10, 'o' ) );
	myMap.insert( ft::pair<int, char>( 20, 'h' ) );
	myMap.insert( ft::pair<int, char>( 8, 'g' ) );
	myMap.insert( ft::pair<int, char>( 12, 'e' ) );
	myMap.insert( ft::pair<int, char>( 18, 'i' ) );
	myMap.insert( ft::pair<int, char>( 25, 'b' ) );

	typedef ft::map<int, char>::iterator iter_type;

	iter_type							from( myMap.begin() );
	iter_type							until( myMap.end() );

	ft::reverse_iterator<iter_type>	rev_until( from );
	ft::reverse_iterator<iter_type>	rev_from( until );

	std::cout << "myMap:";
	while ( rev_from != rev_until ) {

		std::cout << ' ' << (*rev_from).first;
		rev_from++;
	}
	std::cout << std::endl;

	// ******************** base ********************

	ft::reverse_iterator<iter_type>	rev_end( myMap.begin() );
	ft::reverse_iterator<iter_type>	rev_begin( myMap.end() );

	std::cout << "myMap:";
	for ( iter_type it = rev_end.base(); it != rev_begin.base(); ++it )
		std::cout << ' ' << (*it).first;
	std::cout << std::endl;

	from = myMap.begin();
	until = myMap.end();

	// ******************** operator * ********************
	ft::reverse_iterator<iter_type>	rev_until2( from );
	ft::reverse_iterator<iter_type> rev_from2( until );

	std::cout << "myMap:";
	while ( rev_from2 != rev_until2 )
		std::cout << ' ' << (*rev_from2++).first;
	std::cout << std::endl;


	// ******************** operator -- ********************

	ft::reverse_iterator<iter_type>	rev_iterator = myMap.rbegin();
	ft::reverse_iterator<iter_type>	rev_begin2( myMap.end() );
	ft::reverse_iterator<iter_type>	rev_end2( myMap.begin() );

	rev_iterator = rev_begin2;

	while ( rev_iterator != rev_end )
		std::cout << (*rev_iterator++).first << ' ';
	std::cout << std::endl;

	while ( rev_iterator != rev_begin )
		std::cout << (*--rev_iterator).first << ' ';
	std::cout << std::endl;

	// ******************** operator -> ********************

	ft::map<int, std::string>	numbers;

	numbers.insert( ft::make_pair( 1, "one" ) );
	numbers.insert( ft::make_pair( 2, "two" ) );
	numbers.insert( ft::make_pair( 3, "three" ) );

	ft::map<int, std::string>::reverse_iterator rev_end5( numbers.begin() );
	ft::map<int, std::string>::reverse_iterator rev_iterator5( numbers.end() );

	for ( ; rev_iterator5 != rev_end5; ++rev_iterator5 )
		std::cout << rev_iterator5->first << ' ' << rev_iterator5->second << std::endl;

	// ******************** relational operators ********************

	ft::reverse_iterator<iter_type>	rev_iterator1 = --myMap.rend();
	ft::reverse_iterator<iter_type>	rev_iterator2 = myMap.rbegin();
	ft::reverse_iterator<iter_type>	rev_iterator3 = --myMap.rend();

	std::cout << "rev_iterator1 =\t" << (*rev_iterator1).first << std::endl;
	std::cout << "rev_iterator2 =\t" << (*rev_iterator2).first << std::endl;
	std::cout << "rev_iterator3 =\t" << (*rev_iterator3).first << std::endl << std::endl;

	std::cout << std::boolalpha;
	std::cout << "rev_iterator1 != rev_iterator2:\t" << (rev_iterator1 != rev_iterator2) << std::endl;
	std::cout << "rev_iterator1 == rev_iterator2:\t" << (rev_iterator1 == rev_iterator2) << std::endl;
	std::cout << "rev_iterator2 == rev_iterator3:\t" << (rev_iterator2 == rev_iterator3) << std::endl << std::endl;
}

void	capacity_map() {

	std::cout << "************************* Capacity **************************" << std::endl;

	// empty
	ft::map<char, int>	myMap;

	myMap['a']=10;
	myMap['b']=20;
	myMap['c']=30;

	while ( !myMap.empty() ) {

		std::cout << myMap.begin()->first << " => " << myMap.begin()->second << std::endl;
		myMap.erase( myMap.begin() );
	}
	std::cout << std::endl;

	// size
	myMap['a']=101;
	myMap['b']=202;
	myMap['c']=302;

	std::cout << "myMap.size() is " << myMap.size() << std::endl << std::endl;

	// max_size
	ft::map<int, int>	numbers;

	if ( numbers.max_size() > 1000 ) {

		for ( int i = 0; i < 1000; i++ )
			numbers[i] = 0;
		std::cout << "The map contains 1000 elements." << std::endl;
	}
	else
		std::cout << "The map could not hold 1000 elements." << std::endl;
	std::cout << std::endl;
}

void	element_access_map() {

	std::cout << "********************** Element_access ***********************" << std::endl;

	// operator[]
	ft::map<char, std::string>	myMap;

	myMap['a']="an element";
	myMap['b']="another element";
	myMap['c']=myMap['b'];

	std::cout << "myMap['a'] is " << myMap['a'] << std::endl;
	std::cout << "myMap['b'] is " << myMap['b'] << std::endl;
	std::cout << "myMap['c'] is " << myMap['c'] << std::endl;
	std::cout << "myMap['d'] is " << myMap['d'] << std::endl;

	std::cout << "myMap now contains " << myMap.size() << " elements." << std::endl << std::endl;
}

void	modifiers_map() {

	std::cout << "************************* Modifiers *************************" << std::endl;

	// insert
	ft::map<char, int>	myMap;

	myMap.insert( ft::pair<char, int>( 'a', 100 ) );
	myMap.insert( ft::pair<char, int>( 'z', 200 ) );

	ft::pair<ft::map<char, int>::iterator, bool> ret;
	ret = myMap.insert( ft::pair<char, int>( 'z', 500 ) );
	if ( ret.second == false ) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << std::endl;
	}

	ft::map<char, int>::iterator it = myMap.begin();
	myMap.insert( it, ft::pair<char, int>( 'b', 300 ) );
	myMap.insert( it, ft::pair<char, int>( 'c', 400 ) );

	ft::map<char, int>	anotherMap;
	anotherMap.insert( myMap.begin(), myMap.find( 'c' ) );

	std::cout << "myMap contains:" << std::endl;
	for ( it = myMap.begin(); it != myMap.end(); ++it )
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "anotherMap contains:" << std::endl;
	for ( it = anotherMap.begin(); it != anotherMap.end(); ++it )
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << std::endl;

	// erase

	ft::map<char, int>	myMap2;

	myMap2['a'] = 10;
	myMap2['b'] = 20;
	myMap2['c'] = 30;
	myMap2['d'] = 40;
	myMap2['e'] = 50;
	myMap2['f'] = 60;

	it = myMap2.find( 'b' );
	myMap2.erase( it );

	myMap2.erase( 'c' );

	it = myMap2.find( 'e' );
	myMap2.erase( it, myMap2.end() );

	for ( it = myMap2.begin(); it != myMap2.end(); ++it )
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << std::endl;

	// swap
	ft::map<char, int> foo, bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	foo.swap( bar );

	std::cout << "foo contains:" << std::endl;
	for ( it = foo.begin(); it != foo.end(); ++it )
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "bar contains:" << std::endl;
	for ( it = bar.begin(); it != bar.end(); ++it )
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << std::endl;

	// clear
	ft::map<char, int>	myMap3;

	myMap3['x'] = 100;
	myMap3['y'] = 200;
	myMap3['z'] = 300;

	std::cout << "myMap3 contains:" << std::endl;
	for ( it = myMap3.begin(); it != myMap3.end(); ++it )
		std::cout << it->first << " => " << it->second << std::endl;

	myMap3.clear();
	myMap3['a'] = 1101;
	myMap3['b'] = 2202;

	std::cout << "myMap3 contains:" << std::endl;
	for ( it = myMap3.begin(); it != myMap3.end(); ++it )
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << std::endl;
}

void	observers_map() {

	std::cout << "************************* Observers *************************" << std::endl;

	// key_comp
	ft::map<char, int>	myMap;

	ft::map<char, int>::key_compare	myComp = myMap.key_comp();

	myMap['a'] = 100;
	myMap['b'] = 200;
	myMap['c'] = 300;

	std::cout << "myMap contains:" << std::endl;

	char	highest = myMap.rbegin()->first;
	ft::map<char, int>::iterator it = myMap.begin();

	do {
		std::cout << it->first << " => " << it->second << std::endl;
	} while ( myComp((*it++).first, highest) );
	std::cout << std::endl;

	// value_comp
	ft::map<char, int>	myMap2;

	myMap2['x'] = 1001;
	myMap2['y'] = 2002;
	myMap2['z'] = 3003;

	std::cout << "myMap contains:" << std::endl;

	ft::pair<char, int>	highest2 = *myMap2.rbegin();
	ft::map<char, int>::iterator it2 = myMap2.begin();

	do {
		std::cout << it2->first << " => " << it2->second << std::endl;
	} while ( myMap2.value_comp()( *it2++, highest2 ) );
	std::cout << std::endl;
}

void	operations_map() {

	std::cout << "************************* Operations ************************" << std::endl;

	// find
	ft::map<char, int> 				myMap;

	myMap['a']=50;
	myMap['b']=100;
	myMap['c']=150;
	myMap['d']=200;

	std::cout << "elements in myMap:" << std::endl;
	std::cout << "a => " << myMap.find('a')->second << std::endl;
	std::cout << "b => " << myMap.find('b')->second << std::endl;
	std::cout << "c => " << myMap.find('c')->second << std::endl;
	std::cout << "d => " << myMap.find('d')->second << std::endl << std::endl;

	// count
	ft::map<char, int>				myMap2;

	myMap2['a'] = 101;
	myMap2['c'] = 202;
	myMap2['f'] = 303;

	for ( char c = 'a'; c < 'h'; c++ ) {

		std::cout << c;
		if ( myMap2.count( c ) > 0 )
			std::cout << " is an element of myMap." << std::endl;
		else
			std::cout << " is not an element of myMap." << std::endl;
	}
	std::cout << std::endl;

	// lower_bound, upper_bound
	ft::map<char, int>				myMap3;
	ft::map<char, int>::iterator	itlow, itup;

	myMap3['a'] = 20;
	myMap3['b'] = 40;
	myMap3['c'] = 60;
	myMap3['d'] = 80;
	myMap3['e'] = 100;

	itlow = myMap3.lower_bound ( 'b' );
	itup = myMap3.upper_bound ( 'd' );

	myMap3.erase(itlow, itup);

	for (ft::map<char, int>::iterator it=myMap3.begin(); it!=myMap3.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << std::endl;

	// equal_range
	ft::map<char, int>	myMap4;

	myMap4['a'] = 10;
	myMap4['b'] = 20;
	myMap4['c'] = 30;

	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator>	ret;
	ret = myMap4.equal_range( 'b' );

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << std::endl;

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << std::endl << std::endl;
}

void	map_main() {

	std::cout << "/* ************************************************************************** */" << std::endl;
	std::cout << "/*                                       Map                                  */" << std::endl;
	std::cout << "/* ************************************************************************** */" << std::endl << std::endl;

	pair();
	constructors_map();
	iterators_map();
	reverse_iterators_map();
	capacity_map();
	element_access_map();
	modifiers_map();
	observers_map();
	operations_map();
}

void	queue_main() {

	std::cout << "/* ************************************************************************** */" << std::endl;
	std::cout << "/*                                      Queue                                 */" << std::endl;
	std::cout << "/* ************************************************************************** */" << std::endl << std::endl;

	empty_queue();
	size_queue();
	front_queue();
	back_queue();
	push_pop_queue();
	non_member_queue();
}

void	stack_main() {

	std::cout << "/* ************************************************************************** */" << std::endl;
	std::cout << "/*                                      Stack                                 */" << std::endl;
	std::cout << "/* ************************************************************************** */" << std::endl << std::endl;

	empty_stack();
	size_stack();
	top_stack();
	push_pop_stack();
	non_member_stack();
}

void		vector_main() {

	std::cout << "/* ************************************************************************** */" << std::endl;
	std::cout << "/*                                      Vector                                */" << std::endl;
	std::cout << "/* ************************************************************************** */" << std::endl << std::endl;

	iterators_vector();
	reverse_iterators_vector();
	constructors_vector();
	push_pop_front_back_vector();
	capacity_vector();
	element_access_vector();
	modifiers_vector();
	non_member_vector();
}

void 	list_main() {

	std::cout << "/* ************************************************************************** */" << std::endl;
	std::cout << "/*                                       List                                 */" << std::endl;
	std::cout << "/* ************************************************************************** */" << std::endl << std::endl;

	iterators();
	reverse_iterators();
	constructors();
	push_pop_front_back();
	capacity_list();
	modifiers();
	operations();
	non_member();
}

int		main() {

	list_main();
	vector_main();
	stack_main();
	queue_main();
	map_main();

	return 0;
}
