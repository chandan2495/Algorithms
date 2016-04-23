#include<stdio.h>

int quicksort(int a[],int left, int right){
	if(left<right){
		int mid=partition(a,left,right);
		printf("%d %d %d\n",left,mid,right);
		quicksort(a,left,mid-1);
		quicksort(a,mid+1,right);
	}
}

int partition(int a[],int left, int right){
	int pivot=a[left],temp;
	while(left<right){
		while(a[left]<pivot)
			left++;
		while(a[right]>pivot)
			right--;
		if(left<right)
		{
			temp=a[left];
			a[left]=a[right];
			a[right]=temp;
		}
	}
	return left;
}

int main(){
	int n=5,a[]={1,7,5,2,41},i;	
	quicksort(a,0,n-1);
	printf("\n");
	for(i=0;i<5;i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}