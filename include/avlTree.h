#ifndef _avltree_h_
#define _avltree_h_

class Stack {
	public:
		int size,len;
		char *ch = NULL;
		Stack();
		void stackPush(char a);
		char stackPop();
};

typedef struct n {
        int yas, kilo, yukseklik;
        char isim[20];
	Stack s;
        n *sol;
        n *sag;
}node;

//node *push(node *a, int age, int feat, char *name, Stack s);
//void print(node *a);
//void clearNodes(node *a);

node *insert(node*, int, int, char*, Stack);
void empty(node*);
node *rightRotate(node*&);
node *leftRotate(node*&);
node *doubleLeftRotate(node*&);
node *doubleRightRotate(node*&);
node *findMin(node*);
node *findMax(node*);
int height(node*);
int getBalance(node *);
void postorder(node*);
void clearNodes(node*);


#endif
