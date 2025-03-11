import java.util.Scanner;

public class Kruskal {
    int INT = 99;
    int p[];

    public Kruskal(int v) {
        p = new int[v];
        for (int i = 0; i < v; i++) {
            p[i] = i;
        }
    }

    int find(int i) {
        while (p[i] != i) {
            i = p[i];
        }
        return i;
    }

    void union(int i, int j) {
        int a = find(i);
        int b = find(j);
        p[a] = b;
    }

    void kruskalMST(int cost[][]) {
        int mincost = 0;
        int v = cost.length;

        for (int edge = 0; edge < v - 1; edge++) {
            int min = INT, a = -1, b = -1;
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    if (find(i) != find(j) && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }

            union(a, b);
            System.out.println("Edge " + a + " - " + b + " : cost = " + min);
            mincost += min;
        }

        System.out.println("Minimum cost of spanning tree = " + mincost);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of vertices:");
        int v = sc.nextInt();
        int cost[][] = new int[v][v];

        System.out.println("Enter the cost adjacency matrix:");
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cost[i][j] = sc.nextInt();
            }
        }

        Kruskal kruskal = new Kruskal(v);
        kruskal.kruskalMST(cost);
    }
}