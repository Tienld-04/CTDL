#include <bits/stdc++.h>
using namespace std;

class TrieNode {
  public:
    int cnt;
    TrieNode *child[26];

    TrieNode() {
        cnt = 0;
        for (int i = 0; i < 26; ++i) {
            child[i] = NULL;
        }
    }
};

class Trie {
  private:
    TrieNode *root;

  public:
    Trie() {
        root = new TrieNode();
    }

    void add_string(string s) {
        TrieNode *current = root;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            int index = s[i] - 'a';
            if (current->child[index] == NULL) {
                current->child[index] = new TrieNode();
            }
            current = current->child[index];
            current->cnt++;
        }
    }

    void remove(string s) {
        removeHelper(root, s, 0);
    }

    void removeHelper(TrieNode *current, string s, int index) {
        if (index == s.size()) {
            if (current->cnt > 0) {
                current->cnt--;
            }
            return;
        }
        int idx = s[index] - 'a';
        if (current->child[idx] == NULL) {
            return;
        }
        removeHelper(current->child[idx], s, index + 1);
        if (current->child[idx]->cnt == 0) {
            delete current->child[idx];
            current->child[idx] = NULL;
        }
        // Thêm cập nhật giá trị cnt cho nút tiền tố
        int childCount = 0;
        for (int i = 0; i < 26; i++) {
            if (current->child[i] != NULL) {
                childCount++;
            }
        }
        if (childCount == 0 && current->cnt == 0) {
            delete current;
            current = NULL;
        }
    }
    bool isEmpty(TrieNode *node) {
        for (int i = 0; i < 26; ++i) {
            if (node->child[i] != NULL) {
                return false; // Kiểm tra xem nút có nút con nào không
            }
        }
        return true;
    }
    bool find_string(string s) {
        TrieNode *current = root;
        for (int i = 0; i < s.length(); ++i) {
            int index = s[i] - 'a';
            if (current->child[index] == NULL) {
                return false;
            }
            current = current->child[index];
        }
        return true;
    }
    int count_prefix(string s) {
        TrieNode *current = root;
        for (int i = 0; i < s.length(); ++i) {
            int idx = s[i] - 'a';
            if (current->child[idx] == NULL) {
                return 0; // Trả về 0 nếu không tìm thấy chuỗi con
            }
            current = current->child[idx];
        }
        return current->cnt; // Trả về số lần xuất hiện của chuỗi
    }

    bool is_prefix(string prefix, string query) {
        if (prefix.length() > query.length()) {
            return false; // Tiền tố dài hơn xâu truy vấn, không thể là tiền tố
        }
        for (int i = 0; i < prefix.length(); ++i) {
            if (prefix[i] != query[i]) {
                return false; // Ký tự khác nhau, không phải tiền tố
            }
        }
        return true; // Không có ký tự khác nhau, là tiền tố
    }
};

int main() {
    int n;
    cout << "Nhap vao so luong xau: ";
    cin >> n;
    Trie trie;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cout << "s[" << i << "] = ";
        cin >> s[i];
        trie.add_string(s[i]);
    }

    string l;
    cout << "Nhap vao xau can xoa: ";
    cin >> l;
    trie.remove(s[1]);
    string x;
    cout << "\nNhap vao xau can ktra tien to: ";
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (trie.find_string(x) == true) {
            cout << "\nTim thay ";
        } else {
            cout << "\nKhong tim thay xau \n";
        }
    }
    // cout << "Cac xau la tien to cua mot xau khac:\n";
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         if (i != j && trie.is_prefix(s[i], s[j])) {
    //             cout << s[i] << " la tien to cua " << s[j] << endl;
    //         }
    //     }
    // }

    return 0;
}
