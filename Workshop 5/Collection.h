
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
namespace sdds {
template<typename T>
class Collection {
    std::string m_name;
    T* m_arr = nullptr;
    size_t m_size;
    void (*m_observer)(const Collection<T>&, const T&);
public:
    Collection(const std::string& name) {
        m_name = name;
        m_arr = nullptr;
        m_size = 0;
        m_observer = nullptr;
    }
    Collection(const Collection& source) = delete;
    Collection(const Collection&& source) = delete;
    Collection& operator=(const Collection& source) = delete;
    Collection& operator=(const Collection&& source) = delete;
    ~Collection() {
        delete[] m_arr;
    }
    const std::string& name() const {
        return m_name;
    }
    size_t size() const {
        return m_size;
    }
    void setObserver(void (*observer)(const Collection<T>&, const T&)) {
        m_observer = observer;
    }
    Collection<T>& operator+=(const T& item) {
        bool flag = true;
        for(size_t i = 0; i < m_size; i++) {
            if(m_arr[i].title() == item.title()) {
                flag = false;
            }
        }
        if(flag) {
            T* buffer = new T[m_size + 1];
            for(size_t i = 0; i < m_size; i++) {
                buffer[i] = m_arr[i];
            }
            buffer[m_size++] = item;
            delete[] m_arr;
            m_arr = buffer;
            if(m_observer) {
                m_observer(*this, item);
            }
        }
        return *this;
    }
    T& operator[](size_t idx) const {
        if(idx >= m_size || idx < 0) {
            throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
        }
        return m_arr[idx];
    }
    T* operator[](const std::string& title) const {
        T* buffer = nullptr;
        for(size_t i = 0; i < m_size; i++) {
            if(m_arr[i].title() == title) {
                buffer = &m_arr[i];
                i = m_size;
            }
        }
        return buffer;
    }
};
template<typename T>
std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
    for(size_t i = 0; i < collection.size(); i++) {
        os << collection[i];
    }
    return os;
}
}
#endif /* Collection_h */
