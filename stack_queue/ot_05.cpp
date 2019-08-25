/*
题目描述：
实现队列的入队、出队操作
*/

#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include <stdlib.h>
using namespace std;

typedef struct student{
	int date;
	struct student *next;
}node;

typedef struct {
	node *first,*rear;
}queue;

queue *insert(queue *HQ,int num){
	node *s;
	s = (node *)malloc(sizeof(node));
	s -> date = num;
	s -> next = NULL;
	if(HQ -> rear == NULL){
		HQ -> first = s;
		HQ -> rear = s;
	}
	else{
		HQ -> rear -> next = s;
		HQ -> rear = s; 
	}
	return (HQ);
}

queue *del(queue *HQ){
	node *p;
	if(HQ -> first == NULL)
		printf("yichu\n");
	else{
		p = HQ -> first;
		if(HQ -> first == HQ -> rear){
			HQ -> first = NULL;
			HQ -> rear = NULL;
		}
		else{
			HQ -> first  = HQ -> first -> next;
			free(p);
		}
		return (HQ);
	}
}