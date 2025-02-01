#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}


void ULListStr::push_back(const std::string& in)
{
  if (!tail_) {
    Item* temp = new Item();
   temp->prev = tail_;
   tail_ = temp; 
  head_=tail_;

  // tail_->first = 9;
  }
  if (tail_->last ==ARRSIZE) {
   Item* temp = new Item();
   temp->prev = tail_;
   tail_->next = temp;
   tail_ = temp;
  }
  tail_->val[tail_->last] = in;
  tail_->last++;
  (size_)++;
}

void ULListStr::push_front(const std::string& in)
{
  
  if (!head_) {
   Item* temp = new Item();
   temp->next = head_;
   head_ = temp; 
   head_->last = ARRSIZE;
   head_->first = ARRSIZE;
  tail_=head_;

  }
  if (head_->first == 0) {
   Item* temp = new Item();
   temp->next = head_;
   head_->prev = temp;
   head_ = temp;
   head_->last = ARRSIZE;
   head_->first = ARRSIZE;
  }

  head_->val[head_->first-1] = in;
  head_->first--;
  (size_)++;
}

void ULListStr::pop_back() 
{
  if (empty()) return;
  tail_->last--;
  size_--;

  if (tail_->first == tail_->last)
  {
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != nullptr) tail_->next = nullptr;
    else head_ = nullptr;
    delete temp;
  }
}

void ULListStr::pop_front() 
{
  if (empty()) return;
  head_->first++;
  size_--;

  if (head_->first == head_->last)
    {
      Item* temp = head_;
      head_ = head_->next;
      if (head_ != nullptr) head_->prev = nullptr;
      else tail_ = nullptr;
      delete temp;
    }
}

std::string const & ULListStr::back() const
{
  if (empty()) throw std::out_of_range("no items in list");
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
  if (empty()) throw std::out_of_range("no items in list");
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc>=size_) return nullptr;
  Item* temp = head_;
  size_t remainder = loc;
  while (temp != nullptr) {
    size_t arraysize = temp->last-temp->first;
    if (remainder<arraysize) return &temp->val[temp->first+remainder];
    remainder = remainder - arraysize;
    temp = temp->next;
  }
  return nullptr;
}


// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
