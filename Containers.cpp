#include "Containers.h"
#include <iostream>

using namespace std;

Containers::Containers()
{

}

Containers::~Containers()
{
	DeleteMyForwardList();
}

void Containers::CreateMyForwardList()
{
	MyForwardList* tmpPointerToList = new MyForwardList;
	tmpPointerToList->value = 0;
	beginMyForwardList = tmpPointerToList;

	for (size_t i = 1; i < sizeOfMyForwardList; i++)
	{
		MyForwardList* pointerToList = new MyForwardList;
		pointerToList->value = (int)i;

		tmpPointerToList->next = pointerToList;
		tmpPointerToList = pointerToList;
	}
	tmpPointerToList->next = nullptr;
}

void Containers::CreateMyForwardListSharedPtr()
{
	auto tmpPointerList = make_shared<MyForwardListSharedPtr>();
	tmpPointerList->value = 0;
	beginMyForwardListSharedPtr = tmpPointerList;
	for (size_t i = 1; i < sizeOfMyForwardList; i++)
	{
		auto pointerToList = make_shared<MyForwardListSharedPtr>();
		pointerToList->value = (int)i;

		tmpPointerList->next = pointerToList;
		tmpPointerList = pointerToList;
	}
	tmpPointerList->next = nullptr;
}

void Containers::DeleteMyForwardList()
{
	size_t count = 0;
	while (beginMyForwardList)
	{
		MyForwardList* tmpPointer = beginMyForwardList->next;
		delete beginMyForwardList;
		beginMyForwardList = tmpPointer;
		count++;
	}
	if (count)
	{
		cout << endl << "Delete " << count << " nodes in ~ListAlgorithms()" << endl;
	}
}

Containers::MyForwardList* Containers::GetBeginMyForwardList()
{
	CreateMyForwardList();
	return beginMyForwardList;
}

std::shared_ptr<Containers::MyForwardListSharedPtr> Containers::GetBeginMyForwardListSharedPtr()
{
	CreateMyForwardListSharedPtr();
	return beginMyForwardListSharedPtr;
}

void Containers::PrintContainer(shared_ptr<MyForwardListSharedPtr> beginMyForwardListSharedPtr) const
{
	if (!beginMyForwardListSharedPtr)
	{
		cout << endl << "Container is empty." << endl;
		return;
	}
	cout << endl;
	auto beginMyForwardListTmp = beginMyForwardListSharedPtr;
	while (beginMyForwardListTmp)
	{
		cout << beginMyForwardListTmp->value << " ";
		beginMyForwardListTmp = beginMyForwardListTmp->next;
	}
	cout << endl;
}

