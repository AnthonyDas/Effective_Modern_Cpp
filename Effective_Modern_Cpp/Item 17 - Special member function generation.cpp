// Default constructor only generated when a class declares no constructors at all.

/* Generated special member functions are implicitly public and inline. 
They're non-virtual unless it's a destructor in a derived class inheriting
from a base class with a virtual destructor. */

/* Move operations are generated for classes (when needed) only if these three
things are true:
- No copy operations are declared in the class.
- No move operations are declared in the class.
- No destructor is declared in the class.
*/

/* Base classes should have a virtual destructor declared. Often, the default
implementation would be correct and "= default" is a good way to express that.
However, a user-defined destructor will suppress generation of the move operations.
If these are then manually implemented, then the copy operations will be suppressed. */

// To support all operations, quickly add::

class Base {

	virtual ~Base() = default; // Virtual destructor

	Base(const Base &) = default; // Copy constructor
	Base& operation=(const Base &) = default; // Copy assignment

	Base(Base &&) = default; // Move constructor
	Base& operation = (Base &&) = default; // Move assignment
};
