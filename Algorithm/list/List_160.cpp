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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        while( pA != pB){
            pA = (pA == NULL) ? headB : pA->next;
            pB = ( pB == NULL) ? headA : pB->next;
        }
        return pA;
    }
};


int main(){
	// 这里的链表需要可以设计，因此这里不能显示是否运行成功
	vector<int> v = {0, 3};
	vector<int> v1 = {7,3};
	ListNode* head = createList(v);
	ListNode* head1 = createList(v1);

	printList(head);
	printList(head1);
	ListNode* rev =  Solution().getIntersectionNode(head, head1);
	cout << rev << endl;
	deleteList(rev);
}
