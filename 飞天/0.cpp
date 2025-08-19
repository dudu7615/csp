#include "bits/stdc++.h"

using namespace std;
using ll = long long;

class Stu {
   private:
    struct StuInfo {
        char no[9];
        char name[20];
        char sex;
        unsigned int age;
        unsigned int classNo;
        float grade;

        StuInfo* prev;
        StuInfo* next;

        StuInfo(const char no[], const char name[], char sex, unsigned int age,
                unsigned int classNo, float grade)
            : sex(sex),
              age(age),
              classNo(classNo),
              grade(grade),
              prev(nullptr),
              next(nullptr) {
            strncpy(this->no, no, sizeof(this->no) - 1);
            this->no[sizeof(this->no) - 1] = '\0';  // 确保字符串结束符
            strncpy(this->name, name, sizeof(this->name) - 1);
            this->name[sizeof(this->name) - 1] = '\0';
        }
    };

    StuInfo* head = nullptr;
    StuInfo* tail = nullptr;
    int size = 0;

   public:
    void add(const char no[], const char name[], char sex, unsigned int age,
             unsigned int classNo, float grade) {
        StuInfo* newNode = new StuInfo(no, name, sex, age, classNo, grade);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    int getSize() const { return size; }

    StuInfo* operator[](const char no[]) {
        StuInfo* cur = head;
        while (cur != nullptr) {
            if (strcmp(cur->no, no) == 0) {
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    }

    void del(StuInfo* cur) {
        if (cur == nullptr) return;
        if (cur == head) {
            head = head->next;
            head->prev = nullptr;

        } else if (cur == tail) {
            tail = tail->prev;

            tail->next = nullptr;

        } else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        delete cur;
        size--;
    }

    void init() {
        add("20240001", "A", 'M', 18, 1, 90);
        add("20240002", "B", 'F', 19, 2, 80);
        add("20240003", "C", 'M', 20, 3, 70);
        add("20240004", "D", 'F', 21, 4, 60);
        add("20240005", "E", 'M', 22, 5, 50);
    }
};

int main() {
    Stu m;
    m.init();
    char n[9];
    cin >> n;
    cout << m[n]->grade << endl;
    return 0;
}