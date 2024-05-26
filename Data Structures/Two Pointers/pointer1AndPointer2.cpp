// Pointer-1 and Pointer-2 from Two Sequences
//In some other scenarios, we need to compare in two sequences. Each pointer represents the current logical position in the corresponding sequence.

# p1 & p2 from two sequences: p1-> p2->
def pointers_from_two_seq(self, seq1, seq2):
    # init pointers
    p1, p2 = 0, 0       # or seq1[0], seq2[0]
    # or other condition
    while p1 < len(seq1) and p2 < len(seq2):
        # p1 index moves when satisfy the condition
        if self.p1_condition(p1):
            p1 += 1         # or p1 = next(seq1)
        # p2 index move when satisfy the condition
        if self.p2_condition(p2):
            p2 += 1         # or p2 = next(seq2)
        # process logic before or after pointers movement
        self.process_logic(p1, p2)

//Design a class which receives a list of words in the constructor and implements a method that takes two words, word1 and word2, and returns the shortest distance between these two words in the list.
//https://leetcode.com/problems/shortest-word-distance-ii/
/*Idea: First, we create a group of index sequences, locations, for each word. Every time shortest function is called,
we pick up the corresponding sequences loc1 and loc2. 
Then we use two pointers, l1 and l2, to calculate the shortest distance. In each iteration, the smaller pointer moves one step forward. */



//Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
// /https://leetcode.com/problems/wildcard-matching/
/*Idea: Assign one pointer s_cur for the target string and another p_cur for the pattern.
The two pointers record the current match position. When matching '*', match and star are the flags that help to backtrack if matching failed in greedy.*/
