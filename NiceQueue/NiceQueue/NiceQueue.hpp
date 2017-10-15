template <class T>
NiceQueue<T>::NiceQueue(size_t capacity) : inStack(capacity), outStack(capacity)
{
    m_capacity = capacity;
}

template <class T>
size_t NiceQueue<T>::size(void) const
{
    return inStack.size() + outStack.size();
}

template <class T>
void NiceQueue<T>::enq(T newelement) throw (out_of_range)
{
    if (size() == m_capacity)
        throw std::out_of_range("Queue is full!");
    inStack.push(newelement);
}

template <class T>
T NiceQueue<T>::deq(void) throw (out_of_range)
{
    if (size() == 0)
        throw std::out_of_range("Queue is empty!");
    if (outStack.size() == 0)
        while (inStack.size() > 0)
            outStack.push(inStack.pop());
    return outStack.pop();
}

template <class T>
T NiceQueue<T>::getMinimum(void) throw (out_of_range)
{
    if (size() == 0)
        throw std::out_of_range("Queue is empty!");
    if (inStack.size() == 0)
        return outStack.getMinimum();
    if (outStack.size() == 0)
        return inStack.getMinimum();
    if (inStack.getMinimum() < outStack.getMinimum())
        return inStack.getMinimum();
    else return outStack.getMinimum();
}