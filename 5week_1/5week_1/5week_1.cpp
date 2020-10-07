#include <iostream>
#include <algorithm>

using namespace std;

class SequenceList
{
private:
    struct Node
    {
        int e;
        Node* prev;
        Node* next;
    };

public:
    class Iterator // 반복자 클래스
    {
    private:
        Node* v;                    // 반복자가 가리키는 노드를저장하기 위한 포인터 변수
        Iterator(Node* u);          // 반복자 생성자

    public:
        int& operator+();           // 반복자가 가리키고 있는 노드가 가지고 있는 원소 값을 반환하는 연산자
        bool operator==(const Iterator& p) const;  // 현재 노드와 반복자가 가리키고 있는 노드 p와 일치하는지 확인하는 연산자
        bool operator!=(const Iterator& p) const;  // 현재 노드와 반복자가 가리키고 있는 노드 p와 불일치하는지 확인하는 연산자
        Iterator& operator++();         // 다음 노드로 반복자를 이동시키는 연산자
        Iterator& operator--();         // 이전 노드로 반복자를 이동시키는 연산자

        friend class SequenceList;         // SequenceList 클래스가 Iterator 클래스에 접근할 수 있도록 선언하는 friend 선언

    };

private:
    int n;                   // 리스트의 크기
    Node* header;            // header 센티널 노드
    Node* trailer;           // trailer 센티널 노드
public:
    SequenceList();                                 // 생성자
    int size() const;                               // 리스트의 현재 크기를 반환하는 함수
    bool empty() const;                             // 리스트가 비어있는지 여부를 확인하는 함수
    Iterator begin() const;                         // 반복자를 맨 처음 노드로 위치시키는 함수
    Iterator end() const;                           // 반복자를 trailer 센티널 노드에 위치시키는 함수
    void insertFront(const int& e);                 // 원소 e를 리스트의 header 센티널 다음에 삽입시키는 함수
    void insertBack(const int& e);                  // 원소 e를 리스트의 trailer 센티널 앞에 삽입시키는 함수
    void insert(const Iterator& p, const int& e);   // 위치 p 뒤에 원소 e를 가지는 노드를 삽입하는 함수
    void eraseFront();                              // 리스트의 header 센티널 다음에 있는 노드를 삭제하는 함수
    void eraseBack();                               // 리스트의 trailer 센티널 앞에 있는 노드를 삭제하는 함수
    void erase(const Iterator& p);                  // 위치 p에 존재하는 노드를 삭제하는 함수

    Iterator atIndex(int i) const;                  // 인덱스 i를 갖는 원소의 위치를 반환하는 함수
    int indexOf(const Iterator& p) const;           // 위치 p에 있는 원소의 인덱스를 반환하는 함수

};

SequenceList::SequenceList()
{
    n = 0;
    header = new Node;
    trailer = new Node;
    header->next = trailer; // 초기화시 header 센티널 다음(next)에는 바로 trailer 센티널이 연결되도록 함
    trailer->prev = header; // 초기화시 trailer 센티널 앞(prev)에는 바로 header 센티널이 연결되도록 함
}

void SequenceList::insert(const SequenceList::Iterator& p, const int& e)
{
    Node* w = p.v;              // 위치 p의 노드
    Node* u = w->prev;          // 위치 p의 노드 바로 이전에 있는 노드
    Node* v = new Node;         // 새롭게 삽입할 노드를 초기화
    v->e = e; 
    v->next = w; w->prev = v;   // v의 다음을 w로, w의 이전 노드를 v로 설정
    v->prev = u; u->next = v;   // v의 이전 노드를 u로, u의 다음 노드를 v로 설정
    this->n++;
}

void SequenceList::insertFront(const int& e)
{
    insert(begin(), e); // 위치 p를 반복자 begin() 함수를 사용해 설정하면 header 센티널 다음에 노드 삽입 가능
}

void SequenceList::insertBack(const int& e)
{
    insert(end(), e);   // 위치 p를 반복자 end() 함수를 사용해 설정하면 trailer 센티널 앞에 노드 삽입 가능
}

