#include <iostream>

using namespace std;

struct Node{
	Node* next;
	int val;
	Node(int v){
		val = v;
		next=NULL;
	}
};

class LinkedList{
public:
	Node *head;

	LinkedList(){head=NULL;}

	void print(){
		cout << "--------------" << endl;
		Node* curNode=head;
		while(curNode!=NULL){
			cout << curNode->val << " ";
			curNode = curNode->next;
		}
		cout << endl << "--------------" << endl;
	}

	void append(int val){
		
		if (head==NULL){
			head = new Node(val);
		}else{
			Node* curNode = head;
			while(curNode->next!=NULL) curNode = curNode->next;
			curNode->next = new Node(val);
		}
	}

	void reverse(){
		head = reverse(head)
	}

private:
	pair<Node*, Node*> reverse(Node* curNode){
		if (curNode == NULL || curNode->next == NULL)
			return make_pair(curNode, curNode);
		else{
			pair<Node*, Node*> res = reverse(curNode->next);
			res->next = curNode;
			curNode.second->next = NULL;
			return (curNode.first, curNode)
		}
	d
}};



int main(){
	int N,x;

	cin >> N;

	LinkedList ll;
	for (int i=0;i<N;i++){
		cin >> x;
		ll.append(x);
	}

	ll.print();

	return 0;
}


