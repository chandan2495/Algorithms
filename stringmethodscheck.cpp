#include<iostream>
#include<stdio.h>
#include<string>
#include "StringMethods.h"

using namespace std;
int main() {
	string text,pattern;
	cin>>text;
	cin>>pattern;
	StringMethods stringHelper;
	stringHelper.kmp(text, pattern);
	return 0;
}