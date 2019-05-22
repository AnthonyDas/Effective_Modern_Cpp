#include <mutex>

class polynomial {

	// Because mutex can be neither copied nor moved, a side
	// effect is that the class can now neither be coped or moved.

	// If a mutex is overkill, use an atomic instead:
	// mutable std::atomic<unsigned> callCount = 0;
	// Like a mutex, atomics can neither be copied nor moved.

	mutable std::mutex m;
	mutable bool rootAvailable = false; // For caching purposes

private:

	// Const member function but we want to edit data member(s)
	// Therefore, make data members mutable. To ensure thread safety,
	// as const looks like a read-only operation to the outside world,
	// ensure thread safety with a mutex lock.
	double root() const {

		std::lock_guard<std::mutex> lck(m);

		if (!rootAvailable) {

			rootAvailable = true;
		}

		return 0;
	}

};

/* For a single variable or memory location requiring synchronisation, use std::atomic.
But once you get to two or more variables or memory locations requiring manipulation as
a unit, you should use a mutex. */