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
   ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre=new ListNode(0);
        pre->next=head;
        head=pre;
        ListNode *L,*R;
        while(pre->next != NULL)
        {
            L=pre->next;
            R=pre->next;
            while(R->next && R->next->val==L->val)
                R=R->next;
            //如果循环后，L与R节点相同，说明不重复
            if(L == R) pre=pre->next;
            //L与R节点不相同，将pre的next指向R->next,继续重复上述操作
            else {
                pre->next=R->next;
                //C++没有内存回收机制，应该释放这些指针，虽然不释放能通过，但是应该养成好习惯
                L = R;
            }
        }
        return head->next;
    }
};


int main(){
	vector<int> v = {1,2,3,4,4,4,5};
	ListNode* head = createList(v);
	printList(head);
	ListNode* rev =  Solution().deleteDuplicates(head);
	printList(rev);
	deleteList(rev);
}
