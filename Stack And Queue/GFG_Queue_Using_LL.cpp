class Node {
	public:
	int data;
	Node* next;
	
	Node(int new_data) {
		data = new_data;
		next = nullptr;
	}
};

class myQueue {
	Node* start;
	Node* end;
	int currSize;
	public:
	myQueue() {
		// Initialize your data members
		start = NULL, end = NULL, currSize = 0;
	}
	
	bool isEmpty() {
		// check if the queue is empty
		return currSize == 0;
	}
	
	void enqueue(int x) {
		// Adds an element x at the rear of the queue
		Node* newNode = new Node(x);
		if (currSize == 0) start = newNode, end = newNode;
		else{
		    end->next = newNode;
		    end = newNode;
		}
		currSize++;
	}
	
	void dequeue() {
		// Removes the front element of the queue
		Node* poppedNode = start;
		start = start->next;
		delete poppedNode;
		currSize--;
	}
	
	int getFront() {
		// Returns the front element of the queue
		// If queue is empty, return -1
		if (currSize == 0) return -1;
		return start->data;
	}
	
	int size() {
		// Returns the current size of the queue.
		return currSize;
	}
};