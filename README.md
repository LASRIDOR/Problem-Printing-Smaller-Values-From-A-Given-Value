# Problem of Printing Smaller Values From A GivenValue
A program in C ++, in which the problem of printing small values from a given value described below will be solved in several ways, according to some algorithms we have learned
In the course Data Structures, you will compare the effectiveness of the various solutions.

# Problem printing values smaller than a given value
Given n members when each member contains a key and data, and another key, K must be printed
All data with the keys small from K-sorted from small to large.
Suppose: all the keys are different from each other.

# Detailed description of the purpose of the exercise:
The purpose of the exercise is to implement a number of solutions to the problem of printing small values from a given set, to investigate and analyze the differences between the different solutions with respect to n, r when r is
Number of data printed.

# The solutions you need to implement are:
1. An algorithm that goes through the array of members, and copies from it all the data with a key smaller than k, to a chained list when the entry is sorted (the list is sorted at any moment) then the list will be printed on the screen.
2. An algorithm that constructs a binary search tree (normal, unbalanced) from the members, when all the members are put one by one into the tree, and then prints the members inorder until it reaches a value greater than or equal to k.
3. An algorithm that sorts the array into a quick-sort sort (which you must implement) and then prints the members until it encounters a value greater than or equal to k.

The main plan:

Main function of the program:

1. Read from stdin (from the keyboard, not a file) an integer,, n that denotes the number of members, and then read n pairs of numbers followed by a string, each in a row. The integer in each pair indicates the identity number of a player, and the string its name. Check that each name does consist of 2 words separated by a space (first name, space, last name.)
You will then absorb an integer k

For example, the following input:
6
132 Lebron James
118 Stephen Curry
313 Kevin Durant
514 Michael Jordan
323 Dennis Rodman
606 Scottie Pippen
318

Is an input of six players, with the sort key being their ID number, and the name being their satellite data. All data with the ID number must be printed
Their is smaller than 318 in a sorted way and therefore must be printed on the screen:

118 Stephen Curry
132 Lebron James
313 Kevin Durant

2. Run each of the three functions described above on the data series and you will receive from each function the number of comparisons made in addition to the prints that occur in it.
Note: The sorted data will be printed 3 times.
3. Print the number of comparisons in the following format on the screen:
comparisons 130: NaivePrint

BSTPrint: 200 comparisons

PrintBySort: 500 comparisons

(The numbers of the comparisons listed in the example are of course fabricated.)
