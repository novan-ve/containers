/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   listNode.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: novan-ve <novan-ve@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 16:31:02 by novan-ve      #+#    #+#                 */
/*   Updated: 2020/11/29 16:31:06 by novan-ve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {

	template<typename T>
	struct listNode {

		listNode(const T &e) : data(e), next(0), prev(0) {}

		T data;
		listNode<T> *next;
		listNode<T> *prev;

	};
}
