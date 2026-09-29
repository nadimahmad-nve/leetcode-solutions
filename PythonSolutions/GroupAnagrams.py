class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        res = [] 
        hashMap = {}
         
        for s in strs:
            x = ''.join(sorted(s))

            if x in hashMap:
                hashMap[x].append(s)
            else:
                hashMap[x] = [s] 
        
        for val in hashMap.values():
            res.append(val)

        return res 