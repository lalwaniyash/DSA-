 //Step-1->make copy nodes and insert it in beetween original list:
        Node* iter = head;
        Node* front = head;
        
        while(iter!=NULL){
            front = iter->next;
            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;         
        }
        
        //Step-2->Set random pointers of copy Nodes:
        iter = head;
        while(iter!=NULL){
            if(iter->random!=NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        //Step-3->Restore original list and extract copy list
        iter = head;
        Node* dummyHead = new Node(0);
        Node* copy = dummyHead;
        while(iter!=NULL){
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = front;
        }
        return dummyHead->next;