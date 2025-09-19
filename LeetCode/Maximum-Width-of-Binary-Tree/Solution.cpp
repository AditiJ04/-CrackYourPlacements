    public int WidthOfBinaryTree(TreeNode root) {
        if (root == null)
            return 0;
        var max = 1;
        var queue = new Queue<(TreeNode, int)>();
        queue.Enqueue((root, 0));
        var first = -1;
        var last = 0;
        var offset = 0;
        while (queue.Count > 0)
        {
            var total = queue.Count;
            for (var i = 0; i < total; i++)
            {
                var cur = queue.Dequeue();
                var node = cur.Item1;
                var idx = cur.Item2;
                if (first < 0)
                {
                    offset = idx;
                    first = 0;
                }
                last = idx - offset;

                if (node.left != null)
                    queue.Enqueue((node.left, last * 2 + 1));

                if (node.right != null)
                    queue.Enqueue((node.right, last * 2 + 2));
            }

            max = Math.Max(max, last - first + 1);
            first = -1;
            last = 0;
        }
        return max;
   }