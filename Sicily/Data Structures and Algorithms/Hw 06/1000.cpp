void List::insert(int toadd, int pos)
{
	ListNode* curNode = this->head;
	int curPos = 0;
	while (curPos < pos - 1)
	{
		curNode = curNode->next;
		curPos++;
	}
	ListNode* nextNode = curNode->next;
	curNode->next = new ListNode;
	curNode->next->data = toadd;
	curNode->next->next = nextNode;
}

