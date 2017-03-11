///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Bryce Adelstein Lelbach aka wash <brycelelbach@gmail.com>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
///////////////////////////////////////////////////////////////////////////////

#if !defined(BOOST_AWAITABLE_5B4EAC09_286D_4704_BC71_6FF203E31CB3)
#define BOOST_AWAITABLE_5B4EAC09_286D_4704_BC71_6FF203E31CB3

#include <boost/awaitable/preprocessor.hpp>

///////////////////////////////////////////////////////////////////////////////

#define BOOST_AWAITABLE_VERSION 0

// Forward declare namespace.
namespace boost { namespace awaitable
{

inline namespace BOOST_AWAITABLE_PP_CAT(v, BOOST_AWAITABLE_VERSION) {}

}} // boost::awaitable
    
#define BOOST_AWAITABLE_NAMESPACE                                             \
    BOOST_AWAITABLE_PP_CAT(boost::awaitable::v, BOOST_AWAITABLE_VERSION)      \
    /**/

#define BOOST_AWAITABLE_BEGIN_NAMESPACE                                       \
    namespace boost { namespace awaitable {                                   \
    inline namespace BOOST_AWAITABLE_PP_CAT(v, BOOST_AWAITABLE_VERSION) {     \
    /**/

#define BOOST_AWAITABLE_END_NAMESPACE }}

#endif // BOOST_AWAITABLE_5B4EAC09_286D_4704_BC71_6FF203E31CB3


