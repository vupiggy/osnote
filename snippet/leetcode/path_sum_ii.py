# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, sum):
        solution = []
        self.allPathSum(root, sum, [], solution)
        return solution
    
    def allPathSum(self, root, sum, path, solution):
        if root == None:
            return
        path.append(root.val)
        if root.left == None and root.right == None:
            if root.val == sum:
                solution.append(list(path))
        else:
            self.allPathSum(root.left, sum - root.val, path, solution)
            self.allPathSum(root.right, sum - root.val, path, solution)
        path.pop()
