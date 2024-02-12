class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        for i, _ in enumerate(nums[:len(nums)-2]):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i-1]:
                continue

            j = i+1
            k = len(nums)-1

            while j<k:
                print(f"({i},{j},{k})")
                sum = nums[i] + nums[j] + nums[k]
                if sum == 0:
                    res.append([nums[i], nums[j], nums[k]])
                    temp = nums[j]
                    while j < k and temp == nums[j]:
                        j += 1
                    temp = nums[k]
                    while j < k and temp == nums[k]:
                        k -= 1
                elif sum > 0:
                    k -= 1
                else:
                    j += 1
        return res
