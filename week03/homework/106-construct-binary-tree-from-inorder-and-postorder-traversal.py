# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        # 其实判断一个即可，毕竟inorder 和 postorder长度一致，如果一个为None，另一个也为None
        if not inorder:
        # if not inorder or not postorder:
            return None
        # 获取后序遍历的最后一个元素作为根节点
        node = TreeNode(postorder[-1])
        # 根节点在中序遍历中的位置index
        index = inorder.index(node.val)
        node.left = self.buildTree(inorder[0:index], postorder[0:index])
        # Python3 切片原则：前闭后开
        # 取值范围：中序遍历，起始为index+1，去掉根节点；同理，后序遍历，结尾位置为len(postorder)-1，去掉根节点；
        node.right = self.buildTree(inorder[index+1:len(inorder)], postorder[index:len(postorder)-1])
        return node