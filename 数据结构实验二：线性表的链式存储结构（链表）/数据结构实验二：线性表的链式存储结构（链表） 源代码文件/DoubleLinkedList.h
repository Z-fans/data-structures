//
// Created by Zfans on 2019/09/14.
//

#ifndef DOUBLELINKEDLISTBYCPP_DOUBLELINKEDLIST_H
#define DOUBLELINKEDLISTBYCPP_DOUBLELINKEDLIST_H

#include <iostream>
#include <fstream>

using namespace std;

//���ṹ��
template<class T>
struct Node {
    bool survival = true;
    T data;
    Node *prev = NULL;
    Node *next = NULL;

    Node() {}

    Node(T &data, bool &survival) : data(data), survival(survival) {};

    Node(T &data, Node *prev, Node *next) : data(data), prev(prev), next(next) {};
};

//˫������
template<class T>
class DoubleLinkedList {

private:

    Node<T> *pHead;      //��ͷ
    int length;        //  �ɼ�����
    int realLength;        //ʵ�ʳ���

    Node<T> *get_node(int index);

    bool push_back(Node<T> *x);    //ѹ����

public:

    DoubleLinkedList();   //���캯��

    DoubleLinkedList(DoubleLinkedList<T> &DLL);  //�������캯��

    ~DoubleLinkedList();  //��������

    int Length() const;//��ȡ�ɼ�����

    bool IsEmpty() const;    //�п�

    void DisplayData();    //չʾ�ɼ�����

    int LocateTheOrdinalNumberOfTheSpecifiedElement(T &x) const;   //��ȡָ��Ԫ��λ��

    bool InsertFirst(T &x);//�����һλ

    bool push_back(T &x);    //ѹ������

    bool InsertBeforeTheSpecifiedElement(T &se, T &x);   //��ָ��Ԫ��֮ǰ����

    bool InsertAfterTheSpecifiedElement(T &se, T &x);//��ָ��Ԫ��֮�����

    bool InsertAtTheSpecifiedLocation(int index, T &x);//��ָ��λ�ò���

    bool LogicalDeleteTheSpecifiedElement(T &x);   //�߼�ɾ��ָ��Ԫ��

    bool LogicalDeleteElementAtSpecifiedLocation(int index);   //�߼�ɾ��ָ��λ��Ԫ��

    bool LogicalRecoveryOfSpecifiedElement(T &x);    //�߼��ָ�ָ��Ԫ��

    bool PhysicalDeleteTheSpecifiedElement(T &x);   //����ɾ��ָ��Ԫ��

    bool PhysicalDeleteElementAtSpecifiedLocation(int index);   //����ɾ��ָ��λ��Ԫ��

    void DisplayLogicallyDeletedData();   //չʾ�߼�ɾ��������

    bool QuerySpecifiedElement(T &x) const;    //��ѯָ��Ԫ��

    bool ModifyDataForSpecifiedElement(T &se, T &x) const;   //�޸�ָ��Ԫ��

    bool ReadDataFromAFile(const string &fileName);    //���ļ��ж�ȡ����

    bool WriteDataToFile(const string &fileName) const;   //д���ݵ��ļ���

    bool getDataByIndex(int index, T &x);   //��ȡָ��λ��Ԫ��

    DoubleLinkedList<T> operator=(DoubleLinkedList<T> &L);     //����=������

    bool toLogicalEmpty();     //�߼����

    bool toPhysicalEmpty();    //�������

    bool Sort() const;   //�Ż�ð������
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
// ��������ͷ������ͷû�д洢����
    pHead = new Node<T>();

    if (pHead == NULL) {
        cerr << "�洢�������" << endl;
        exit(1);
    }

    pHead->prev = pHead->next = pHead;
    length = 0;
    realLength = 0;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
// ɾ�����еĽڵ�

    Node<T> *pTemp;
    Node<T> *pNode = pHead->next;
    while (pNode != pHead) {
        pTemp = pNode;
        pNode = pNode->next;
        delete pTemp;
    }
    // ɾ��"��ͷ"

