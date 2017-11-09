//Longest common subsequence
import java.lang.Math.*;
import java.util.*;
class LCS{

	public static int lcs(String str1,String str2){
		int m = str1.length();
		int n = str2.length();
		int arr[][] = new int[m+1][n+1];
		for(int i=0;i<=m;i++)
			for(int j=0;j<=n;j++){
				if(i==0 || j==0)
					arr[i][j] = 0;
				else if(str1.charAt(i-1) == str2.charAt(j-1))
					arr[i][j] = 1 + arr[i-1][j-1];
				else
					arr[i][j] = Math.max(arr[i-1][j],arr[i][j-1]);
			}
		for(int i=0;i<m+1;i++){
			for(int j=0;j<n+1;j++)
				System.out.print(arr[i][j]+" ");
			System.out.println();
		}
		
	}

	public static void main(String args[]){
		String str1,str2;
		Scanner in = new Scanner(System.in);
		str1 = in.nextLine();
		str2 = in.next();
		System.out.println("Longest Common Subsequence:" + LCS.lcs(str1,str2));
	}
}
