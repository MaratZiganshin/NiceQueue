template <class T>
NiceStack<T>::NiceStack(size_t capacity)
{
    if (capacity == 0)
        throw std::invalid_argument("Invalid stack capacity!");
    m_capacity = capacity;
    storage = vector<TypeElementStack>(m_capacity);
    iHead = 0;
}

template <class T>
size_t NiceStack<T>::size() const
{
    return iHead;
}

template <class T>
void NiceStack<T>::push(T newelement) throw (out_of_range)
{
    if (iHead >= m_capacity) 
        throw std::out_of_range("Stack is full!");
    if (iHead == 0)
        storage[iHead++] = std::pair<T, T>(newelement, newelement);
    else if (storage[iHead - 1].second < newelement)
    {
        storage[iHead] = std::pair<T, T>(newelement, storage[iHead - 1].second);
        iHead++;
    }
    else
    {
        storage[iHead] = std::pair<T, T>(newelement, newelement);
        iHead++;
    }
}

template <class T>
T NiceStack<T>::pop(void) throw (out_of_range)
{
    if (iHead == 0)
        throw std::out_of_range("Stack is empty!");
    return storage[--iHead].first;
}

template <class T>
T NiceStack<T>::getMinimum(void) throw (out_of_range)
{
    if (iHead == 0)
        throw std::out_of_range("Stack is empty!");
    return storage[iHead - 1].second;
}



