# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        node = root
        if node is None:
            return 0
        left_length = self.maxDepth(node.left)
        right_length = self.maxDepth(node.right)
        return max(left_length, right_length) + 1
