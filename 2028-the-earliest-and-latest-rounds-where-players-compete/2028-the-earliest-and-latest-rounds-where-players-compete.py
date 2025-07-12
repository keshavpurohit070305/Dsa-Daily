class Solution:
    def earliestAndLatest(self, n: int, firstPlayer: int, secondPlayer: int) -> List[int]:
        self.seen = [[[False for _ in range(28)] for _ in range(28)] for _ in range(28)]
        self.n = n
        self.min_rounds = float('inf')
        self.max_rounds = float('-inf')
        
        def allPossibleMatchups(mask, left, right, p1, p2, rounds, l, m, r):
            if left >= right:
                allPossibleMatchups(mask, 0, self.n - 1, p1, p2, rounds + 1, l, m, r)
            elif not (mask & (1 << left)):
                allPossibleMatchups(mask, left + 1, right, p1, p2, rounds, l, m, r)
            elif not (mask & (1 << right)):
                allPossibleMatchups(mask, left, right - 1, p1, p2, rounds, l, m, r)
            elif left == p1 and right == p2:
                self.min_rounds = min(self.min_rounds, rounds)
                self.max_rounds = max(self.max_rounds, rounds)
            elif not self.seen[l][m][r]:
                self.seen[l][m][r] = True
                
                if left != p1 and left != p2:
                    new_l = l - (1 if left < p1 else 0)
                    new_m = m - (1 if p1 < left < p2 else 0)
                    new_r = r - (1 if left > p2 else 0)
                    allPossibleMatchups(mask ^ (1 << left), left + 1, right - 1, p1, p2, rounds, new_l, new_m, new_r)
                
                if right != p1 and right != p2:
                    new_l = l - (1 if right < p1 else 0)
                    new_m = m - (1 if p1 < right < p2 else 0)
                    new_r = r - (1 if right > p2 else 0)
                    allPossibleMatchups(mask ^ (1 << right), left + 1, right - 1, p1, p2, rounds, new_l, new_m, new_r)
        
        mask = (1 << n) - 1
        p1 = firstPlayer - 1
        p2 = secondPlayer - 1
        
        allPossibleMatchups(mask, 0, n - 1, p1, p2, 1, p1, p2 - p1 - 1, n - 1 - p2)
        
        return [self.min_rounds, self.max_rounds]