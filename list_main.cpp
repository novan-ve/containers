/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_main.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 17:00:16 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/11/29 17:00:18 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <cmath>

template< typename T >
void	printContainer( const T & con, const char* str ) {

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

	printContainer( myList, "myList" );

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

	printContainer( first, "the contents of the first are" );
	printContainer( second, "the contents of the second are" );
	printContainer( third, "the contents of the third are" );

	third.clear();

	printContainer( fourth, "the contents of the fourth are" );
	printContainer( fifth, "the contents of the fifth are" );

	fifth.clear();

	printContainer( sixth, "the contents of the sixth are" );
	std::cout << std::endl;
}

void 	push_pop_front_back() {

	std::cout << "******************** push_pop_front_back ********************" << std::endl;

	ft::list<int>	myList;

	myList.push_back( 15 );
	myList.push_back( 28 );
	myList.push_back( 42 );

	printContainer( myList, "myList" );

	myList.push_front( 7 );
	myList.push_front( 5 );
	myList.push_front( 3 );

	printContainer( myList, "myList" );
	std::cout << std::endl;

	std::cout << "front:  " << myList.front() << std::endl;
	std::cout << "back:   " << myList.back() << std::endl << std::endl;

	myList.pop_back();
	printContainer( myList, "myList" );

	myList.pop_back();
	printContainer( myList, "myList" );

	myList.pop_back();
	printContainer( myList, "myList" );

	myList.pop_back();
	printContainer( myList, "myList" );

	myList.pop_back();
	printContainer( myList, "myList" );

	myList.push_back( 3 );
	myList.push_back( 5 );
	myList.push_back( 7 );
	myList.push_back( 15 );
	myList.push_back( 28 );
	myList.push_back( 42 );

	myList.pop_front();
	printContainer( myList, "myList" );

	myList.pop_front();
	printContainer( myList, "myList" );

	myList.pop_front();
	printContainer( myList, "myList" );

	myList.pop_front();
	printContainer( myList, "myList" );

	myList.pop_front();
	printContainer( myList, "myList" );

	myList.pop_front();
	printContainer( myList, "myList" );
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

	printContainer( myList, "myList" );

	myList.clear();
	myList.push_back( 1101 );
	myList.push_back( 2202 );

	printContainer( myList, "myList" );

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

	printContainer( myList, "myList" );

	ft::list<int>::iterator it = myList.begin();

	++it;

	myList.insert( it, 10 );
	printContainer( myList, "myList" );

	myList.insert( it, 2, 20 );
	printContainer( myList, "myList" );

	--it;

	ft::list<int>	myList2;

	myList2.push_back( 30 );
	myList2.push_back( 30 );

	myList.insert( it, myList2.begin(), myList2.end() );
	printContainer( myList, "myList" );
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
	printContainer( myList, "myList" );

	++it;
	--it2;

	std::cout << *myList.erase( it, it2 ) << std::endl;
	printContainer( myList, "myList" );

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

	printContainer( first, "first contains" );
	printContainer( second, "second contains" );

	// resize
	myList.clear();

	for ( int i = 1; i < 10; ++i )
		myList.push_back( i );

	myList.resize( 5 );
	myList.resize( 8, 100 );
	myList.resize( 12 );

	printContainer( myList, "myList" );
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
	printContainer( myList, "myList" );

	myList2.splice( myList2.begin(), myList, it );
	printContainer( myList, "myList" );

	it = myList.begin();
	for ( int i = 0; i < 3; i++ )
		it++;

	myList.splice( myList.begin(), myList, it, myList.end() );
	printContainer( myList, "myList" );
	printContainer( myList2, "myList2" );
	std::cout << std::endl;

	// remove
	int		myInts[] = { 17, 89, 7, 89, 14 };

	myList.clear();
	for ( int i = 0; i < 5; i++ )
		myList.push_back( myInts[i] );

	myList.remove( 89 );
	printContainer( myList, "myList" );
	std::cout << std::endl;

	// remove_if
	int		myInts2[] = { 15, 36, 7, 17, 20, 39, 4, 1 };

	myList.clear();
	for ( int i = 0; i < 8; i++ )
		myList.push_back( myInts2[i] );

	myList.remove_if( single_digit );

	myList.remove_if( is_odd() );

	printContainer( myList, "myList" );
	std::cout << std::endl;

	// sort
	ft::list<std::string>	mySlist;

	mySlist.push_back( "one" );
	mySlist.push_back( "two" );
	mySlist.push_back( "Three" );

	printContainer( mySlist, "myList" );

	mySlist.sort();
	printContainer( mySlist, "myList" );

	mySlist.sort( compare_nocase );
	printContainer( mySlist, "myList" );
	std::cout << std::endl;

	// unique

	double	myDoubles[] = { 12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25 };
	ft::list<double>	myDlist;

	for ( int i = 0; i < 10; i++ )
		myDlist.push_back( myDoubles[i] );

	myDlist.sort();

	myDlist.unique();
	printContainer( myDlist, "myList" );

	myDlist.unique( same_integral_part );
	printContainer( myDlist, "myList" );

	myDlist.unique( is_near() );
	printContainer( myDlist, "myList" );
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
	printContainer( myDlist, "myList" );

	myDlist2.push_back( 2.1 );

	myDlist.merge( myDlist2, mycomparison );
	printContainer( myDlist, "myList" );
	std::cout << std::endl;

	// reverse
	myList.clear();

	for ( int i = 1; i < 10; i++ )
		myList.push_back( i );

	myList.reverse();

	printContainer( myList, "myList" );
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

	printContainer( a, "a" );
	printContainer( b, "b" );
	printContainer( c, "c" );

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

	printContainer( foo, "foo" );
	printContainer( bar, "bar" );

	std::cout << std::endl;
}

int 	list_main() {

	iterators();
	reverse_iterators();
	constructors();
	push_pop_front_back();
	capacity_list();
	modifiers();
	operations();
	non_member();

	// system( "leaks a.out" );

	return 0;
}
