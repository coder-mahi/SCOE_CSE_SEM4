/*          10------20-----30           10 -> 20,50
 *           |     /        |           20 -> 10,50,30
 *           |   /          |           50 -> 10,20
 *           | /            |           30 -> 20,40
 *          50              40          40 -> 30
 */
import java.util.ArrayList;
public class Graph_AdjList {
    static class Edge{
        int src,dest;
        Edge(int src,int dest){
            this.src = src;
            this.dest = dest;
        }

        @Override
        public String toString(){
            return "("+src+","+dest+")";
        }
    }

    static void createGraph(ArrayList<Edge> graph[]){
        for(int i=0;i<graph.length;i++){
            graph[i] = new ArrayList<Edge>();
        }

        graph[0].add(new Edge(10, 20));
        graph[0].add(new Edge(10, 50));

        graph[1].add(new Edge(20, 10));
        graph[1].add(new Edge(20, 50));
        graph[1].add(new Edge(20, 30));

        graph[2].add(new Edge(50, 10));
        graph[2].add(new Edge(50, 20));

        graph[3].add(new Edge(30, 20));
        graph[3].add(new Edge(30, 40));

        graph[4].add(new Edge(40, 30));
    }

    static void display(ArrayList<Edge>[] graph){
        for(int i=0;i<graph.length;i++){
            System.out.print("Vertex " + i + ": ");
            for(int j=0;j<graph[i].size();j++){
                System.out.print(graph[i].get(j)+", ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        int V = 5;
        ArrayList<Edge> graph[] = new ArrayList[V];
        createGraph(graph);
        display(graph);
    }
}
