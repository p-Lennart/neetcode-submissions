class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        letters = {}
        for c in s:
            if not c in letters:
                letters[c] = 1;
            else: 
                letters[c] += 1;
        
        for c2 in t:
            if not c2 in letters:
                letters[c2] = -1;
            else: 
                letters[c2] -= 1;

        for k in letters:
            if letters[k] != 0:
                return False

        return True