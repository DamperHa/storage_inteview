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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* head_odd = odd;
        ListNode* head_even = even;

        while (even!= NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = head_even;

        return head_odd;
    }
};

int main(){
	vector<int> v = {1,2,3,4,5};
	ListNode* head = createList(v);
	printList(head);
	ListNode* rev =  Solution().oddEvenList(head);
	printList(rev);
	deleteList(rev);
}
