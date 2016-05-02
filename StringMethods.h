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
	prefixSuffix = (int*)malloc(sizeof(int)*pLen);
	prefixSuffix[0]=0;
	for(i=1,j=0;i<pLen;i++) {
		if(pattern[i]==pattern[j]) {
			prefixSuffix[i]=j+1;
			j++;
		} else {	// if not match reset j to 0
			j=0;
			if(pattern[i]==pattern[j]) {
				prefixSuffix[i]=j+1;				
				j++;
			}
		}		
	}

	// start pattern search in main text using prefixSuffix array
	i=0; j=0;
	while(i<tLen) {
		if (text[i+j] == pattern[j]) {
			j++;
		} else {
			i = i + j;
			j = prefixSuffix[j-1];
			i = i-j;
		}
		if (j==pLen) {
			printf("Found at index %d\n", i);
			break;
		}
	}
}