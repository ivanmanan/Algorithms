class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums)-1
        while l <= r:
            mid = int((l+r)/2)
            print(mid)
            if(nums[mid] == target):
                return mid
            elif nums[mid] > target:
                # Go left
                r = mid-1
            else:
                l = mid+1

        return -1
