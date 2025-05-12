// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train(): countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newc = new Car(light);
  if (first == nullptr) {
    first = newc;
    newc->prev = first;
    newc->next = first;
  } else {
    Car* last = first->prev;
    last->next = newc;
    newc->prev = last;
    newc->next = first;
    first->prev = newc;
  }
}

int Train::getLength() {
  first->light = true;
  Car* sled = first->next;
  while (1) {
    int dlina = 1;
    countOp++;
    while (sled->light == false) {
      sled = sled->next;
      dlina++;
      countOp++;
    }
    sled->light = false;
    for (int erin = 0; erin < dlina; erin++) {
      sled = sled->prev;
      countOp++;
    }
    if (first->light == false) {
      return dlina;
    }
    sled = sled->next;
  }
}

int Train::getOpCount() {
  return countOp;
}
