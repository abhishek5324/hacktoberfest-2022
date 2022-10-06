import java.util.*;
class Node3{
	int source;
	int dest;
	int weight;
	Node3(int s, int d, int w){
		this.source =s;
		this.dest = d;
		this.weight=w;
	}
}
public class BellManFord_Algo {
	int V=7;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BellManFord_Algo ob = new BellManFord_Algo();
		ArrayList<Node3> al = new ArrayList<Node3>();
		al.add(new Node3(1,2,6));
		al.add(new Node3(1,3,5));
		al.add(new Node3(1,4,5));
		al.add(new Node3(2,5,-1));
		al.add(new Node3(3,2,-2));
		al.add(new Node3(3,5,1));
		al.add(new Node3(4,3,-2));
		al.add(new Node3(4,6,-1));
		al.add(new Node3(5,7,3));
		al.add(new Node3(6,7,3));
		int source =1;
		ob.shortestPath(al,source);
	}
	void shortestPath(ArrayList<Node3> al , int source) {
		int arr[] = new int[V+1];
		Arrays.fill(arr, Integer.MAX_VALUE);
		arr[source]=0;
		//For direct Graph positive+negative applicable
		for(int i=1;i<V;i++) {
			for(Node3 it : al) {
				if(arr[it.dest] > arr[it.source]+it.weight) {
					arr[it.dest]=arr[it.source]+it.weight;
				}
			}
		}//For undirect graph only positive applicable 
		int flag=0;
		for(Node3 it : al) {
			if(arr[it.dest] > arr[it.source]+it.weight) {
				flag=1;
				System.out.print("There is a negative cycle in graph");
				break;
			}
		}
		if(flag==0) {
			System.out.print("Shortest Path from "+source+" : ");
			for(int i=1;i<=V;i++) {
				System.out.print(arr[i]+" ");
			}
		}
	}
}
