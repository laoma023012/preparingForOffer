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

	std::cout << "插入测试完成" << std::endl;

	linkedlist.reverse();
	linkedlist.output();

	std::cout << "翻转测试完成" << std::endl;
	
	linkedlist.deleteNode(1);
	linkedlist.output();
	
	std::cout << "删除节点测试完成" << std::endl;

	system("pause");
	return 0;
}