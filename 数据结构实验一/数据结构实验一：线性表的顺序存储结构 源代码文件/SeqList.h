//
// Created by Zfans on 2019/09/09.
//

#ifndef SEQLISTBYCPP_SEQLIST_H
#define SEQLISTBYCPP_SEQLIST_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int defaultSize = 64;

template<class T>
struct Node {               //һ�����ݽ�����һ�� ���ڱ�־ ��һ�� ������
    bool survival = true;
    T data;
};

template<class T>
class SeqList {
protected:
    Node<T> *data;      //��������
    int maxSize;             //��ǰ����
    int length;        //  �ɼ�����
    int realLength;        //ʵ�ʳ���

    bool ExpansionCapacity();     //��չ����

    Node<T> getNodeByIndex(int &index);    //ͨ���±��ȡ���

    bool push_back(Node<T> &x);     //ѹ����

    int RealLocateTheOrdinalNumberOfTheSpecifiedElement(T &x) const;   //��ȡָ��Ԫ��λ��

public:

    explicit SeqList(int &size = const_cast<int &>(defaultSize));    //���캯��

    SeqList(SeqList<T> &L);            //�������캯��

    ~SeqList();    //��������

    int Length() const;            //��ȡ�ɼ�����

    bool IsEmpty() const;    //�п�

    bool toLogicalEmpty();     //�߼����

    bool toPhysicalEmpty();    //�������

    SeqList<T> operator=(SeqList<T> &L);     //����=������

    bool push_back(T &x);    //ѹ������

    bool InsertBeforeTheSpecifiedElement(T &se, T &x);   //��ָ��Ԫ��֮ǰ����

    bool InsertAfterTheSpecifiedElement(T &se, T &x);//��ָ��Ԫ��֮�����

    bool InsertAtTheSpecifiedLocation(int &index, T &x);    //��ָ��λ�ò���

    bool LogicalDeleteTheSpecifiedElement(T &x);   //�߼�ɾ��ָ��Ԫ��

    bool LogicalDeleteElementAtSpecifiedLocation(int &index);   //�߼�ɾ��ָ��λ��Ԫ��

    bool LogicalRecoveryOfSpecifiedElement(T &x);    //�߼��ָ�ָ��Ԫ��

    bool PhysicalDeleteTheSpecifiedElement(T &x);   //����ɾ��ָ��Ԫ��

    bool PhysicalDeleteElementAtSpecifiedLocation(int &index);   //����ɾ��ָ��λ��Ԫ��

    void DisplayData();    //չʾ�ɼ�����

    void DisplayLogicallyDeletedData();   //չʾ�߼�ɾ��������

    bool QuerySpecifiedElement(T &x) const;    //��ѯָ��Ԫ��

    int LocateTheOrdinalNumberOfTheSpecifiedElement(T &x) const;   //��ȡָ��Ԫ��λ��

    bool ModifyDataForSpecifiedElement(T &se, T &x) const;   //�޸�ָ��Ԫ��

    bool ReadDataFromAFile(string &fileName);    //���ļ��ж�ȡ����

    bool WriteDataToFile(string &fileName) const;   //д���ݵ��ļ���

    bool Sort() const;   //ѡ������

    bool getDataByIndex(int &index, T &x);   //��ȡָ��λ��Ԫ��
};

template<class T>
bool SeqList<T>::ExpansionCapacity() {
    Node<T> *newList = new Node<T>[maxSize + defaultSize];
    if (newList == NULL) {
        cerr << "Storage allocation error!" << endl;
        exit(1);
    }
    maxSize += defaultSize;
    Node<T> *srcptr = data;
    Node<T> *destprt = newList;
    int n = realLength;
    while (n--)*destprt++ = *srcptr++;
    delete[] data;
    data = newList;
    return true;
}

template<class T>
Node<T> SeqList<T>::getNodeByIndex(int &index) {
    return data[index];
}

template<class T>
bool SeqList<T>::getDataByIndex(int &index, T &x) {
    if (index <= 0 || index > length)
        return false;

    for (int i = 0; i < realLength; ++i) {
        if (data[i].survival) {
            index--;
            if (index == 0) {
                x = data[i].data;
                return true;
            }
        }
    }
    return false;
}

template<class T>
bool SeqList<T>::Sort() const {
    int minIndex;
    for (int i = 0; i < realLength - 1; ++i) {
        if (data[i].survival) {
            minIndex = i;
            for (int j = i + 1; j < realLength; ++j) {
                if (data[j].data < data[minIndex].data)
                    minIndex = j;
            }
            if (minIndex != i) {
                Node<T> t = data[i];
                data[i] = data[minIndex];
                data[minIndex] = t;
            }
        }
    }
    return true;
}

