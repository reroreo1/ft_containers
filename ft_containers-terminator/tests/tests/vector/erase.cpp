/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rezzahra <rezzahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:43:28 by mleblanc          #+#    #+#             */
/*   Updated: 2023/02/04 23:55:21 by rezzahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_prelude.hpp"

void vec_test_erase()
{
    SETUP_ARRAYS();

    {
        intvector v(b_int, b_int + b_size - 5);

        intvector::iterator it = v.erase(v.begin() + 26);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);

        it = v.erase(it);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);

        it = v.erase(v.end() - 1);

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);

        it = v.erase(v.begin());

        PRINT_LINE("It:", *it);
        CHECK_AND_PRINT_ALL(v);
    }

    {
        intvector v(1, 5);

        intvector::iterator it = v.erase(v.begin());

        if (it != v.end()) {
            PRINT_MSG("Wrong iterator");
        }
        CHECK_AND_PRINT_ALL(v);
    }
}

MAIN(vec_test_erase)
