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

int 	main() {

	//pair();

	ft::map<int, char>	myMap;

	myMap.insert( ft::pair<int, char>( 15, 'm' ) );
	myMap.insert( ft::pair<int, char>( 10, 'o' ) );
	myMap.insert( ft::pair<int, char>( 20, 'b' ) );
	myMap.insert( ft::pair<int, char>( 25, 'a' ) );
	myMap.insert( ft::pair<int, char>( 8, 'n' ) );
	myMap.insert( ft::pair<int, char>( 12, 'h' ) );

//	myMap.test();

	ft::map<int, char>::iterator it = myMap.begin();

	while ( it != myMap.end() ) {
		std::cout << it->first;
		std::cout << it->second << std::endl;
		it++;
	}

	return 0;
}
