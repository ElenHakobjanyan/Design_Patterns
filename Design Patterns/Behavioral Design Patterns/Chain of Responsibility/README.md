# Chain of Responsibility

## Summary:

Event broker.

Chain of Responsibility lets components process a command (or a query) in turn. 
The simplest implementation of CoR is one where you simply make a pointer chain and, in theory, 
you could replace it with just an ordinary vector or, perhaps, a list if you wanted fast removal as well.

A more sophisticated Broker Chain implementation that also leverages the Mediator and Observer patterns allows us to process 
queries on an event (signal), letting each subscriber perform modifications of the originally passed object 
(it’s a single reference that goes through the entire chain) before the final values are returned to the client.

## TODO

add smart pointers?
finish the checkers with regex-es