    delete pHead;
    pHead = NULL;
}

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList<T> &DLL) {
    if (DLL.pHead == NULL || DLL.pHead == DLL.pHead->next) {
        DoubleLinkedList();
        return;
    }

    length = DLL.length;
    realLength = DLL.realLength;

    Node<T> *srcptr = DLL.pHead;
    Node<T> *destptr = pHead = new Node<T>;

    while (DLL.pHead != srcptr->next) {
        srcptr = srcptr->next;
        destptr->next = new Node<T>(srcptr->data, srcptr->survival);
        destptr->next->prev = destptr;
        destptr = destptr->next;
    }
    pHead->prev = destptr;
    destptr->next = pHead;
}

template<class T>
Node<T> *DoubleLinkedList<T>::get_node(int index) {
    // �жϲ�����Ч��
    if (index <= 0 || index > realLength) {
        cout << "get node failed! the index in out of bound!" << endl;
        return NULL;
    }

    // �������
    if (index <= realLength / 2) {
        int i = 1;
        Node<T> *pIndex = this->pHead->next;
        while (i++ < index) {
            pIndex = pIndex->next;
        }
        return pIndex;
    }

    // �������
    int j = 1;
    int rIndex = realLength - index + 1;
    Node<T> *prIndex = pHead->prev;
    while (j++ < rIndex) {
        prIndex = prIndex->prev;
    }
    return prIndex;
}

template<class T>
int DoubleLinkedList<T>::Length() const {
    return length;
}

template<class T>
bool DoubleLinkedList<T>::IsEmpty() const {
    return !length;
}

template<class T>
bool DoubleLinkedList<T>::push_back(T &x) {
    Node<T> *pNode = new Node<T>(x, pHead->prev, pHead);
    if (pNode == NULL) {
        cerr << "�洢�������" << endl;
        exit(1);
    }
    pHead->prev->next = pNode;
    pHead->prev = pNode;
    realLength++;
    length++;

    return true;
}

template<class T>
void DoubleLinkedList<T>::DisplayData() {
    Node<T> *p = pHead->next;
    while (p != pHead) {
        if (p->survival) {
            cout << p->data << " ";
        }
        p = p->next;
    }
}

template<class T>
bool DoubleLinkedList<T>::InsertBeforeTheSpecifiedElement(T &se, T &x) {
    int index = 0, flag = 0;

    Node<T> *p = pHead->next;
    while (p != pHead) {
        index++;
        if (p->data == se && p->survival) {
            flag = 1;
            break;
        }
        p = p->next;
    }

    if (flag == 0)
        return false;

    if (index == 1)
        return InsertFirst(x);

    Node<T> *pIndex = get_node(index);
    Node<T> *pNode = new Node<T>(x, pIndex->prev, pIndex);
    if (pNode == NULL) {
        cerr << "�洢�������" << endl;
        exit(1);
    }
    pIndex->prev->next = pNode;
    pIndex->prev = pNode;
    length++;
    realLength++;

    return true;
}

template<class T>
int DoubleLinkedList<T>::LocateTheOrdinalNumberOfTheSpecifiedElement(T &x) const {
    int index = 0;
    Node<T> *p = pHead->next;
    while (p != pHead) {
        if (p->survival) {
            index++;
            if (p->data == x) {
                return index;
            }
        }
        p = p->next;
    }
    return index;
}

template<class T>
bool DoubleLinkedList<T>::InsertFirst(T &x) {
    Node<T> *pNode = new Node<T>(x, pHead, pHead->next);
    if (pNode == NULL) {
        cerr << "�洢�������" << endl;
        exit(1);
    }
    pHead->next->prev = pNode;
    pHead->next = pNode;
    length++;
    realLength++;

    return true;
}

