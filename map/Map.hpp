/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 17:20:49 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/12/04 17:20:52 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterators/iterators.hpp"

namespace ft {

	struct	mapNode {

		int			data;

		mapNode*	left;
		mapNode*	right;
	};

	class map {

		mapNode*	_root;

	public:

		map() : _root( NULL ) {}

		void	insert( mapNode* root, int data ) {


		}

	};
}
