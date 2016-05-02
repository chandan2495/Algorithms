#include<malloc.h>
using namespace std;

class StringMethods
{
public:
	StringMethods();
	int kmp(string text, string pattern);		
};

StringMethods::StringMethods() {

}

int StringMethods:: kmp(string text, string pattern) {
	int *prefixSuffix;
	int pLen, tLen,j,i;
	pLen = pattern.length();
	tLen = text.length();

	// calculate prefix-suffix of pattern
	prefixSuffix = (int*)calloc(sizeof(int),(pLen+1));	
	prefixSuffix[0]=-1;
	for(i=1,j=-1;i<pLen;) {
		while(j>=0 && pattern[i]!=pattern[j]) // if not matched go back to find last prefixsuffix match
				j = prefixSuffix[j];									
		i++,j++;
		prefixSuffix[i]=j;	// if match store j+1
	}

	// start pattern search in main text using prefixSuffix array
	i=0; j=0;
	while(i<tLen) {
		while(j>=0 && text[i]!=pattern[j]) 
			j = prefixSuffix[j];
		j++;i++;
		if (j==pLen)
		{
			printf("Found pattern at index %d\n", i-j);
			j = prefixSuffix[j];	// reset j to find all the patterns in text
		}
	}
}