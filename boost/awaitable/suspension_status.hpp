///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Bryce Adelstein Lelbach aka wash <brycelelbach@gmail.com>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
///////////////////////////////////////////////////////////////////////////////

#if !defined(BOOST_AWAITABLE_3739E5F4_392F_4509_928C_E4A099A7FD89)
#define BOOST_AWAITABLE_3739E5F4_392F_4509_928C_E4A099A7FD89

#include <boost/awaitable/version.hpp>
#include <boost/awaitable_api.hpp>

BOOST_AWAITABLE_BEGIN_NAMESPACE

// suspension_status: A higher-order Awaitable which tracks the status of the
// associated coroutine. Useful because we currently don't have core language
// support for checking the state of a coroutine and many methods of
// coroutine_handle will exhibit UB if the coroutine they refer to is not
// suspended.

template <typename Awaitable>
struct suspension_status
{
  private:
    Awaitable a;
    bool state; // False if suspended and true otherwise.

  public:
    suspension_status() noexcept(noexcept(Awaitable{})) : a{}, state{true} {}

    constexpr auto await_ready() noexcept(noexcept(a.await_ready()))
    {
        // Coroutines TS 5.8.3 [expr.await] p5.1 states "the await-expression
        // evaluates the await-ready expression, then if the result is false,
        // the coroutine is considered suspended. Then, the await-suspend
        // expression is evaluated". I intrepret this to mean that we become
        // suspended here, not in await_suspend. 
        return state = a.await_ready();
    }

    // This has to be templated in case the wrapped Awaitable takes
    // coroutine_handle<Promise> instead of coroutine_handle<>.
    template <typename Promise>
    constexpr auto await_suspend(coroutine_handle<Promise> h)
        noexcept(noexcept(a.await_suspend(h)))
    {
        return a.await_suspend(h);
    }

    constexpr void await_resume() noexcept(noexcept(a.await_resume()))
    {
        state = true;
        a.await_resume();
    }

    constexpr bool is_suspended() const noexcept
    {
        return !state;
    }
};

BOOST_AWAITABLE_END_NAMESPACE

#endif // BOOST_AWAITABLE_3739E5F4_392F_4509_928C_E4A099A7FD89


