# Rectangular Pasture- solution

I had to read the solution for this one- it was hard. So I knew that the solution was probably $O(n^2)$, and that going through all $2^n$ possibilities was not going to work, or all possible rectangles.
I just wanted to explain the USACO Guide solution in a different way for people who didn't get why they did the things they did (such as me). 

The solution requires coordinate compression since the squares can be from $0$ to $10^9$ but there are max $2500$ cows, and the distance between different points don't really matter. What I needed to do was sort all the x coordinates and give each one a rank:

(0, 2, 3, 9, 100, 1033)
to
(1, 2, 3, 4, 5, 6)

(Since there was a prefix sum, I 1-indexed everything as 0-indexing a prefix sum can lead to out of bounds errors).

So what I did was tied the x and y coordinate to a specific ID for a cow (the first cow in the input has ID 1, the second cow has ID 2...), sorted them, and changed the position of each cow to its ID.

Here's an example with the sample case. 

```
# note the coords are (0, 2), (1, 0), (2, 3), and (3, 5) in that order
vector<pair, pair> xs = {(0, 1), (1, 2), (2, 3), (3, 4)};
vector<pair, pair> ys = {(2, 1), (0, 2), (3, 3), (5, 4)};
```

After sorting:

```
# RANKS:                 1       2       3        4
vector<pair, pair> xs = {(0, 1), (1, 2), (2, 3), (3, 4)};
vector<pair, pair> ys = {(0, 2), (2, 1), (3, 3), (5, 4)};
vector<pair, pair> coords = {(1, 2), (2, 1), (3, 3), (4, 4)}; # new coordinates
```

The hardest idea in here is how to calculate the number of cows. The empty set can always be found since there are $10^{18}$ different points and $2500$ cows, you'll find an empty square.

You can also always get subsets of 1 cow by selecting only the cell with that cow on it (no 2 cows will be on the same spot)

As for subsets of 2 cows or more, we can loop through all pairs of cows and form rectangles with the cows acting as top-left/top-right/bottom-left/bottom-right corners. Some of these subsets may include 3 or more cows
(e.g. the rectangle with cow 2 and cow 4 in it has cow 3).

What's very handy is the fact that no two cows have the same x coordinate, or the same y coordinate. This means each rectangle (from each pair of cows) has different x coordinates than the other rectangles, so we aren't counting anything twice.

The solution then mentions that we can get all the other rectangles (of course, not every rectangle has its cows in the corner) by checking for any cows above the rectangle and below the rectangle. It's entirely possible to
go in the opposite direction (look for any cows to the right and to the left of the rectangle), I assume the solution authors just chose the y axis at random.

We can use 2d prefix sums to find the cows above and below the axes. Let's say you have 3 cows above the rectangle and 2 cows below. There are (3+1)(2+1) = 12 possibilities here:

- don't extend the rectangle upwards
- extend the rectangle to include 1 of the topmost cows
- extend the rectangle to include 2 of the topmost cows
- extend the rectangle to include 3 of the topmost cows

And you can do the same thing with the bottom part of the rectangle.

Hopefully this clears the solution up!



e




e
