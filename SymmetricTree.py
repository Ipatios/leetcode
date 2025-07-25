class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSymmetric(self, root: [TreeNode]) -> bool:

        def is_mirror(n1, n2):  # n1:left, n2:right
            if not n1 and not n2:
                return True

            if not n1 or not n2:
                return False

            return (
                n1.val == n2.val
                and is_mirror(n1.left, n2.right)
                and is_mirror(n1.right, n2.left)
            )

        return is_mirror(root.left, root.right) #here is where the recursion starts 

def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(3)
    s = Solution()
    print(s.isSymmetric(root))


if __name__ == "__main__":
    main()
