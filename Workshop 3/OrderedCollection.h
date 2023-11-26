

#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H

#include "Collection.h"

namespace sdds
{
    template <typename T>
    class OrderedCollection : public Collection<T, 72>
    {
    public:
        virtual bool operator+=(const T &newItem) override
        {
            bool flag = Collection<T, 72>::operator+=(newItem);
            if (flag)
            {
                for (size_t i = Collection<T, 72>::size() - 1; i > 0 && Collection<T, 72>::operator[](i) < Collection<T, 72>::operator[](i - 1); --i)
                {
                    T temp = Collection<T, 72>::operator[](i);
                    Collection<T, 72>::operator[](i) = Collection<T, 72>::operator[](i - 1);
                    Collection<T, 72>::operator[](i - 1) = temp;
                }
            }
            return flag;
        }
    };
}

#endif /* OrderedCollection_h */
