# Painting the Barn- a solution

Not-so-fun fact: I tried this problem last year, and it passed the sample case but not the other cases, and I feel like this was the start of my disillusionment with competitive programming as I couldn't find the bug. But now I feel much better about it!

So this one uses 2d prefix sums, as it seems inefficient to manually increment all of these squares with one coat of paint. I'm not sure why though.

I find that you can solve this by drawing this out on paper, and I figured out what the 2d array should represent: arr[x][x] should represent the number of coats of paint on the square with
$(x, x), (x+1, x), (x, x+1), (x+1, x+1)$ as its corners. 

I developed a 1002x1002 array with indices from 0 to 1001. What I needed to do was update a constant number of squares per query (even if they asked you to paint 1,000,000 squares), and then preprocess the array

Using the sample case, I used a "2D difference array" method to find the squares to increment.

|   |   |   |   |   |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 1 | 0 |
| 0 | 1 | 1 | 1 | 0 |
| 0 | 1 | 1 | 1 | 0 |
| 0 | 0 | 0 | 0 | 0 |

to

|   |   |   |   |   |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | -1 |
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |
| 0 | -1 | 0 | 0 | 1 |

After that, you use the prefix sum method, and since you only have one million squares to check (crazy how fast computers work amirite), you can manually check how many squares have K coats of paint.

Time Complexity: $O(N+M^2)$ (where $M$ is the size of the barn, 1000 in this problem).

If you are stuck on this problem like I was last year, and your solution is passing the sample case but not the actual cases try:

```
2 1
0 0 9 9
1 1 8 8
```

It should return $32$ or something like that.
