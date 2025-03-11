import java.util.*;
class Dijkstras
{
	static final int v=5;
	int mindistance(int distance[],boolean vis[])
	{
		int m=Integer.MAX_VALUE,index=-1;
		for(int i=0;i<v;i++)
		{
			if(vis[i]==false && distance[i]<=m)
			{
				m=distance[i];
				index=i;
			}
		}
		return index;
	}
	void printSolution(int distance[],int n)
	{
		System.out.println("The distance from source");
		for(int j=0;j<n;j++)
		{
			System.out.println("To"+j+"Shortest distance"+distance[j]);
		}
	}
	public void dijkstra(int arr[][],int s)
	{
		int distance[]=new int[v];
		boolean vis[]=new boolean [v];
		for(int i=0;i<v;i++)
		{
			distance[i]=Integer.MAX_VALUE;
			vis[i]=false;
		}
		distance[s]=0;
		for(int j=0;j<v-1;j++)
		{
			int ux=mindistance(distance,vis);
			vis[ux]=true;
			for(int vx=0;vx<v;vx++)
			{
				if(!vis[vx] && arr[ux][vx]!=-1 && distance[ux]!=Integer.MAX_VALUE && distance[ux]+arr[ux][vx]<distance[vx])
				{
					distance[vx]=distance[ux]+arr[ux][vx];
				}
			}
			
		}
		printSolution(distance,v);
	}
		
	public static void main(String args[])
	{
		Dijkstras d=new Dijkstras();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the number of vertices : ");
		int v=sc.nextInt();
		System.out.println("Enter the element of matrix : ");
		int arr[][]=new int[v][v];
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				arr[i][j]=sc.nextInt();
			}
		}
		d.dijkstra(arr,0);
	}
}