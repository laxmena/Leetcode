class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        ans = []
        inblock = False
        for line in source:
            if not inblock:
                ans.append([])
            i = 0
            while i < len(line):
                if not inblock:
                    if line[i] == '/' and i + 1 < len(line) and line[i+1] in '/*':
                        if line[i+1] == '/':
                            break
                        i += 1    
                        inblock = True
                    else:
                        ans[-1].append(line[i])
                else:
                    if line[i] == '*' and i + 1 < len(line) and line[i+1] == '/':
                        i += 1
                        inblock = False
                i += 1
        return [''.join(line) for line in ans if line]