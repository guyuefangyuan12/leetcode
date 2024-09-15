struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeNodes(ListNode* head)
	{
		ListNode* ans = new ListNode();
		ListNode* temp = ans;
		int sum = 0;
		for (ListNode* cur = head->next; cur != nullptr; cur = cur->next)
		{
			if (cur->val == 0)
			{
				ListNode* node = new ListNode(sum);
				temp->next = node;
				temp = temp->next;
				sum = 0;
			}
			else
			{
				sum += cur->val;
			}
		}
		return ans->next;
	}
};