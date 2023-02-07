/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils1.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:44:22 by mac               #+#    #+#             */
/*   Updated: 2023/02/07 17:52:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS1_HPP
#define UTILS1_HPP

namespace ft
{
    template <class U, class V>
    struct pair
    {
        typedef U first_type;
        typedef V second_type;
        U first;
        V second;
        pair() : first(U()), second(V()){};
        pair(const U &x, const V &y)
        {
            first = x;
            second = y;
        };
        pair(const pair<U, V> &p)
        {
            first = p.first;
            second = p.second;
        };
        
        template <class U1, class V1>
        pair& operator=( const pair<U1,V1>& p)
        {
            first = first_type(p.first);
            second = second_type(p.second);
        };      

        pair& operator=( const pair& p){
            first = p.first;
            second = p.second;
            return (*this);
        };
        
    };
    template <class U, class V>
    bool operator==(const pair<U, V> &x, const pair<U, V> &y)
    {
        return (x.first == y.first && x.second == y.second);
    };
    template <class U, class V>
    bool operator<(const pair<U, V> &x, const pair<U, V> &y)
    {
        return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
    };
    template <class U, class V>
    bool operator!=(const pair<U, V> &x, const pair<U, V> &y)
    {
        return (!(x == y));
    };
    template <class U, class V>
    bool operator>(const pair<U, V> &x, const pair<U, V> &y)
    {
        return ((x != y) && !(x < y));
    };
    template <class U, class V>
    bool operator>=(const pair<U, V> &x, const pair<U, V> &y)
    {
        return (!(x < y));
    };
    template <class U, class V>
    bool operator<=(const pair<U, V> &x, const pair<U, V> &y)
    {
        return (!(x > y));
    };
    template <class U, class V>
    pair<U, V> make_pair(const U &x, const V &y)
    {
        return (pair<U, V>(x, y));
    };
};
#endif