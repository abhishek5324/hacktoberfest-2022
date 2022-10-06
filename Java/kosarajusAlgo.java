import java.util.*;
public class Kosarajus_Algo {
	int V;
	Kosarajus_Algo(int v){
		this.V=v;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int v =10;
		Kosarajus_Algo ob = new Kosarajus_Algo(v);
		ArrayList<ArrayList<Integer>> al = new ArrayList<ArrayList<Integer>>();
		for(int i=0;i<v;i++) {
			al.add(new ArrayList<Integer>());
		}
		ob.addEdge(al, 0, 1);
		ob.addEdge(al, 1, 2);
		ob.addEdge(al, 1, 3);
		ob.addEdge(al, 2, 0);
		ob.addEdge(al, 3, 4);
		ob.addEdge(al, 4, 3);
		ob.addEdge(al, 4, 5);
		ob.addEdge(al, 5, 6);
		ob.addEdge(al, 6, 7);
		ob.addEdge(al, 6, 9);
		ob.addEdge(al, 7, 8);
		ob.addEdge(al, 8, 5);
		ob.kosarajusAlgorithm(al);
	}
	void createSSC(ArrayList<ArrayList<Integer>> al, int data, boolean[] visited) {
		visited[data]=true;
		System.out.print(data+" ");
		for(Integer it : al.get(data)) {
			if(visited[it]==false) {
				createSSC(al,it,visited);
			}
		}
	}
	void topologicalSort(ArrayList<ArrayList<Integer>> al, Stack<Integer> s, int data, boolean[] visited) {
		visited[data]=true;
		for(Integer it : al.get(data)) {
			if(visited[it] == false) {
				topologicalSort(al,s,it,visited);
			}
		}
		s.add(data);
	}
	void kosarajusAlgorithm(ArrayList<ArrayList<Integer>> al) {
		boolean visited[] = new boolean[V];
		Stack<Integer> s = new Stack<Integer>();
		for(int i=0;i<V;i++) {
			if(visited[i]==false) {
				topologicalSort(al,s,i,visited);
			}
		}
		ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
		for(int i=0;i<V;i++) {
			ans.add(new ArrayList<Integer>());
		}
		for(int i=0;i<V;i++) {
			visited[i]=false;
			for(Integer it:al.get(i)) {
				ans.get(it).add(i);
			}
		}
		while(! s.isEmpty()) {
			int data=s.peek();
			s.pop();
			if(visited[data]==false) {
				createSSC(ans,data,visited);
				System.out.println();
			}
		}
	}
	void addEdge(ArrayList<ArrayList<Integer>> al, int i, int j) {
		al.get(i).add(j);
	}
}
