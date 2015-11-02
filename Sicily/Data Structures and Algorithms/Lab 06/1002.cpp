bool check(node* head)
{
	node* fast = head;
	node* slow = head;
	while(fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
			fast = fast->next;
		else
			return false;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}