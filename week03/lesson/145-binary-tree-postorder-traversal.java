/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        seq = new ArrayList<Integer>();
        find(root);
        return seq;
    }
    private void find(TreeNode root) {
        if (root == null) return;
        find(root.left);
        find(root.right);
        seq.add(root.val);
    }
    private List<Integer> seq;

}