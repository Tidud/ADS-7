// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  if (first == nullptr) {
    first = new Car{light, nullptr, nullptr};
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    Car* newCar = new Car{light, first, last};
    last->next = newCar;
    first->prev = newCar;
  }
}

int Train::getLength() {
  first->light = true;
  int len = 0;
  while (++len) {
    Car* current = first;
    for (int i = 0; i < len; ++i) {
      current = current->next;
      current->light = false;
      ++countOp;
    }
    for (int i = 0; i < len; ++i) {
      current = current->prev;
      ++countOp;
    }

    if (current->light != true) return len;
  }
  return 0;
}

int Train::getOpCount() { return countOp; }
