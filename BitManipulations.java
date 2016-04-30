import java.io.*;
import java.util.*;

class BitManipulationsImpl {

	// Returns next big number having same number of one's as given number
	int getNextBigNumber(int n) {
		int c0=0,c1=0,p,temp;		
		temp = n;
		// get number of trailing zeros from rightmost side
		while((temp&1)==0 && temp!=0)
		{
			c0++;
			temp = temp>>>1;			
		}
		System.out.println("Zero's count " + c0);
		// get number of trailing ones after zeros from rightmost side
		while((temp&1)==1)
		{
			c1++;
			temp = temp>>>1;
		}
		System.out.println("One's count " + c1);
		p = c0+c1;
		if(p==31 || p==0)	// in case given number is largest (p==31 e.g. 11110000...00)
		{
			return -1;
		}
		else {
			n = (n | (1<<p));	// flip pth bit to 1
			n = (n & (~0 << p));	// clear all bits in right of pth bit
			n =  n | ( ( 1<< (c1-1) )-1 );	// set c0+1 zero's followed by c1-1 one's after pth bit
			return n;
		}
	}
	int getNextSmallNumber(int n) {
		int c0=0,c1=0,p,temp;		
		temp = n;
		// get number of trailing ones after zeros from rightmost side
		while((temp&1)==1)
		{
			c1++;
			temp = temp>>>1;
		}
		System.out.println("One's count " + c1);

		// get number of trailing zeros from rightmost side
		while((temp&1)==0 && temp!=0)
		{
			c0++;
			temp = temp>>>1;			
		}
		System.out.println("Zero's count " + c0);

		p = c0+c1;
		if(p==31 || p==0)	// in case given number is smallest (p==31 e.g. 000001111.....11)
		{
			return -1;
		}
		else {
			n = (n | ~(1<<p));	// flip pth bit to 0
			n = (n & (~0 << p));	// clear all bits in right of pth bit
			n =  n | ( ( 1<< (c1+c0) )-1 );	// set c1 one's followed by c0 zero's after pth bit
			return n;
		}
	}
}

class BitManipulations {
	public static void main(String []args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a number : ");
		int n = sc.nextInt();
		int next = 0,prev=0;
		next = (new BitManipulationsImpl()).getNextBigNumber(n);
		if (next == -1) {
			System.out.println("There is no number greater then " + n);
		}
		else {
			System.out.println("Next greater number is : " + next);
		}
		prev = (new BitManipulationsImpl()).getNextSmallNumber(n);
		if (prev == -1) {
			System.out.println("There is no number smaller then " + n);
		}
		else {
			System.out.println("Next smaller number is : " + prev);
		}
	}
}