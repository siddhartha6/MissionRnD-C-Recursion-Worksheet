/*

You have N steps to climb .
You can either take one step or two steps at a time .
You need to find the total number of ways you can reach N steps .

Example : For N=4 , You can either reach 4 steps in following ways
->1111
->112
->121
->211
->22
So total number of ways is 5

Input : A Integer denoting N (number of steps )
Output : Return an Integer denoting the number of ways to reach N steps

Example Input : get_steps(5)
Example Output : Returns 8

Note : Test Cases would be small <25.

*/

int test[25];
int count_steps(int s)
{
	if (s <= 1)
		return s;
	if (test[s] != -1)
		return test[s];         //if already test[s] value is in memory then returning it directly
	test[s] = count_steps(s - 1) + count_steps(s - 2);     //fibonacci series
	return test[s];
}
int get_steps(int s)
{
	if (s <= 0)
		return 0;
	int index = 0, result = 0;
	for (index = 0; index <= s + 1; index++)
	{
		test[index] = -1;
	}
	result = count_steps(s + 1); //no of ways of getting steps will be (s+1)th fibonacci term
	return result;
}
