class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        minVal = 1441
        timearr = []
        for time in timePoints:
            hr, m = time.split(':')
            hr, m = int(hr)*60, int(m)

            timearr.append(hr+m)
        timearr = sorted(timearr)
        timearr.append(timearr[0])
        for i in range(0, len(timearr)-1):
            minVal = min(minVal, (timearr[i+1]-timearr[i])%1440)
        return minVal