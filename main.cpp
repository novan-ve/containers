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

int 	main() {

	ft::list<int>	first;

	first.push_back( 15 );
	first.push_back( 28 );
	first.push_back( 42 );

	for ( ft::list<int>::iterator it = first.begin(); it != first.end(); ++it )
		std::cout << *it << std::endl;

	return 0;
}
