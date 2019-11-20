//
// Created by Zfans on 2019/11/19.
//

#ifndef HASHTABLE_OPENHASHTABLE_H
#define HASHTABLE_OPENHASHTABLE_H

#include <cassert>
#include <iostream>

template<class T>
struct ChainNode {   //��Ͱ��ͬ����ӱ������㶨��
    unsigned long long key{};
    T value;             //Ԫ��
    ChainNode<T> *link;     //��ָ��

    explicit ChainNode(ChainNode<T> *link) : link(link) {}

    ChainNode(unsigned long long int key, T value, ChainNode<T> *link) :
            key(key), value(value), link(link) {}
};

template<class T>
class OpenHashTable {   //ɢ�б���ͷָ������������
public:
    explicit OpenHashTable(int divisor, int bucketSize = DefaultSize);//ɢ�б�Ĺ��캯��
    ~OpenHashTable() {   //��������
        delete[]hashTable;
    }

    bool Search(unsigned long long key, T &value);//��ɢ�б�������k1
    bool Insert(unsigned long long key, const T &value); //��ɢ�б��в���value
    bool Remove(unsigned long long key);//��ɢ�б���ɾ���ؼ���Ϊkey��Ԫ��
    [[nodiscard]] const std::vector<int> &getAsl() const;

private:
    int divisor{};//������������������
    int bucketSize{}; //Ͱ�ĸ���
    int elementSize;//Ԫ�ظ���
    int detectionTimes;  //̽�����
    int LinearDetectionTimes;//����̽�����
    ChainNode<T> **hashTable; //ɢ�б���
    ChainNode<T> *FindPos(unsigned long long key);//ɢ��
    std::vector<int> ASL;

};

template<class T>
OpenHashTable<T>::OpenHashTable(int divisor, int bucketSize) {//���캯��
    this->divisor = divisor;
    this->bucketSize = bucketSize;
    if (this->divisor > this->bucketSize)
        this->divisor = this->bucketSize;
    detectionTimes = 0;
    LinearDetectionTimes = 0;
    elementSize = 0;
    hashTable = new ChainNode<T> *[bucketSize];//����ͷ���
    for (int i = 0; i < bucketSize; ++i) {
        hashTable[i] = new ChainNode<T>(nullptr);
    }
    assert(hashTable != nullptr);  //���ԣ��жϴ洢����ɹ���
}

template<class T>
ChainNode<T> *OpenHashTable<T>::FindPos(const unsigned long long key) {
    //��ɢ�б�hashTable�������ؼ���Ϊkey��Ԫ�ء���������һ��ָ��ɢ�б���ĳλ�õ�ָ�룻
    //��Ԫ�ز����ڣ��򷵻�nullptr��
    detectionTimes++;
    int j = key % divisor;        //����ɢ�е�ַ
    ChainNode<T> *p = hashTable[j]->link;           //ɨ���j����ͬ����ӱ�
    int currentLinearDetectionTimes = 0;  //̽�����
    currentLinearDetectionTimes++;
    while (p != nullptr && p->key != key) {
        currentLinearDetectionTimes++;
        p = p->link;
    }
    LinearDetectionTimes += currentLinearDetectionTimes;
    ASL.push_back(LinearDetectionTimes / detectionTimes);
    return p;   //����
}

template<class T>
bool OpenHashTable<T>::Insert(const unsigned long long key, const T &value) {
    ChainNode<T> *p = FindPos(key);
    if (p == nullptr) {
        auto *newOne = new ChainNode<T>(key, value, p);
        int j = key % divisor;        //����ɢ�е�ַ
        ChainNode<T> *t = hashTable[j];
        while (t->link != nullptr) {
            t = t->link;
        }
        t->link = newOne;
        elementSize++;
        return true;
    } else if (p->value == value) {
        std::cout << "�������д�Ԫ�أ������ظ����룡" << std::endl;
        return false;
    }
}

template<class T>
bool OpenHashTable<T>::Search(const unsigned long long key, T &value) {
    ChainNode<T> *p = FindPos(key);
    if (p == nullptr)
        return false;
    value = p->value;
    return true;
}

template<class T>
bool OpenHashTable<T>::Remove(const unsigned long long key) {
    ChainNode<T> *p = FindPos(key);
    if (p == nullptr) {
        return false;
    }
    int j = key % divisor;        //����ɢ�е�ַ
    ChainNode<T> *t = hashTable[j];
    while (t->link != p) {
        t = t->link;
    }
    t->link = p->link;
    delete p;
    elementSize--;
    return true;
}

template<class T>
const std::vector<int> &OpenHashTable<T>::getAsl() const {
    return ASL;
}


#endif //HASHTABLE_OPENHASHTABLE_H
