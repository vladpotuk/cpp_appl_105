#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue() : size(0) {}

bool PriorityQueue::IsEmpty() const {
    return size == 0;
}

bool PriorityQueue::IsFull() const {
    return size == MAX_SIZE;
}

void PriorityQueue::InsertWithPriority(int value, int priority) {
    if (!IsFull()) {
        Element newElement(value, priority);

        
        int i = size - 1;
        while (i >= 0 && elements[i].priority > newElement.priority) {
            elements[i + 1] = elements[i];
            i--;
        }

        elements[i + 1] = newElement;
        size++;
    }
}

int PriorityQueue::PullHighestPriorityElement() {
    if (!IsEmpty()) {
        int value = elements[0].value;

 
        for (int i = 1; i < size; i++) {
            elements[i - 1] = elements[i];
        }

        size--;
        return value;
    }
    return -1;
}

int PriorityQueue::Peek() const {
    if (!IsEmpty()) {
        return elements[0].value;
    }
    return -1;
}

void PriorityQueue::Show() const {
    for (int i = 0; i < size; i++) {
        std::cout << "Value: " << elements[i].value << ", Priority: " << elements[i].priority << std::endl;
    }
}
