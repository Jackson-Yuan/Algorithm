#include "iostream"
#include "vector"
#include "string"
#include "map"
#include "set"

using namespace std;

/**
 * 请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。
 * 实现 AllOne 类：
 * AllOne() 初始化数据结构的对象。
 * inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
 * dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，那么需要将这个 key 从数据结构中删除。测试用例保证：在减少计数前，key 存在于数据结构中。
 * getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
 * getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。
 * 链接：https://leetcode-cn.com/problems/all-oone-data-structure
 * */

/**
 * 此题就一个东西，利用自定义结构体来让set进行排序，以此模拟堆
 *
 * 注意set里面判短重复，其实就是比大小，如此题，按照题意其实本质只需要count排
 * 但如果只利用了count大小关系，忽略了str，那么不同的str相同的count回视为一样的元素
 * 注意结构体定义自定义排序规则写法
 * */
struct node {
    string str;
    int count;

    bool operator<(const node &b) const {
        if (count == b.count) {
            return str < b.str;
        }
        return count < b.count;
    }
};


class AllOne {
private:
    map<string, int> m;
    set<node> st;
public:
    AllOne() {
        m.clear();
        st.clear();
    }

    void inc(string key) {
        auto ite = m.find(key);
        node cur;
        cur.str = key;

        if (ite == m.end()) {
            m[key] = 1;
            cur.count = 1;
            st.insert(cur);
        } else {
            cur.count = ite->second;
            st.erase(cur);
            cur.count = ++(ite->second);
            st.insert(cur);
        }


    }

    void dec(string key) {
        auto ite = m.find(key);

        node cur;
        cur.str = key;
        cur.count = ite->second;
        st.erase(cur);


        --(ite->second);
        if (ite->second == 0) {
            m.erase(key);
        } else {
            cur.count = ite->second;
            st.insert(cur);
        }
    }

    string getMaxKey() {
        return st.empty() ? "" : (--st.end())->str;
    }

    string getMinKey() {
        return st.empty() ? "" : st.begin()->str;
    }
};


int main() {
    AllOne allOne;
    allOne.inc("a");
    allOne.inc("b");
    allOne.inc("b");
    allOne.inc("b");
    allOne.inc("b");
    allOne.dec("b");
    allOne.dec("b");

    cout << allOne.getMaxKey();
    cout << allOne.getMinKey();
}

