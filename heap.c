#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "heap.h"

bool existsAndLessThan(Heap* h,int index1, int index2){

	if(index1 >= h->size || index1 < 0){return false;}
	if(index2 >= h->size || index2 < 0){return false;}

	int key1 = h->elements[index1]->key;
	int key2 = h->elements[index2]->key;

	if(key1 < key2){return true;}

	return false;
}

void swap(Heap* h, int index1, int index2) {

	Entry* ent = h->elements[index1];
	h->elements[index1]=h->elements[index2];
	h->elements[index2]=ent;
}


void bubbleUp(Heap* h, int index) {

	if(index <= 0 || index >= h->size){return;}
	Entry* en = h->elements[index];

	int parentIndex= (index-1)/2;

	Entry* pen = h->elements[parentIndex];

	if(parentIndex < 0 || parentIndex >= h->size){return;}
	if(en->key < pen->key){

		swap(h,index,parentIndex);
		bubbleUp(h, parentIndex);	
	}

}

void expandCapacity(Heap* h) {

	if(h->size == h->capacity){

		Entry** newList=calloc(h->capacity*2,sizeof(Entry));
		h->capacity=h->capacity*2;

		int i;

		for(i=0;i<h->size;i++){

			newList[i] = h->elements[i];
		}

		free(h->elements);

		h->elements = newList;
	}
}


void add(Heap* h, int k, char* val) {

	expandCapacity(h);

	Entry* ent=malloc(sizeof(Entry));

	ent->key = k;

	ent->value= val;

	h->size= h->size +1;

	h->elements[h->size-1]=ent;

	bubbleUp(h,h->size-1);
}

void bubbleDown(Heap* h, int index) {

	if(index >= h->size){ return;}

	int leftIndex= 2*index+1;

	if(leftIndex >= h->size){ return;}

	int smallerChildIndex = leftIndex;
	int rightIndex = leftIndex+1;

	if(existsAndLessThan(h,rightIndex,leftIndex)==true){
		smallerChildIndex=rightIndex;
	}

	if(existsAndLessThan(h,smallerChildIndex, index)==true){
		swap(h,index,smallerChildIndex);
		bubbleDown(h,smallerChildIndex);
	}
}

char* removeMin(Heap* h) {

	if(h->size==0){return NULL;}

	Entry* ent = h->elements[0];

	char* vall= ent->value;

	free(ent);

	h->elements[0] = h->elements[h->size -1];

	h->size=h->size-1;

	bubbleDown(h,0);

	return vall; 

}

void cleanupHeap(Heap* h) {

	int i;

	for(i=0;i < h->size;i++){

		free(h->elements[i]);
	}
	free(h->elements);

	free(h);

}

void printHeap(Heap* h) {

	int i;

	for(i=0; i< h->size ;i++){
		printf("%d",h->elements[i]->key); 
	}

}

Heap* makeHeap(int capacity) {

	Heap* h = calloc(1,sizeof(Heap));

	h->elements=calloc(capacity,sizeof(Entry));

	h->capacity=capacity;

	h->size=0;

	return h;
}

char* peek(Heap* heap) {

	if(heap->elements[0]==NULL){
		return NULL;
	}

	char* topChar =heap->elements[0]->value;
	return topChar;
}

int size(Heap* heap) {

	return heap->size;
}



