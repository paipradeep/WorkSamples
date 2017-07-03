import java.util.*;

class NQueen{

	public static int N;
	
	public static boolean isSafe(int[][] A,int row,int column){
	
		for(int i=0;i<row;i++)
			if(A[i][column] == 1)
				return	false;
		int i=row,j=column;
		while(i>0 && j>0)
		{
			if(A[i--][j--] == 1)
				return false;
		}
		i = row;
		j = column;
		while(i>0 && j<N)
		{
			if(A[i--][j++] == 1)
				return false;
		}
		
		return true;
	}
	public static boolean place(int[][] A,int row){
	
		if(row>=N)
			return true;
		for(int i=0;i<N;i++)
		{
			if(isSafe(A,row,i))
			{
				A[row][i] = 1;
				if(place(A,row+1))
					return true;
				A[row][i] = 0;
			}
		}
		return false;
	}
	
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the size of the board");
		N = in.nextInt();
		int A[][] = new int[N][N];
		
		if(place(A,0))
		{	
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
					System.out.print(A[i][j] + "\t");
				System.out.println();
			}
		}
		else
			System.out.println("Cannot be placed");
	}
}
