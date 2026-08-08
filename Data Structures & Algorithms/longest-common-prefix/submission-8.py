class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        trie = {}
    
        for idx, s in enumerate(strs):
            pos = trie
            for i in range(0, len(s)):
                if s[i] not in pos:
                    pos[s[i]] = {}
                pos = pos[s[i]]
            
            pos["$" + str(idx)] = "$"

        
        trace = ""
        posWalk = trie
        while isinstance(posWalk, dict) and len(posWalk) == 1:
            for node in posWalk:
                if node[0] != "$":
                    trace += node
                posWalk = posWalk[node]
                break
    
        return trace