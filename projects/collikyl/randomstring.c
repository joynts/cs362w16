//inputChar(): This function returns a random character based on the ASCII value generated by a call to rand().
//The range of possible ASCII values are 32 - 127, with 32 representing a space, and 127 representing the NULL char
//as opposed to the DELETE char that it normally represents.
//inputString(): This function returns a random 6 char string. It fills in the char array by calling inputChar() six times.
//
//
//
//Analysis: The goal of the testing is to output the error message "error" using random values for the char and the string.
//In order to output the error message, the testme function must first reach case 9. In order to reach case 9, previous
//calls to inputChar must return the results '[' '(' '{' '' 'a' 'x' '}' ')' ']' in an ordered, non-contigous manner.
//Once case 9 is reached, the inputString() must return 'reset'. Returning 'reset' before case 9 is reached does not mean
//that 'error' will be printed once case 9 is reached, rather case 9 must first be reached before the final condition 'reset'
//can be evaluated. Reaching case 9 is fairly quick, however, the odds of having inputString() return 'reset' are abysmally low
//and random testing is incredibly inefficient in displaying this error. The total number of permutations of a 6 char string,
//consisting of 95 values is 95P6 = 625 757 605 200, so the odds of getting the specific string 'reset' are 1/(625 757 605 200).
