/*
An iterator is an object used to reference an object stored in a container.
This, it is a generalization of the pointer

An iterator allows for accessing information included in a container so that desired operations can be performed on these elements.

!No Iterators are supported for the stack, queue, and priority_queue containers.

Iterators operations for classes list, map, multimap, set, and multiset are as follows(i1 and i2 are iterators, n a number):

i1++, ++i1, i1--, --i1
i1 = i2
i1 == i2, i1 != i2
*i1

In addition to these operations, iterator operations for classes deque and vector are as follows:

i1 < i2, i1 <= i2, i1 > i2, i1 >= i2
i1 + n, i1 - n
i1 += n, i1 -= n
i1[n]
*/