template<class T>
bool SeqList<T>::WriteDataToFile(string &fileName) const {
    if (fileName.size() == 0) {
        cout << "File name is empty!";
        return false;
    }

    ofstream out(fileName);

    if (!out.is_open()) {
        cout << "Failed to open the file!";
        return false;
    }

    for (int i = 0; i < realLength; ++i) {
        out << data[i].data << " " << data[i].survival << endl;
    }
    out.close();
    return true;
}

template<class T>
bool SeqList<T>::ReadDataFromAFile(string &fileName) {
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
        Node<T> t;
        in >> t.data >> t.survival;
        push_back(t);
    }
    if (data[realLength].survival) {
        realLength--;
        length--;
    } else
        realLength--;
    in.close();
    return true;
}

template<class T>
bool SeqList<T>::ModifyDataForSpecifiedElement(T &se, T &x) const {
    int index = LocateTheOrdinalNumberOfTheSpecifiedElement(se) - 1;

    if (index == -1 || !data[index].survival)
        return false;

    data[index].data = x;

    return true;
}

template<class T>
int SeqList<T>::RealLocateTheOrdinalNumberOfTheSpecifiedElement(T &x) const {
    for (int i = 0; i < realLength; ++i) {
        if (data[i].data == x) {
            return i + 1;
        }
    }
    return 0;
}

template<class T>
bool SeqList<T>::push_back(Node<T> &x) {
    if (realLength == 0) {
        data[0] = x;

        if (x.survival == true) {
            length++;
            realLength++;
        } else
            realLength++;

        return true;
    }
    if (realLength + 1 == maxSize) { //��Ϊ������data[index+1]���� ����realLength+1��ǰһ����������
        ExpansionCapacity();
    }
    int index = 0;
    for (int i = 0; i < realLength; ++i) {
        if (data[i].survival == true) {
            index++;
        }
        if (index == length) {
            for (int j = realLength; j > i; j--) {
                data[j + 1] = data[j];
            }
            data[i + 1] = x;

            if (x.survival == true) {
                length++;
                realLength++;
            } else
                realLength++;

            return true;
        }
    }
    return false;
}

template<class T>
SeqList<T>::SeqList(int &size) {
    maxSize = size;
    length = 0;
    realLength = 0;
    data = new Node<T>[maxSize];

    if (data == NULL) {
        cerr << "Storage allocation error!" << endl;
        exit(1);
    }
}

template<class T>
SeqList<T>::SeqList(SeqList<T> &L) {
    maxSize = L.maxSize;
    length = L.length;
    realLength = L.realLength;
    data = new Node<T>[maxSize];
    if (data == NULL) {
        cerr << "Storage allocation error!" << endl;
        exit(1);
    }
    for (int i = 0; i < realLength; ++i) {
        data[i] = L.getNodeByIndex(i);
    }
}

template<class T>
SeqList<T>::~SeqList() {
    delete[]data;
}

template<class T>
int SeqList<T>::Length() const {
    return length;
}

template<class T>
bool SeqList<T>::IsEmpty() const {
    return !length;
}

template<class T>
bool SeqList<T>::toLogicalEmpty() {
    for (int i = 0; i < realLength; ++i) {
        if (data[i].survival) {
            data[i].survival = false;
            length--;
        }
    }
    return true;
}

template<class T>
bool SeqList<T>::toPhysicalEmpty() {
    maxSize = defaultSize;
    length = 0;
    realLength = 0;
    delete[] data;
    data = new Node<T>[maxSize];

    if (data == NULL) {
        cerr << "Storage allocation error!" << endl;
        exit(1);
    }
    return true;
}

template<class T>
SeqList<T> SeqList<T>::operator=(SeqList<T> &L) {
    maxSize = L.maxSize;
    length = L.length;
    realLength = L.realLength;
    data = new Node<T>[maxSize];
    if (data == NULL) {
        cerr << "Storage allocation error!" << endl;
        exit(1);
    }
    for (int i = 0; i < realLength; ++i) {
        data[i] = L.getNodeByIndex(i);
    }
}

template<class T>
bool SeqList<T>::push_back(T &x) {
    if (realLength == 0) {
        Node<T> newOne;
        newOne.data = x;
        data[0] = newOne;

        length++;
        realLength++;

        return true;
    }

    if (realLength + 1 == maxSize) { //��Ϊ������data[index+1]���� ����realLength+1��ǰһ����������
        ExpansionCapacity();
    }

    int index = 0;

    for (int i = 0; i < realLength; ++i) {
        if (data[i].survival == true) {
            index++;
        }
        if (index == length) {
            for (int j = realLength; j > i; j--) {
                data[j + 1] = data[j];
            }

            Node<T> newOne;
            newOne.data = x;

            data[i + 1] = newOne;

            length++;
            realLength++;

            return true;
        }
    }
    return false;
}

