//
// Created by Tom Guy on 06/06/2021.
//

#ifndef EX2_SORTEDLIST_H
#define EX2_SORTEDLIST_H

namespace mtm
{

    template<class T>
    class SortedList
    {
    private:
        class Node
        {
        private:
            T data;
            Node *next = nullptr;

            T &operator*();

            Node &operator=(const Node &other);

            explicit Node(const T &data_to_insert);

            Node(Node &other);

            Node *getNext();

            void setNext(Node *next);

            friend class SortedList<T>;
        };

        Node *head = nullptr;
        Node *tail = nullptr;
        int size = 0;

        void clear();

    public:

        class const_iterator
        {
        private:
            class Node *element;

            class Node *getNext();

            const_iterator operator+(int number);

            void setNext(class Node *next);

            explicit const_iterator(class Node *node);

        public:
            const_iterator operator++();

            bool operator==(const_iterator iter);

            const T &operator*() const;

            friend class SortedList<T>;

            bool operator!=(const_iterator other);
        };

        SortedList() = default;                         // constructor
        ~SortedList();                                  // destructor
        SortedList(const SortedList &list);             // copy
        void insert(const T &data);                     // insert
        const_iterator begin() const;                         // begin
        const_iterator end() const;                           // end
        void remove(const_iterator iterator);           // remove
        int length();             // length
        SortedList<T> &operator=(const SortedList &list); // operator =
        template<class condition>
        SortedList<T> filter(condition cond);

        template<class operation>
        SortedList<T> apply(operation func);

    };

    template<class T>
    T &SortedList<T>::Node::operator*()
    {
        return data;
    }

    template<class T>
    typename SortedList<T>::Node *SortedList<T>::Node::getNext()
    {
        return next;
    }

    template<class T>
    typename SortedList<T>::Node &SortedList<T>::Node::operator=(const SortedList<T>::Node &other)
    {
        if (&other == this)
        {
            return *this;
        }
        T new_data = other.data;
        delete &data;
        data = new_data;
        return *this;
    }

    template<class T>
    SortedList<T>::Node::Node(const T &data_to_insert) : data(data_to_insert)
    {
    }

    template<class T>
    SortedList<T>::Node::Node(SortedList<T>::Node &other)
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
    void SortedList<T>::insert(const T &data)
    {
        bool inserted = false;
        auto *new_item = new SortedList<T>::Node(data);
//        new_item.setData(data);
        if (size == 0)
        {
            head = new_item;
            new_item->setNext(tail);
            inserted = true;
        }
        if (data < **head)
        {
            new_item->setNext(head);
            head = new_item;
            inserted = true;
        }
        if (!inserted)
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
            if (!inserted)
            {
                new_item->setNext(tail);
                item.setNext(new_item);
            }
        }

        size++;
    }

    template<class T>
    void SortedList<T>::Node::setNext(SortedList<T>::Node *new_next)
    {
        next = new_next;
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
        if ((*iterator_to_remove) == (**head))
        {
            SortedList<T>::Node *temp = head->getNext();
            delete head;
            head = temp;
            size--;
            return;
        }
        auto previous = begin();
        for (auto iter = begin(); iter != end(); ++iter)
        {
            if (iterator_to_remove == iter)
            {
                previous.setNext(iter.getNext());
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
            insert(*(iter));
        }
    }

    template<class T>
    int SortedList<T>::length()
    {
        return size;
    }

    template<class T>
    SortedList<T> &SortedList<T>::operator=(const SortedList &list)
    {
        if (&list == this)
        {
            return *this;
        }
        clear();
        for (auto iterator = list.begin(); iterator != list.end(); ++iterator)
        {
            insert(*iterator);
        }
        return *this;
    }

    template<class T>
    template<class condition>
    SortedList<T> SortedList<T>::filter(condition cond)
    {
        SortedList<T> new_list;
        for (auto iterator = begin(); iterator != end(); ++iterator)
        {
            if (cond(*iterator))
            {
                new_list.insert(*iterator);
            }
        }
        return new_list;
    }

    template<class T>
    template<class operation>
    SortedList<T> SortedList<T>::apply(operation func)
    {
        SortedList<T> new_list;
        for (auto iterator = begin(); iterator != end(); ++iterator)
        {
            new_list.insert(func(*iterator));
        }
        return new_list;
    }

    template<class T>
    void SortedList<T>::clear()
    {
        delete head;
        head = nullptr;
        size = 0;
    }

    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::const_iterator::operator++() //TODO
    {
        if (element == nullptr)
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
    typename SortedList<T>::Node *SortedList<T>::const_iterator::getNext()
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
        for (int i = 0; i < number; ++i)
        {
            ++ret;
        }
        return ret;
    }

    template<class T>
    void SortedList<T>::const_iterator::setNext(SortedList<T>::Node *next)
    {
        element->setNext(next);
    }

    template<class T>
    SortedList<T>::const_iterator::const_iterator(SortedList<T>::Node *node)
    {
        element = node;
    }

} // mtm

#endif //EX2_SORTEDLIST_H
