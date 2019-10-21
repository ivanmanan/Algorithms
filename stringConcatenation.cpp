/*
  Given strings A and B,
  determine if string A can be formed by concatenating any substrings of B

  Ex.
  A=zaza
  B=baz

  1. ##z
  2. #az
  3. #a#

  SOLUTION:
  1. Inefficient: Create all possible substrings, and check longest existing
     substring for every index of A. TIME: O(A*B!)
  2. Efficient: Dynamic Programming. TIME: O(A*B)

 */
