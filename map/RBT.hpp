/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:19:14 by mac               #+#    #+#             */
/*   Updated: 2023/02/07 16:41:44 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP

struct Node{
    int value;
    Node *left;
    Node *right;
    Node *parent;
    bool color;
};

class Rbt{
    private:
        Node *root;
        Node *nil;
};






#endif