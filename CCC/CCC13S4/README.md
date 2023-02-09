This program is a straightforward application of BFS: we have a directed graph. Let the edges go from shortest person to tallest person. 
The approach is straightforward: BFS from p and try to find q in the queue. If you find q, q is taller. Then BFS from q and try to find p. If you find p, p is taller.

If you don't find them in either case, the solution is ambiguous and print "unknown".

The additional DMOJ data is very punishing towards data with even small inefficiencies. An old version I had submitted ("CCC13S4Inefficient.cpp") uses the inefficient method of storing
the visited array as all the visited values (as integers) instead of a boolean array, so figuring out whether a value has been visited is done in $O(N)$ time rather than $O(1)$.

There was also a minor logical error of searching for q throughout the entire deque, instead of checking whether each value about to be inserted into the deque was equal to q, which caused my program
to fail the last case on the DMOJ data
