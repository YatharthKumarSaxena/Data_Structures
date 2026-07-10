from collections import deque
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        senate = list(senate)
        qu = deque()
        rad = deque()
        dire = deque()
        n = len(senate)
        for i in range(n):
            qu.append(i)
            if senate[i]=='R': rad.append(i)
            else: dire.append(i)
        while len(qu)!=1:
            if senate[qu[0]]=='R':
                i = qu[0]
                if len(dire)==0: return "Radiant"
                idx = dire[0]
                senate[idx] = 'X'
                qu.append(i)
                dire.popleft()
                rad.append(rad[0])
                rad.popleft()
            elif senate[qu[0]]=='D':
                i = qu[0]
                if len(rad)==0: return "Dire"
                idx = rad[0]
                senate[idx] = 'X'
                qu.append(i)
                rad.popleft() 
                dire.append(dire[0])
                dire.popleft()
            qu.popleft()
        return "Radiant" if senate[qu[0]]=='R' else "Dire"