#ifndef LINKED_LIST
#define LINKED_LIST

using namespace std;
#include "node.h"
#include<cstdlib>

class Linked_List {
private:
	unsigned int length; // the number of nodes contained in the list
	Node* head; // a pointer to the first node in the list
	// anything else you need...
public:

	Linked_List(){
		this->length = 0;
		this->head = NULL;
	}

	Node* get_head(){
		return this->head;
	}

	int get_length(){
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
		Node* current = this->head;
		this->length = 0;
		while (current != NULL){
			this->length = this->length + 1;
			current = current->next;
		}
		return this->length;
	}
   
	void print(){
	// output a list of all integers contained within the list
		Node* current = this->head;
		while (current != NULL){
			cout << current->val << " ";
			current = current->next;
		}
		cout << endl;
	}

	void clear(){
	// delete the entire list (remove all nodes and reset length to 0)
		Node* current = head;
		Node* temp = NULL;
		while (current != NULL){ //current is pointing to a node
			temp = current->next;
			delete current;
			current = temp;
		}
		head = NULL;
	}

	void push_front(int val){
	// insert a new value at the front of the list 
		Node* current = this->head;
		this->head = new Node(val, current);
	}

	void push_back(int val){
	// insert a new value at the back of the list 
		//go to end of list and reassign pointers
		Node* current = this->head;
		while (current != NULL){
			if (current->next == NULL){
				break;
			}
			current = current->next;
		}
		current->next = new Node(val, NULL);
	}

	void insert(int val, unsigned int index){
	// insert a new value in the list at the specified index 
		Node* current = this->head;

		//push front if inserting at front of list
		if (index == 0){
			push_front(val);
		}
		//loop through to index and reassign pointers
		else if (index <= get_length()){
			for (int i = 0; i < index - 1; i++){
				current = current->next;
			}
			current->next = new Node(val, current->next);
		}
	}

	Node* merge(Node* l, Node* r){
		Node* finished;

		//single item lists
		if (!l){return (r);}
		else if (!r){return (l);}

		//r val needs to be placed first
		if (r->val <= l->val){
			finished = r;
			//merge l and next item from r list
			finished->next = merge(r->next, l);
		}
		//l val needs to be placed first
		else {
			finished = l;
			//merge r and next item from l list
			finished->next = merge(r, l->next);
		}
		//pointer to merged list
		return finished;
	}

	int middle(Node* back){
		int length = 0;

		while (back != NULL){
			length = length + 1;
			back = back->next;
		}
		return length;
	}

	void recursive_sort(Node** current){
		Node* current_rec = *current;

		//will point at left and right halves
		Node* l, * r;

		//Base case
		if ((!current_rec)|| (!current_rec->next)) {return;}

		//split up into left and right
		Node* back = current_rec;

		int length = middle(back);

		back = current_rec;

		for (int i = 0; i < length/2 - 1; i++){back = back->next;}

		//set left and right pointers
		l = current_rec;
		r = back->next;
		back->next = NULL;

		//recursion on halves
		recursive_sort(&r);
		recursive_sort(&l);

		//merge halves and return to current
		*current = merge(l,r);
	}

	void sort_ascending(){
	// sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.

		recursive_sort(&this->head);
	}

	void sort_descending(){
	// sort the nodes in descending order
		Node* current = this->head;

		//NULL so first item pointer (becoming end of list) will point at null
		Node* backwards = NULL;
		Node* forward = NULL;

		//sort so we can just flip
		sort_ascending();

		//goes through each item
		while(current){
			//temp store for rest of list
			forward = current->next;

			//pointer from ahead flipped to point at current
			current->next = backwards;

			//move backwards up an item
			backwards = current;

			//move current up an item
			current = forward;
		}
		//point head at new front of list
		this->head = backwards;
	}

	// you can add extra member variables or functions as desired

};

bool prime(int val){
	bool yes = 1;

	//account for negatives
	val = abs(val);

	//checks for multiples
	for (int i = 2; i <= val/2; i++){
		if (val % i == 0){
			yes = 0;
			break;
		}
	}

	//accounts for zero
	if (val == 0){
		return 0;
	}
	else{
		return yes;
	}
}

unsigned int count_prime(Linked_List& list){
//count and return the number of prime numbers within the list

	//sorts so duplicate check works
	list.sort_ascending();

	Node* current = list.get_head();
	unsigned int primes = 0;
	int nullcheck;

	//loops through each item in the list
	while(current){
		if (current->next){
			if (current->val != current->next->val){
				nullcheck = 1;
			}
			else{
				nullcheck = 0;
			}
		}
		else{
				nullcheck = 1;
		}

		//if item meets requirements (including prime) increments count
		if (nullcheck && prime(current->val)){
			primes++;
		}
		current = current->next;
	}
	return primes;
}


#endif