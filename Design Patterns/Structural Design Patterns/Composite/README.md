# Composite

It’s a fact of life that objects are quite often composed of other objects (or, in other words, they aggregate other objects). There are very few ways for an object to advertise that it’s composed of something.

You can advertise being composed of a collection of objects by implementing begin()/end() members, but keep in mind that this doesn’t actually state a lot: after all, you can do anything you want in it. Similarly, you can try to advertise that you are a container of a specific type by doing an iterator typedef.

Another option for advertising being a container is inheriting from a container. This is mostly fine: even though STL containers do not have virtual destructors, if you don’t need anything in your destructor either, and you don’t envisage people inheriting from your type, then everything is fine—go ahead and inherit from std::vector; nothing bad should happen.


Essentially, we try to give single objects and groups of objects an identical interface.


### Array Backed Properties:

The approach of using array-backed properties is as follows. First of all, we define enumeration members for all the required properties, and then proceed to create an array of the appropriate size. 

This is the kind of code that your IDE will not generate for you, but that’s a small price to pay for the flexibility.

Now, here come the awesome parts: our calculations of sum(), average(), and max() become truly trivial because, in all of those cases, all we have to do is iterate an array.

Not only is the code a lot easier to write and maintain, but adding a new property to the class is as simple as adding a new enum member and a getter-setter pair; the aggregates need not change at all.


### Grouping Graphic Objects:

Think of an application such as PowerPoint where you can select several different objects and drag them as one. And yet, if you were to select a single object, you can grab that object too. Same goes for rendering: you can render an individual graphic object, or you can group several shapes together and they get drawn as one group.

Several rectangles and circles grouped together represent a Composite graphic object (hence the name of the Composite design pattern).


### Neural Networks:

Part of machine learning is the use of artificial neural networks: software constructs that attempt to mimic the way neurons work in our brains.

The central concept of neural networks is, of course, a neuron. A neuron can produce a (typically numeric) output as a function of its inputs, and we can feed that value on to other connections in the network.

Suppose we also want to create neuron layers. A layer is quite simply a specific number of neurons grouped together.


### Summary:

The Composite (aka Object Tree) design pattern allows us to provide identical interfaces for individual objects and collections of objects. This can be done either through the explicit use of interface members or, alternatively, through duck typing—for example, range-based for loops don’t require you to inherit anything, and work on the basis of the typing having suitable-looking begin()/end() members.

It is precisely these begin()/end() members that allow a scalar type to masquerade as a “collection.” It is also interesting to note that the nested for loops of our connect_to() function are able to connect the two constructs together despite them having different iterator types: Neuron returns a Neuron* whereas NeuronLayer returns vector<Neuron>::iterator - these two are not quite the same thing. Ahh, the magic of templates!

Finally, I must admit that all of these jumps through hoops are necessary only if you want to have a single member function. If you are OK with calling a global function or if you are happy with having more than one connect_to() implementation, the base class SomeNeurons is unnecessary.

Composite is a structural design pattern that lets you compose objects into tree structures and then work with these structures as if they were individual objects.

The Composite pattern provides you with two basic element types that share a common interface: simple leaves and complex containers. A container can be composed of both leaves and other containers. This lets you construct a nested recursive object structure that resembles a tree.


### Pros and Cons:

+You can work with complex tree structures more conveniently: use polymorphism and recursion to your advantage.

+Open/Closed Principle. You can introduce new element types into the app without breaking the existing code, which now works with the object tree.

-It might be difficult to provide a common interface for classes whose functionality differs too much. In certain scenarios, you’d need to overgeneralize the component interface, making it harder to comprehend.
