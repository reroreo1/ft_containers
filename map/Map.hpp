/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:55:43 by mac               #+#    #+#             */
/*   Updated: 2023/02/07 17:57:53 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

namespace ft
{
    template <class Key, class T, class Compare = less <Key>, class Allocator = allocator <pair <const Key, T> > >
    class map;
    template <class Key, class T, class Compare, class Allocator>
    bool operator==(const map<Key, T, Compare, Allocator> &x,
                    const map<Key, T, Compare, Allocator> &y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator<(const map<Key, T, Compare, Allocator> &x,
                   const map<Key, T, Compare, Allocator> &y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator!=(const map<Key, T, Compare, Allocator> &x,
                    const map<Key, T, Compare, Allocator> &y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator>(const map<Key, T, Compare, Allocator> &x,
                   const map<Key, T, Compare, Allocator> &y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator>=(const map<Key, T, Compare, Allocator> &x,
                    const map<Key, T, Compare, Allocator> &y);
    template <class Key, class T, class Compare, class Allocator>
    bool operator<=(const map<Key, T, Compare, Allocator> &x,
                    const map<Key, T, Compare, Allocator> &y);
    template <class Key, class T, class Compare, class Allocator>
    void swap(map<Key, T, Compare, Allocator> &x,
              map<Key, T, Compare, Allocator> &y);
    template <class Key, class T, class Compare = less<Key>, class Allocator = allocator<pair<const Key, T> > >
}

#endif