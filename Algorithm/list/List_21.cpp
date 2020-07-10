#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};

ListNode* createList(vector<int> v){
	if (v.size() == 0)
		return NULL;
	ListNode* head = new ListNode{v[0]};
	ListNode* cur = head;

	for (int i =1; i < v.size(); i++){
		cur->next= new ListNode{v[i]};
		cur = cur->next;
	}
	return head;
	
}


void printList(ListNode* head){
	ListNode* cur = head;
	while (cur != NULL){
		cout << cur->val << "->";
		cur = cur->next;
	}
	cout << "NULL" << endl;
	return;
}


void deleteList(ListNode* head){
	ListNode* cur = head;
	while (cur != NULL){
		ListNode* delNode = cur;
		cur = cur->next;
		delete delNode;
	}

	return;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (p != NULL && q != NULL){
            ListNode* temp = NULL;
            if (p->val < q->val){
                temp = p;
				p = p->next;
			}
            else{
                temp = q;
				q = q->next;
			}
            cur->next = temp;
            cur =cur->next;

			cout << temp->val << endl;
        }

		cur->next = (p == NULL) ? q : p;
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};


int main(){
	vector<int> v1 = {1,2,3,4,4,4,5};
	vector<int> v2 = {1,2,3,4,4,4,5};
	ListNode* head1 = createList(v1);
	ListNode* head2 = createList(v2);
	printList(head1);
	ListNode* rev =  Solution().mergeTwoLists(head1, head2);
	printList(rev);
	deleteList(rev);
}
