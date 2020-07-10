#include <iostream>
#include <vector>
#include <stack>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode{0};
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while( n > 0){
            fast = fast->next;
            n--;
        }
        while( fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;
        return dummy->next;
    }
};

int main(){
	vector<int> v1 = {5, 9,98787, 0};
	ListNode* head1 = createList(v1);
	printList(head1);
	ListNode* rev =  Solution().removeNthFromEnd(head1, 3);
	printList(rev);
	deleteList(rev);
}
