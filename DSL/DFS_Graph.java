/*
Analysis of DFS
Time Complexity:
The time complexity of DFS is O(V + E), where V is the number of vertices (nodes) and E is the number of edges in the graph.
Each vertex and edge is visited once in the worst-case scenario.

Space Complexity:
The space complexity of DFS is O(V) for the recursive implementation and O(V + E) for the iterative implementation using a stack.
The space required is proportional to the maximum depth of the recursion stack or the maximum size of the stack.
 */
import java.util.*;
class DFS_Graph {

    // Function to perform DFS
    private static void dfs(int node, boolean[] visited, List<List<Integer>> adjList) {
        // Mark the current node as visited
        visited[node] = true;
        
        // Process the current node (print or do other operations)
        System.out.print(node + " ");

        // Explore all unvisited neighbors
        for (int neighbor : adjList.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adjList);
            }
        }
    }

    // Function to initialize DFS and handle disconnected components
    private static void performDFS(int numNodes, List<List<Integer>> adjList) {
        boolean[] visited = new boolean[numNodes + 1];

        // Iterate through all nodes to handle disconnected components
        for (int i = 1; i <= numNodes; ++i) {
            if (!visited[i]) {
                dfs(i, visited, adjList);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numNodes = scanner.nextInt();
        int numEdges = scanner.nextInt();
        List<List<Integer>> adjList = new ArrayList<>(numNodes + 1);
        
        // Initialize adjacency list
        for (int i = 0; i <= numNodes; i++) {
            adjList.add(new ArrayList<>());
        }

        // Adding edges to the graph
        for (int i = 0; i < numEdges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }

        // Perform DFS
        System.out.print("DFS traversal: ");
        performDFS(numNodes, adjList);

        scanner.close();
    }
}
