class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        
        m = {}
        for (idx, word) in enumerate(["qwertyuiop", "asdfghjkl", "zxcvbnm"]):
            for ch in word:
                m[ch] = idx
        
        result = []
        
        for word in words:
            default = m[word[0].lower()]
            result.append(word)
            for ch in word:
                if default != m[ch.lower()]:
                    result.pop()
                    break
        
        return result
            
                