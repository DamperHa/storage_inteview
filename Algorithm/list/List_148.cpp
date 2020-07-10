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
    ListNode* sortList(ListNode* head) {
        if( head == NULL ||head->next == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while( fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        } 
        // 以slow为中点划分

        ListNode* temp = slow->next;
        slow->next = NULL;
        ListNode* L = sortList(head);
        ListNode* R = sortList(temp);
        
        // 合并
        ListNode* dummy = new ListNode{0};
        ListNode* cur = dummy;
        while( L != NULL && R != NULL){
            if( L->val > R->val){
                cur->next = R;
                R = R->next;
                cur = cur->next;
            }else{
                cur->next = L;
                L = L->next;
                cur = cur->next;
            }
        }
        ListNode* res = (L == NULL) ? R : L;
        cur->next = res;
        return dummy->next; // 可以释放内存
    }
};

int main(){
	vector<int> v1 = {5, 19,0,38,9};
	ListNode* head1 = createList(v1);
	printList(head1);
	ListNode* rev =  Solution().sortList(head1);
	printList(rev);
	deleteList(rev);
}
