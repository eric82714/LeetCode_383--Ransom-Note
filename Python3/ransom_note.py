class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(magazine) < len(ransomNote): return False
        
        hashmap = {}
        
        for w in ransomNote:
            if w not in magazine: return False
            if w in magazine and w not in hashmap:
                hashmap[w] = magazine.count(w) - 1
                continue
            if w in magazine and w in hashmap and hashmap[w] != 0:
                hashmap[w] -= 1
                continue
            if w in magazine and w in hashmap and hashmap[w] == 0:
                return False
            
        return True
