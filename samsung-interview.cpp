/*
Link of question: https://docs.google.com/document/d/1kAmP9uJLzwIjOPI6i9FNlJ-d9b_HRJjiD9_7wvpomr0/edit?usp=sharing
*/
#include<iostream>
using namespace std;
class Data{
public:
	int leftend;
	int rightend;
	Data(int leftend,int rightend)
	{
		this->leftend=leftend;
		this->rightend=rightend;
	}


};
class AvlTree{
public:
	AvlTree *left,*right;
	Data *val; 
	int diff;
	int height;
	AvlTree(int leftend,int rightend)
	{
		this->left=this->right=NULL;
		this->val=new Data(leftend,rightend);
		this->diff=rightend-leftend;
		this->height=1;
	}

};
int max(int x,int y)
{
	 return (x>y)?x:y;

}
int Height(AvlTree *root)
{
	if(root==NULL)
		return 0;
	else
		return root->height;

}
AvlTree *LeftRoataion(AvlTree *curr)
{
	AvlTree *rightchild=curr->right;
	AvlTree *grandchild=rightchild->left;

	//roate
	rightchild->left=curr;
	curr->right=grandchild;

	//update the heights


	curr->height=max(Height(curr->left),Height(curr->right))+1;
	rightchild->height=max(Height(rightchild->left),Height(rightchild->right))+1;
	return rightchild;

}

AvlTree *RightRoataion(AvlTree *curr)
{
	AvlTree *leftchild=curr->left;
	AvlTree *grandchild=leftchild->right;

	//roate
	leftchild->right=curr;
	curr->left=grandchild;

	//update the heights

	curr->height=max(Height(curr->left),Height(curr->right))+1;
	leftchild->height=max(Height(leftchild->left),Height(leftchild->right))+1;
	return leftchild;

}
//return 1 for right 
//return  0 for left
int compare(AvlTree *root,int leftend,int rightend)
{
	int key=rightend-leftend;
	if(key>root->diff)
	{
		return 1;
	}
	else if(key<root->diff)
	{
		return 0;
	}
	else
	{
		if(leftend<root->val->leftend)
			return 1;
		else if(leftend>root->val->leftend)
			return 0;
		else
			return 2;
	}

}
AvlTree * insert(AvlTree *root,int leftend ,int rightend)
{
	if(root==NULL)
	{
		return new AvlTree(leftend,rightend);
	}
	
	if(compare(root,leftend,rightend))
		root->right=insert(root->right,leftend,rightend);
	else if(!compare(root,leftend,rightend))
		root->left=insert(root->left,leftend,rightend);


	root->height=max(Height(root->left),Height(root->right))+1;
	int difference=(Height(root->left)-Height(root->right));

	//rightright rotate
	if(difference>1&&(!compare(root,leftend,rightend)))
		return 	RightRoataion(root);

	 if(difference>1&&(compare(root,leftend,rightend)))
	{
		root->left=LeftRoataion(root->left);
		return RightRoataion(root);
	}
	
	if(difference<-1&&(compare(root,leftend,rightend)))
		return 	LeftRoataion(root);

	 if(difference<-1&&(!compare(root,leftend,rightend)))
	{
		root->left=RightRoataion(root->right);
		return LeftRoataion(root);
	}
	return root;
}

void Inorder(AvlTree *root)
{
	if(root==NULL)
	{
				return ;
	}
	Inorder(root->left);
	cout<<root->val->leftend<<" "<<root->val->rightend<<endl;

	Inorder(root->right);


}
AvlTree * MinimumElement(AvlTree *root)
{
	
	if(root->left==NULL)
	{
		//cout<<"Minimum Element is : "<<root->val->leftend<<" "<<root->val->rightend<<endl;
		return root;
	}
return	MinimumElement(root->left);
}
AvlTree * MaximumElement(AvlTree *root)
{
		
	if(root->right==NULL)
	{
		//cout<<"Maximum Element is : "<<root->val->leftend<<" "<<root->val->rightend<<endl;;
		return root;
	}
	MaximumElement(root->right);
}
int GetBalance(AvlTree *root)
{
	if(root==NULL)
		return 0;
	return Height(root->left)-Height(root->right);
}
AvlTree *deleter(AvlTree *root,int leftend,int rightend)
{
	if(root==NULL)
		return root;
	if(compare(root,leftend,rightend)==1)
		root->right=deleter(root->right,leftend,rightend);
	else if(compare(root,leftend,rightend)==0)
		root->left=deleter(root->left,leftend,rightend);
	else
	{
		if(root->left==NULL||root->right==NULL)
		{
			AvlTree *temp=root->left?root->left:root->right;
			if(temp==NULL)
			{
				temp=root;
				root=NULL;
			}
			else
				*root=*temp;
			delete(temp);
		}
		else
		{
			AvlTree *inorder=MinimumElement(root->right);
			root->val=inorder->val;
			root->diff=inorder->diff;
			root->right=deleter(root->right,inorder->val->leftend,inorder->val->rightend);
		}

	}
	if(root==NULL)
		return root;
	root->height=max(Height(root->left),Height(root->right))+1;
	int balance=GetBalance(root);
	//LL
	if(balance>1&&GetBalance(root->left)>=0)
		return RightRoataion(root);
	//RR
	if(balance<-1&&GetBalance(root->right)<=0)
		return LeftRoataion(root);
	//LR
	if(balance>1&&GetBalance(root->left)<0)
	{
		root->left=LeftRoataion(root->left);
		return RightRoataion(root);
	}
	//RL
	if(balance<-1&&GetBalance(root->right)>0)
	{
		root=RightRoataion(root->right);
		return LeftRoataion(root);
	}
	return root;

}

