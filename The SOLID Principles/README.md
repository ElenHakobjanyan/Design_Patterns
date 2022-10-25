# The SOLID Design Principles

These principles were introduced by **Robert C. Martin** in the early
2000s—in fact, they are just a selection of five principles out of dozens.

SOLID is an acronym which stands for the following design principles (and their abbreviations):
- Single Responsibility Principle (SRP)
- Open-Closed Principle (OCP)
- Liskov Substitution Principle (LSP)
- Interface Segregation Principle (ISP)
- Dependency Inversion Principle (DIP)


### Single Responsibility Principle (SRP)

> Each class has only one responsibility, and therefore has only one reason to change.
An extreme example of an antipattern that violates the SRP is called a God Object. 
A *God Object* is a huge class that tries to handle as many concerns as possible, 
becoming a monolithic monstrosity that is very difficult to work with.

### Open-Closed Principle (OCP)

> A type is open for extension but closed for modification.
Basically, OCP states that you shouldn’t need to go back to code you’ve already written and tested and change it.

### Liskov Substitution Principle (LSP)

> If an interface takes an object of type Parent, it should equally take an object of type Child without anything breaking.

### Interface Segregation Principle (ISP)

> The idea here is to segregate parts of a complicated interface into separate interfaces so as to avoid forcing implementers to implement functionality that they do not really need.
ISP suggests that you split up interfaces so that implementers can pick and choose depending on their needs.

### Dependency Inversion Principle (DIP)

A. High-level modules should not depend on low-level modules. Both should depend on abstractions.
B. Abstractions should not depend on details. Details should depend on abstractions.
Such an approach supports better configurability and testability — provided you’re using a good framework to handle these dependencies for you.
