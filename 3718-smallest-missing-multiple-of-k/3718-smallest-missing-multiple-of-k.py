class Solution(object):
    def missingMultiple(self, nums, k):
        current= set(nums)
        multi=k
        while multi in current:
            multi +=k
        return multi

        