#include<stdio.h>
/*
链表的简单实现
*/
struct Stu
{
	long num;
	double score;
	struct Stu *next;
};
void main()
{
	struct Stu a, b, c, *head;
 
	a.num = 10001;
	a.score = 98;
	b.num = 10002;
	b.score = 89;
	c.num = 10003;
	c.score = 90;
 
	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
 
	do {
		printf("%d     %5.2f\n", head->num, head->score);
		head = head->next;
	} while (head!=NULL);
 

}