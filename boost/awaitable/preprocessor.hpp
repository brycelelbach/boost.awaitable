///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2001-2015 Housemarque Oy (housemarque.com)
// Copyright (c) 2007-2017 Hartmut Kaiser
// Copyright (c) 2014-2017 Bryce Adelstein Lelbach <brycelelbach@gmail.com>
// Compliments of HPX (github.com/STEllAR-GROUP/hpx) and Boost (boost.org)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
///////////////////////////////////////////////////////////////////////////////

#if !defined(BOOST_AWAITABLE_PP_F32BAD82_9E86_4092_AA56_B3858284835D)
#define BOOST_AWAITABLE_PP_F32BAD82_9E86_4092_AA56_B3858284835D

///////////////////////////////////////////////////////////////////////////////
// Concatenation

/* Example usage:

#include <iostream>

int main()
{
    std::cout << BOOST_AWAITABLE_PP_CAT(1, BOOST_AWAITABLE_PP_CAT(2, 3)) << "\n";
}
*/

#define BOOST_AWAITABLE_PP_CAT(a, b) BOOST_AWAITABLE_PP_CAT_I(a, b)

#if    defined(_MSC_VER)                                                      \
    && (defined(__EDG__) || defined(__EDG_VERSION__))                         \
    && (defined(__INTELLISENSE__) || __EDG_VERSION__ >= 308)
    #define BOOST_AWAITABLE_PP_CAT_I(a, b) BOOST_AWAITABLE_PP_CAT_II(~, a ## b)
    #define BOOST_AWAITABLE_PP_CAT_II(p, res) res
#else
    #define BOOST_AWAITABLE_PP_CAT_I(a, b) a ## b
#endif

///////////////////////////////////////////////////////////////////////////////
// Expansion

#define BOOST_AWAITABLE_PP_EXPAND(x) x

///////////////////////////////////////////////////////////////////////////////
// Macro overloading

/* Example usage:

#include <iostream>

#define FOO(...) BOOST_AWAITABLE_PP_EXPAND(BOOST_AWAITABLE_PP_CAT(FOO_, BOOST_AWAITABLE_PP_NARG(__VA_ARGS__))(__VA_ARGS__))

#define FOO_1(x) "FOO(" #x ")"

#define FOO_2(x, y) "FOO(" #x ", " # y ")"

#define FOO_3(x, y, z) "FOO(" #x ", " #y ", " #z ")"

int main()
{
    std::cout << FOO(1)       << "\n" 
              << FOO(1, 2)    << "\n" 
              << FOO(1, 2, 3) << "\n"; 
}
*/

#define BOOST_AWAITABLE_PP_ARGN_(                                             \
     _1, _2, _3, _4, _5, _6, _7, _8, _9,_10,_11,_12,_13,_14,_15,_16,          \
    _17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,          \
    _33,_34,_35,_36,_37,_38,_39,_40,_41,_42,_43,_44,_45,_46,_47,_48,          \
    _49,_50,_51,_52,_53,_54,_55,_56,_57,_58,_59,_60,_61,_62,_63,  N,...) N    \
    /**/

#define BOOST_AWAITABLE_PP_NARG(...)                                          \
    BOOST_AWAITABLE_PP_EXPAND(BOOST_AWAITABLE_PP_ARGN_(__VA_ARGS__,           \
    63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,                          \
    47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,                          \
    31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,                          \
    15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))                         \
    /**/

#endif // BOOST_AWAITABLE_PP_F32BAD82_9E86_4092_AA56_B3858284835D

