# Singleton

The Singleton design pattern grew out of a very simple idea that you should only have one instance of a particular component in your application.

### Singleton as Global Object:

The naïve approach to this problem is to simply agree that we are not going to instantiate this object ever. The problem with this approach is that objects can be created in stealthy ways where the call to the constructor isn’t immediately obvious.

The most obvious idea that comes to mind is to offer a single, static global object. The trouble with global static objects is that their initialization order in different compilation units is undefined. This can lead to nasty effects, like one global object referring to another when the latter hasn’t yet been initialized. There’s also the issue of discoverability. 

One way to mitigate this is to offer a global (or indeed, member) function that exposes the necessary object. This function can be called to get a reference to the database. However, thread safety for the preceding is only guaranteed since C++11. If it decides to use some other, similarly exposed, singleton in its destructor, the program is likely to blow up.

Having a global static doesn’t really prevent anyone from making another instance.

### Classic Implementation:

We can put a static counter right in the constructor and throw if the value is ever incremented. Even though it prevents the creation of more than one instance by throwing an exception, it fails to communicate the fact that we don’t want anyone calling the constructor more than once.

Make its constructor private and introduce the aforementioned function as a member function to return the one and only instance. Hiding the constructor and deleting copy/move constructor/assignment operators. Finally, you can implement get() as a heap allocation (so that only the pointer, not the entire object, is static). The preceding implementation relies on the assumption that it lives until the end of the program and the use of a pointer instead of a
reference ensures that a destructor, even if you make one (which, if you do, would have to be public), is never called.

### Thread Safety:

Prior to C++11, you would construct the singleton using an approach called double-checked locking.

### The Trouble with Singleton:

The real problem with singletons like the preceding one is their use in other components. This presents an issue for testing.

### Singletons and Inversion of Control:

The approach of explicitly making a component a singleton is distinctly invasive, and a decision to stop treating the class as a Singleton down the line will end up particularly costly. An alternative solution is to adopt a convention where, instead of directly enforcing the lifetime of a class, this function is outsourced to an IoC container.

According to many people, using a singleton in a DI container is the only socially acceptable use of a singleton. 

At least with this approach, if you need to replace a singleton object with something else, you can do it in one central place: the container configuration code. An added benefit is that you won’t have to implement any singleton logic yourself, which prevents possible errors. Also Boost.DI is thread safe.

### Monostate:

Monostate is a variation on the Singleton pattern. It is a class that behaves like a singleton while appearing as an ordinary class. The class appears as an ordinary class with getters and setters, but they actually work on static data. 

The Monostate approach works to some degree and has a couple of advantages. For example, it is easy to inherit, it can leverage polymorphism, and its lifetime is reasonably well defined (but then again, you might not always wish it so). Its greatest advantage is that you can take an existing object that’s already used throughout the system, patch it up to behave in a Monostate way, and provided your system works fine with the non plurality of object instances, you’ve got yourself a Singleton-like implementation with no extra code needing to be rewritten.

The disadvantages are obvious, too: it is an intrusive approach (converting an ordinary object to a Monostate is not easy), and its use of static members means it always takes up space, even when it’s not needed. Ultimately, Monostate’s greatest downfall is that it makes a very optimistic assumption that the class fields are always exposed through getters and setters. If they are being accessed directly, your refactoring is almost doomed to fail.

### Summary:

If you really must use a singleton, try avoiding using it directly and instead keep specifying it as a dependency (e.g., a constructor argument) where all dependencies are satisfied from a single location in your application (e.g., an inversion of control container).

Singleton is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.

The Singleton pattern solves two problems at the same time, violating the Single Responsibility Principle:
1. Ensure that a class has just a single instance.
	The most common reason for this is to control access to some shared resource - for example, a database or a file.
2. Provide a global access point to that instance.
	
### Pros and Cons:

+You can be sure that a class has only a single instance.

+You gain a global access point to that instance.

+The singleton object is initialized only when it’s requested for the first time.

-Violates the Single Responsibility Principle. The pattern solves two problems at the time.

-The Singleton pattern can mask bad design, for instance, when the components of the program know too much about each other.

-The pattern requires special treatment in a multithreaded environment so that multiple threads won’t create a singleton object several times.

-It may be difficult to unit test the client code of the Singleton because many test frameworks rely on inheritance when producing mock objects. 
Since the constructor of the singleton class is private and overriding static methods is impossible in most languages, 
you will need to think of a creative way to mock the singleton. Or just don’t write the tests. Or don’t use the Singleton pattern.
