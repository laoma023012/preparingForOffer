#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H//一般是文件名的大写
template <typename Type> class Node{

public:
	/* Node 节点里面包含两个成员 ， 数据成员 和 next 指针成员*/
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

	/* func : 链表元素插入 */
	void insert(Node<Type> * data, int index){
		/*case:1  链表头为空 ， 即为空链表 ， 该情况下只有插入 Index = 0 才为有效合法情形*/
		if (this->head == NULL){
			if (index != 0)
			{
				std::cout << "插入的位置不合法" << std::endl;
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

		/* 循环检查 遍历下一个节点 */
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
		std::cout << "超出索引，插入位置不合法" << std::endl;
		return;
	}

	/* 遍历链表的全部内容，然后输出 */
	void output(){
		if (head == NULL){
			std::cout << "链表为空" << std::endl;
			return;
		}
		Node<Type> *current_node = head;
		while (current_node != NULL){
			std::cout << current_node->data << std::endl;
			current_node = current_node->next;
		}
	}

	/* 删除链表操作 */
	void deleteNode(int index){
		if (head == NULL){
			std::cout << "链表已经为空" << std::endl;
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
		std::cout << "index 超出链表长度，无法删除" << std::endl;
	}

	void reverse(){
		if (head == NULL){
			std::cout << "链表已经为空" << std::endl;
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
			//head ->next =  NULL; 这句话写错了，不能将中间过程的火车头 next 成员置空，这样的话全火车都是断裂的
			current_node = next_node;
		}
		return;
	}

};
#endif