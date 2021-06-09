//
// Created by tomgu on 06/06/2021.
//

#ifndef EX2_SORTEDLIST_H
#define EX2_SORTEDLIST_H

namespace mtm
{

    using std::exception;
    template<class T> class SortedList;
    template<class T>
    class Node
    {
    private:
        T data;
        Node* next = nullptr;
        T& operator*();
        Node() = default;
        Node& operator=(const Node& other);
        explicit Node(const T& data_to_insert);
        Node(Node& other);
        ~Node() = default;
        Node* getNext();
        void setNext(Node *next);
        void setData(const T& to_insert);
        friend class SortedList<T>;
    };


    template<class T>
    class SortedList
    {
    public:

        class const_iterator
        {
        private:
            Node<T>* element;
            Node<T>* getNext();
            const_iterator operator+(int number);
            void setNext(Node<T> *next);
            explicit const_iterator (Node<T> *node);

        public:
            const_iterator operator++();
            bool operator==(const_iterator iter);
            const T& operator*() const;
            friend class SortedList<T>;
            bool operator!=(const_iterator other);
        };

        SortedList() = default;                         //constractor
        ~SortedList();                                  // destractor
        SortedList(const SortedList& list);             // copy
        void insert(const T& data);                     // insert
        const_iterator begin() const;                         // begin
        const_iterator end() const;                           // end
        void remove(const_iterator iterator);           // remove
        int length(const SortedList& list);             // length
        SortedList<T>& operator=(const SortedList& list); // operator =
        template<class condition>
        SortedList <T> &filter(condition cond);
        template<class operation>
        SortedList <T> &apply(operation oper);

    private:

        Node<T> *head = nullptr, *tail = nullptr;
        int size = 0;
        friend class const_iterator;
    };

    template<class T>
    T &Node<T>::operator*()
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
        T new_data = other.data;
        delete &data;
        data = new_data;
        return *this;
    }

    template<class T>
    Node<T>::Node(const T& data_to_insert)
    {
        T new_data = data_to_insert;
        data = new_data;
    }

    template<class T>
    Node<T>::Node(Node<T> &other)
    {
        data = *other;
    }

//    template<class T>
//    Node<T>::~Node()
//    {
//        delete &data;
//        delete next;
//    }

    template<class T>
    void SortedList<T>::insert(const T& data)
    {
        bool inserted = false;
        Node<T>* new_item = new Node<T>(data);
//        new_item.setData(data);
        if(size == 0)
        {
            head = new_item;
            new_item->setNext(tail);
            inserted = true;
        }
        if(data < **head)
        {
            new_item->setNext(head);
            head = new_item;
            inserted = true;
        }
        if(!inserted)
        {
            const_iterator item = begin();
            for (item = begin(); item + 1 != end(); ++item)
            {
                if (data < *(item + 1))
                {
                    new_item->setNext(item.getNext());
                    item.setNext(new_item);
                    inserted = true;
                    break;
                }
            }
            if(!inserted)
            {
                new_item->setNext(tail);
                item.setNext(new_item);
            }
        }

        size ++;
    }

    template<class T>
    void Node<T>::setNext(Node<T> *next)
    {
        this->next = next;
    }

//    template<class T>
//    void Node<T>::setData(const T &to_insert)
//    {
//        data = to_insert;
//    }
//

    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::begin() const
    {
        return const_iterator(head);
    }

    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::end() const
    {
        return const_iterator(tail);
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
        for (auto iter = begin(); iter != end(); ++iter)
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
        for (auto iter = list.begin(); iter != list.end(); ++iter)
        {
            this->insert(*(iter));
        }
    }

    template<class T>
    int SortedList<T>::length(const SortedList &list)
    {
        return size;
    }

    template<class T>
    SortedList<T> &SortedList<T>::operator=(const SortedList &list) //TODO
    {
        SortedList new_list(list);
        delete this;
        this = &new_list;
        return *this;
    }

    template<class T>
    template<class condition>
    SortedList <T> &SortedList<T>::filter(condition cond)
    {
        SortedList<T> new_list;
        for (auto iterator = begin(); iterator != end(); ++iterator)
        {
            if(cond(*iterator))
            {
                new_list.insert(iterator);
            }
        }
        return new_list;
    }

    template<class T>
    template<class operation>
    SortedList <T> &SortedList<T>::apply(operation oper)
    {
        SortedList<T> new_list;
        for (auto iterator = begin(); iterator != end(); ++iterator)
        {
            new_list.insert(oper(*iterator));
        }
        return new_list;
    }

    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::const_iterator::operator++() //TODO
    {
        if(this->element == nullptr)
        {
            throw std::out_of_range("out of range");
        }
        element = element->getNext();
        return *this;
    }

    template<class T>
    bool SortedList<T>::const_iterator::operator==(const_iterator iter)
    {
        return element == iter.element;
    }

    template<class T>
    const T &SortedList<T>::const_iterator::operator*() const
    {
        return **element;
    }


    template<class T>
    Node<T> *SortedList<T>::const_iterator::getNext()
    {
        return element->next;
    }

    template<class T>
    bool SortedList<T>::const_iterator::operator!=(SortedList::const_iterator other)
    {
        return element != other.element;
    }

    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::const_iterator::operator+(int number)
    {
        auto ret = *this;
        for (int i = 0; i<number; ++i)
        {
            ++ret;
        }
        return ret;
    }

    template<class T>
    void SortedList<T>::const_iterator::setNext(Node<T> *next)
    {
        element->setNext(next);
    }

    template<class T>
    SortedList<T>::const_iterator::const_iterator(Node<T> *node)
    {
        element = node;
    }

} // mtm

#endif //EX2_SORTEDLIST_H
