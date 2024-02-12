# TODO: This is not complete yet
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = [[]]
        q = deque()
        q.append([root,0])
        col_min = 0
        col_map = defaultdict(list) # initializes empty list if key does not exist

        while q:
            curr = q[0][0]
            col = q[0][1]
            q.popleft()

            if(col_min < col):
                col_min = col

            col_map[col].append(curr.val)

            if curr.left:
                q.append([curr.left,col-1])
            if curr.right:
                q.append([curr.right,col+1])

        i = col_min
        while i in col_map:
            res.append(col_ma[i])
            i += 1

        return res
