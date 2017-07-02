import java.util.*;
/*The solution for the mazing problem by BackTracking
The input and output are the square matrix of order size
where the 1 indicates the prescence of path and 0indicates the blockof path
*/

class Backtrack{
	
	public static int size; 
	
	static boolean backtrack(int A[][],int solution[][],int i,int j){
		
		if(i==size-1 && j==size-1)
		{	solution[i][j] = 1;
			return true;
		}
		boolean v = false,w = false;
		if(i!=size-1 && A[i+1][j] == 1)
			v = backtrack(A,solution,i+1,j);
		if(j!=size-1 && A[i][j+1] == 1)
			w = backtrack(A,solution,i,j+1);
		if(v | w)
		{	solution[i][j] = 1;
			return true;
		}
		else
			return false;
	} 
		
	
	public static void main(String args[]){
		
		Scanner in = new Scanner(System.in);
		System.out.println("Enter size");
		size = in.nextInt();
		int A[][] = new int[size][size];
		int solution[][] = new int[size][size];
		System.out.println("\nEnter maze: ");
		
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
			{
				A[i][j] = in.nextInt();
				solution[i][j] = 0;
			}
		boolean t = backtrack(A,solution,0,0);
		if(t)
		{	System.out.println();
			for(int i=0;i<size;i++)
			{	for(int j=0;j<size;j++)
					System.out.print(solution[i][j] + "\t");
				System.out.println();
			}	
				
		}
		else
			System.out.println("Path doent exist");
	}
}			
