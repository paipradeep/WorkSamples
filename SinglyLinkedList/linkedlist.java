import java.util.*;

class Node{
	int data;
	Node next;
}

class linkedlist{
	Node insertNode(Node head,int data,int pos){
		Node newNode = new Node();
		newNode.data = data;
		if(pos==0 && head == null){
			newNode.next = null;
			return newNode;
		}
		if(head == null){
			System.out.println("Invalid position");
			return head;
		}
		if(pos==0){
			newNode.next = head;
			return newNode;
		}
		int count = 0;
		Node CN=head,PN=null;
		while(CN!=null && count<pos){
			PN = CN;
			CN = CN.next;
			count++;
		}
		if(count == pos){
			PN.next = newNode;
			newNode.next = CN;
			return head;
		}
		System.out.println("Invalid position");
		return head;
	}

	Node deleteNode(Node head,int pos){
		//delete by position
		if(head == null){
			System.out.println("List is empty");
			return head;
		}
		Node CN=head,PN=null;
		int count = 0;
		while(CN!=null && count<pos){
			PN = CN;
			CN = CN.next;
			count++;
		}
		if(CN == null){
			System.out.println("Invalid position");
			return head;

		}
		if(pos == count){

			PN.next = CN.next;
			CN = null;
			return head;
		}
		System.out.println("Invalid position");
		return head;
	}

	int findLength(Node head){
		if(head == null)
			return 0;
		return 1+findLength(head.next);
	}

	/*boolean findLoop(Node head){
		if(head == null || head.next==null)
			return "NO";
		Node p1=head
	}*/
	void printList(Node head){
		System.out.println();
		if(head == null)
			//System.out.println("List is empty");
			return;
		System.out.print(head.data + " ");
		printList(head.next);
	}

	Node search(Node head,int data){

		if(head == null)
			return head;
		Node CN = head;
		while(CN!= null && CN.data!=data){

			CN = CN.next;
		}
		if(CN == null){
			System.out.println("Element not found");

			return null;
		}
		return CN;
	}
    Node swap2Nodes(Node head,int data1,int data2){
		//Assuming that all datas of linked list are unique
		if(head == null){
			return head;
		}
		Node CN1=head,PN1=null,CN2=head,PN2=null;
		while(CN1!=null && CN1.data!=data1){
			PN1 = CN1;
			CN1 = CN1.next;
		}
		if(CN1 == null)
		{
			System.out.println("Not found");
			return null;
		}
		while(CN2!=null && CN2.data!=data2){
			PN2 = CN2;
			CN2 = CN2.next;
		}
		if(CN2 == null)
		{
			System.out.println("Not found");
			return null;
		}
		if(PN1!=null)
			PN1.next = CN2;
		else
			head = CN2;
		if(PN2!=null)
			PN2.next = CN1;
		else
			head = CN1;
		Node temp = CN1.next;
		CN1.next = CN2.next;
		CN2.next = temp;
		return head;



	}
	void deleteList(Node head){
		//not working
		if(head== null)
			return;
		Node t = head.next;
		head = null;
		deleteList(t);
	}
	public static void main(String args[]){
		linkedlist l = new linkedlist();
		Node head = new Node();
		head.data = 10;
		head.next = null;
		head = l.insertNode(head,4,0);
		head = l.insertNode(head,3,0);
		head = l.insertNode(head,2,0);
		head = l.insertNode(head,1,0);
		l.printList(head);
		//l.deleteNode(head,2);
		//l.printList(head);
		//l.deleteNode(head,5);
		l.printList(head);
		System.out.println(l.findLength(head));
		//l.deleteList(head);
		l.printList(head);
		Node temp=null;
		//Node c = l.search(head,15,temp);
		l.swap2Nodes(head,2,3);
		l.printList(head);


	}
}
