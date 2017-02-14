package DataStructures;
import DataStructures.Node;

public class LinkedList {

		Node HEAD;
		private int count;


		public LinkedList() {
				HEAD = null;
				count = 0;
		}

		public void firstAlloc(int data) {
				
				HEAD = new Node();
				HEAD.data = data;
				HEAD.next = null;

				return;
		}

		public void pushBack(int data) {

				if(HEAD != null) {

						Node temp = HEAD;
						while(temp != null)
								temp = temp.next;

						temp = new Node();
						temp.data = data;
						temp.next = null;
				
				}

				else 
						firstAlloc(data);

				count++;

				return;
		}

		public void pushFront(int data) {

				if(HEAD != null) {
						
						Node temp = HEAD.next;
						HEAD = new Node();
						HEAD.data = data;
						HEAD.next = temp;
				}


				else
						firstAlloc(data);

				count++;
				return;				
		}

		public int popFront() {

				//System.out.println((int)HEAD);
				if(HEAD == null) {
						System.out.println("UNDERFLOW in popFront");
						return -1;
				}

				int popped_data = HEAD.data;
				HEAD = HEAD.next;

				count--;
				return popped_data;
		}

		public int popBack() {

				if(HEAD == null) {
						
						System.out.println("UNDERFLOW in popBack");
						return -1;
				}

				Node current = HEAD.next;
				Node prev = HEAD;
				int popped_data = 9999;
				if(current == null) {
						assert count == 1:"count is not equal to 1, count system anomaly " + count;
						/*HEAD IS THE ONLY NODE*/
						popped_data = HEAD.data;
						HEAD = null;
						prev = null;

						return popped_data;
				}

				while(current.next != null) {
						prev = current;
						current = current.next; 
				}

				popped_data = current.data; /*current.data*/
				prev.next = current.next; /*at this point current.next is equal to null*/
				current = null;
				count --;

				if(count == 0)
						HEAD = null;

				return popped_data;
		}

		public void traverse() {
				Node temp = HEAD;

				while(temp != null)
						System.out.print(temp.next + "-> ");
		}

		public int getCount() {
				return count;
		}
}