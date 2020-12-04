/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_main.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 13:08:22 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/12/04 13:08:24 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/Stack.hpp"

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

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

int		main() {

	empty_stack();
	size_stack();
	top_stack();
	push_pop_stack();
	non_member_stack();

	return 0;
}
