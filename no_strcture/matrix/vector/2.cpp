// only functions, not complete codes
    void deleteNode(Node* del_node) {
        /* without head node in SLL*/
        if (del_node->next!=NULL){
            del_node->data = del_node->next->data;
            del_node->next = del_node->next->next;
        }
        
        
    Node* sortedMerge(Node* head1, Node* head2) {
      //sorted 2 sll's merging
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        while (head1 && head2){
            if (head1->data <= head2->data){
                tail->next = head1;
                head1 = head1->next;
            }
            else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        while (head1){
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }
        while (head2){
            tail -> next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
        Node* merge = dummy->next;
        delete dummy;
        return merge;
    }
    
