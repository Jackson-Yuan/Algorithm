#include "iostream"
#include "vector"
#include "string"
#include "map"
#include "set"

using namespace std;

/**
 * �������һ�����ڴ洢�ַ������������ݽṹ�����ܹ����ؼ�����С�������ַ�����
 * ʵ�� AllOne �ࣺ
 * AllOne() ��ʼ�����ݽṹ�Ķ���
 * inc(String key) �ַ��� key �ļ������� 1 ��������ݽṹ���в����� key ����ô�������Ϊ 1 �� key ��
 * dec(String key) �ַ��� key �ļ������� 1 ����� key �ļ����ڼ��ٺ�Ϊ 0 ����ô��Ҫ����� key �����ݽṹ��ɾ��������������֤���ڼ��ټ���ǰ��key ���������ݽṹ�С�
 * getMaxKey() ��������һ�����������ַ��������û��Ԫ�ش��ڣ�����һ�����ַ��� "" ��
 * getMinKey() ��������һ��������С���ַ��������û��Ԫ�ش��ڣ�����һ�����ַ��� "" ��
 * ���ӣ�https://leetcode-cn.com/problems/all-oone-data-structure
 * */

/**
 * �����һ�������������Զ���ṹ������set���������Դ�ģ���
 *
 * ע��set�����ж��ظ�����ʵ���Ǳȴ�С������⣬����������ʵ����ֻ��Ҫcount��
 * �����ֻ������count��С��ϵ��������str����ô��ͬ��str��ͬ��count����Ϊһ����Ԫ��
 * ע��ṹ�嶨���Զ����������д��
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

