#pragma once

#include <initializer_list>

namespace asg
{
template<class T>
class vector
{
  public:
    explicit vector(size_t count = 0);
    explicit vector(std::initializer_list<T> il_);

    ~vector() = default;

    T* front();
    T* back();

    size_t size() const;
    size_t capacity() const;
    bool empty() const;

  private:
    size_t calculate_capacity_from_count(size_t size);

    size_t size_ {0};
    size_t capacity_ {0};
    T* storage_ = nullptr;
};

template<class T>
T* asg::vector<T>::back()
{
    if(empty())
    {
        return nullptr;
    }

    return &storage_[ size_ - 1 ];
}

template<class T>
T* asg::vector<T>::front()
{
    if(empty())
    {
        return nullptr;
    }

    return &storage_[ 0 ];
}

template<class T>
asg::vector<T>::vector(size_t count /*= 0*/)
    : size_ {count}
    , capacity_ {calculate_capacity_from_count(count)}
    , storage_ {new T[ capacity_ * sizeof(T) ]}
{}

template<class T>
asg::vector<T>::vector(std::initializer_list<T> il_)
    : size_ {il_.size()}
    , capacity_ {calculate_capacity_from_count(size_)}
    , storage_ {new T[ capacity_ * sizeof(T) ]}
{
    int i {0};
    for(auto it = il_.begin(); it != il_.end(); ++it, ++i)
    {
        storage_[ i ] = *it;
    }
}

template<class T>
bool asg::vector<T>::empty() const
{
    return size_ == 0u;
}

template<class T>
size_t asg::vector<T>::capacity() const
{
    return capacity_;
}

template<class T>
size_t asg::vector<T>::calculate_capacity_from_count(size_t size)
{
    constexpr size_t initial_capacity = 16;
    if(size < initial_capacity)
    {
        return initial_capacity;
    }

    constexpr double golden_ratio = 1.618;
    const size_t cap              = size * golden_ratio;
    return cap;
}

template<class T>
size_t asg::vector<T>::size() const
{
    return size_;
}

} // namespace asg
