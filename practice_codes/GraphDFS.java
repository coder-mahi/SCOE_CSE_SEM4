import java.util.*;
class GraphDFS
{
    int NOV,NOE;
    LinkedList<Integer>[] adj;

    GraphDFS(int v)
    {
        NOV=v;
        adj=new LinkedList[v];
        for(int i=0;i<v;i++)
        {
            adj[i]=new LinkedList<>();
        }
    }

    public void addEdge(int s,int d)
    {
        adj[s].add(d);
    }

    public void DFS(int a)
    {
        boolean[] vis=new boolean[NOV];
        LinkedList<Integer> stack=new LinkedList<>();
        vis[a]=true;
        stack.add(a);

        while(!stack.isEmpty())
        {
            int c=stack.pop();
            System.out.print(" "+c);
            for(int next:adj[c])
            {
                if (!vis[next])
                {
                    vis[next]=true;
                    stack.add(next);
                }
            }
        }
    }

    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number of vertices : ");
        int NOV=sc.nextInt();
        System.out.print("Enter number of edges : ");
        int NOE=sc.nextInt();

        GraphDFS g=new GraphDFS(NOV);

        while(NOE!=0)
        {
            System.out.print("Enter source of edge : ");
            int s=sc.nextInt();
            System.out.print("Enter destination of edge : ");
            int d=sc.nextInt();

            g.addEdge(s, d);
            NOE--;
        }

        System.out.println("BFS start from : 0");
        g.DFS(0);
    }
}

