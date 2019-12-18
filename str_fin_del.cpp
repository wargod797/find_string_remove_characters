#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define NO_OF_CHARS 256
using namespace std;

int *getCharCountArray(char *str)
{
int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
int i;
for (i = 0; *(str+i); i++)
	count[*(str+i)]++;
return count;
}

char *removeDirtyChars(char *str, char *mask_str)
{
int *count = getCharCountArray(mask_str);
int ip_ind = 0, res_ind = 0;
while (*(str + ip_ind))
{
	char temp = *(str + ip_ind);
	if (count[temp] == 0)
	{
		*(str + res_ind) = *(str + ip_ind);
		res_ind++;
	}
	ip_ind++;
}

/* After above step string is ngring.
	Removing extra "iittg" after string*/
*(str+res_ind) = '\0';

return str;
}

/* Driver program to test getCharCountArray*/
int main()
{
	char str[50];
	char mask_str[50];
	cout<<"Enter the String = ";cin>>str;
	cout<<"Enter the String letters delete = ";cin>>mask_str;
	cout<<removeDirtyChars(str, mask_str);
	return 0;
}

