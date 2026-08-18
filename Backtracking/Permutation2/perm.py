class Solution:
    def doBackTrack(self, ans, idx, nums):
        n = len(nums)

        if idx == n:
            ans.append(nums.copy())
            return

        st = set()

        for i in range(idx, n):
            if nums[i] in st:
                continue

            st.add(nums[i])

            nums[i], nums[idx] = nums[idx], nums[i]

            self.doBackTrack(ans, idx + 1, nums)

            nums[i], nums[idx] = nums[idx], nums[i]

    def permuteUnique(self, nums):
        ans = []
        self.doBackTrack(ans, 0, nums)
        return ans