#include <iostream>
#include <stdexcept>
class List {

private:

    class Item { // item of list
    public:
        int data;
        Item* prev;
        Item* next;
        Item(int data, Item* prev = NULL, Item* next = NULL) : data(data), prev(prev), next(next) {};
    };

    Item* head; // pointer to the first item of list
    Item* tail; // pointer to the last item of List
    size_t size; // size of list

    // get pointer to the item of list by index
    Item* getItem(size_t index) {
        if (index < get_size()) {
            Item* item = head;
            item = head;
            for (int i = 0; i < (int)index; i++) {
                item = item->next;
            }
            return item;
            item = NULL;
        }
    }

public:
    // Constructors
    List(int data) {
        Item* item = new Item(data); // Create temporary node
        head = tail = item;
        size = 1;
    }
    List() {
        head = tail = NULL;
        size = 0;
    }

    // Destructor
    ~List() {
        clear();
    }

    // Add item to the end
    void push_back(int data) {
        Item* item = new Item(data);
        if (isEmpty()) {
            head = tail = item;
        }
        else {
            item->prev = tail;
            tail->next = item;
            tail = item;
        }
        size++;
    }

    // Add item to the beginning
    void push_front(int data) {
        Item* item = new Item(data);
        if (isEmpty()) {
            head = tail = item;
        }
        else {
            item->next = head;
            head->prev = item;
            head = item;
        }
        size++;

    }

    // Delete first element
    void pop_front() { //мб объединить до одного
        if (get_size() == 1) {
            delete head;
            head = tail = NULL;
            size--;
        }

        else if (get_size() > 1) {
            Item* item = head->next;
            delete head;
            head = item;
            head->prev = NULL;
            size--;
        }
        else if (isEmpty()) throw "List is empty. First element cannot be deleted\n";
    }

    // Delete last element
    void pop_back() { //мб объединить до одного
        if (get_size() == 1) {
            delete tail;
            head = tail = NULL;
            size--;
        }
        if (get_size() > 1) {
            Item* item = tail->prev;
            delete tail;
            tail = item;
            tail->next = NULL;
            size--;
        }
        if (isEmpty()) throw "List is empty. Last element cannot be deleted\n";
    }
    // Print element at user's position
    int at(size_t index) {
        if (index < get_size() && index >= 0)
            return getItem(index)->data;
        else  throw "Index is out of range";
    }
    void insert(int data, size_t index) {
        if (index <= get_size() && index >= 0) {
            if (index == 0) push_front(data);
            else if (index == get_size()) push_back(data);
            else {
                Item* next_item = getItem(index);
                Item* item = new Item(next_item->data, next_item, next_item->next);
                next_item->data = data;
                next_item->next = item;
                if (tail == next_item) tail = item;
                size++;
            }
        }
        else throw "Index is out of range";
    }

    void set(size_t index, int data) {
        if (index < get_size() && index >= 0) {
            getItem(index)->data = data;
        }
        else throw "Index is out of range";
    }

    size_t get_size() const {
        return size;
    }

    bool isEmpty() {
        return get_size() == 0;
    }

    void remove(size_t index) {
        if (index < get_size() && index >= 0) {
            Item* item = getItem(index);
            if (get_size() == 1) {
                delete item;
                head = tail = NULL;
            }
            else {
                if (index == get_size() - 1) {
                    item->prev->next = NULL;
                    tail = getItem(index);
                }
                else if (index == 0) {
                    item->next->prev = NULL;
                    head = item;
                }
                else {

                    item->next->prev = item->prev;
                    item->prev->next = item->next;
                }
                delete item;
            }
            size--;
        }
        else throw "Index is out of range";
    }
    void push_back(List& const list) {
        for (int i = 0; i < (int)list.get_size(); i++) {
            int data = list.at(i);
            this->push_back(data);
        }
    }

    void clear() {
        while (head != NULL) {
            Item* item = head->next;
            delete head;
            head = item;
        }
        head = tail = NULL;
        size = 0;
    }

    friend std::ostream& operator<< (std::ostream& out, const List& list);
};
