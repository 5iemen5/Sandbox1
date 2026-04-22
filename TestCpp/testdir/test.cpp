#include <iostream>
#include <cstdint>
#include <cstdio>
#include <stdlib.h>

#define MAX_SIZE 100

class stack{

  private: 

    const uint16_t absoluteMax = 256;
    uint16_t currentSize;

    struct node{
      uint16_t value;
      node * next; 
    };

    struct node * pTopNode = NULL;

  public:
  
    uint16_t max;

    uint16_t Push(uint16_t val) {

        if(pTopNode == NULL){
          std::cout << "First node!" << std::endl;

          struct node * Node = (struct node *)malloc(sizeof(struct node));
          Node->next = NULL;
          Node->value = val;
          ++currentSize;
          pTopNode = Node;

          printf("Pushed %d\r\n", val);
          return sizeof(struct node);
        }

        if (currentSize >= absoluteMax) {
          printf("Stack full\r\n");
          return 0;
        }

        struct node * Node = (struct node *)malloc(sizeof(struct node));
        Node->next = pTopNode;
        Node->value = val;
        ++currentSize;
        pTopNode = Node;

        printf("Pushed %d\r\n", val);
        return sizeof(struct node);
    }

    uint16_t Peek(void){
      if(pTopNode != NULL) {
        printf("Peeked %d\r\n", pTopNode->value);
        return pTopNode->value;
      }
      else printf("Stack empty!\r\n");
      return 0;
    }

    uint16_t Pop(void){
      
      if(pTopNode == NULL){
        printf("Nothing to pop!\r\n");
        return 0;
      } 

      struct node * pPrevTopNode = NULL;

      pPrevTopNode = pTopNode;
      uint16_t retval = pTopNode -> value;
      pTopNode = pTopNode -> next;
      free(pPrevTopNode);

      printf("Popped %d\r\n", retval);
      return retval;

    }

}MyStack;

class queue{

  private: 

    const uint16_t absoluteMax = 256;
    uint16_t currentSize;

    struct node{
      uint16_t value;
      node * next; 
    };

    struct node * pTopNode = NULL;

  public:
  
    uint16_t max;

    uint16_t Push(uint16_t val) {

        if(pTopNode == NULL){
          std::cout << "First node!" << std::endl;

          struct node * Node = (struct node *)malloc(sizeof(struct node));
          Node->next = NULL;
          Node->value = val;
          ++currentSize;
          pTopNode = Node;

          printf("Pushed %d\r\n", val);
          return sizeof(struct node);
        }

        if (currentSize >= absoluteMax) {
          printf("Stack full\r\n");
          return 0;
        }

        struct node * Node = (struct node *)malloc(sizeof(struct node));
        Node->next = pTopNode;
        Node->value = val;
        ++currentSize;
        pTopNode = Node;

        printf("Pushed %d\r\n", val);
        return sizeof(struct node);
    }

    uint16_t Peek(void){
      if(pTopNode != NULL) {
        printf("Peeked %d\r\n", pTopNode->value);
        return pTopNode->value;
      }
      else printf("Stack empty!\r\n");
      return 0;
    }

    uint16_t Pop(void){
      
      if(pTopNode == NULL){
        printf("Nothing to pop!\r\n");
        return 0;
      } 

      struct node * pPrevTopNode = NULL;

      pPrevTopNode = pTopNode;
      uint16_t retval = pTopNode -> value;
      pTopNode = pTopNode -> next;
      free(pPrevTopNode);

      printf("Popped %d\r\n", retval);
      return retval;

    }

}MyQueue;




int main(){

  std::cout << "Hello World!" << std::endl;

  MyStack.Peek();

  MyStack.Push(10);
  MyStack.Peek();
  MyStack.Push(15);
  MyStack.Peek();

  printf("\r\n");

  MyStack.Pop();
  MyStack.Pop();
  MyStack.Pop();
  MyStack.Pop();
  MyStack.Pop();
  MyStack.Pop();
  MyStack.Pop();
  MyStack.Pop();
  MyStack.Pop();
  


  return 0;
}