template<class T>
bool SeqList<T>::InsertBeforeTheSpecifiedElement(T &se, T &x) {
    int index = LocateTheOrdinalNumberOfTheSpecifiedElement(se) - 1;

    if (index == -1)
        return false;

    if (data[index].survival) {
        for (int j = realLength; j >= index; --j) {
            data[j + 1] = data[j];
        }
        Node<T> newOne;
        newOne.data = x;

        data[index] = newOne;

        length++;
        realLength++;

        return true;
    }
    return false;
}

template<class T>
bool SeqList<T>::InsertAfterTheSpecifiedElement(T &se, T &x) {
    int index = LocateTheOrdinalNumberOfTheSpecifiedElement(se) - 1;

    if (index == -1)
        return false;

    if (data[index].survival) {
        for (int j = realLength; j > index; --j) {
            data[j + 1] = data[j];
        }
        Node<T> newOne;
        newOne.data = x;

        data[index + 1] = newOne;

        length++;
        realLength++;

        return true;
    }
    return false;
}

template<class T>
bool SeqList<T>::InsertAtTheSpecifiedLocation(int &index, T &x) {
    if (index <= 0 || index > length)
        return false;

    for (int i = 0; i < realLength; ++i) {
        if (data[i].survival) {
            index--;
            if (index == 0) {
                for (int j = realLength; j >= i; --j) {
                    data[j + 1] = data[j];
                }
                data[i].data = x;
                length++;
                realLength++;
                return true;
            }
        }
    }
    return false;
}

template<class T>
bool SeqList<T>::LogicalDeleteTheSpecifiedElement(T &x) {
    int index = LocateTheOrdinalNumberOfTheSpecifiedElement(x) - 1;

    if (index == -1)
        return false;

    if (data[index].survival) {
        data[index].survival = false;

        length--;

        return true;
    }
    return false;
}

template<class T>
bool SeqList<T>::LogicalDeleteElementAtSpecifiedLocation(int &index) {
    if (index <= 0 || index > length)
        return false;

    for (int i = 0; i < realLength; ++i) {
        if (data[i].survival) {
            index--;
            if (index == 0) {
                data[i].survival = false;
                length--;
                return true;
            }
        }
    }
    return false;
}

template<class T>
bool SeqList<T>::LogicalRecoveryOfSpecifiedElement(T &x) {
    int index = LocateTheOrdinalNumberOfTheSpecifiedElement(x) - 1;
    if (index == -1)
        return false;
    if (!data[index].survival) {
        data[index].survival = true;
        length++;
        return true;
    }
    return false;
}

template<class T>
bool SeqList<T>::PhysicalDeleteTheSpecifiedElement(T &x) {

    int index = LocateTheOrdinalNumberOfTheSpecifiedElement(x) - 1;

    if (index == -1)
        return false;

    if (!data[index].survival) {
        return false;
    }

    for (int j = index; j < realLength - 1; ++j) {
        data[j] = data[j + 1];
    }
    length--;
    realLength--;

    return true;
}

template<class T>
bool SeqList<T>::PhysicalDeleteElementAtSpecifiedLocation(int &index) {
    if (index <= 0 || index > length)
        return false;

    for (int i = 0; i < realLength; ++i) {
        if (data[i].survival) {
            index--;
            if (index == 0) {
                for (int j = i; j < realLength - 1; ++j) {
                    data[j] = data[j + 1];
                }
                length--;
                realLength--;
                return true;
            }
        }
    }
    return false;
}

template<class T>
void SeqList<T>::DisplayData() {
    for (int i = 0; i < realLength; ++i) {
        if (data[i].survival) {
            cout << data[i].data << " ";
        }
    }
}

template<class T>
void SeqList<T>::DisplayLogicallyDeletedData() {
    for (int i = 0; i < realLength; ++i) {
        if (!data[i].survival) {
            cout << data[i].data << " ";
        }
    }
}

template<class T>
bool SeqList<T>::QuerySpecifiedElement(T &x) const {
    for (int i = 0; i < realLength; ++i) {
        if (data[i].data == x && data[i].survival)
            return true;
    }
    return false;
}

template<class T>
int SeqList<T>::LocateTheOrdinalNumberOfTheSpecifiedElement(T &x) const {
    int index = 0;
    for (int i = 0; i < realLength; ++i) {
        if (data[i].survival) {
            index++;
            if (data[i].data == x) {
                return index;
            }
        }
    }
    return index;
}

#endif //SEQLISTBYCPP_SEQLIST_H