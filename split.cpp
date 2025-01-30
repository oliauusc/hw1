/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

void split(Node*& in, Node*& odds, Node*& evens) {

if (in == nullptr)
  return;

Node* nextIn = in->next;
Node* oddsPtr = nullptr;
Node* evensPtr = nullptr;

if ((in->value)%2 == 0) {
  in->next = evens;
  evens = in;
}
else {
  in->next = odds;
  odds = in;
}
//   if (evens == nullptr) {
//     evens = in;
//     evensPtr = in;
//   }
//   else {
//     evensPtr->next = in;
//     evensPtr = evensPtr->next;
//   }
// }

// else {
//   if (odds == nullptr) {
//     odds = in;
//     oddsPtr = in;
//   }
//   else {
//     oddsPtr->next = in;
//     oddsPtr = oddsPtr->next; 
//   }
// }

in = nextIn;

split(in, odds, evens);
}
