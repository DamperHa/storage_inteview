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
    bool isPalindrome(ListNode* head) {
        if( head == NULL )  return true; 
        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* pre = NULL;
        while( fast && fast->next){
            fast = fast->next->next;
            ListNode* nxt = slow->next;
            slow->next = pre;
            pre = slow;
            slow  = nxt;

        }
        
        if( fast )
            slow = slow->next;
        while(pre && slow){
            
            if( pre->val != slow->val)
                return false;
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};


int main(){
	vector<int> v = {1,0,3,3,2,1};
	ListNode* head = createList(v);
	printList(head);
	bool rev =  Solution().isPalindrome(head);
	cout << rev << endl;
}
