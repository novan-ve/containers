/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 14:00:59 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/11/13 14:01:00 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <iostream>
#include <list>

int 	main() {

	ft::list<int>	first;

	first.push_back( 15 );
	first.push_back( 28 );
	first.push_back( 42 );

	for ( ft::list<int>::const_iterator it = first.begin(); it != first.end(); ++it )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	first.push_front( 7 );
	first.push_front( 5 );
	first.push_front( 3 );

	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << first.front() << std::endl;
	std::cout << first.back() << std::endl << std::endl;

	first.pop_back();
	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	first.pop_back();
	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	first.pop_back();
	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	first.pop_back();
	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	first.pop_back();
	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	first.pop_back();
	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	first.push_back( 3 );
	first.push_back( 5 );
	first.push_back( 7 );
	first.push_back( 15 );
	first.push_back( 28 );
	first.push_back( 42 );

	first.pop_front();
	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	first.pop_front();
	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	first.pop_front();
	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	first.pop_front();
	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	first.pop_front();
	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	first.pop_front();
	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); it++ )
		std::cout << *it << std::endl;
	std::cout << std::endl;

	for ( ft::list<int>::reverse_iterator it = first.rbegin(); it != first.rend(); it++ )
		std::cout << *it << std::endl;
	return 0;
}
