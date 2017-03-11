///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Bryce Adelstein Lelbach aka wash <brycelelbach@gmail.com>
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
///////////////////////////////////////////////////////////////////////////////

#if !defined(BOOST_AWAITABLE_7985975E_171D_404C_9615_67402B3FD09F)
#define BOOST_AWAITABLE_7985975E_171D_404C_9615_67402B3FD09F

#include <boost/awaitable/version.hpp>
#include <boost/awaitable_api.hpp>

BOOST_AWAITABLE_BEGIN_NAMESPACE

// suspend_if: A trivial Awaitable similar to suspend_never and suspend_always
// from the Coroutine TS v1.
//
// suspend_if takes a single boolean parameter on construction. If the bool is
// true, suspend_if will suspend the current coroutine when awaited and control
// will return to the caller or resumer. If the bool is false, suspend_if will
// not suspend when awaited and execution of the current coroutine will
// continue.
struct suspend_if
{
  private:
    bool const b;

  public:
    constexpr suspend_if(bool b) noexcept : b(b_) {}

    constexpr bool await_ready() const noexcept { return !b_; }

    constexpr void await_suspend(coroutine_handle<>) const noexcept {}

    constexpr void await_resume() const noexcept {}
};

BOOST_AWAITABLE_END_NAMESPACE

#endif // BOOST_AWAITABLE_7985975E_171D_404C_9615_67402B3FD09F


