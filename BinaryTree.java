import java.util.*;

class BinaryTree
{
	class Node
	{
		int data;
		Node left,right;
		Node(){}
		Node(int data)
		{
			this.data = data;
			this.left = null;
			this.right = null;
		}
	}
	Node root;
	BinaryTree()
	{
		root = null;
	}
	
	public Node insertNode(Node root,int data)
	{
		if(root == null)
		{
			root = new Node(data);
			return root;
		}
		if(data <= root.data)
			root.left = insertNode(root.left,data);
		else
			root.right = insertNode(root.right,data);
		return root;
	}
	
	public void inorder(Node root)
	{
		if(root == null)
			return;
		inorder(root.left);
		System.out.print("\t" + root.data);
		inorder(root.right);
	}
	
	public static void main(String args[])
	{
		BinaryTree B = new BinaryTree();
		Scanner in = new Scanner(System.in);
		int choice,data;
		while(true)
		{
			System.out.println("\nEnter choice\n1-insert Node\n2- Display");
			choice = in.nextInt();
			switch(choice)
			{
				case 1:	System.out.println("\nEnter data");
					data = in.nextInt();
					B.root = B.insertNode(B.root,data);
					break;
				case 2:	B.inorder(B.root);
					break;
			}
		}
	}
}
		
