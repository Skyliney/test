#include<stdio.h>
struct node
{
	int date;
	struct node *next;
};
struct node *create(int);
struct node *getIndex0f(struct node *, int);
void traverse(struct node *, void(*)(struct node *));
void via(struct node *);
void add(struct node *,int, int);
void main()
{
	struct node *Head = create(5);
	traverse(Head, via);
	putchar('\n');
	getIndex0f(Head, 3)->date = 3;
	traverse(Head, via);
	putchar('\n');
	add(Head, 2, 2);
	traverse(Head, via);
}
void add(struct node *list,int index, int length)
{
	struct node *NewHead = create(length);
	struct node *t = getIndex0f(list, index)->next;
	getIndex0f(list, index)->next = NewHead;
	getIndex0f(NewHead, length - 1)->next = t;
}
void via(struct node *node)
{
	printf("%d \t", node->date);
}
struct node *create(int count)
{
	struct node *head = malloc(sizeof(struct node));
	if (head == NULL)
	{
		printf("Á´±í´´½¨Ê§°Ü");
		return NULL;
	}
	head->date = 1;
	head->next = NULL;
	struct node *tail = head;
	for (int i = 0; i < count - 1; i++)
	{
		struct node *p;
		do
			p = malloc(sizeof(struct node));
		while (p == NULL);
		p->date = 0;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	return head;
}
struct node *getIndex0f(struct node *list, int index)
{
	struct node *p = list;
	for (int i = 0; i < index; i++)
	{
		p = p->next;
	}
	return p;
}
void traverse(struct node *list, void(*via)(struct node *node))
{
	while (list != NULL)
	{
		via(list);
		list = list->next;
	}
}