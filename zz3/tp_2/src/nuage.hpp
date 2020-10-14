#include "cartesien.hpp"
#include "polaire.hpp"

#include <vector>

template <typename T>
class Nuage
{
private:
    std::vector<T> _points;

public:
    using const_iterator = typename std::vector<T>::const_iterator;
    void ajouter(T);
    unsigned int size() const;
    const_iterator begin() const;
    const_iterator end() const;
};

template <typename T> 
T barycentre_v1(Nuage<T>&);

template <typename T, template <typename> class V>
T barycentre_v2(V<T> &);

template <typename T, template <typename, typename = std::allocator<T>> class V>
T barycentre_v2(V<T> &);