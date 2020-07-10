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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* head = new ListNode{0};
		ListNode* cur = head;

		int carry = 0;
		while(p != NULL || q!= NULL){
			int x = (p==NULL)? 0 : p->val;
			int y = (q==NULL)? 0 : q->val;
			int sum = x + y + carry;

			carry = sum/10;
			cur->next = new ListNode{sum%10};
			cur = cur->next;

			p = (p == NULL)? NULL:p->next;
			q = (q == NULL)? NULL: q->next;
		}

		if (carry)
			cur->next = new ListNode{carry};

		return head->next;
	}
};


int main(){
	vector<int> v = {0};
	vector<int> v1 = {7,3};
	ListNode* head = createList(v);
	ListNode* head1 = createList(v1);

	printList(head);
	printList(head1);
	ListNode* rev =  Solution().addTwoNumbers(head, head1);
	printList(rev);
	deleteList(rev);
}
