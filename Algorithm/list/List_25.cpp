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

	pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail ){
		ListNode* cur = head;
		while( cur->next == tail ){
			ListNode* nxt = cur->next;
			cur->next->next = cur;
			cur = nxt;
		}

		return{tail, head};
	}

    pair<ListNode*, ListNode*> reverse1(ListNode* head, ListNode* tail) {
        ListNode* prev = NULL;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode{0};
		dummy->next = head;
		ListNode* pre = dummy;

		while( head ){
			ListNode* cur = pre;

			for( int i = 0; i < k; ++i ){
				cur = cur->next;
				if( !cur )
					return dummy->next;
			}

			ListNode* nxt = cur->next;
			pair<ListNode*,ListNode*> result = reverse( head, cur );
			head = result.first;
			cur = result.second;

			pre->next = head;
			cur->next = nxt;
			pre = cur;
			head = nxt;
		}

		return dummy->next;

    }
};

int main(){
	vector<int> v = {6, 4, 5, 6,7,8,9,0,0};
	ListNode* head = createList(v);

	printList(head);
	ListNode* rev =  Solution().reverseKGroup(head, 4);
	printList(rev);
	deleteList(rev);
}
