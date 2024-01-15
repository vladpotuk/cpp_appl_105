#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

class PriorityQueue {
private:
    static const int MAX_SIZE = 100; 

    struct Element {
        int value;
        int priority;

        Element() : value(0), priority(0) {}  

        Element(int val, int pri) : value(val), priority(pri) {}
    };

    Element elements[MAX_SIZE];
    int size;

public:
    PriorityQueue();
    bool IsEmpty() const;
    bool IsFull() const;
    void InsertWithPriority(int value, int priority);
    int PullHighestPriorityElement();
    int Peek() const;
    void Show() const;
};

#endif
