/*
 * Queue.hpp
 *
 *  Created on: Aug 7, 2023
 *      Author: nangb
 */

#ifndef APPLICATION_USER_SRC_QUEUE_HPP_
#define APPLICATION_USER_SRC_QUEUE_HPP_


class Queue {
private:
    std::pair<int32_t, int32_t> myqueue[100];
	int32_t front, rear;

public:
	static const int MAX_SIZE = 100;
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if (front == 0 && rear == MAX_SIZE - 1) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (front == -1) return true;
        else return false;
    }

    void enQueue(std::pair<int32_t, int32_t> value) {
        if (!isFull()) {
            if (front == -1) front = 0;
            rear++;
            myqueue[rear] = value;
        }
    }
    std::pair<int32_t, int32_t> deQueue() {
    	std::pair<int32_t, int32_t> value;
        if (!isEmpty()) {
            value = myqueue[front]; if (front >= rear) {      //only one element in queue
                front = -1;
                rear = -1;
            }
            else {
                front++;
            }
            return(value);
        }
    }
};



#endif /* APPLICATION_USER_SRC_QUEUE_HPP_ */
