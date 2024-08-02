/*
    ʹ��˫ջ���
    ����ջ���ٽ�𣬹��������ջ֮��
    1.����ַ��������ַ���ת��Ϊ�ַ�������ջa
    2.ɾ���ַ���������ɾ��ջa��ֱ��û���ַ�
    3.������ƣ���ջa���ַ����η���ջb
    4.������ƣ���ջb���ַ����η���ջa
    5.���ƶ���ɺ��ȡ�ַ�������ջa��ȡ���10���ַ�����ȡ���˳���Ƿ��ģ��ǵ�����˳���ת����
    ����ȡ��֮��ԭջa��������ջ��������,����ο�����readLeftChar()
*/
#include<stack>
#include <utility>
#include<string>
using namespace std;
class TextEditor {
public:
    stack<char> left, right;
    TextEditor() {}

    void addText(string text) {
        for (char c : text) left.push(c);
    }

    int deleteText(int k) {
        k = min(k, (int)left.size());
        for (int i = 0; i < k; i++) left.pop();
        return k;
    }

    string text() {
        string res;
        for (int i = 0, k = min((int)left.size(), 10); i < k; i++) {
            res.insert(res.begin(), left.top());
            left.pop();
        }
        addText(res);
        return res;
    }

    string cursorLeft(int k) {
        k = min(k, (int)left.size());
        while (k--) {
            right.push(left.top());
            left.pop();
        }
        return text();
    }

    string cursorRight(int k) {
        k = min(k, (int)right.size());
        while (k--) {
            left.push(right.top());
            right.pop();
        }
        return text();
    }
};
