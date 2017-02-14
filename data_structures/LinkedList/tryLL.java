import DataStructures.LinkedList;


class tryLL {

		public static void main(String args[]) {
				
				LinkedList l1 = new LinkedList();
				System.out.println("Total after alloc-" + l1.getCount());
				l1.pushBack(5);
				System.out.println("Total after pushBack:-" + l1.getCount());
				l1.pushFront(10);
				System.out.println("Total after pushFront:-" + l1.getCount());
				l1.pushBack(16);
				System.out.println("Total after pushBack:-" + l1.getCount());
				l1.pushBack(1);
				System.out.println("Total after pushBack:-" + l1.getCount());
				l1.popBack();
				System.out.println("Total after popBack:-" + l1.getCount());
				l1.popFront();

				System.out.println("Total:-" + l1.getCount());
				l1.traverse();

		}
}