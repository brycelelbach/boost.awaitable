## Awaitable Concepts

The requirements on the type of the expression <code><i>cast-expression</i></code> required for expression <code>co_await <i>cast-expression</i></code> to be valid. `BasicAwaitable` is the minimal set of requirements. `AwaitableByTransform` and `AwaitableByProxy` are satisified by types that have a mechanism for producing `BasicAwaitable` objects. `Awaitable` is satisified by types that meet any of the three other concepts.

<code><i>cast-expression</i></code> (type <code><i>CE</i></code>) goes through a "pipeline" described in Coroutine TS 5.3.8 [**expr.await**] p3, where <code><i>p</i></code> (type <code><i>P</i></code> which satisfies `BasicCoPromise`):

| # | Object/Expression Type | Object/Expression Name | Object/Expression Definition                                                                                                                                                                                  | 
|---|------------------------|------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1 | <code><i>A</i></code>  | <code><i>a</i></code>  | <code><i>p</i>.await_transform(<i>cast-expression</i>)</code> if it is valid (AKA <code>AwaitableByTransform&lt;<i>CE</i>, <i>P</i>&gt;</code> is satisfied); otherwise, <code><i>cast-expression</i></code>. |
| 2 | <code><i>O</i></code>  | <code><i>o</i></code>  | <code>operator co_await(<i>a</i>)</code> if it is valid (AKA <code>AwaitableByProxy&lt;<i>A</i>&gt;</code> is satisfied); otherwise, <code><i>a</i></code>.                                                   |
| 3 | <code><i>E</i></code>  | <code><i>e</i></code>  | Copy-initialized from <code><i>o</i></code> if <code><i>o</i></code> is a prvalue; otherwise an lvalue reference to <code><i>o</i></code>.                                                                    |

### `BasicAwaitable`

```c++
template <typename E>
concept bool BasicAwaitable =
    requires (E e, coroutine_handle<> h)
    {
        // Coroutine TS 5.3.8 [expr.await] p3.6
        { e.await_ready() } -> bool;

        // Coroutine TS 5.3.8 [expr.await] p3.7
        requires requires { { e.await_suspend(h) } -> void; }
              || requires { { e.await_suspend(h) } -> bool; };

        // Coroutine TS 5.3.8 [expr.await] p3.8
        e.await_resume();
    };
```

###### TODO

* `h` needs to be a `coroutine_handle<P>` where `P` is a `BasicCoPromise` instead of `coroutine_handle<>`.
* I believe there Coroutine TS 5.3.8 [**expr.await**] p3.4 requires that `o` is "`CopyConstructible` if `o` is a prvalue". This needs to be clarified and I have to figure out how to write the condition.

### `AwaitableByTransform`

```c++
// Coroutine TS 5.3.8 [expr.await] p3.2
template <typename CE, TransformCoPromise P>
concept bool AwaitableByTransform =
    requires (CE cast_expression, P p)
    {
        p.await_transform(cast_expression);
        requires BasicAwaitable<decltype(p.await_transform(cast_expression))>
              || AwaitableByProxy<decltype(p.await_transform(cast_expression))>;
    };
```

### `AwaitableByProxy`

```c++
// Coroutine TS 5.3.8 [expr.await] p3.3
template <typename A>
concept bool AwaitableByProxy =
    // Member function. 
    requires (A a) { { a.operator co_await() } -> BasicAwaitable; }
    // Non-member function. 
 || requires (A a) { { operator co_await(a) } -> BasicAwaitable; };
```

### `Awaitable`

```c++
template <typename T, BasicCoPromise P>
concept bool Awaitable = BasicAwaitable<T>
                      || AwaitableByTransform<T, P>
                      || AwaitableByProxy<T>;
```

## CoPromise Concepts

### `BasicCoPromise`

### `TransformCoPromise`

