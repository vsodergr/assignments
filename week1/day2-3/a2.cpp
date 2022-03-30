#include <iostream>

struct Node {
  int data;
  Node* next;
};

void PrintList(Node* n) {
  while (n != nullptr) {
    std::cout << n->data << " ";
    n = n->next;
  }
}

void InsertAfterIndex(Node** head, int data, size_t idx) {
  size_t jump_count = 0;
  Node* new_node = new Node();
  Node* node_at_pos = *head;
  new_node->data = data;

  while ((node_at_pos->next != nullptr) && (jump_count < idx)) {
    node_at_pos = node_at_pos->next;
    jump_count++;
  }

  // If list ended before requested position was reached.
  if (jump_count < idx) {
    std::cout << "Requested position is past the end of the list. Appending "
                 "node to end.\n";
  }

  new_node->next = node_at_pos->next;
  node_at_pos->next = new_node;
}

void Append(Node** head, int data) {
  Node* new_node = new Node();
  Node* last = *head;
  new_node->data = data;
  new_node->next = nullptr;

  if (*head == nullptr) {
    *head = new_node;
    return;
  }

  while (last->next != nullptr) {
    last = last->next;
  }

  last->next = new_node;
}

int main() {
  Node* head = nullptr;

  int value_arr[] = {11, 3, 10, 50, 23, 5, 60};

  for (size_t i = 0; i < (sizeof(value_arr) / sizeof(value_arr[0])); i++) {
    Append(&head, value_arr[i]);
  }

  InsertAfterIndex(&head, 15, 6);

  PrintList(head);
  std::cout << "\n";
}