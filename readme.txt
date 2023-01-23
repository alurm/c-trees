Weird binary tree implementation in C

First, define a pair as a structure which has a left pointer and a right pointer. Pseudocode: pair(left = "hello", right = "world")

Second, define a choiced as a structure which has a bool and a pointer to something. Pseudocode: choiced(bool = false, data = "hello").

Third, define binary tree like this:

	- either a leaf: choiced(bool = false, data = "something");
	- or a node: choiced(bool = true, data = pair(left = left_node, right = right_node)).

Next, define a couple of macros for allocating the tree on the stack. That's it.

License: MIT.
