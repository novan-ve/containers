/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_main.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 10:45:59 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/12/05 10:46:00 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../map/Map.hpp"

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

int 	main() {

	pair();
	constructors_map();
	iterators_map();
	reverse_iterators_map();
	capacity_map();
	element_access_map();
	modifiers_map();
	observers_map();
	operations_map();

	return 0;
}
