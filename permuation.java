import java.io.*;
import java.util.*;

class Permutation{
	public static void genPermutation(String s, String prefix) {
		if (s.length()==0) {
			System.out.println(prefix);
			return;
		}
		for (int i=0;i<s.length() ;i++ ) {
			String temp = s.substring(0,i) + s.substring(i+1);
			genPermutation(temp, prefix + s.charAt(i));
		}
	}

	public static void main(String[] args) {
		String s;
		Scanner sc= new Scanner(System.in);
		s = sc.nextLine();
		genPermutation(s,"");
	}
}

