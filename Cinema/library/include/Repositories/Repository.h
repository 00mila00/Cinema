//
// Created by student on 12.06.2020.
//

#ifndef repositoryClass
#define repositoryClass
#include <memory>
#include <string>

template <class T>
class Repository {

    virtual bool add(const std::shared_ptr<T>&)= 0;
    virtual bool remove(const std::shared_ptr<T>&)= 0;
    virtual std::string report() const= 0;
    virtual unsigned int size() = 0;
    virtual std::shared_ptr<T> search(unsigned int) = 0;

   // virtual ~Repository()= default;
};

#endif //LIBRARY_REPOSITORY_H
