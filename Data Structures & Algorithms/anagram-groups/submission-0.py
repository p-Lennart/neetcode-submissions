class Solution:    
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        grams = {}
        
        for strn in strs:
            alph: List[int] = [0] * 26
            for c in strn: 
                i = ord(c) - ord('a')
                alph[i] += 1

            key = " ".join(map(str, alph))
            if key not in grams:
                grams[key] = [strn]
            else:
                grams[key].append(strn)
        
        return list(grams.values())
        
        
        