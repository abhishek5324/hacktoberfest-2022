import java.util.*;
class Node4 implements Comparator<Node4> {
	int dest;
	int weight;
	Node4(){}
	Node4(int d, int w){
		this.dest =d;
		this.weight =w;
	}
	@Override
	public int compare(Node4 o1, Node4 o2) {
		// TODO Auto-generated method stub
		if(o1.weight > o2.weight) {
			return 1;
		}
		if(o1.weight < o2.weight) {
			return -1;
		}
		return 0;
	}
}
public class Prims_Algo {
	int V;
	LinkedList<Node4>[] ll;
	Prims_Algo(int v){
		this.V=v;
		ll = new LinkedList[V];
		for(int i=0;i<V;i++) {
			ll[i]= new LinkedList<Node4>();
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Prims_Algo ob = new Prims_Algo(6);
		ob.addEdge(0, 1, 1);
		ob.addEdge(0, 2, 2);
		ob.addEdge(1, 2, 3);
		ob.addEdge(1, 4, 7);
		ob.addEdge(2, 4, 5);
		ob.addEdge(2, 3, 3);
		ob.addEdge(4, 5, 6);
		ob.addEdge(4, 3, 2);
		ob.addEdge(3, 5, 4);
		int source = 0;
		ob.spanningTree(source);
		//ob.printGraph();
	}
	void spanningTree(int source) {
		int key[] = new int[V];
		Arrays.fill(key, Integer.MAX_VALUE);
		
		boolean[] visited = new boolean[V];
		Arrays.fill(visited, false);
		
		int parent[] = new int[V];
		parent[source]=-1;
		
		PriorityQueue<Node4> pq = new PriorityQueue<Node4>(new Node4());
		pq.add(new Node4(source,-1));

		while(! pq.isEmpty()) {
			Node4 node = pq.poll();
			visited[node.dest]=true;
			for(Node4 it : ll[node.dest]) {
				if(! visited[it.dest] && key[it.dest] > it.weight) {
					pq.add(new Node4(it.dest,it.weight));
					key[it.dest] = it.weight;
					parent[it.dest]=node.dest;
				}
			}
		}
		int sum=0;
		for(int i=1;i<V;i++) {
			sum+=key[i];
			System.out.println(parent[i]+" , "+i+" --> "+key[i]);
		}
		System.out.print("Total weight of minimum spanning tree is : "+sum);
	}
	void printGraph() {
		for(int i=0;i<ll.length;i++) {
			System.out.print("Vertex "+i+" : ");
			for(Node4 it : ll[i]) {
				System.out.print(it.dest+" --> "+it.weight+"  ");
			}
			System.out.println();
		}
	}

	void addEdge(int i, int j, int w) {
		ll[i].add(new Node4(j,w));
		ll[j].add(new Node4(i,w));
	}
}
