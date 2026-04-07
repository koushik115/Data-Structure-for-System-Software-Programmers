#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define DEQUE_MAX_SIZE	10

int deque_arr[DEQUE_MAX_SIZE];
int front = -1;
int rear = -1;

void insert_frontEnd(int item);
void insert_rearEnd(int item);
int delete_frontEnd(void);
int delete_rearEnd(void);
void display(void);
int isEmpty(void);
int isFull(void);

int main(void) {
	int choice, item;
	while(1) {
		printf("1.Insert at the front end\n");
		printf("2.Insert at the rear end\n");
		printf("3.Delete at front end\n");
		printf("4.Delete at rear end\n");
		printf("5.Display\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Input the element for adding in queue : ");
				scanf("%d", &item);
				insert_frontEnd(item);
				break;

			case 2:
				printf("Input the element for adding in queue : ");
				scanf("%d", &item);
				insert_rearEnd(item);
				break;

			case 3:
				item = delete_frontEnd();
				printf("Deleted element is %d\n", item);
				break;


			case 4:
				item = delete_rearEnd();
				printf("Deleted element is %d\n", item);
				break;

			case 5:
				display();
				break;

			case 6:
				exit(1);

			default:
				printf("Wrong choice\n");
		}
	}
}

void insert_frontEnd(int item) {
	if(isFull()) {
		printf("error: queue overflow!\n");
		return ;
	}

	if(front == -1) {
		front = rear = 0;
	} else if(front == 0) {
		front = DEQUE_MAX_SIZE - 1;
	} else {
		front--;
	}

	deque_arr[front] = item;
}

void insert_rearEnd(int item) {
	if(isFull()) {
		printf("error: queue overflow!\n");
		return;
	}

	if(front == -1) {
		front = rear = 0;
	} else if(rear == DEQUE_MAX_SIZE - 1) {
		rear = 0;
	} else {
		rear++;
	}

	deque_arr[rear] = item;
}

int delete_frontEnd(void) {
	int item;

	if(isEmpty()) {
		printf("error: queue underflow!\n");
		return INT_MIN;
	}
	
	item = deque_arr[front];
	if(front == rear) {
		front = rear = -1;
	} else if(front == DEQUE_MAX_SIZE - 1) {
		front = 0;
	} else {
		front++;
	}

	return item;
}

int delete_rearEnd(void) {
	int item;

	if(isEmpty()) {
		printf("error: queue underflow!\n");
		return INT_MIN;
	}

	item = deque_arr[rear];
	if(front == rear) {
		printf("error: queue underflow!\n");
		return INT_MIN;
	} else if(rear == 0) {
		rear = DEQUE_MAX_SIZE - 1;
	} else {
		rear--;
	}

	return item;
}

int isFull(void) {
	return ((front == 0 && rear == DEQUE_MAX_SIZE - 1) || (front == rear + 1));
}

int isEmpty(void) {
	return (front == -1 && rear == -1);
}

void display(void) {
	int i;

	if(isEmpty()) {
		printf("error: queue is empty!\n");
		return;
	}

	printf("queue elements : \n");

	i = front;
	if(front <= rear) {
		while(i <= rear) {
			printf(" %d", deque_arr[i++]);
		}
	} else {
		while(i <= DEQUE_MAX_SIZE - 1) {
			printf(" %d", deque_arr[i++]);
		}

		i = 0;
		while(i <= rear) {
			printf(" %d", deque_arr[i++]);
		}
	}

	printf("\n");
}

