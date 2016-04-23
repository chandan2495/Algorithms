#include<stdio.h>

int mergesort(int a[],int left,int right){
	if(left<right){
		int mid=(left+right)/2;
		mergesort(a,left,mid);
		mergesort(a,mid+1,right);
		merge(a,left,right);
	}
}

int merge(int a[], int left, int right){
	int b[100],i,j,mid,k;
	mid=(left+right)/2;
	i=left;j=mid+1;
	k=0;
	while(i<=mid&&j<=right){
		if(a[i]<a[j])
			b[k++]=a[i],i++;
		else
			b[k++]=a[j],j++;
	}
	while(i<=mid)
		b[k++]=a[i],i++;
	while(j<=right)
		b[k++]=a[j],j++;			
	for(i=0;i<k;i++){
		printf("%d ", b[i]);		
		a[i+left]=b[i];
	}
}

int main(){
	int n=5,a[]={1,7,5,2,41},i;	
	mergesort(a,0,n-1);
	printf("\n");
	for(i=0;i<5;i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}