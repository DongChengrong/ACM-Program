#encoding:utf-8
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        llen = 0;
        myList = []
        
        #计算root的长度
        p = root
        while p is not None:
            llen = llen+1
            p = p.next
        
        #计算最少的部分有几个元素
        #计算有几部分多出一个元素
        n = llen / k;
        c = llen % k;
        
        p = root #指向要被选择的元素

        #加入列表
        for i in range(0,k):
            head = ListNode(1) #每一部分的头
            if n == 0 and i >= c:
                myList.append(None)
            else:
                q = head
                if i < c:
                    for j in range(0,n+1):
                        q.next = p
                        p = p.next
                        q = q.next
                        q.next = None
                        
                else:
                    for j in range(0,n):
                        q.next = p
                        p = p.next
                        q = q.next
                        q.next = None
                        
                head = head.next
                myList.append(head)
        
        return myList
