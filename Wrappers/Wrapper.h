#ifndef WRAPPER_H
#define WRAPPER_H

template <class T>
class Wrapper
{
public:
    Wrapper()
    {
        DataPtr = 0;
    }

    ~Wrapper()
    {
        delete DataPtr;
    }

    Wrapper(const T &inner)
    {
        DataPtr = inner.clone();
    }

    Wrapper(const Wrapper<T> &original)
    {
        if (original.DataPtr != 0)
            DataPtr = original.DataPtr->clone();
        else
            DataPtr = 0;
    }

    Wrapper &operator=(const Wrapper<T> &original)
    {
        if (this != &original)
        {
            if (DataPtr != 0)
                delete DataPtr;
            if (original.DataPtr != 0)
                DataPtr = original.DataPtr->clone();
        }
        return *this;
    }

    T &operator*()
    {
        return *DataPtr;
    }

    const T &operator*() const
    {
        return *DataPtr;
    }

    T *operator->()
    {
        return DataPtr;
    }

    const T *operator->() const
    {
        return DataPtr;
    }

private:
    T *DataPtr;
};

#endif