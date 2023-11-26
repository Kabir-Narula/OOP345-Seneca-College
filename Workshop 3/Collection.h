
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include "Book.h"
#include <iomanip>
namespace sdds
{
    template <typename T, unsigned C>
    class Collection
    {
        T m_items[C];
        static T m_smallestItem;
        static T m_largestItem;
        unsigned m_size = 0;

    protected:
        void setSmallestItem(const T &smallest)
        {
            if (smallest < m_smallestItem)
            {
                m_smallestItem = smallest;
            }
        }
        void setLargestItem(const T &largest)
        {
            if (m_largestItem < largest)
            {
                m_largestItem = largest;
            }
        }
        T &operator[](unsigned index)
        {
            return m_items[index];
        }
        unsigned incrSize()
        {
            return ++m_size;
        }

    public:
        static T getSmallestItem()
        {
            return m_smallestItem;
        }
        static T getLargestItem()
        {
            return m_largestItem;
        }
        unsigned size() const
        {
            return m_size;
        }
        unsigned capacity() const
        {
            return C;
        }
        virtual bool operator+=(const T &newItem)
        {
            bool flag = false;
            if (size() < capacity())
            {
                setSmallestItem(newItem);
                setLargestItem(newItem);
                m_items[m_size++] = newItem;
                flag = true;
            }
            return flag;
        }
        void print(std::ostream &os) const
        {
            os << "[";
            for (unsigned i = 0; i < size(); i++)
            {
                os << m_items[i];
                if (i < m_size - 1)
                {
                    os << ",";
                }
            }
            os << "]" << std::endl;
        }
    };
    template <>
    class Collection<Book, 10>
    {
        Book m_items[10];
        Book m_smallestItem = {"", 1, 10000};
        Book m_largestItem = {"", 10000, 1};
        unsigned m_size = 0;

    protected:
        void setSmallestItem(const sdds::Book &smallest)
        {
            if (smallest.ratio() < m_smallestItem.ratio())
            {
                m_smallestItem = smallest;
            }
        }

        void setLargestItem(const sdds::Book &largest)
        {
            if (m_largestItem.ratio() < largest.ratio())
            {
                m_largestItem = largest;
            }
        }
        Book &operator[](unsigned index)
        {
            return m_items[index];
        }

    public:
        Book &getSmallestItem()
        {
            return m_smallestItem;
        }

        Book &getLargestItem()
        {
            return m_largestItem;
        }

        unsigned size() const
        {
            return m_size;
        }

        unsigned capacity() const
        {
            return 10;
        }
        virtual bool operator+=(const Book &newItem)
        {
            bool flag = false;
            if (size() < capacity())
            {
                setSmallestItem(newItem);
                setLargestItem(newItem);
                m_items[m_size++] = newItem;
                flag = true;
            }
            return flag;
        }
        void print(std::ostream &os) const
        {
            os << "| " << std::setfill('-') << std::setw(75) << "-" << std::setfill(' ') << "|" << std::endl;
            for (unsigned i = 0; i < size(); i++)
            {
                os << "| ";
                os << m_items[i];
                os << " |" << std::endl;
            }
            os << "| " << std::setfill('-') << std::setw(75) << "-" << std::setfill(' ') << "|" << std::endl;
        }
    };

    template <>
    class Collection<Book, 72>
    {
        Book m_items[72];
        Book m_smallestItem = {"", 1, 10000};
        Book m_largestItem = {"", 10000, 1};
        unsigned m_size = 0;

    protected:
        void setSmallestItem(const sdds::Book &smallest)
        {
            if (smallest.ratio() < m_smallestItem.ratio())
            {
                m_smallestItem = smallest;
            }
        }

        void setLargestItem(const sdds::Book &largest)
        {
            if (largest.ratio() > m_largestItem.ratio())
            {
                m_largestItem = largest;
            }
        }
        Book &operator[](unsigned index)
        {
            return m_items[index];
        }

    public:
        Book &getSmallestItem()
        {
            return m_smallestItem;
        }

        Book &getLargestItem()
        {
            return m_largestItem;
        }

        unsigned size() const
        {
            return m_size;
        }

        unsigned capacity() const
        {
            return 72;
        }
        virtual bool operator+=(const Book &newItem)
        {
            bool flag = false;
            if (size() < capacity())
            {
                setSmallestItem(newItem);
                setLargestItem(newItem);
                m_items[m_size++] = newItem;
                flag = true;
            }
            return flag;
        }
        void print(std::ostream &os) const
        {
            os << "| " << std::setfill('-') << std::setw(75) << "-" << std::setfill(' ') << "|" << std::endl;
            for (unsigned i = 0; i < size(); i++)
            {
                os << "| ";
                os << m_items[i];
                os << " |" << std::endl;
            }
            os << "| " << std::setfill('-') << std::setw(75) << "-" << std::setfill(' ') << "|" << std::endl;
        }
    };

    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem = 9999;
    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem = -9999;
}

#endif /* Collection_h */
