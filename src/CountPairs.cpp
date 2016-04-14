/*
You have been given a string and its length .
Two letters are said to be a pair ,If they are equal and have a character in between them .

Ex : In aba ,a[0] and a[2] are pairs becuase both are 'a' and have one letter 'b' in between .

Ex: In abab , There are two pairs ,Two 'a's and ,Two 'b's .

In abbbb; there are Two pairs , (a[1],a[3]),(a[2],a[4]);

Input : String and length of string
Output : return Total number of pairs Count .

Example Input : count_pairs_wrapper("zzzaz",5);
Example Output : 2

Hint : You can use count_pairs_wrapper as a wrapper function for your original recursive function which might take
more parameters .

NOTE : Donot use any Global Variables
*/

#include "stdafx.h"

//You can use this function ,for the actual recursion .Think of similar functions for all other problems.
int count_pairs(char *str, int len, int start, int end, int count){

	if (end == len)  //if end value equal to length of string thrn returning count
		return count;
	if (str[start] == str[end])       //if alternate positions are equal incrementing count
		count++;
	return count_pairs(str, len, start + 1, end + 1, count);
}

int count_pairs_wrapper(char *str, int len){
	//Wrapper function which might call a recursive function ,which might take extra parameters .
	if (str == NULL || len <= 2)       //zeroString case
		return 0;
	int result = 0;
	result = count_pairs(str, len, 0, 2, 0); //starting comparing at alternative postions
	return result;

}


