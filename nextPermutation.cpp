/*
  See animation:
  https://assets.leetcode.com/static_assets/media/original_images/31_Next_Permutation.gif

  1. Find first decreasing element from right to left
  2. Starting from that element index, iterate to right to find smallest number that is larger than the element index.
  3. Reverse the numbers from the initial element and target element found.

 */