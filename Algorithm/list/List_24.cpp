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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode{0};
        dummy->next = head;
        ListNode* pre = dummy;
        while (pre->next && pre->next->next){
            ListNode* node1 = pre->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;

            node2->next = node1;
            node1->next = next;
            pre->next = node2;
            pre = node1;
        }

        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
        
    }
};

int main(){
	vector<int> v = {1,2,3,4,4,4,5};
	ListNode* head = createList(v);
	printList(head);
	ListNode* rev =  Solution().swapPairs(head);
	printList(rev);
	deleteList(rev);
}
