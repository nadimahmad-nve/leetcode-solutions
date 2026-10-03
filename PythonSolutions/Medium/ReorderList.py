class Solution:
    def reorderList(self, head: ListNode | None) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        # Use fast & slow pointer, move to the middle 
        # Sever the list there. 
        # Reverse the second half (because we need to traverse backwards)
        # Zip them together

        slow = head 
        fast = head 

        while fast.next != None:
            if fast.next.next == None: 
                fast = fast.next 
                break 
            else:
                fast = fast.next.next
            
            slow = slow.next
        
        
        secondList = slow.next 
        
        # Reverse the second list 
        prev = None 
        curr = secondList 

        while curr != None: 
            temp = curr.next 
            curr.next = prev 
            prev = curr 
            curr = temp 
        
        secondList = prev 
        firstList = head 

        # Stitch them together
        dummy = ListNode()
        curr = dummy 

        count = 0

        while curr != None: 
            if count % 2 == 0: 
                # First list 
                curr.next = firstList 
                curr = firstList 

                if firstList != None: 
                    firstList = firstList.next 
            else:
                # Second List
                curr.next = secondList
                curr = secondList

                if secondList != None:
                    secondList = secondList.next 
            
            count += 1
        
        return dummy.next 
