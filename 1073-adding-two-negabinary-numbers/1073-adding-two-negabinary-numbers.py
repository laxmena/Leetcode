class Solution:
    def toBase10(self, arr1):
        num1 = 0
        for i in range(len(arr1)):
            if(arr1[i] == 0):
                continue
            num1 += pow(-2, len(arr1)-1-i)
        return num1
    
    def toBaseNeg2(self, dec):
        res = []
        base = -2
        while(dec != 0):
            rem = dec%base
            dec = dec//base
            res.append(abs(rem))
            if(rem < 0):
                dec += 1                
        
        if(res == []): return [0]
        return res[::-1]
    
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        num1 = self.toBase10(arr1)
        num2 = self.toBase10(arr2)
        return self.toBaseNeg2(num1+num2)