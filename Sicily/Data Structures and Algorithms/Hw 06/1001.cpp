void List::remove(int pos)
{
	ListNode* curNode = this->head;
	int curPos = 0;
	while (curPos < pos - 1)
	{
		curNode = curNode->next;
		curPos++;
	}
	ListNode* delNode = curNode->next;
	curNode->next = curNode->next->next;
	delete delNode;
}

