import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class main {

	public static void main(String[] args) throws FileNotFoundException {

		System.out.print("Elements within input file: ");

		Scanner scanner = new Scanner(new File(args[0]));

		int count=0;

		int num;

		while (scanner.hasNextInt()) {
			count++;
			System.out.print(scanner.nextInt()+" ");

		}

		System.out.print("\n\n"+"Total number of elements found in file: "+count+"\n");


		liststack stk = new liststack();


		scanner = new Scanner(new File(args[0]));

		while (scanner.hasNextInt()) {

			num = scanner.nextInt();

			System.out.print("\nPushing: "+ num + " in to stack"+" ..... mem addr of Node.next is: ");


			stk.push(num);
		}


		System.out.print("\n");

		stk.display();

		System.out.print("\n\n");

		while(!stk.isEmpty()) {

			System.out.print("Popping: "+stk.pop()+" from stack\n");

		}

		stk.display();

	}
}


class listnode {

	int data;
	listnode next;

	listnode(int s) {
		this.data = s;
		next = null;
	}

}


class liststack {

	listnode top;

	liststack() {

		top = null;

	}

	public Boolean isEmpty() {

		if (top == null)
			return true;
		else
			return false;

	}

	void push(int x) {

		listnode newnode; // same as listnode* n = new listnode(x);
		newnode = new listnode(x);
		newnode.next = top;
		System.out.println(newnode.next);
		top = newnode;
	}

	int pop() {

		if (top == null) {
			System.out.print("Stack Empty");
			return 0;
		}

		else {

			int temp = top.data;
			top = top.next;
			return temp;

		}

	}

	void display() {

		System.out.print("\nCurrent values within stack from top to bottom: ");

		listnode temp = top;

		if (temp == null)
			System.out.print("\nStack Empty!\n");

		while (temp != null) {

			System.out.print(temp.data + " ");
			temp = temp.next;

		}

	}

}