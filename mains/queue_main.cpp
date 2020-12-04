/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_main.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 14:27:39 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/12/04 14:27:40 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../queue/Queue.hpp"

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
}

int		main() {

	empty_queue();
	size_queue();
	front_queue();
	back_queue();
	push_pop_queue();
	non_member_queue();

	return 0;
}
