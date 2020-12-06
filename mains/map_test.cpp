/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_test.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 17:28:10 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/12/04 17:28:11 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

struct	mapNode {

	int			data;

	mapNode*	left;
	mapNode*	right;
};

void printBT(const std::string& prefix, const mapNode* node, bool isLeft)
{
	if( node != 0 )
	{
		std::cout << prefix;

		std::cout << (isLeft ? "├──" : "└──" );

		// print the value of the node
		std::cout << node->data << std::endl;

		// enter the next tree level - left and right branch
		printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
		printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
	}
}

void printBT(const mapNode* node)
{
	printBT("", node, false);
}

mapNode*	insert( mapNode* root, int data ) {

	if ( root == NULL ) {
		root = new mapNode();
		root->data = data;
		root->left = root->right = 0;
	}
	else if ( data <= root->data ) {
		root->left = insert( root->left, data );
	}
	else {
		root->right = insert( root->right, data );
	}
	return root;
}

bool	search( mapNode* root, int data ) {

	if ( root == NULL ) {
		return false;
	}
	else if ( root->data == data ) {
		return true;
	}
	else if ( data <= root->data ) {
		return search( root->left, data );
	}
	else {
		return search( root->right, data );
	}
}

mapNode*	findMin( mapNode *root ) {

	while ( root->left != NULL )
		root = root->left;
	return root;
}

mapNode*	Delete( mapNode *root, int data ) {

	if ( root == NULL ) {
		return root;
	}
	else if ( data < root->data ) {
		root->left = Delete( root->left, data );
	}
	else if ( data > root->data ) {
		root->right = Delete( root->right, data );
	}
	else // found
	{
		// Case 1: No child
		if ( root->left == NULL && root->right == NULL ) {

			delete root;
			root = NULL;
		}
		// Case 2: One child
		else if ( root->left == NULL ) {

			mapNode*	tmp = root;
			root = root->right;
			delete tmp;
		}
		else if ( root->right == NULL ) {

			mapNode*	tmp = root;
			root = root->left;
			delete tmp;
		}
		// Case 3: 2 children
		else {

			mapNode*	tmp = findMin( root->right );
			root->data = tmp->data;
			root->right = Delete( root->right, tmp->data );
		}
	}
	return root;
}

/*
 * 			15
 * 		   / \
 * 		  10  20
 * 		 / \    \
 * 		8   12	 25
 */
int 	main() {

	mapNode*	root = NULL;

	root = insert( root, 15 );
	root = insert( root, 10 );
	root = insert( root, 20 );
	root = insert( root, 25 );
	root = insert( root, 8 );
	root = insert( root, 12 );


	if ( search( root, 15 ) == true )
		std::cout << "12: found" << std::endl;
	else
		std::cout << "12: not found" << std::endl;

	if ( search( root, 13 ) == true )
		std::cout << "13: found" << std::endl;
	else
		std::cout << "13: not found" << std::endl << std::endl;

	root = Delete( root, 20 );
	printBT( root );
	std::cout << std::endl;

	root = Delete( root, 10 );
	printBT( root );
	std::cout << std::endl;

	root = Delete( root, 25 );
	root = Delete( root, 8 );
	root = Delete( root, 12 );
	root = Delete( root, 15 );

	std::map<int, char>	myMap;

	myMap[3] = 'm';
	myMap[2] = 'k';
	myMap[4] = 'n';
	myMap[5] = 'o';
	myMap[1] = 'a';

	for ( std::map<int, char>::iterator it = myMap.begin(); it != myMap.end(); it++ ) {
		std::cout << it->first;
		std::cout << '\t' << it->second << std::endl;
	}
	std::cout << "Front: " << myMap.begin()->first << ": " << myMap.begin()->second << std::endl;
	std::cout << "Back: " << (--myMap.end())->first << ": " << (--myMap.end())->second << std::endl;
	return 0;
}
