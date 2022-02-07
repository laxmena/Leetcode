class Solution:
    mem = {0: 0, 1: 1}
    def fib(self, n: int) -> int:
        if(n in self.mem): 
            return self.mem[n]
        else: 
            self.mem[n-1] = self.fib(n-1)
            self.mem[n-2] = self.fib(n-2)
            return self.mem[n-1] + self.mem[n-2]
        