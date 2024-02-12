class Solution:
    """
    M lists, a list has at most N elements
    TIME: O(N*M log M) - we only heap sort M elements at a time
    SPACE: O(M)
    """
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # NOTE: In Python3, must specify a cmp operator
        ListNode.__eq__ = lambda self, other: self.val == other.val
        ListNode.__lt__ = lambda self, other: self.val < other.val

        minheap = []
        head = tail = ListNode(0) # dummy node
        for l in lists:
            if l:
                heapq.heappush(minheap, (l.val, l))

        while minheap:
            val, curr = heapq.heappop(minheap)
            tail.next = curr
            tail = tail.next
            if curr.next:
                heapq.heappush(minheap, (curr.next.val, curr.next))
        return head.next
