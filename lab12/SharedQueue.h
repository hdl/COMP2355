//
//  SharedQueue.h
//  Lab12
//

#ifndef __Lab12__SharedQueue__
#define __Lab12__SharedQueue__

#include <mutex>
#include <iostream>

// Adapt LList code below to implement SharedQueue
// (then remove this comment)

template <typename T>
class SharedQueue {
public:
    SharedQueue();
    ~SharedQueue();
    bool IsEmpty() const;
    void Add(T value);
    bool Remove(T &item);
    void Print();
private:
    struct QueueItem {
        T item;
        QueueItem *next;
    };
    std::mutex lock;
    QueueItem *head, *tail;
};

template <typename T>
SharedQueue<T>::SharedQueue()
{
    head = tail = nullptr;
}

template <typename T>
SharedQueue<T>::~SharedQueue()
{
    T item;
    while (!IsEmpty())
    {
        Remove(item);
    }
}

template <typename T>
bool SharedQueue<T>::IsEmpty() const
{
    return (head == nullptr);
}

template <typename T>
void SharedQueue<T>::Add(T value)
{
    lock.lock();
    QueueItem *tmp = new QueueItem();
    tmp->item = value;
    tmp->next = nullptr;
    if(IsEmpty())
        head = tmp;
    else{
        tail->next = tmp;
    }
    tail = tmp;
    lock.unlock();
}

template <typename T>
bool SharedQueue<T>::Remove(T &item)
{
    lock.lock();
    if (IsEmpty()){
        //std::cout<<"empty now"<<std::endl;
        lock.unlock();
        return 0;
    }
    else{
        QueueItem *tmp = head;
        if(head == tail){
            head = nullptr;
            tail = nullptr;
        }else{
            head = head->next;
        }
        item = tmp->item;
        delete tmp;
        lock.unlock();
        return 1;
    }
    
}

template <typename T>
void SharedQueue<T>::Print()
{
    lock.lock();
    std::cout << "Print:";
    for (QueueItem *iter = head; iter!=nullptr; iter = iter->next)
    {
        std::cout << iter->item<< " ";
    }
    std::cout << std::endl;
    lock.unlock();
}




#endif /* defined(__Lab12__SharedQueue__) */
