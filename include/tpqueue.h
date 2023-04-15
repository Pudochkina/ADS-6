// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int frst, lst, cnt;

 public:
    TPQueue() : frst(0), lst(0), cnt(0) {
        arr = new T[size];
    }
    ~TPQueue() {
        delete[] arr;
    }
    const T& pop() {
       if (isEmpty()) {
           throw std::string("Empty!");
       }
       cnt--;
       return arr[frst++ % size];
    }
    void push(const T& value) {
        if (isFull()) {
            throw std::string("Full!");
        } else {
            int temp = lst;
            for (int i = lst; i > frst; i--) {
                if (arr[i - 1].prior < value.prior) {
                    temp = i - 1;
                    arr[i % size] = arr[i - 1];
                }
            }
            arr[temp % size] = value;
            cnt++;
            lst++;
        }
    }
    bool isEmpty() const {
        return 0 == cnt;
    }
    bool isFull() const {
        return size == cnt;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