class Assign{
public:
int left;
int right;
int seat;
};
int arr[111111];
int n;
int q;
Assign assign[111111];
int reverse[11111];
int main()
{

AvlTree *root=NULL;
cin>>n>>q;
int cnt=0;
root=insert(root,0,n+1);
while(q--)
{
	int type;
	cin>>type;
	if(type==1)
	{
		int id;
		cin>>id;

			AvlTree *temp=MaximumElement(root);
			int ll;
			int rr;
			ll=temp->val->leftend;
			rr=temp->val->rightend;
			int seat=(ll+rr)/2;
			if(cnt==0)
				seat=1;
			else
			{
				assign[reverse[ll]].right=seat;
				assign[reverse[rr]].left=seat;
			}
			assign[id].left=ll;
			assign[id].right=rr;
			reverse[seat]=id;
			assign[id].seat=seat;
			root=deleter(root,ll,rr);
			root=insert(root,ll,seat);
			root=insert(root,seat,rr);

			cout<<seat<<endl;
			cnt++;
	
	}
	else if(type==2)
	{	
		int id;
		cin>>id;
		int ll;
		int rr;
		ll=assign[id].left;
		rr=assign[id].right;
		cout<<ll<<" "<<rr<<endl;
		int seat=assign[id].seat;
		root=deleter(root,ll,seat);
		root=deleter(root,seat,rr);
		root=insert(root,ll,rr);
		assign[reverse[ll]].right=rr;
		assign[reverse[rr]].left=ll;
		cnt--;
		
	}
	else
	{
			cout<<"Press 1 for insert\nPress 2 to print sorted list\nPress 3 to find minimum element\nPress 4 to find maximum element \nPress 5 to delete any node\n";
		int choice;
		cout<<endl;
		cin>>choice;
		bool flag=false;
		switch(choice)
		{
			case 1:
			int left,right;
			cin>>left;
			cin>>right;
			root=insert(root,left,right);
			break;
			case 2:
			Inorder(root);
			cout<<endl;
			break;
			case 3:
			MinimumElement(root);
			break;
			case 4:
			MaximumElement(root);
			break;
			case 5:
			cin>>left;
			cin>>right;
			root=deleter(root,left,right);
			break;
			default:
			flag=true;

		}
	}
}

	// while(1)
	// {

	// 	cout<<"Press 1 for insert\nPress 2 to print sorted list\nPress 3 to find minimum element\nPress 4 to find maximum element \nPress 5 to delete any node\n";
	// 	int choice;
	// 	cout<<endl;
	// 	cin>>choice;
	// 	bool flag=false;
	// 	switch(choice)
	// 	{
	// 		case 1:
	// 		int left,right;
	// 		cin>>left;
	// 		cin>>right;
	// 		root=insert(root,left,right);
	// 		break;
	// 		case 2:
	// 		Inorder(root);
	// 		cout<<endl;
	// 		break;
	// 		case 3:
	// 		MinimumElement(root);
	// 		break;
	// 		case 4:
	// 		MaximumElement(root);
	// 		break;
	// 		case 5:
	// 		cin>>left;
	// 		cin>>right;
	// 		root=deleter(root,left,right);
	// 		break;
	// 		default:
	// 		flag=true;

	// 	}
	// 	if(flag)
	// 		break;
	// }	
	return 0;
	
}
