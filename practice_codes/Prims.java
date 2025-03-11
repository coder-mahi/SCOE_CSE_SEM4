import java.util.Arrays;
import java.util.Scanner;

public class Prims {
    static void prim(int cost[][], int v) {
        int mincost = 0;
        int edgeCount = 0;
        boolean visited[] = new boolean[v];
        Arrays.fill(visited, false);
        visited[0] = true; // Start from the first vertex

        while (edgeCount < v - 1) {
//int INF = Integer.MAX_VALUE;
            int INF=99;
            int min = INF;
            int x = -1;
            int y = -1;

            for (int p = 0; p < v; p++) {
                if (visited[p]) {
                    for (int q = 0; q < v; q++) {
                        if (!visited[q] && cost[p][q] < min) {
                            min = cost[p][q];
                            x = p;
                            y = q;
                        }
                    }
                }
            }

            if (x != -1 && y != -1) {
                visited[y] = true;
                System.out.printf("Edge (%d, %d) with cost %d%n", x, y, min);
                mincost += min;
                edgeCount++;
            }
        }

        System.out.println("Total cost of Minimum Spanning Tree: " + mincost);
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of vertices:");
        int v = sc.nextInt();
        System.out.println("Enter the cost adjacency matrix:");

        int cost[][] = new int[v][v];
        for (int p = 0; p < v; p++) {
            for (int q = 0; q < v; q++) {
                cost[p][q] = sc.nextInt();
            }
        }
        prim(cost, v);
    }
}
