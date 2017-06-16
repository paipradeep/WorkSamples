//java CopyFile sourceFile destinationFile
//Any other format of command line will result in handled Exceptions

import java.io.*;

class CopyFile{

	public static void main(String args[]) throws IOException
	{
		int i;
		FileInputStream fin;
		FileOutputStream fout;
		try{
			try{
				fin = new FileInputStream(args[0]);
			}catch(FileNotFoundException e)
			{	//If Source file is absent
				System.out.println("Input file not specified");
				return;
				
			}
			
			try{
				fout = new FileOutputStream(args[1]);
			}catch(FileNotFoundException e)
			{
				System.out.println("Output file not specified");
				return;
			}
			
		}catch(ArrayIndexOutOfBoundsException e)
		{	//If command line format is wrong
			System.out.println("Wrong format\njava Copyfile inputfile outputfile");
			return;
		}
		
		try{
			do{
				i = fin.read();
				if(i!=-1)
					fout.write(i);
			}while(i!=-1);
		}catch(IOException e)
		{
			System.out.println("File error!!!");
		}
		//Closing of Opened files
		fin.close();
		fout.close();
	}
}
