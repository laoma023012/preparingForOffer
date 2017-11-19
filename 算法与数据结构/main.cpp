#include <iostream>
#include "LinkedList.h"


int main(){
	LinkedList<int> linkedlist;
	for (int i = 0; i < 11; i++){
		std::cout << " i = " << i << std::endl;
		Node<int> *node = new Node<int>(i);
		linkedlist.insert(node, 0);
	}
	Node<int> *node = new Node<int>(15);
	linkedlist.insert(node, 7);
	linkedlist.output();

	std::cout << "����������" << std::endl;

	linkedlist.reverse();
	linkedlist.output();

	std::cout << "��ת�������" << std::endl;
	
	linkedlist.deleteNode(1);
	linkedlist.output();
	
	std::cout << "ɾ���ڵ�������" << std::endl;

	system("pause");
	return 0;
}