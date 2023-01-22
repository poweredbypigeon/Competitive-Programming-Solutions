**DIAMOND COLLECTOR SOL**

So it's optimal for one diamond case to have diamonds greater than size than any of the diamond cases in the other.

So [9, 12], and [10] would be suboptimal. 

First of all, like any other 2 pointers problems, sort the array. 

This one I had to look at the solution for:

canTakeLeft[n]- how many diamonds we can take assuming index i is the samllest diamond

could be a vector pair figuring out the index of the smallest diamond that can't fit in the case to make sure we
don't take the same diamond twice. 

{1, 5, 5, 9, 10, 12, 14}

augmented n+K: {4, 8, 8, 12, 13, 15, 17}

here it is (0-indexed): {1, 1}, {2, 3}, {1, 3}, {3, 6}, {2, 6}, {2, -1}, {1, -1}.

though be fair you can easily compute f based on the index, index + f = s.

And what happens is if you want 1 to be the first diamond case, you add 1 to your total (number of diamonds in the case) then take

the maximum out of indexes 1 to (N-1) (diamondCase.s, 7);

Or if you want 2 to be the first diamond case, add 2 to your total then take the maximum out of indexes 3 to (N-1).

Pre compute the maximum indices in an array so it doesn't take O(N^2) (using prefix sum methods).
