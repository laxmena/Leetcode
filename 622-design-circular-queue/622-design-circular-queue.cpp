class Node
{
   public:
   int data;
   Node* next;
   Node(int data)
   {
       this->data=data;
       next=NULL;
   }
};
class MyCircularQueue {
public:
    Node* head=NULL;
    Node* tail=NULL;
    int maxSize;
    int size=0;
    MyCircularQueue(int k) {
        maxSize=k;
    }
    
    bool enQueue(int value) {
        if(size==maxSize)
        {
            return false;
        }
        if(head==NULL)
        {
            size++;
            Node* temp=new Node(value);
            head=temp;
            tail=temp;
            return true;
        }
        size++;
        Node* temp=new Node(value);
        tail->next=temp;
        tail=temp;
        return true;
    }
    
    bool deQueue() {
        if(size==0||head==NULL)
        {
            return false;
        }
        size--;
        if(head==tail)
        {
            Node* temp=head;
            head=head->next;
            tail=head;
            tail=NULL;
            head==NULL;
            delete temp;
            return true;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return true;
    }
    
    int Front() {
        if(head==NULL)
        {
            return -1;
        }
        return head->data;
    }
    
    int Rear() {
        if(tail==NULL)
        {
            return -1;
        }
        return tail->data;
    }
    
    bool isEmpty() {
        if(size==0)
        {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(size==maxSize)
        {
            return true;
        }
        return false;
    }
};