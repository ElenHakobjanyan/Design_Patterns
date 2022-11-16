# Structural Design Patterns

Structural patterns explain how to assemble objects and classes into larger structures, while keeping these structures flexible and efficient.


As the name suggests, Structural patterns are all about setting up the structure of your application so as to improve SOLID conformance as well as general usability and refactorability of your code.

When it comes to determining the structure of an object, we can employ two fairly well-known methods:
- **Inheritance**: an object automatically acquires the non private fields and functions of its base class or classes. To allow instantiation, the object must implement every pure virtual member from its parents; if it does not, it is abstract and cannot be created (but you can inherit from it).
- **Composition**: generally implies that the child cannot exist without the parent. Think of an object having members of owner<T> type: when the object gets destroyed, they get destroyed with it.
- **Aggregation**: an object can contain another object, but that object can also exist independently. Think of an object having members of type T* or shared_ptr<T>.
