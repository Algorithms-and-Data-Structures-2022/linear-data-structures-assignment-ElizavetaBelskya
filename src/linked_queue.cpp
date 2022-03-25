#include "assignment/linked_queue.hpp"

namespace assignment {

  LinkedQueue::~LinkedQueue() {
    LinkedQueue::Clear();
  }

  void LinkedQueue::Enqueue(int value) {
    if (size_ == 0) {
      Node* node = new Node(value, nullptr);
      front_ = node;
      back_ = node;
      size_++;
    } else {
      Node* node = new Node(value, nullptr);
      back_->next = node;
      back_ = node;
      size_++;
    }
  }

  bool LinkedQueue::Dequeue() {
    if (size_ == 0){
      return false;
    } else {
      Node* n = front_;
      delete front_;
      front_ = n->next;
      size_--;
      return true;
    }
  }

  void LinkedQueue::Clear() {
    Node* n = front_;
    for (int i =0; i < size_; i++) {
      Node* k = n->next;
      delete n;
      n = k;
    }
    front_ = nullptr;
    back_ = nullptr;
    size_ = 0;
  }

  std::optional<int> LinkedQueue::front() const {
    return front_->value;
  }

  std::optional<int> LinkedQueue::back() const {
    return back_->value;
  }

  bool LinkedQueue::IsEmpty() const {
    return (size_ == 0);
  }

  int LinkedQueue::size() const {
    return size_;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedQueue::LinkedQueue(const std::vector<int>& values) {

    if (values.empty()) {
      return;
    }

    auto* curr_node = new Node(values.front());
    front_ = curr_node;

    for (int index = 1; index < values.size() - 1; ++index) {
      curr_node->next = new Node(values[index]);
      curr_node = curr_node->next;
    }

    if (values.size() == 1) {
      back_ = front_;
    } else {
      curr_node->next = new Node(values.back());
      back_ = curr_node->next;
    }

    size_ = static_cast<int>(values.size());
  }

  std::vector<int> LinkedQueue::toVector() const {
    if (front_ == nullptr || size_ == 0) {
      return {};
    }

    std::vector<int> array;
    array.reserve(size_);

    for (auto* node = front_; node != nullptr; node = node->next) {
      array.push_back(node->value);
    }

    return array;
  }

}  // namespace assignment