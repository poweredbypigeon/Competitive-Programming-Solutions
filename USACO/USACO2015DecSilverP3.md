# Solution for "Breed Counting"

Time complexity: $$O(N+Q)$$

This solution uses prefix sums. Since the queries ask you a ranged sum for each breed, we can treat the breeds as separate and use 3 different prefix sum arrays (one for the Holsteins, Guernseys, and Jerseys).

Then you can just run the query on each prefix sum array. 
