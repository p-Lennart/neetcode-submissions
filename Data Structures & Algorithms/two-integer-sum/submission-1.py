class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        invert = {}
        for idx, n in enumerate(nums):
            invert[target - n] = idx
        
        for idx, n in enumerate(nums):
            if n in invert:
                idx2 = invert[n]
                if idx == idx2:
                    continue
                elif idx < idx2:
                    return [idx, idx2]
                else:
                    return [idx2, idx]

        