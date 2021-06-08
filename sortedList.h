//
// Created by tomgu on 06/06/2021.
//

#ifndef EX2_SORTEDLIST_H
#define EX2_SORTEDLIST_H

namespace mtm
{
//איטרטורים להפוך לקבועים
// להוסיף שתי פונקציות חסרות
// חריגות
    template<class T>
    class Node
    {
    public:
        T data;
        Node* next = nullptr;
        T& operator*() const;
        Node& operator=(const Node& other);
        explicit Node(const T& data);
        Node(Node& other);
        ~Node();
        Node* getNext();
        void setNext(Node *next);
    };


    template<class T>
    class SortedList
    {
    public:

        class const_iterator
        {
        public: //private
            Node<T>* element;
            Node<T>* getNext();

//        public:
            const_iterator operator++();
            bool operator==(const_iterator iter);
            const T& operator*() const; //TODO
        };

        SortedList() = default;                         //constractor
        ~SortedList();                                  // destractor
        SortedList(const SortedList& list);             // copy
        void insert(const T& data);                     // insert
        const_iterator begin();                         // begin
        const_iterator end();                           // end
        void remove(const_iterator iterator);           // remove
        int length(const SortedList& list);             // length
        SortedList<T>& operator=(const SortedList& list); // operator =

//    private:

        Node<T> *head = nullptr, *tail = nullptr;
        int size = 0;
    };

    template<class T>
    T &Node<T>::operator*() const
    {
        return data;
    }

    template<class T>
    Node<T>* Node<T>::getNext()
    {
        return next;
    }

    template<class T>
    Node<T>& Node<T>::operator=(const Node<T> &other)
    {
        T new_data = *other;
        delete data;
        data = new_data;
        return *this;
    }

    template<class T>
    Node<T>::Node(const T& data)
    {
        T new_data = data;
        this->data = new_data;
    }

    template<class T>
    Node<T>::Node(Node<T> &other)
    {
        data = *other;
    }

    template<class T>
    Node<T>::~Node()
    {
        delete data;
    }

    template<class T>
    void SortedList<T>::insert(const T& data)
    {
        bool inserted = false;
        Node<T> new_item(data);
        if(size == 0)
        {
            head = &new_item;
            new_item.setNext(tail);
            inserted = true;
        }
        if(data < **head)
        {
            new_item->getNext() = head;
            head = &new_item;
            inserted = true;
        }
        if(!inserted)
        {
            for (auto item = begin(); item != end(); item++)
            {
                if (data < *(item + 1))
                {
                    new_item->getNext() = item->getNext();
                    item->getNext() = &new_item;
                    break;
                }
            }
        }
        size ++;
    }

    template<class T>
    void Node<T>::setNext(Node<T> *next)
    {
        Node::next = next;
    }


    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::begin()
    {
        return head;
    }

    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::end()
    {
        return tail;
    }

    template<class T>
    void SortedList<T>::remove(const_iterator iterator_to_remove)
    {
        if(*iterator_to_remove == *head)
        {
            Node<T>* temp = (*head)->getNext();
            delete *head;
            head = temp;
            size --;
            return;
        }
        Node<T>* previous = begin();
        for (auto iter = begin(); iter != end(); iter++)
        {
            if(iterator_to_remove == iter)
            {
                (*previous)->getNext() = iter->getNext();
                delete  iter;
                break;
            }
          previous = iter;
        }
      size--;
    }

    template<class T>
    SortedList<T>::~SortedList()
    {
        delete head;
    }

    template<class T>
    SortedList<T>::SortedList(const SortedList &list)
    {
        *head = *list.head;
        Node<T> *temp = head;
        for (auto iter = list.begin(); iter != list.end(); iter++)
        {
            *(temp->getNext()) = *(iter->getNext());
            temp++;
        }
    }

    template<class T>
    int SortedList<T>::length(const SortedList &list)
    {
        return size;
    }

    template<class T>
    SortedList<T> &SortedList<T>::operator=(const SortedList &list)
    {
        SortedList new_list(list);
        delete this;
        this = &new_list;
        return *this;
    }

    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::const_iterator::operator++() //TODO
    {
        element = element->getNext();
    }

    template<class T>
    bool SortedList<T>::const_iterator::operator==(const_iterator iter)
    {
        return element == iter.element;
    }

    template<class T>
    const T &SortedList<T>::const_iterator::operator*() const
    {
        return *element;
    }


    template<class T>
    Node<T> *SortedList<T>::const_iterator::getNext()
    {
        return element->getNext();
    }

} // mtm

#endif //EX2_SORTEDLIST_H
