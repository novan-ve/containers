/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapNode.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 10:48:19 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/12/05 10:48:26 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Pair.hpp"

namespace ft {

	template <class Key, class T>
	struct mapNode {

		typedef ft::pair<Key, T>	value_type;

		mapNode( value_type v = value_type() ) : data( v ) {}

		value_type	data;

		mapNode*	left;
		mapNode*	right;
		mapNode*	up;
	};
}
