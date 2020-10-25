#ifndef MY_STRING_H
#define MY_STRING_H

/*3.56
Prints out a table giving, for each character in the string
the character and its frequency of occurence. Looks for characters
on the ASCII table from 32-126*/
void string_character_occurence(char *str);


/*3.57
Checks if a string is a plaindrome, ignoring blanks.
Returns true if it is, else false*/
int string_is_palindrome(char *str);

/*3.58
Returns a pointer to a copy of string "str" that was allocated
to the heap and reutnrs a pointer to a new string that is a 
concatenation of original and add_on*/
char* string_strcpy(char *str);
char* string_strcat(char *original, char *add_on);

/*3.59
Prints out words from stdin that appear as substrings in str*/
void string_substrings(char *str);

/*3.60
Replaces substrings of more than one blank in a string by exactly one string*/
void string_delete_multiple_blanks(char *str);

/*3.61
Pointer version of program 3.15
Discovers all occurences of a word from the command line
in a much larger text string (str)*/
void string_pointer_3_15(char *p);

/*3.62
Finds the length of the longest sequence of blanks in a given string,
examining as few characters as possible in the string*/       
int string_longest_sequence_of_blanks(char *str);

 #endif
