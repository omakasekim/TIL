
/*
The STL provides some 70 generic functions, called algorithms, that can be applied to the STL containers and to arrays.

These algorithms are implementing operations that are
very frequently used in most programs, such as
locating an element in a container, inserting an element into a sequence of elements, removing an element from a sequence, modifying elements, comparing elements, findign a value based on a sequence of elements, sorting the sequence of elements, and so on.


Almost all STL algorithms use iterators to indicate the range of elements on which they operate. The first iterator references the first element of the range, and the second iterator references an element 
after the last element of the range, Therefore, it is assumed that it is always possible to reach the position indicated by the second iterator by incrementing the first iterator.
Here are some examples.

The  call
*/

// random_shuffle(c.begin(), c.end());
//randomly reorders all the elements of the container c. The call
// i3 = find(i1,i2, el);
//returns an iterator indicating the position of element el in the range i1 up to, but not including, i2. The call

// n = count_if(i1, i2, oddNum);
//counts with the algorithm count_if() the elements in the range indicated by iterator i1 and i2 for which a one-argument user-defined Boolean function oddNum() returns true.


