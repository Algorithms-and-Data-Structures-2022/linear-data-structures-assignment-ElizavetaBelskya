#include "assignment/linked_list.hpp"

namespace assignment {

  LinkedList::~LinkedList() {
    LinkedList::Clear();
  }

  void LinkedList::Add(int value) {
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

  bool LinkedList::Insert(int index, int value) {
    if (index < 0 || index > size_) {
      return false;
    } else if (index == 0) {
      if (size_!=0 ) {
        Node* node = new Node(value, nullptr);
        node->next = front_;
        front_ = node;
        size_++;
      } else {
        Node* node = new Node(value, nullptr);
        front_ = node;
        back_ = node;
        size_++;
      }
    } else if (index == size_) {
      Node* node = new Node(value, nullptr);
      back_->next = node;
      back_ = node;
      size_++;
    } else {
      Node* n = front_;
      for (int i = 0; i < index-1; i++) {
        n = n->next;
      }
      Node* k = n->next;
      Node* node = new Node(value, nullptr);
      n->next = node;
      node->next = k;
      size_++;
    }
    return true;
  }

  bool LinkedList::Set(int index, int new_value) {
    if (index >= 0 && index < size_) {
      Node* n = front_;
      for (int i = 0; i < index; i++) {
        n = n->next;
      }
      n -> value = new_value;
      return true;
    }
    return false;
  }

  std::optional<int> LinkedList::Remove(int index) {
    if (size_!=0) {
      if ((index > 0 && index < size_-1)) {
        Node* n = front_;
        for (int i = 0; i < index-1; i++) {
          n = n->next;
        }
        int oldElem = n->next->value;
        n->next = n->next->next;
        size_--;
        return oldElem;
      } else if (index == 0) {
        int oldElem = front_->value;
        front_ = front_->next;
        size_--;
        return oldElem;
      } else if (index == size_-1) {
        Node* n = front_;
        for (int i = 0; i < index-1; i++) {
          n = n->next;
        }
        int oldElem = back_->value;
        n->next = nullptr;
        back_ = n;
        size_--;
        return oldElem;
      }
    }
    return std::nullopt;
  }

  void LinkedList::Clear() {
    size_ = 0;
    front_ = nullptr;
    back_ = nullptr;
  }

  std::optional<int> LinkedList::Get(int index) const {
    if (index >= 0 && index < size_) {
      Node* n = front_;
      for (int i = 0; i < index; i++) {
        n = n->next;
      }
      return n->value;
    }
    return std::nullopt;
  }

  std::optional<int> LinkedList::IndexOf(int value) const {
    Node* n = front_;
    for (int i = 0; i < size_; i++) {
      if (n->value == value) {
        return i;
      }
      n = n->next;
    }
    return std::nullopt;
  }

  bool LinkedList::Contains(int value) const {
    Node* n = front_;
    for (int i = 0; i < size_; i++) {
      if (n->value == value) {
        return true;
      }
      n = n->next;
    }
    return false;
  }

  bool LinkedList::IsEmpty() const {
    return (size_ == 0);
  }

  int LinkedList::size() const {
    return size_;
  }

  std::optional<int> LinkedList::front() const {
    if (front_ != nullptr) {
      return front_->value;
    }
    return std::nullopt;
  }

  std::optional<int> LinkedList::back() const {
    if (back_ != nullptr) {
      return back_->value;
    } else {
      return std::nullopt;
    }
  }

  Node* LinkedList::FindNode(int index) const {
    if (index > -1 && index < size_) {
      Node* n = front_;
      for (int i = 0; i < index; i++) {
        n = n->next;
      }
      return n;
    }
    return nullptr;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedList::LinkedList(const std::vector<int>& values) {

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

  std::vector<int> LinkedList::toVector() const {

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