# Creational Design Patterns

They are common approaches related to the creation of objects.

Creational design patterns provide various object creation mechanisms, which increase flexibility and reuse of existing code.

### Ways that objects are created in C++:
- _Stack allocation_ creates an object that will be allocated on the stack. The object will be cleaned up automatically at the end of the scope.
- _Heap allocation_ using a raw pointer puts the object on the heap (a.k.a. the free store). Leaves open the question of who is in charge of cleaning up the object.
- A _unique pointer_ (unique_ptr) can take a heap-allocated pointer and manage it so that it’s cleaned up automatically when there is no longer a reference to it. A unique pointer really is unique: you cannot make copies of it, and you cannot pass it into another function without losing control of the original.
- A _shared pointer_ (shared_ptr) takes a heap-allocated pointer and manages it, but allows the sharing of this pointer around in code. The owned pointer is only cleaned up when there are no components holding on to the pointer.
- A _weak pointer_ (weak_ptr) is a smart but non owning pointer, holding a weak reference to an object managed by a shared_ptr. You need to convert it to a shared_ptr in order to be able to actually access the referenced object. One of its uses is to break circular references of shared_ptrs.

### Returning Objects From Functions:
If you are returning anything bigger than a word-sized value, there are several ways of returning something from a function. 

- The first, and most obvious, is a **full copy**. _Return Value Optimization_ (RVO) is a compiler feature that specifically prevents those extra copies being made. In complex scenarios, however, you really cannot rely on RVO happening, but when it comes to choosing whether or not to optimize return values, you should resist the temptation until A) you understand exactly what you’re doing; and B) you actually experience a performance effect that requires optimization.
- Another approach is, of course, to simply return a **smart pointer** such as a unique_ptr. This is very safe, but also opinionated: you’ve chosen the smart pointer for the user.
- The third and final option is to use a **raw pointer**, perhaps in tandem with _GSL’s owner<T>_. This way, you are not enforcing the clean-up of the allocated object, but you are sending a very clear message that it is the caller’s responsibility. Now the caller of make_foo() needs to handle the pointer: either by correctly calling delete or by wrapping it in a unique_ptr or shared_ptr.
