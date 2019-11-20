//
// Created by Zfans on 2019/11/18.
//

#ifndef HASHTABLE_CLOSEDHASHTABLE_H
#define HASHTABLE_CLOSEDHASHTABLE_H

#include <vector>

const int DefaultSize = 1024;

enum KindOfStatus {  //Ԫ�ط��ࣨ�/��/ɾ��
    Active,
    Empty,
    Deleted
};

template<class T>
struct element {
    unsigned long long key;
    T value;
};

template<class T>
class ClosedHashTable {
public:
    explicit ClosedHashTable(int divisor, int capacity = DefaultSize);//���캯��

    ~ClosedHashTable() {   //��������
        delete[]hashTable;
        delete[]status;
    }

    ClosedHashTable<T> &operator=(const ClosedHashTable<T> &otherHashTable);

    bool Search(unsigned long long key, T &value);//��ɢ�б�������key,������� ͨ��value����
    bool Insert(unsigned long long key, const T &value); //��ɢ�б��в���value
    bool Remove(unsigned long long key);//��ɢ�б���ɾ���ؼ���Ϊkey��Ԫ��
    void makeEmpty();  //��ɢ�б�Ϊ��
    [[nodiscard]] const std::vector<int> &getAsl() const;

private:
    int divisor;//ɢ�к����ĳ���
    int currentSize, capacity;//��ǰԪ�ظ��� ����
    int detectionTimes;  //̽�����
    int LinearDetectionTimes;//����̽�����
    element<T> *hashTable;   //ɢ�б�洢����
    KindOfStatus *status; //״̬����
    [[nodiscard]] int FindPos(unsigned long long key);//ɢ�к����������ʼͰ��
    std::vector<int> ASL;

};

template<class T>
ClosedHashTable<T>::ClosedHashTable(const int divisor, int capacity) {//���캯��
    this->divisor = divisor;
    this->capacity = capacity;
    detectionTimes = 0;
    LinearDetectionTimes = 0;
    if (this->divisor > capacity)
        this->divisor = capacity;
    currentSize = 0;
    hashTable = new element<T>[capacity];
    status = new KindOfStatus[capacity];
    for (int i = 0; i < capacity; ++i) {
        status[i] = Empty;
    }
}

template<class T>
int ClosedHashTable<T>::FindPos(const unsigned long long key) {
    //������һ��ɢ�б��йؼ�����keyƥ���Ԫ�أ������ɹ����������ظ�Ԫ�ص�λ�ã�
    //���򷵻ز���㣨������㹻�Ŀռ䣩
    detectionTimes++;
    int InitBucketNum = key % divisor;       //�����ʼͰ��
    int LineProbePoint = InitBucketNum;     //����̽��ָ��
    int currentLinearDetectionTimes = 0;  //̽�����
    do {
        currentLinearDetectionTimes++;
        if (status[LineProbePoint] == Empty ||
            (status[LineProbePoint] == Active && hashTable[LineProbePoint].key == key)) {//�ҵ�
            LinearDetectionTimes += currentLinearDetectionTimes;
            ASL.push_back(LinearDetectionTimes / detectionTimes);
            return LineProbePoint;
        }
        LineProbePoint = (LineProbePoint + 1) % capacity;//����ѭ����������һ����Ͱ
    } while (LineProbePoint != InitBucketNum);  //תһȦ�ص���ʼ�㣬��������ʧ��
    LinearDetectionTimes += currentLinearDetectionTimes;
    ASL.push_back(LinearDetectionTimes / detectionTimes);
    return LineProbePoint;
}

template<class T>
bool ClosedHashTable<T>::Search(const unsigned long long key, T &value) {
    //ʹ������̽�鷨��ɢ�б�ÿ��Ͱ����һ��Ԫ�أ�������key�����key�ڱ��д��ڣ�
    //��������true������Ӧ�ò���value�����ҵ���Ԫ�أ����key���ڱ��У��򷵻�false��
    int pos = FindPos(key); //����
    if (status[pos] != Active || hashTable[pos].key != key)
        return false;
    value = hashTable[pos].value;
    return true;
}

template<class T>
void ClosedHashTable<T>::makeEmpty() {  //���ɢ�б�
    for (int i = 0; i < capacity; ++i) {
        status[i] = Empty;
    }
    currentSize = 0;
}

template<class T>
ClosedHashTable<T> &ClosedHashTable<T>::operator=(const ClosedHashTable<T> &otherHashTable) {
    //���غ���������һ��ɢ�б�ht2
    if (this != &otherHashTable) {           //��ֹ���Ҹ���
        delete[] hashTable;
        delete[] status;
        capacity = otherHashTable.capacity;
        detectionTimes = otherHashTable.detectionTimes;
        LinearDetectionTimes = otherHashTable.LinearDetectionTimes;
        hashTable = new element<T>[capacity];
        status = new KindOfStatus[capacity];
        for (int i = 0; i < capacity; ++i) {   //��Դɢ�б���Ŀ��ɢ�б���
            hashTable[i] = otherHashTable.hashTable[i];
            status[i] = otherHashTable.status[i];
        }
        currentSize = otherHashTable.currentSize;   //���͵�ǰԪ�ظ���
    }
    return *this;   //����Ŀ��ɢ�б�ṹָ��
}

template<class T>
bool ClosedHashTable<T>::Insert(const unsigned long long key, const T &value) {
    //��HashTable��������value�����ҵ����ٲ��룬��δ�ҵ����������������ٲ��룬����false��
    //���ҵ�λ�õı�ָ��Empty��Deleted�����۱��Ƿ�������value���룬����true��
    int pos = FindPos(key);//��ɢ�к�������Ͱ��
    if (status[pos] != Active) {  //��Ͱ�գ������Ԫ��
        hashTable[pos].key = key;
        hashTable[pos].value = value;
        status[pos] = Active;
        currentSize++;
        return true;
    }
    if (status[pos] == Active && hashTable[pos].value == value) {
        std::cout << "�������д�Ԫ�أ������ظ����룡" << std::endl;
        return false;
    }
    std::cout << "�����������ܲ��룡" << std::endl;
    return false;
}

template<class T>
bool ClosedHashTable<T>::Remove(const unsigned long long key) {
    //��ht����ɾ��Ԫ��key���������Ҳ���k1������Ȼ�ҵ�k1�������Ѿ��߼�ɾ����
    //�򷵻�false�������ڱ���ɾ��Ԫ��k1������true���������ò���e1�еõ���
    int pos = FindPos(key);
    if (status[pos] == Active && hashTable[pos].key == key) {   //�ҵ�ҪɾԪ�أ����ǻԪ��
        status[pos] = Deleted;            //���߼�ɾ����־��������������ɾ��
        currentSize--;                 //ɾ��������ɣ����سɹ���־
        return true;
    } else
        return false;            //�����ޱ�ɾԪ�أ����ز��ɹ���־
}

template<class T>
const std::vector<int> &ClosedHashTable<T>::getAsl() const {
    return ASL;
}


#endif //HASHTABLE_CLOSEDHASHTABLE_H
