#include <bits/stdc++.h>
using namespace std;

struct Node
   {
       int low;int high;int mx;
       Node* left,*right;
   };


Node* create_node(int lo, int hi)
  {
    Node *temp=new Node();
           temp->mx=hi;
           temp->low=lo;
           temp->high=hi;
           temp->left=NULL;
           temp->right=NULL;

    return temp;

  }

Node * insertion(Node* local_root, int lo, int hi)
   {
       if(!local_root)
       {
           local_root = create_node(lo,hi);
       }


       else if(local_root->low >= lo)
       {
           local_root->mx = max(local_root->high,hi);

           local_root->left=insertion(local_root->left,lo,hi);
       }

       else

       {
           local_root->mx=max(local_root->high,hi);

           local_root->right=insertion(local_root->right,lo,hi);

       }

       return local_root;

   }


void change(Node* node1, Node* node2)
  {
	node1->low = node2->low;
	node1->high = node2->high;
  }

void removal(Node* current,Node* local_root, Node* parent, bool head)
  {
	                            //head=true means the root node
	int child=0;
	bool left=false, right=false;

	if(current->low <= parent->low) left=true;
	else right=true;

	if(current->left) child++;
	if(current->right) child++;

	if(child==0)
    {
		if(head)
		{
			parent=NULL;
			return;
		}

		if(left) parent->left=NULL;
		else parent->right=NULL;
	}

	else if(child==1)
    {
		if(head)
		{
			if(current->left) local_root=local_root->left;
			else local_root=local_root->right;
			return;
		}

		if(left)
        {
			if(current->right) parent->left=current->right;
			else parent->left=current->left;
		}

		else
        {
			if(current->right) parent->right=current->right;
			else parent->right=current->left;
		}
	}
	else
        {
		Node* temp=current;
		temp=temp->left;
		if(temp->right)
		{
			while(temp->right)
			{
				parent=temp;
				temp=temp->right;
			}

			change(current, temp);
			parent->right=NULL;
		}
		else
        {
			change(current, temp);
			removal(temp, local_root,current, false);
		}
	}
 }


Node* deletion(Node* local_root,Node* temp_node)
  {
    Node* current=new Node();
    current = local_root;
	Node *parent= new Node();
	parent = local_root;

	while(true)
        {
		if(current==NULL)
		{
			cout<<"This interval does not exist"<<endl;
			break;
		}

		if(temp_node->low < current->low)
		{
			parent=current; current=current->left;
		}

		else if(temp_node->low > current->low)
		{
			parent=current; current=current->right;
		}

		else
        {
			removal(current,local_root, parent, false);
			break;
		}
	}
  }

Node *search_interval(Node *local_root, int lo, int hi)
   {
        if (!local_root)
            return NULL;

        if (local_root->low<=hi && local_root->high>=lo)
            return local_root;

        if (local_root->left != NULL && (local_root->left)->mx >= lo)
            return search_interval(local_root->left, lo, hi);

        return search_interval(local_root->right, lo, hi);
    }

int main()
{
    Node *root = NULL;

       int n,lo,hi;
        cin>>n;  //n=no. of nodes in tree to be inserted

     for(int i=0;i<n;i++)
       {
           cin>>lo>>hi;
           root = insertion(root,lo,hi);
       }

      // cout<<root->low<<endl;
       cout<<"no. of elements to search"<<endl;
       cin>>n;

     for(int i=0;i<n;i++)
       {
             cin>>lo>>hi;
             Node *temp = new Node();
             temp = search_interval(root,lo,hi);
         if(temp)
           {
                 cout<<"Yes,its Overlap and Overlapping Interval is : "<<temp->low<<" "<<temp->high<<endl;
           }

         else
                cout<<"No Overlapping"<<endl;
        }

             cout<<"No. of nodes to delete"<<endl;
             cin>>n;
             
        for(int i=0;i<n;i++)
        {
              cin>>lo>>hi;
              Node *temp = new Node();
              temp = create_node(lo,hi);
              deletion(root,temp);
              cout<<"Interval has been deleted"<<endl;
        }

 }
