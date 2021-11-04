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
        if (index < get_size() && index>=0) {
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

    // Delete last element
    void pop_back() {
        try {
            if (get_size() == 1) {
                delete head;
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
        }

        catch (const std::exception& exception) {
            throw exception;
        }
    }

    // Delete first element
    void pop_front() {
        try {
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
        }
        catch (const std::exception& exception) {
            throw exception;
        }
    }

    //Inserting an item into a list by index
    void insert(int data, size_t index) {
        try {
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
        catch (const std::exception& exception) {
            throw exception;
        }
    }

    // Print element at user's position
    int at(size_t index) {
        try {
            return getItem(index)->data;
        }

        catch (const std::exception& exception) {
            throw exception;
        }
    }
    //Deleting a list item by index
    void remove(size_t index) {
        try {
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
        catch (const std::exception& exception) {
            throw exception;
        }
    }
    //Returns the size of the list
    size_t get_size() const {
        return size;
    }

    //Deleting a list from memory
    void clear() {
        while (head != NULL) {
            Item* item = head->next;
            delete head;
            head = item;
        }
        head = tail = NULL;
        size = 0;
    }

    //Replacing an element by index
    void set(size_t index, int data) {
        try {
            getItem(index)->data = data;
        }
        catch (const std::exception& exception) {
            throw exception;
        }
    }

    //Checking for list emptiness
    bool isEmpty() {
        return get_size() == 0;
    }
    
    //Adding the passed list to the end of the current list
    void push_back(List& const list) {
        Item* item = list.head;
        for (int i = 0; i < (int)list.get_size(); i++) {
            this->push_back(item->data);
            item = item->next;
        }
    }

    //Overloading the output operator
    friend std::ostream& operator<< (std::ostream& out, const List& list);
};
