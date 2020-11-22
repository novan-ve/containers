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

int 	main() {

	std::cout << "******************** Reverse iterators ********************" << std::endl;

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

	// ******************** operator + ********************

	ft::reverse_iterator<iter_type>	rev_it;

	rev_it = myList.rbegin() + 3;
	std::cout << "The fourth element from the end is: " << *rev_it << std::endl;

	// ******************** operator += ********************

	ft::reverse_iterator<iter_type>	rev_iterator = myList.rbegin();

	rev_iterator += 2;

	std::cout << "The third element from the end is: " << *rev_iterator << std::endl;

	// ******************** operator - ********************

	rev_iterator = myList.rend() - 3;

	std::cout << "myList.rend()-3 points to: " << *rev_iterator << std::endl;

	// ******************** operator -- ********************

	ft::reverse_iterator<iter_type>	rev_begin2( myList.end() );
	ft::reverse_iterator<iter_type>	rev_end2( myList.begin() );

	rev_iterator = rev_begin2;

	while ( rev_iterator != rev_end )
		std::cout << *rev_iterator++ << ' ';
	std::cout << std::endl;

	while ( rev_iterator != rev_begin )
		std::cout << *(--rev_iterator) << ' ';
	std::cout << std::endl;

	// ******************** operator -= ********************

	rev_iterator = myList.rend();

	rev_iterator -= 4;

	std::cout << "rev_iterator now points to: " << *rev_iterator << std::endl;

	// ******************** operator -> ********************

//	std::map<int, std::string> numbers;
//	numbers.insert( std::make_pair(1,"one"));
//	numbers.insert( std::make_pair(2,"two"));
//	numbers.insert( std::make_pair(3,"three"));
//
//	ft::reverse_iterator<std::map<int, std::string>::iterator>	rev_end3( numbers.begin());
//	ft::reverse_iterator<std::map<int, std::string>::iterator>	rev_iterator3( numbers.end());
//
//	for ( ; rev_iterator3 != rev_end3; ++rev_iterator3 )
//		std::cout << rev_iterator3->first << ' ' << rev_iterator3->second << std::endl;

	// ******************** operator [] ********************

	rev_iterator = myList.rbegin();

	std::cout << "The fourth element from the end is: " << rev_iterator[3] << std::endl << std::endl;

	// ******************** relational operators ********************

	ft::reverse_iterator<iter_type>	rev_iterator1 = myList.rend() - 5;
	ft::reverse_iterator<iter_type>	rev_iterator2 = myList.rbegin() - 4;
	ft::reverse_iterator<iter_type>	rev_iterator3 = myList.rend() - 3;

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
	std::cout << "rev_iterator2 >  rev_iterator3:\t" << (rev_iterator2 >  rev_iterator3) << std::endl;

	// ******************** operator + (non member) ********************

	rev_it = 3 + myList.rbegin();

	std::cout << "The fourth element from the end is: " << *rev_it << std::endl;

	// ******************** operator - (non member) ********************

	rev_from = myList.rbegin();
	rev_until = myList.rend();

	std::cout << "myList.rbegin(): " << *myList.rbegin() << std::endl;
	std::cout << "myList.rbegin() - 3: " << *(myList.rbegin() - 3) << std::endl;

	std::cout << "myList has " << (rev_until - rev_from) << " elements." << std::endl;

	return 0;
}
