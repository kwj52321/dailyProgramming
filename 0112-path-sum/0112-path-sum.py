# Definition for a binary tree root.
# class Treeroot:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[Treeroot], targetSum: int) -> bool:
        if root == None:
            return False

        r_targetSum = targetSum - root.val

        if root.left == None and root.right == None:
            return r_targetSum == 0

        leftPath = self.hasPathSum(root.left, r_targetSum)
        rightPath = self.hasPathSum(root.right, r_targetSum)
        if leftPath or rightPath:
            return True

        return False
        