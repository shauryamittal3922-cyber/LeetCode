# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode | None) -> list[list[int]]:
        
        res = []

        def bfs(node, depth):
            if not node:
                return []

            if(len(res)) == depth:
                res.append([])

            res[depth].append(node.val)

            bfs(node.left, depth+1)
            bfs(node.right, depth+1)
        
        bfs(root, 0)
        return res