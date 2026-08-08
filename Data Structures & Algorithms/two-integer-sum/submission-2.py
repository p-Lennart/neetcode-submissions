class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        invert = {}

        for idx, n in enumerate(nums):
            if n in invert:
                return [invert[n], idx]

            invert[target - n] = idx
            

        