template<class T>
bool DoubleLinkedList<T>::InsertAfterTheSpecifiedElement(T &se, T &x) {
    int index = 0, flag = 0;

    Node<T> *p = pHead->next;
    while (p != pHead) {
        index++;
        if (p->data == se && p->survival) {
            flag = 1;
            break;
        }
        p = p->next;
    }

    if (flag == 0)
        return false;

    if (index == realLength)
        return push_back(x);

    Node<T> *pIndex = get_node(index);
    Node<T> *pNode = new Node<T>(x, pIndex, pIndex->next);
    if (pNode == NULL) {
        cerr << "�洢�������" << endl;
        exit(1);
    }
    pIndex->next->prev = pNode;
    pIndex->next = pNode;
    length++;
    realLength++;

    return true;
}

template<class T>
bool DoubleLinkedList<T>::InsertAtTheSpecifiedLocation(int index, T &x) {
    if (index <= 0 || index > length)
        return false;

    if (index == 1)
        return InsertFirst(x);

    if (index == length)
        return push_back(x);

    int realIndex = 0;

    Node<T> *p = pHead->next;
    while (p != pHead) {
        realIndex++;
        if (p->survival) {
            index--;
        }
        if (index == 0)
            break;
        p = p->next;
    }
    InsertBeforeTheSpecifiedElement(get_node(realIndex)->data, x);

    return true;
}

template<class T>
bool DoubleLinkedList<T>::LogicalDeleteTheSpecifiedElement(T &x) {
    Node<T> *p = pHead->next;
    while (p != pHead) {
        if (p->data == x && p->survival) {
            p->survival = false;
            length--;
            return true;
        }
        p = p->next;
    }
    return false;
}

template<class T>
bool DoubleLinkedList<T>::LogicalDeleteElementAtSpecifiedLocation(int index) {
    if (index <= 0 || index > length)
        return false;

    int realIndex = 0;

    Node<T> *p = pHead->next;
    while (p != pHead) {
        realIndex++;
        if (p->survival) {
            index--;
        }
        if (index == 0)
            break;
        p = p->next;
    }

    Node<T> *realIndexNode = get_node(realIndex);

    if (realIndexNode->survival) {
        realIndexNode->survival = false;
        length--;
        return true;
    }
    return false;
}

template<class T>
bool DoubleLinkedList<T>::LogicalRecoveryOfSpecifiedElement(T &x) {
    Node<T> *p = pHead->next;
    while (p != pHead) {
        if (p->data == x && !p->survival) {
            p->survival = true;
            length++;
            return true;
        }
        p = p->next;
    }
    return false;
}

template<class T>
bool DoubleLinkedList<T>::PhysicalDeleteTheSpecifiedElement(T &x) {
    Node<T> *p = pHead->next;
    while (p != pHead) {
        if (p->data == x && p->survival) {
            p->next->prev = p->prev;
            p->prev->next = p->next;
            delete p;
            length--;
            realLength--;
            return true;
        }
        p = p->next;
    }
    return false;
}

template<class T>
bool DoubleLinkedList<T>::PhysicalDeleteElementAtSpecifiedLocation(int index) {
    if (index <= 0 || index > length)
        return false;

    int realIndex = 0;

    Node<T> *p = pHead->next;
    while (p != pHead) {
        realIndex++;
        if (p->survival) {
            index--;
        }
        if (index == 0)
            break;
        p = p->next;
    }

    Node<T> *realIndexNode = get_node(realIndex);

    if (realIndexNode->survival) {
        realIndexNode->next->prev = realIndexNode->prev;
        realIndexNode->prev->next = realIndexNode->next;
        delete realIndexNode;
        length--;
        realLength--;
        return true;
    }
    return false;
}

template<class T>
void DoubleLinkedList<T>::DisplayLogicallyDeletedData() {
    Node<T> *p = pHead->next;
    while (p != pHead) {
        if (!p->survival) {
            cout << p->data << " ";
        }
        p = p->next;
    }
}

