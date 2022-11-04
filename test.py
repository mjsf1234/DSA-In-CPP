class Solution:
   def solve(self, weights, values, capacity):
      def dp(i, k):
         if i == len(weights):
            return 0
         ans = dp(i + 1, k)
         if k >= weights[i]:
            ans = max(ans, dp(i, k - weights[i]) + values[i])
         return ans
      return dp(0, capacity)
ob = Solution()
weights = [6, 8, 4,10,7,5]
values = [12, 24, 20,30,27,25]
capacity = 30
print(ob.solve(weights, values, capacity))