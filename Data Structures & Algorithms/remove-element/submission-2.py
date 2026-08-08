class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        kkk = 0
        for idx, n in enumerate(nums):
            if nums[idx] != val:
                nums[kkk] = nums[idx]
                kkk += 1
        return kkk
        