#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H//һ�����ļ����Ĵ�д
template <typename Type> class Node{

public:
	/* Node �ڵ��������������Ա �� ���ݳ�Ա �� next ָ���Ա*/
	Type data;
	Node<Type> *next;
	Node(const Type& _data){
		this->data = _data;
		this->next = NULL;
	}
};

template<typename Type> class LinkedList{

private:
	Node<Type> *head;

public:
	LinkedList(){
		head = NULL;
	}

	~LinkedList(){
		Node<Type> *current_Node = head;
		while (current_Node != NULL){
			Node<Type> *delete_Node = current_Node;
			current_Node = current_Node->next;
			delete delete_Node;
		}

	}

	/* func : ����Ԫ�ز��� */
	void insert(Node<Type> * data, int index){
		/*case:1  ����ͷΪ�� �� ��Ϊ������ �� �������ֻ�в��� Index = 0 ��Ϊ��Ч�Ϸ�����*/
		if (this->head == NULL){
			if (index != 0)
			{
				std::cout << "�����λ�ò��Ϸ�" << std::endl;
				return;
			}
			this->head = data;
			return;
		}
		if (index == 0){
			data->next = head;
			head = data;
			return;
		}
		Node<Type> *current_Node = head;
		int count = 0;

		/* ѭ����� ������һ���ڵ� */
		while (current_Node->next != NULL && count < index - 1)
		{
			current_Node = current_Node->next;
			count++;
		}
		if (current_Node->next != NULL && count == index - 1){

			Node<Type> *tmpNode = current_Node->next;
			current_Node->next = data;
			data->next = tmpNode;
		}
		std::cout << "��������������λ�ò��Ϸ�" << std::endl;
		return;
	}

	/* ���������ȫ�����ݣ�Ȼ����� */
	void output(){
		if (head == NULL){
			std::cout << "����Ϊ��" << std::endl;
			return;
		}
		Node<Type> *current_node = head;
		while (current_node != NULL){
			std::cout << current_node->data << std::endl;
			current_node = current_node->next;
		}
	}

	/* ɾ��������� */
	void deleteNode(int index){
		if (head == NULL){
			std::cout << "�����Ѿ�Ϊ��" << std::endl;
			return;
		}
		Node<Type> *current_node = head;
		int count = 0;
		if (index == 0){
			head = current_node->next;
			delete current_node;
			return;
		}
		while (current_node->next != NULL && count < index - 1){
			current_node = current_node->next;
			count = count + 1;
		}
		//std::cout << "count = " << count << std::endl;

		if (current_node->next != NULL && count == index - 1){
			Node<Type> *delete_node = current_node->next;
			current_node->next = delete_node->next;
			delete delete_node;
			return;
		}
		std::cout << "index ���������ȣ��޷�ɾ��" << std::endl;
	}

	void reverse(){
		if (head == NULL){
			std::cout << "�����Ѿ�Ϊ��" << std::endl;
			return;
		}
		Node<Type> *current_node, *next_node;

		//-----------------
		current_node = head->next;
		head->next = NULL;

		while (current_node != NULL){
			next_node = current_node->next;
			current_node->next = head;
			head = current_node;

			//-----------------
			//head ->next =  NULL; ��仰д���ˣ����ܽ��м���̵Ļ�ͷ next ��Ա�ÿգ������Ļ�ȫ�𳵶��Ƕ��ѵ�
			current_node = next_node;
		}
		return;
	}

};
#endif