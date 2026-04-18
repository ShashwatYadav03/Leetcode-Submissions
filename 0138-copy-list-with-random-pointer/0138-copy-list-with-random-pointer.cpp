class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Step 1 Create deep copy without random pointers
        Node* dummy = new Node(0);
        Node* tempC = dummy;
        Node* temp = head;
        while(temp){
            Node* a = new Node(temp->val);
            tempC->next = a;
            tempC = tempC->next;
            temp = temp->next;
        }
        Node* duplicate = dummy->next;
        // Step 2 alternate connections
        Node* a = head;
        Node* b = duplicate;
        dummy = new Node(-1);
        Node* tempD = dummy;
        while(a){
            tempD->next = a;
            a=a->next;
            tempD = tempD->next;
            tempD->next = b;
            b = b->next;
            tempD = tempD->next;
        }
        dummy = dummy->next;
        // Making alternate connections
        Node* t1 = dummy;
        while(t1){
            Node* t2 = t1->next;
            if(t1->random) t2->random = t1->random->next;
            t1 =t1->next->next;
        }
        // Step 4 Removing connections

        Node* d1 = new Node(-1);
        Node* d2 = new Node(-1);
        t1=d1;
        Node* t2=d2;
        Node* t = d2;
        t = dummy;
        while(t){
            t1->next = t;
            t = t->next;
            t1 = t1->next;
            t2->next = t;
            t= t->next;
            t2=t2->next;
        }
        t1->next = NULL;
        t2->next = NULL;
        d1 = d1->next;
        d2 = d2->next;
        return d2;

    }
};