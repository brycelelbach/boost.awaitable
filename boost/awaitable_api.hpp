///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Bryce Adelstein Lelbach aka wash <brycelelbach@gmail.com>
// Copyright (c) 2017 Gor Nishanov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
///////////////////////////////////////////////////////////////////////////////

#if !defined(BOOST_AWAITABLE_77FD2560_5F9E_4A03_BDA5_6BCF01FBC809)
#define BOOST_AWAITABLE_77FD2560_5F9E_4A03_BDA5_6BCF01FBC809

// Forward declarations and overview of the Boost.Awaitable library.

#include <boost/awaitable/version.hpp>
#include <boost/awaitable/coroutine_ts_support_library.hpp>

BOOST_AWAITABLE_BEGIN_NAMESPACE

///////////////////////////////////////////////////////////////////////////////

// Import some names from the Coroutine TS support library for brevity
using BOOST_AWAITABLE_STD_COROUTINE_NAMESPACE::coroutine_handle;
using BOOST_AWAITABLE_STD_COROUTINE_NAMESPACE::suspend_always;
using BOOST_AWAITABLE_STD_COROUTINE_NAMESPACE::suspend_never;

///////////////////////////////////////////////////////////////////////////////

// Trivial Awaitable that always suspends if constructed with a value of true,
// and never suspends otherwise.
struct suspend_if;

// A higher-order Awaitable which tracks whether or not the associated
// coroutine is suspended.
template <typename Awaitable>
struct suspension_status;

template <typename T>
struct generator;

BOOST_AWAITABLE_END_NAMESPACE

#endif // BOOST_AWAITABLE_77FD2560_5F9E_4A03_BDA5_6BCF01FBC809

