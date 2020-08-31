#include <iostream>
#include <cstdlib>

#include "../include/avlTree.h"

Stack::Stack() {
        this->size = 2;
        this->len = 0;
}

void Stack::stackPush(char a) {
        if(ch == NULL) {
                ch = (char*)malloc(sizeof(char)*2);
        }

        if(len >= size) {
                char *ch2 = (char*)malloc(sizeof(char)*size*2);
                for(int i=0;i<size;i++) {
                        ch2[i] = ch[i];
                }

                free(ch);
                ch = ch2;
                size *= 2;
        }

        ch[len++] = a;
}

char Stack::stackPop() {
	if(ch == NULL) {
		return '\0';
	}
	if(len <= size/4) {
		char *ch2 = (char*)malloc(sizeof(char)*size/2);
		for(int i=0;i<size;i++) {
			ch2[i] = ch[i];
		}
		free(ch);
		ch = ch2;
		size /= 2;
	}
	return ch[--len];
}

void empty(node *a) {
	if(a == NULL) {
		return;
	}
	empty(a->sol);
	empty(a->sag);
	delete a;
}

node *insert(node *a, int age, int feat, char *name, Stack s) {
	if(a == NULL) {
		s.stackPush('O');
		s.stackPush('D');
		a = (node*)malloc(sizeof(node));
		a->yas = age;
		a->kilo = feat;
		strcpy(a->isim, name);
		a->yukseklik = 0;
		a->s = s;
		a->sol = a->sag = NULL;
	}

	else if(a->yas > age) {
		s.stackPush('A');
		a->sol = insert(a->sol, age, feat, name,s);
		if(height(a->sol) - height(a->sag) == 2) {
			if(a->sol->yas > age) {
				a = rightRotate(a);
			}
			else {
				a = doubleRightRotate(a);
			}
		}
	}

	else if(a->yas < age) {
		s.stackPush('Y');
		a->sag = insert(a->sag, age, feat, name,s);
		if(height(a->sag) - height(a->sol) == 2) {
			if(a->sag->yas < age) {
				a = leftRotate(a);
			}
			else {
				a = doubleLeftRotate(a);
			}
		}
	}

	//a->yukseklik = max(height(a->sol), height(a->sag))+1;
	return a;
}

node *rightRotate(node* &a) {
	node *temp = a->sol;
	a->sol = temp->sag;
	temp->sag = a;
	//a->yukseklik = max(height(a->sol), height(a->sag))+1;
	//temp->yukseklik = max(height(temp->sol), a->yukseklik)+1;
	return temp;
}

node *leftRotate(node* &a) {
	node *temp = a->sag;
	a->sag = temp->sol;
	temp->sol = a;
	//a->yukseklik = max(height(a->sol), height(a->sag))+1;
	//temp->yukseklik = max(height(a->sag), a->yukseklik)+1;
	return temp;
}

node *doubleLeftRotate(node* &a) {
	a->sag = rightRotate(a->sag);
	return leftRotate(a);
}

node *doubleRightRotate(node* &a) {
	a->sol = leftRotate(a->sol);
	return rightRotate(a);
}

node *findMin(node *a) {
	if(a == NULL) {
		return NULL;
	}
	else if(a->sol == NULL) {
		return a;
	}
	return findMin(a->sol);

}

node *findMax(node *a) {
	if(a == NULL) {
		return NULL;
	}
	else if(a->sag == NULL) {
		return a;
	}
	else {
		findMax(a->sag);
	}
	return a;
}

int height(node *a) {
	return(a == NULL ? -1 : a->yukseklik);
}

int getBalance(node *a) {
	if(a == NULL) {
		return 0;
	}
	return height(a->sol) - height(a->sag);
}

void postorder(node *a) {
	if(a == NULL) {
		return;
	}

	postorder(a->sol);
	postorder(a->sag);
	std::cout<<a->isim<<" , "<<a->yas<<" , "<<a->kilo<<"  ";
	std::cout<<"Yigit : ";
	for(int i=0;a->s.ch[i] != '\0';i++) {
		std::cout<<a->s.ch[i]<<"  ";
		a->s.stackPop();
	}
	std::cout<<"\n";
}

void clearNodes(node *a) {
	free(a->sol);
	free(a->sag);
	free(a);
}

