/*Another common usage is putting pointers on the left-most side and right-most side. 
One pointer starts from the beginning, while the other pointer starts from the end. They move toward each other until they meet in the middle. */

# left & right boundary: left-> <-right
def left_right_boundary(self, seq):
    left, right = 0, len(seq) - 1
    while left < right:
        # left index moves when satisfy the condition
        if self.left_condition(left):
            left += 1
        # right index move when satisfy the condition
        if self.right_condition(right):
            right -= 1
        # process logic before or after pointers movement
        self.process_logic(left, right)

  /*Left and right pointers form an interval to process.
These two pointers carry information and handle the logic in each iteration.*/
  
  /* The most classic and famous example is binary search. We find the target by shrinking the lower and upper bounds continuously.
  We cut off the half of the interval in each iteration. The following example is a version with both lower and upper bounds included.*/

  /*Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number. */
  // https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

  /*Find all unique quadruplets in the array which gives the sum of target.*/
  // https://leetcode.com/problems/4sum/


  /*Find two lines, which together with x-axis form a container, such that the container contains the most water possible.*/

  https://leetcode.com/problems/container-with-most-water/