template<class T>
bool DoubleLinkedList<T>::QuerySpecifiedElement(T &x) const {
    Node<T> *p = pHead->next;
    while (p != pHead) {
        if (p->data == x && p->survival)
            return true;
        p = p->next;
    }
    return false;
}

template<class T>
bool DoubleLinkedList<T>::ModifyDataForSpecifiedElement(T &se, T &x) const {
    Node<T> *p = pHead->next;
    while (p != pHead) {
        if (p->data == se && p->survival) {
            p->data = x;
            return true;
        }
        p = p->next;
    }
    return false;
}

template<class T>
bool DoubleLinkedList<T>::ReadDataFromAFile(const string &fileName) {
    if (fileName.size() == 0) {
        cout << "File name is empty!";
        return false;
    }
    ifstream in(fileName);
    if (!in.is_open()) {
        cout << "Failed to open the file!";
        return false;
    }
    while (!in.eof()) {
        T t;
        Node<T> *temp = new Node<T>(t, pHead->prev, pHead);
        in >> temp->data >> temp->survival;
        push_back(temp);
    }
    PhysicalDeleteElementAtSpecifiedLocation(length);
    in.close();
    return true;
}

template<class T>
bool DoubleLinkedList<T>::push_back(Node<T> *x) {
    pHead->prev->next = x;
    pHead->prev = x;
    if (x->survival) {
        realLength++;
        length++;
    } else
        realLength++;
    return true;
}

template<class T>
bool DoubleLinkedList<T>::WriteDataToFile(const string &fileName) const {
    if (fileName.size() == 0) {
        cout << "File name is empty!";
        return false;
    }

    ofstream out(fileName);

    if (!out.is_open()) {
        cout << "Failed to open the file!";
        return false;
    }

    Node<T> *p = pHead->next;
    while (p != pHead) {
        out << p->data << " " << p->survival << endl;
        p = p->next;
    }
    out.close();
    return true;
}

template<class T>
bool DoubleLinkedList<T>::getDataByIndex(int index, T &x) {
    if (index <= 0 || index > length)
        return false;

    int realIndex = 0;

    Node<T> *p = pHead->next;
    while (p != pHead) {
        realIndex++;
        if (p->survival) {
            index--;
        }
        if (index == 0)
            break;
        p = p->next;
    }

    Node<T> *realIndexNode = get_node(realIndex);

    if (realIndexNode->survival) {
        x = realIndexNode->data;
        return true;
    }
    return false;
}

template<class T>
DoubleLinkedList<T> DoubleLinkedList<T>::operator=(DoubleLinkedList<T> &L) {
    DoubleLinkedList(L);
}

template<class T>
bool DoubleLinkedList<T>::toLogicalEmpty() {
    Node<T> *p = pHead->next;
    while (p != pHead) {
        if (p->survival) {
            p->survival = false;
            length--;
        }
        p = p->next;
    }
    return true;
}

template<class T>
bool DoubleLinkedList<T>::toPhysicalEmpty() {
    Node<T> *p = pHead->next;
    while (p != pHead) {
        Node<T> *del = p;
        p = p->next;
        delete del;
    }
    pHead->next = pHead->prev = pHead;
    length = 0;
    realLength = 0;
    return true;
}

template<class T>
bool DoubleLinkedList<T>::Sort() const {
    Node<T> *p01 = pHead->next;
    bool flag;
    while (p01 != pHead) {
        flag = false;
        Node<T> *p02 = pHead->prev;
        while (p02 != pHead) {
            if (p02->data < p02->prev->data) {
                p02->prev->prev->next = p02->prev->next;
                p02->next->prev = p02->prev;
                p02->prev->next = p02->next;
                p02->next = p02->prev;
                p02->prev = p02->prev->prev;
                p02->next->prev = p02->prev->next;
                flag = true;
            }
            p02 = p02->prev;
        }
        if (!flag) break;
        p01 = p01->next;
    }
    return true;
}

#endif //DOUBLELINKEDLISTBYCPP_DOUBLELINKEDLIST_H
