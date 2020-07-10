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

	ListNode* reverse( ListNode* head){
		ListNode* pre = NULL;
		ListNode* cur = head;

		while(cur !=NULL){
			ListNode* nxt = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nxt;
		}
		return pre;
	}

    void reorderList(ListNode* head) {
        if( head == NULL || head->next == NULL)
            return ;
        ListNode* slow  = head;
        ListNode* fast = head;
        
        while( fast != NULL && fast->next != NULL){
			slow = slow->next;
            fast = fast->next->next;
        }

        // 此时slow位于后半部分的起点

        ListNode* temp = slow->next;
        slow->next = NULL;
		ListNode* head1 = reverse(temp);

        while(head1 != NULL){
			ListNode* nxt = head->next;
			ListNode* nxt1 = head1->next;
			
			head1->next = nxt;
			head->next = head1;

			head = nxt;
			head1 = nxt1;
		}
    
    }
};

int main(){
	vector<int> v = {1,2, 5, 10, 6,7, 8};
	ListNode* head = createList(v);
	printList(head);
	Solution().reorderList(head);
	printList(head);
	deleteList(head);
}
