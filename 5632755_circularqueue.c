#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//원형큐 코드
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

//함수 선언

void init_queue(QueueType* q);
int is_empty(QueueType* q);
int is_full(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);
element peek(QueueType* q);

void error(char* message);
void queue_print(QueueType* q);

int main(void)
{
	int menu_num = 0;
	QueueType q;
	int element;
	init_queue(&q);
	while (1)
	{
		printf("\n===== Menu =====\n");
		printf("1. Input data and Enqueue\n");
		printf("2. Dequeue and Print data;\n");
		printf("3. Print Queue\n");
		printf("4. Exit\n");
		printf("Select number : ");
		scanf("%d", &menu_num);
		

		if (menu_num == 1)
		{
			printf("\nInput the data: ");
			scanf("%d", &element);

			if (is_full(&q))
			{
				printf("Queue is Full!\n");
			}

			else {
				enqueue(&q, element);
				//queue_print(&q);
				printf("Enqueue: %d\n", element);
				}
			

			
		}
		else if (menu_num == 2)
		{
			if (is_empty(&q))
			{
				printf("Queue is Empty.\n");
			}
			else {
				printf("\nDequeue: %d\n", dequeue(&q));
				}
		}
		else if (menu_num == 3)
		{
			queue_print(&q);
		}
		else if (menu_num == 4)
		{
			exit(0);
		}
		else
			printf("잘못 입력하셨습니다.\n");
		
	}
}

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return(q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
//원형큐 출력함수
void queue_print(QueueType* q)
{
	printf("QUEUE(front = %d rear = %d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d |", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

//삽입함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
	{
		error("Queue is Full!");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
	{
		error("Queue is empty.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

//삭제함수
element peek(QueueType* q)
{
	if (is_empty(q))
	{
		error("Queue is empty.");
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}