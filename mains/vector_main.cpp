/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_main.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 15:18:23 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/12/03 17:39:25 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../vector/Vector.hpp"

template< typename T >
void	printContainer( const T & con, const char* str = "myVector" ) {

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

	printContainer( myVector );

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

void 	push_pop_front_back_vector() {

	std::cout << "******************** push_pop_front_back ********************" << std::endl;

	ft::vector<int>	myVector;

	myVector.push_back( 15 );
	myVector.push_back( 28 );
	myVector.push_back( 42 );

	printContainer( myVector );

	myVector.push_back( 7 );
	myVector.push_back( 5 );
	myVector.push_back( 3 );

	printContainer( myVector );
	std::cout << std::endl;

	std::cout << "front:  " << myVector.front() << std::endl;
	std::cout << "back:   " << myVector.back() << std::endl << std::endl;

	myVector.pop_back();
	printContainer( myVector );

	myVector.pop_back();
	printContainer( myVector );

	myVector.pop_back();
	printContainer( myVector );

	myVector.pop_back();
	printContainer( myVector );

	myVector.pop_back();
	printContainer( myVector );
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

	std::cout << "myInts: " << myInts.max_size() << std::endl;
	std::cout << "myVector: " << myVector.max_size() << std::endl;

	// capacity
	ft::vector<int>	myVector2;

	for ( int i = 0; i < 100; i++ )
		myVector2.push_back( i );

	std::cout << "size: " << myVector2.size() << std::endl;
	std::cout << "capacity: " << myVector2.capacity() << std::endl;
	std::cout << "max_size: " << myVector2.max_size() << std::endl;

	// resize
	ft::vector<int>	myVector3;

	for ( int i = 1; i <= 10; ++i )
		myVector3.push_back( i );
	std::cout << std::endl;

	myVector3.resize( 5 );
	myVector3.resize( 8, 100 );
	myVector3.resize( 12 );

	printContainer( myVector3 );

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
	printContainer( myVector );
	std::cout << std::endl;

	// at
	for ( size_t i = 0; i < myVector.size(); i++ )
		myVector.at( i ) = i;

	printContainer( myVector );
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

	printContainer( myVector2 );
	std::cout << std::endl;
}

void	modifiers_vector() {

	std::cout << "************************* Modifiers *************************" << std::endl;

	// clear
	ft::vector<int> myVector;

	myVector.push_back(100);
	myVector.push_back(200);
	myVector.push_back(300);

	printContainer( myVector );

	myVector.clear();
	myVector.push_back(1101);
	myVector.push_back(2202);

	printContainer( myVector );
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

	printContainer( myVector2 );
	std::cout << std::endl;

	// erase
	myVector.clear();

	for ( int i = 1; i <= 10; i++ )
		myVector.push_back( i );

	myVector.erase( myVector.begin() + 5 );
	printContainer( myVector );

	it = myVector.erase( myVector.begin(), myVector.begin() + 3 );
	printContainer( myVector );
	std::cout << std::endl;

	// swap
	ft::vector<int>	foo( 3, 100 );
	ft::vector<int>	bar( 5, 200 );

	foo.swap( bar );

	printContainer( foo, "foo" );
	printContainer( bar, "bar" );
}

void	non_member_vector() {

	std::cout << "************************ Non_member *************************" << std::endl;

	// relational operators
	ft::vector<int> foo (3,100);
	ft::vector<int> bar (2,200);

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << std::endl;

	// swap
	ft::swap( foo, bar );

	printContainer( foo, "foo contains" );
	printContainer( bar, "bar contains" );
}

int		vector_main() {

	iterators_vector();
	reverse_iterators_vector();
	constructors_vector();
	push_pop_front_back_vector();
	capacity_vector();
	element_access_vector();
	modifiers_vector();
	non_member_vector();


	return 0;
}
