#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Node
{
    string key;
    Node* next;
    Node* prev; //Указатель на предыдущий элемент
};

struct LinkedList
{
    Node* head; //Указатель на начало списка
    Node* tail; //Указатель на конец списка
    // Конструктор
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
};

//Функция для добавления элемента в конец списка
void addNode(LinkedList& list, const string& value)
{
    Node* newNode = new Node;
    newNode->key = value;
    newNode->next = nullptr;
    newNode->prev = nullptr; //Инициализируем указатель на предыдущий элемент

    if (list.head == nullptr) //Если список пустой, новый элемент становится головным и хвостовым
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else
    {
        newNode->prev = list.tail; //Указываем на предыдущий элемент
        list.tail->next = newNode; //Добавляем новый элемент после текущего хвостового элемента
        list.tail = newNode; //Обновляем указатель на хвостовой элемент
    }
}

//Функция для вывода списка
void print_list(Node* beg)
{
    if (beg == nullptr) //Если список пустой
    {
        cout << "Список пустой" << endl;
        return;
    }

    cout << "Ваш список: ";
    Node* p = beg;
    while (p != nullptr) //Пока не конец списка
    {
        cout << p->key << ' ';
        p = p->next; //Перейти на следующий элемент
    }
    cout << endl;
}

//Функция для удаления узла
Node* del_Node(Node* beg, int k)
{
    setlocale(LC_ALL, "RUS");
    k--;
    Node* p = beg;

    if (k == 0)
    {
        beg = beg->next;
        if (beg == nullptr) return nullptr;
        delete p;
        return beg;
    }

    for (int i = 0; i < k - 1 && p != nullptr; i++, p = p->next);

    if (p == nullptr || p->next == nullptr) return beg;

    Node* r = p->next; //Встать на удаляемый элемент
    p->next = r->next; //Изменить ссылку

    if (r->next != nullptr) //Если удаляемый элемент не последний
        r->next->prev = p; //Обновляем указатель на предыдущий элемент

    delete r;
    r = p->next; //Встать на следующий
    return beg;
}

void add_Node(LinkedList& list, int k, const string& value)
{
    setlocale(LC_ALL, "RUS");
    k--;

    Node* p = new Node;
    p->key = value;

    if (k == 0)
    {
        p->next = list.head; //Добавить перед головным элементом
        if (list.head != nullptr) {
            list.head->prev = p; //Установить указатель на предыдущий элемент для головного элемента
        }
        list.head = p; //Обновить указатель на головной элемент
        return;
    }

    Node* r = list.head; //Встать на начало списка
    for (int i = 0; i < k - 1 && r != nullptr; i++, r = r->next);
    if (r == nullptr) {
        cout << "Указанный индекс выходит за пределы списка" << endl;
        return;
    }
    p->next = r->next; //Связать r с концом списка
    p->prev = r; //Связать p с r в обратном направлении
    if (r->next != nullptr) {
        r->next->prev = p; //Установить указатель на предыдущий элемент для следующего элемента после r
    }
    r->next = p;
}

//Функция для поиска индекса ключевого слова
int find_key_index(Node* beg)
{
    setlocale(LC_ALL, "RUS");
    cout << "Введите ключевое слово: ";
    string key_word;
    cin >> key_word;
    Node* r = beg;
    int counter = 1;
    while (r != nullptr)
    {
        if (r->key == key_word)
            return counter;
        r = r->next;
        counter++;
    }
    cout << "Такое ключевое слово не найдено" << endl;
    return -1;
}

//Функция для удаления списка
Node* delete_list(Node* beg)
{
    setlocale(LC_ALL, "RUS");
    Node* p = beg;
    int counter = 0; 
    while (p != nullptr)
    {
        p = p->next;
        counter++;
    }
    for (int i = counter; i > 1; i--)
    {
        beg = del_Node(beg, i); //Используем функцию del_Node() для удаления узлов
    }
    beg = del_Node(beg, 1); //Удаляем первый узел
    return beg;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int c;
    string value;
    LinkedList list; //Создаем экземпляр связного списка
    cout << "Введите количество элементов списка: "; cin >> c;
    for (int i = 1; i <= c; i++) {
        cout << "Введите элемент спика: "; cin >> value;
        addNode(list, value);
    }

    Node* first = list.head; //Устанавливаем начало списка на головной элемент
    print_list(first); //Выводим список на экран

    cout << "Номер элемента, который вы хотите удалить: ";
    int n;
    cin >> n;

    first = del_Node(first, n); //Удаляем элемент из списка
    print_list(first); //Выводим обновленный список на экран

    int num = find_key_index(first); //Ищем индекс ключевого слова в списке

    cout << "Введите количество, добавляемых слева и справа элементов: ";
    int k;
    string add;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cout << "Введите добавлемяый элемент: "; cin >> add;
        add_Node(list, num + i, add); //Добавляем элементы слева от ключевого слова
    }
    num += k;
    for (int i = 0; i < k; i++) {
        cout << "Введите добавлемяый элемент: "; cin >> add;
        add_Node(list, num + i + 1, add); //Добавляем элементы справа от ключевого слова
    }
    print_list(list.head); //Выводим обновленный список на экран
    cout << endl;
    return 0;
}
