// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
private:
  T arr[100];
  int f;
  int l;
public:
  TPQueue() : f(0), l(0) {}
  void push(T uni) {
    int lat = l++;
    while ((--lat >= f) && (arr[lat % size].prior < uni.prior)) {
      arr[(lat + 1) % size] = arr[lat % size];
    }
    arr[(lat + 1) % size] = uni;
  }
  T pop() {
    return arr[(f++) % size];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
