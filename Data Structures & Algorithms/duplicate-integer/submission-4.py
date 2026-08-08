class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        if len(nums) < 1:
            return False

        nmin = min(nums)
        nmax = max(nums)

        occ = [0] * (nmax - nmin + 1)
        for n in nums:
            occ[n-nmin] += 1
            if occ[n-nmin] > 1:
                return True

        return False
        