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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> uset;
        ListNode* cur = head;

        while( cur != NULL){
            if( uset.count( cur) != 0)
                return cur;
            uset.insert( cur ); 
            cur = cur->next;
        }
        return NULL;
    }
};

class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while( fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if( slow == fast) break;
        }

        if( fast == NULL || fast->next == NULL)
            return NULL; 

        slow = head;
        while( slow != fast ){
            slow = slow->next;
            fast =fast->next;
        } 
        return slow;
    }
};


int main(){
	return;
}
