#include "ArrayStack.h"

int main() {

    string str = "abcdefghijklmnopqrstuvwxyz0123456789";

    ArrayStack<char> textReverseString;

    cout << "����ǰ��" << str << endl;
    cout << "�����" << textReverseString.ReverseString(str) << endl;

    string str2 = "[()] {} {[()()]()}";
    cout << str2;

    ArrayStack<char> textCheckBracketMatching;

    if (textCheckBracketMatching.CheckBracketMatching(str2))
        cout << "  ����ƥ�䣡" << endl;
    else
        cout << "  ���Ų�ƥ�䣡" << endl;

    str2 = "[()] {} {[()()]()";
    cout << str2;
    textCheckBracketMatching.toEmpty();
    if (textCheckBracketMatching.CheckBracketMatching(str2))
        cout << "  ����ƥ�䣡" << endl;
    else
        cout << "  ���Ų�ƥ�䣡" << endl;

    str2 = "[()] {} {[()()]()}}";
    cout << str2;
    textCheckBracketMatching.toEmpty();
    if (textCheckBracketMatching.CheckBracketMatching(str2))
        cout << "  ����ƥ�䣡" << endl;
    else
        cout << "  ���Ų�ƥ�䣡" << endl;

    ArrayStack<char> textArithmeticExpressionEvaluation;
    string str3 = "((1.2*3.4+5^6-7)/8)";
    cout << "�������ʽ��" << str3 << endl;
    cout << "ת��Ϊ��׺���ʽ��";
    vector<string> postfix = textArithmeticExpressionEvaluation.ArithmeticToPostfix(str3);
    for (auto str:postfix)
        cout << str;
    cout << endl << "���ֵΪ��";
    cout << textArithmeticExpressionEvaluation.ArithmeticExpressionEvaluation(str3);

    return 0;
}