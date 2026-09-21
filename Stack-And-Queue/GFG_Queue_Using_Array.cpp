class myQueue {
	int capacity;
	int* queueArray;
	int front;
	int rear;
	int currSize;
	public:
	myQueue(int n) {
		// Define Data Structures
		capacity = n;
		queueArray = new int[capacity];
		front = -1;
		rear = -1;
		currSize = 0;
	}
	
	bool isEmpty() {
		// check if the queue is empty
		return currSize == 0;
	}
	
	bool isFull() {
		// check if the queue is full
		return currSize == capacity;
	}
	
	void enqueue(int x) {
		// Adds an element x at the rear of the queue.
		if (currSize >= capacity) return;
		if (currSize == 0) front++;
		rear = (rear+1)%capacity;
		queueArray[rear] = x;
		currSize++;
	}
	
	void dequeue() {
		// Removes the front element of the queue.
		if (currSize == 0) return;
		if (currSize == 1) {
		    front = -1, rear = -1;
		    currSize--;
		    return;
		}
		front++;
		currSize--;
	}
	
	int getFront() {
		// Returns the front element of the queue.
		if (currSize == 0) return -1;
		return queueArray[front];
	}
	
	int getRear() {
		// Return the last element of queue
		if (currSize == 0) return -1;
		return queueArray[rear];
	}
};
