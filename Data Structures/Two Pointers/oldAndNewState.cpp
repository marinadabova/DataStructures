//
/*Another idea is to use two pointers as variables.
In the whole algorithm process, variables store intermediate states and participate in the calculation to generate new states. 
*/
# old & new state: old, new = new, cur_result
def old_new_state(self, seq):
    # initialize state
    old, new = default_val1, default_val2
    for element in seq:
        # process current element with old state
        old, new = new, self.process_logic(element, old)

          
/* Calculate cur_result based on old_state and cur_element of the sequence.
Before assigning cur_result to new_state, store the value of new_state to old_state first.
Regard cur_result as the new_state.
After traversing the whole sequence, the results are calculated based on old_state and new_state.*/

/* A simple and classic example is calculating a Fibonacci number.
Each number is the sum of the two preceding ones, starting from 0 and 1.
*/

          //https://leetcode.com/problems/fibonacci-number/description/

/*Determine the maximum amount of money you can steal tonight without robbing adjacent houses. */
          //https://leetcode.com/problems/house-robber/
//Merge two sorted linked lists and return a new list.
          //https://leetcode.com/problems/merge-two-sorted-lists/
//Given a non-empty string containing only digits, determine the total number of ways to decode it.
          //https://leetcode.com/problems/decode-ways/
    
