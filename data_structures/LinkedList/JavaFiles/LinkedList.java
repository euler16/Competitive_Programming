package DataStructure;

class LinkedList {

		Node HEAD;
		private int count;

		LinkedList() {
				HEAD = null;
				count = 0;
		}

		public void pushBack(int data) {

				Node temp = HEAD;
				while(temp != null)
						temp = temp.next;

				temp = new Node();
				temp.data = data;
				temp.next = null;

				count++;

				return;
		}

		public void pushFront(int data) {

				Node temp = HEAD.next;
				HEAD = new Node();
				HEAD.data = data;
				HEAD.next = temp;

				count++;				
		}

		public int popFront() {

				int popped_data = HEAD.data;
				HEAD = HEAD.next;

				count--;
				return popped_data;
		}

		public int popBack() {

				int popped_data = 0;
				Node temp = HEAD;
				while(temp.next.next != null)
						temp = temp.next;

				popped_data = temp.next.data;
				temp.next = null;

				count--;
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