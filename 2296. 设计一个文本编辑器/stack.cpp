/*
    使用双栈求解
    两个栈快速解答，光标在两个栈之间
    1.添加字符串，将字符串转变为字符依次入栈a
    2.删除字符串，依次删除栈a，直至没有字符
    3.光标左移，将栈a的字符依次放入栈b
    4.光标右移，将栈b的字符依次放入栈a
    5.标移动完成后读取字符串，从栈a读取最多10个字符（读取结果顺序是反的，记得做下顺序调转），
    最后读取完之后复原栈a，调用入栈函数即可,具体参考函数readLeftChar()
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
