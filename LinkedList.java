import java.util.*;

class LinkedList
{
	class Node
	{
		int value;
		Node link;
		Node(){}
		Node(int value)
		{
			this.value = value;
			this.link = null;
		}
		Node(int value,Node next)
		{
			this.value = value;
			this.link = next;
		}
	}
	Node head;
	LinkedList()
	{
		head = null;
	}
	
	protected Node insertBeg(Node head,int value)
	{
		Node NN;
		if(head == null)
		{
			NN = new Node(value);
			return NN;
		}
		NN = new Node(value,head);
		return NN;
	}
	
	protected Node insertEnd(Node head,int value)
	{
		if(head == null)
		{
			Node NN = new Node(value);
			return NN;
		}
		head.link = insertEnd(head.link,value);
		return head;
	}
	
	protected Node insertAtPos(Node head,int value,int pos)
	{
		Node NN;
		int count = 2;
		if(head == null && pos ==1)
		{
			NN = new Node(value);
			return NN;
		}
		else if(head == null)
		{
			System.out.println("Invalid position");
			return head;
		}
		else if(pos == 1)
		{
			NN = new Node(value,head);
			return NN;
		}
		else
		{
			Node CN;
			CN = head;
			while(CN.link!=null && count<pos)
			{
				++count;
				CN = CN.link;
			}
			if(count == pos)
			{
				NN = new Node(value,CN.link);
				CN.link = NN;
			}
			else
				System.out.println("\nInvalid positin");
				
		}
		return head;
	}
	
	protected Node deleteBeg(Node head)
	{
		if(head == null)
		{	System.out.println("\nEmpty linkedlist");
			return head;
		}
		return head.link;
	}
	
	protected Node deleteEnd(Node head)
	{
		if(head == null)
		{	System.out.println("\nEmpty linkedlist");
			return head;
		}
		Node CN = head,PN = null;
		while(CN.link!=null)
		{
			PN = CN;
			CN = CN.link;
		}
		PN.link = null;
		return head;
	}
	
	Node reverse(Node head)
	{
		Node CN = head,PN = null,NN;
		while(CN!=null)
		{
			NN = CN.link;
			CN.link = PN;
			PN = CN;
			CN = NN;
		}
		return PN;
	}		
	
	public void Display(Node head)
	{
		if(head == null)
			return;
		System.out.print("\t" + head.value);
		Display(head.link);
	}
	
	public static void main(String args[])
	{
		LinkedList L = new LinkedList();
		int choice,value,pos;
		Scanner in = new Scanner(System.in);
		while(true)
		{
			System.out.println("\nEnter choice\n1-insert at beginning \n2-insert at end\n3-Insert at pos\n4- display\n5-delete at beggining\n6-delete at end\n7-reverse");
			choice = in.nextInt();
			switch(choice)
			{
				case 1:	System.out.println("Enter value:");
					value = in.nextInt();
					L.head = L.insertBeg(L.head,value);
					break;
				case 2:	System.out.println("Enter value:");
					value = in.nextInt();
					L.head = L.insertEnd(L.head,value);
					break;
				case 3:	System.out.println("Enter value:");
					value = in.nextInt();
					System.out.println("Enter position:");
					pos = in.nextInt();
					L.head = L.insertAtPos(L.head,value,pos);
					break;
				case 4: L.Display(L.head);
					break;
				case 5: L.head = L.deleteBeg(L.head);
					break;
				case 6: L.head = L.deleteEnd(L.head);
					break;
				case 7:	L.head = L.reverse(L.head);
					break;
				default:System.exit(0);
				
					
			}
		}
	}
}
		
		
	
