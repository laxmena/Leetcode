class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        minVal = 1441
        timearr = []
        for time in timePoints:
            hr, m = time.split(':')
            hr, m = int(hr)*60, int(m)
            # if(hr == 0):
            #     timearr.append(1440+m)
                
            timearr.append(hr+m)
        timearr = sorted(timearr)
        timearr += timearr
        for i in range(0, len(timearr)-1):
            minVal = min(minVal, (timearr[i+1]-timearr[i])%1440)
        return minVal