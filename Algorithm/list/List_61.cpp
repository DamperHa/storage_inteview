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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode *p = head;
        // 统计长度
        int len = 1;
        for(; p->next; p=p->next) len++;
        // 首尾相连
        p->next = head;
        // 找到断点
        k %= len;
        for(p = head; --len != k; p = p->next);
        // 更改首尾
        head = p->next;
        p->next = NULL;
        return head;
    }
};


int main(){
	vector<int> v = {1};
	ListNode* head = createList(v);
	printList(head);
	ListNode* rev =  Solution().rotateRight(head,1);
	printList(rev);
	deleteList(rev);
}
