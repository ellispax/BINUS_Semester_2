Challenge 1

Creat a method named ScaleBalancing that reads in a String which will contain two elements, the first being the two
positive integer weights on a balance scale (left and right sides) and the second element being a list of available weights as
positive integers.
Your goal is to determine if you can balance the scale by using the least amount of weights from the list but using at most only 2
weights.
For example: if the String contains ["5, 9", "1, 2, 6, 7"] then this means there is a balance scale with a weight of 5 on the left side
and 9 on the right side. It is in fact possible to balance this scale by adding a 6 to the left side from the list of weights and adding a
2 to the right side. Both scales will now equal 11 and they are perfectly balanced.
Your program should return a comma
separated string of the weights that were used from the list in ascending order, so for this example your program should return
the string 2,6.

There will only ever be one unique solution and the list of available weights will not be empty. It is also possible to add two
weights to only one side of the scale to balance it. If it is not possible to balance the scale then your program should return the
string not possible.

Sample Test Cases

Input:new String[] {"3, 4", "1, 2, 7, 7"}


Output:"1"

Input:new String[] {"13, 4", "1, 2, 3, 6, 14"}

Output:"3,6"


Challenge 2

Create a method named CorrectPath that reads in a String parameter being passed, which will represent the movements
made in a 5x5 grid of cells starting from the top left position. The characters in the input string will be entirely composed of: r, l,
u, d, ?. 
Each of the characters stand for the direction to take within the grid, for example: r = right, l = left, u = up, d = down.
Your goal is to determine what characters the question marks should be in order for a path to be created to go from the top left of the
grid all the way to the bottom right without touching previously travelled on cells in the grid.

For example: if str is "r?d?drdd" then your program should output the final correct string that will allow a path to be formed
from the top left of a 5x5 grid to the bottom right. For this input, your program should therefore return the string rrdrdrdd.
There will only ever be one correct path and there will always be at least one question mark within the input string.

Sample Test Cases

Input:"???rrurdr?"

Output:"dddrrurdrd"

Input:"drdr??rrddd?"

Output:"drdruurrdddd"
