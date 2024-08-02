#include<iostream>
#include<string>


//使用string类暴力求解


using namespace std;
class TextEditor {
public:
	string textBorad;
	int length;
	int cursor;

	TextEditor() {
		textBorad = "|";
		cursor = 0;
		length = textBorad.length();
	}

	void addText(string text) {
		textBorad.insert(cursor, text);
		cursor += text.length();
		length = textBorad.length();
	}

	int deleteText(int k) {
		int count;
		if (cursor < k) {
			textBorad.erase(textBorad.begin(), textBorad.begin() + cursor);
			count = cursor;
			cursor = 0;

		}

		else {
			textBorad.erase(textBorad.begin() + cursor - k, textBorad.begin() + cursor);
			count = k;
			cursor -= k;
		}
		length = textBorad.length();

		return count;
	}

	string cursorLeft(int k) {
		string temp;
		if (cursor - k > 0) {
			textBorad.erase(cursor, 1);
			textBorad.insert(cursor - k, "|");
			length = textBorad.length();
			cursor -= k;
		}
		else {
			textBorad.erase(cursor, 1);
			textBorad.insert(0, "|");
			length = textBorad.length();
			cursor = 0;
		}
		if (cursor < 10) {
			temp = textBorad.substr(0, cursor);
		}
		else {
			temp = textBorad.substr(cursor - 10, 10);
		}
		return temp;
	}

	string cursorRight(int k) {
		string temp;
		if (cursor + k > length) {
			textBorad.erase(cursor, 1);
			textBorad.insert(length - 1, "|");
			length = textBorad.length();
			cursor = length - 1;
		}
		else {
			textBorad.erase(cursor, 1);
			textBorad.insert(cursor + k, "|");
			length = textBorad.length();
			cursor = cursor + k;
		}
		if (cursor < 10) {
			temp = textBorad.substr(0, cursor);
		}
		else {
			temp = textBorad.substr(cursor - 10, 10);
		}
		return temp;
	}
};


int main() {
	TextEditor textEditor;
	textEditor.addText("leetcode");
	cout << textEditor.textBorad << endl;
	cout << textEditor.deleteText(4) << endl;
	cout << textEditor.textBorad << endl;
	textEditor.addText("practice");
	cout << textEditor.textBorad << endl;
	cout << textEditor.cursorRight(3) << endl;
	cout << textEditor.textBorad << endl;
	cout << textEditor.cursorLeft(8) << endl;
	cout << textEditor.textBorad << endl;
	cout << textEditor.deleteText(10) << endl;
	cout << textEditor.textBorad << endl;
	cout << textEditor.cursorLeft(2) << endl;
	cout << textEditor.textBorad << endl;
	cout << textEditor.cursorRight(6) << endl;
	cout << textEditor.textBorad << endl;
	cin.get();
}