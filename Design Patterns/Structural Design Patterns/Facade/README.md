# Facade

The Façade design pattern is a way of putting a simple interface in front of one or more complicated subsystems.

###### Summary:

A facade might provide limited functionality in comparison to working with the subsystem directly.
However, it includes only those features that clients really care about.

Having a facade is handy when you need to integrate your app with a sophisticated library that has dozens of features,
but you just need a tiny bit of its functionality.

The Client uses the facade instead of calling the subsystem objects directly.

Instead of making your code work with dozens of the framework classes directly, you create a facade class which encapsulates
that functionality and hides it from the rest of the code. This structure also helps you to minimize the effort of upgrading to future
versions of the framework or replacing it with another one. The only thing you’d need to change in your app would be the implementation of
the facade’s methods.

The facade pattern is a useful approach to plan software projects that have multiple layers.
Create facades to define entry points to each level of a subsystem.
You can reduce coupling between multiple subsystems by requiring them to communicate only through facades.


###### Pros and Cons

+ You can isolate your code from the complexity of a subsystem.

- A facade can become a god object coupled to all classes of an app.