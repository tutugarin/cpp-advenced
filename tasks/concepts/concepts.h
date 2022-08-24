#include <type_traits>
#include <iterator>

template <class P, class T>
concept Predicate = requires(P p, T t) {
    requires std::is_same_v<bool, decltype(p(t))>;
};

template <class T>
concept RandomAccess = requires(T t) {
    requires std::is_same_v<std::random_access_iterator_tag,
                            typename std::iterator_traits<decltype(t.begin())>::iterator_category>;
};

template <class T>
concept GetByIndex = requires(T t) {
    requires sizeof(t[size_t()]) != 0;
};

template <class T>
concept Indexable = RandomAccess<T> || GetByIndex<T>;
