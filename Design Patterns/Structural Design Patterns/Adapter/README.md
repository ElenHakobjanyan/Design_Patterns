# Adapter

We are given an interface, but we want a different one, and building an adapter over the interface is what gets us to where we want to be.

## Summary:

Adapter is a very simple concept: it allows you to adapt the interface you have to the interface you need. 

The only real issue with adapters is that, in the process of adaptation, you sometimes end up generating temporary data so as to satisfy 
some other representation of data. And when this happens, turn to caching: ensuring that new data is only generated when necessary. 
Oh, and you’ll need to do a bit more work if you want to clean up stale data when the cached objects have changed. 

Another concern is laziness: the adapter implementation can perform the conversion as soon as it is created or maybe you only want 
the work to be done when the adapter is actually used.

### The classes and objects participating in this pattern include:

- **Target** 	– defines the domain-specific interface that Client uses.
- **Adapter** 	– adapts the interface Adaptee to the Target interface.
- **Adaptee** 	– defines an existing interface that needs adapting.
- **Client** 	– collaborates with objects conforming to the Target interface.

1. The client makes a request to the adapter by calling a method on it using the target interface.
2. The adapter translates that request on the adaptee using the adaptee interface.
3. Client receives the results of the call and is unaware of the adapter's presence.
