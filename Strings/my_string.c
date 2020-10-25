#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "string.h"
#define SIZE 96
#define N 10000


void string_character_occurence(char *str)
{
	int characters[SIZE], ch;
	int i;
	
	for (i = 0; i < SIZE; i++)
		characters[i] = 0;
	for (i = 0; str[i] != '\0'; i++) {
		characters[(int)str[i] - 32]++;
	}
	printf("%-12s%-8s\n", "Character", "Count");
	printf("____________________\n");
	for (i = 0; i < SIZE; i++) {
		if (characters[i] > 0) {
			printf("%-12c", (char)(i + 32));
			printf("%-8d\n", characters[i]);
		}
	}
}

int string_is_palindrome(char *str)
{
	int len = strlen(str), i, j;
	
	for (i = 0, j = len - 1; i < j; i++, j--) {
		while (isspace(str[i]))
			i++;
		while (isspace(str[j]))
			j--;
		if (i < j)
			if (str[i] != str[j])
				return 0;
	}
	return 1;
}


char* string_strcpy(char *str)
{
	int len = strlen(str), i;
	char *copy = (char*)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return NULL;
	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[i] = '\0';
	return copy;
}

char* string_strcat(char *original, char *add_on)
{
	int len1 = strlen(original), len2 = strlen(add_on), i, j;
	char *new_str = (char*)malloc(sizeof(char) *(len1 + len2 + 1));
	if (new_str == NULL)
		return NULL;
	for (i = 0; i < len1; i++)
		new_str[i] = original[i];
	for (j = 0; j < len2; i++, j++)
		new_str[i] = add_on[j];
	new_str[i] = '\0';
	return new_str;
}


void string_substrings(char *str)
{
	char str2[100];
	int status = 1, str_len = strlen(str), i, j, k,
		is_substring;
	
	status = scanf("%s", str2);
	while (status != EOF) {
		for (i = 0; i <= str_len - strlen(str2); i++) {
			if (str2[0] == str[i]) {
				is_substring = 1;
				for (j = 1, k = i + 1; str2[j] != '\0' && is_substring; j++, k++) {
					if (str2[j] != str[k])
						is_substring = 0;
				}
				if (is_substring) {
					printf("%s\n", str2);
					break;
				}
			}
		}
		status = scanf("%s", str2);
	}
}

void string_delete_multiple_blanks(char *str)
{
	int i, j, k;

	for (i = 0, j = 0; str[i] != '\0'; ++i, j = i)
		if (isspace(str[i])) {
			while (isspace(str[j]))
				j++;
			k = j - i;
			if (k > 1)
				for (; j <= strlen(str); j++)
					str[j - (k - 1)] = str[j];
		}
}

void string_pointer_3_15(char *p)
{
	int i, j, t;
	char a[N], *tempa, *tempp;
	for (tempa = a, i = 0; i < N - 1; *tempa = t, i++, tempa++)
		if ((t = getchar()) == EOF)
			break;
	*tempa = 0;
	for (tempa = a; *tempa; tempa++) {
		for (tempp = p; *tempp; tempp++) {
			if (*(a + ((tempa - a) + (tempp - p))) != *tempp)
				break;
		}
		if (*tempp == 0)
			printf("%d ", tempa - a);
	}
	printf("\n");
}


int string_longest_sequence_of_blanks(char *str)
{
	int len = strlen(str);
	int max_count = 0, count, i;
	for (i = 0; i < len - max_count; i++)
		if (isspace(str[i])) {
			for (count = 0; isspace(str[i]); count++, i++);
			if (count > max_count)
				max_count = count;
		}
	return max_count;
}
