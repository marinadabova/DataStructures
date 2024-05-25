//Two pointers -fast and slow

/* The first idea is to use two pointers as slow runner and fast runner. Each of them flags a key point during traversal.
In general, fast runner grows each iteration and slow runner grows with some restrictions. 
By that, we can process logic based on these two runners.*/

# slow & fast runner: slow-> fast->->
def slow_fast_runner(self, seq):
    # initialize slow runner
    slow = seq[0]   # for index: slow = 0
    # fast-runner grows each iteration generally
    for fast in range(seq):     # for index: range(len(seq))
        #slow-runner grows with some restrictions
        if self.slow_condition(slow):
            slow = slow.next    # for index: slow += 1
        # process logic before or after pointers movement
        self.process_logic(slow, fast)


/*A classic example is to remove duplicates from a sorted array.
We can use the fast runner to represent the current element and use the slow runner to flag the end of the new, non-duplicate array.*/
//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

  
/*Given a linked list, remove the n-th node from the end of the list and return its head. */
 // https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
