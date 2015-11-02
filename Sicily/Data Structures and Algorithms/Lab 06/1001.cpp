void delete_duplicate(LinkList& head)
{
	if (head == NULL) return;
    LinkList curNode = head->next;
    LinkList preNode = head;
	while (curNode != NULL)
	{
		if (curNode->data == preNode->data)
		{
			//	delete current Node
			preNode->next = curNode->next;
			delete curNode;
			curNode = preNode->next;
		}
		else
		{
			//	goto next node
			preNode = preNode->next;
			curNode = curNode->next;
		}
	}
}