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
  countOp = 0;
  int step = 0, len = 1;
  Car* current = first;
  current->light = true;
  while (++step) {
    current = current->next;
    ++countOp;
    if (current->light) {
      current->light = false;
      len = step;
      for (int i = 0; i < step; ++i) {
        current = current->prev;
        ++countOp;
      }
      if (!current->light) return len;
      step = 0;
    }
  }
}

int Train::getOpCount() { return countOp; }
