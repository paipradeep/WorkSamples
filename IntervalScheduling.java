import java.util.Scanner;
class IntervalScheduling{
	int start;
	int finish;
	public static int partition(IntervalScheduling IS[], int low, int high){
        	int pivot = IS[high].finish; 
       		int i = (low-1); 
        	for (int j=low; j<high; j++)
        	{
           
           		 if (IS[j].finish <= pivot)
            		 {
               			 i++;
               			 IntervalScheduling temp = IS[i];
                		 IS[i] = IS[j];
               			 IS[j] = temp;
           		 }
       		}
 	
       
       		IntervalScheduling temp = IS[i+1];
        	IS[i+1] = IS[high];
        	IS[high] = temp;
        	return i+1;
        }
 
        public static void sort(IntervalScheduling IS[], int low, int high)
    	{
        	if (low < high)
        	{
          
           		int pi = partition(IS, low, high);
           		sort(IS, low, pi-1);
           	 	sort(IS, pi+1, high);
        	}
        }

	public static int schedule(IntervalScheduling IS[],int n,int sch[]){
		//int n = finish.length;
		sch[0] = 0;
		int j=1;
		System.out.println("hufrggfru");
		for(int i=1;i<n;i++)
			if(IS[i].start>=IS[sch[j-1]].finish){
				//System.out.println(IS[i].start + " " +IS[j-1].finish);
				sch[j++] = i;
			}
		return j;
	}
	
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		System.out.println("Enter numer of jobs:");
		int n = in.nextInt();
		IntervalScheduling IS[] = new IntervalScheduling[n];
		for(int i=0;i<n;i++){
			IS[i] = new IntervalScheduling();
			System.out.println("Enter starting and finishing time:");
			IS[i].start = in.nextInt();
			IS[i].finish = in.nextInt();
		}
		sort(IS,0,n-1);
		/*System.out.println("Jobs after sorting");
		for(int i=0;i<n;i++)
			System.out.println(IS[i].start + " " + IS[i].finish);*/
		int sch[] = new int[n];
		int j=schedule(IS,n,sch);
		System.out.println("\nScheduled jobs are:");
		for(int i=0;i<j;i++)
			System.out.println(sch[i] + " " + IS[sch[i]].start + " to " + IS[sch[i]].finish);
			
	}
}			
		
