#include<bits/stdc++.h>
using namespace std;

 struct Edge
  {
	int src, dest, weight;
  };

 int main()
  {
	clock_t s;

    cout<<"Enter number of test cases"<<endl;
	int T;
	cin>>T;
	while(T--)
      {
		int V,E,src_vertex;
		cout<<"Enter the number of vertices and edges respectively"<<endl;
		cin>>V>>E;
        cout<<"Enter the source vertex"<<endl;
		cin>>src_vertex;
		Edge *edge;
		edge = new Edge[E];
		for(int i=0;i<E;i++)
		 {
			cin>>edge[i].src>>edge[i].dest>>edge[i].weight;
		 }

		s=clock();

		int *dist;
		dist = new int[V];
		for(int i=0;i<V;i++)
         {
			dist[i]=INT_MAX;
		 }
		dist[src_vertex]=0;
		int a,b,c;
		bool flag;
		for(int i=0;i<V;i++)
		  {
			for(int j=0;j<E;j++)
			 {
				a=edge[j].src; b=edge[j].dest; c=edge[j].weight;
				if(dist[a] != INT_MAX)
				 {
					if(dist[b] > (dist[a]+c))
					 {
						if(i==V-1)
						 {
							flag=true;
						 }
						else
						 {
							dist[b] = dist[a]+c;
						 }
					 }
				 }
			 }
		 }

		if(flag==true)
            {
			cout<<"Graph contains negative weight cycle"<<endl;
		    }

		else
         {
			  cout<<"\nDistance of all vertices from the source vertex:\n";
			  cout<<"Vertex   Distance from source"<<endl;
			for(int i=0;i<V;i++)
			 {
				cout<<i<<"           ";
				if(dist[i]==INT_MAX)
				cout<<"inf"<<endl;
				else
				cout<<dist[i]<<endl;
			 }
			cout<<endl;
		 }

		s = clock()-s;

		printf ("It took %d clicks (%f seconds).\n",s,((float)s)/CLOCKS_PER_SEC);
	}
	return 0;
}