void SequenceList::erase(const Iterator& p)
{
    Node* v = p.v;             // 위치 p에 있는 노드를 v에 정의
    Node* w = v->next;         // v 다음의 노드를 w로 정의
    Node* u = v->prev;         // v 이전에 있는 노드를 u로 정의
    u->next = w; w->prev = u;  // v를 삭제하기 위해 w와 u를 서로 연결
    delete v;                  // 노드 v 삭제
    this->n--;
}

void SequenceList::eraseFront()
{
    erase(begin()); // header 센티널 다음 노드를 삭제하기 위해 begin() 사용
}

void SequenceList::eraseBack()
{
    erase(--end()); // trailer 센티널 앞의 노드를 삭제하기 위해 end()함수 사용 후, -- 연산자 사용하여 trailer 센티널 앞에 있는 노드 지정
}

int SequenceList::size() const
{
    return n;
}

bool SequenceList::empty() const
{
    return (n == 0);
}

SequenceList::Iterator::Iterator(Node* u) // 반복자 생정자
{
    v = u;
}

SequenceList::Iterator SequenceList::begin() const
{
    return Iterator(header->next); // hedaer 센티널 노드 다음 노드를 지정하여 반복자 생성
}

SequenceList::Iterator SequenceList::end() const
{
    return Iterator(trailer); // trailer 센티널 노드를 지정하여 반복자 생성
}

int& SequenceList::Iterator::operator+()
{
    return v->e; // 반복자가 현재 가리키고 있는 노드의 값을 반환
}

bool SequenceList::Iterator::operator==(const Iterator& p) const
{
    return v == p.v; // 현재 반복자가 가리키고 있는 노드 v가 위치 p의 노드와 일치하는지 확인
}

bool SequenceList::Iterator::operator!=(const Iterator& p) const
{
    return v != p.v;  // 현재 반복자가 가리키고 있는 노드 v가 위치 p의 노드와 불일치 하는지 확인
}

SequenceList::Iterator& SequenceList::Iterator::operator++()
{
    v = v->next;  // 현재 반복자가 가리키고 있는 노드의 다음 노드를 지정하게 함
    return *this;
}

SequenceList::Iterator& SequenceList::Iterator::operator--()
{
    v = v->prev;  // 현재 반복자가 가리키고 있는 노드의 이전 노드를 지정하게 함
    return *this;
}

SequenceList::Iterator SequenceList::atIndex(int i)const
{
    Iterator p = begin();  // 반복자를 begin()을 이용해 맨 첫 노드를 가리키게 설정
    for (int j = 0; j < i;j++)
    {
        ++p;  // j가 인덱스 i와 일치할 때 까지 p증가, 전위 연산자를 사용하여 j < i
    }
    return p;  // 위치 p 반환
}

int SequenceList::indexOf(const Iterator& p)const
{
    Iterator q = begin();  // 반복자 q를 begin()을 이용해 맨 첫 노드를 가리키게 설정
    int j = 0;  // 인덱스 초기화

    while (q != p)
    {
        // p를 찾을 때 까지 위치 q를 이동하고 인덱스를 계싼
        ++q;
        ++j;
    }
    return j;  // 인덱스 j 반환
}

int main()
{
    int T;
    cin >> T;

    SequenceList sl;
    SequenceList::Iterator iter = sl.begin();

    for (int i = 0; i < T; i++)
    {
        string oper;
        cin >> oper;

        if (oper == "insert")
        {
            int e;
            cin >> e;
            sl.insert(iter, e);
        }
        else if (oper == "erase")
        {
            if (sl.size() == 0)
                cout << "Empty" << endl;
            else
                sl.erase(iter);
        }
        else if (oper == "begin")
        {
            iter = sl.begin();
        }
        else if (oper == "end")
        {
            iter = sl.end();
        }
        else if (oper == "++")
        {
            iter = ++iter;
        }
        else if (oper == "--")
        {
            iter = --iter;
        }
        else if (oper == "print")
        {
            if (sl.size() == 0)
                cout << "Empty" << endl;
            else {
                iter = sl.begin();
                for (iter;iter != sl.end();++iter) {
                    cout << iter.operator+() << " ";
                }
                cout << "\n";
            }
        }
        else if (oper == "size")
        {
            cout << sl.size() << endl;
        }
        else
        {
            cout << "Your command is wrong, try again." << endl;
        }

    }

}
