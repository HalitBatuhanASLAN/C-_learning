#ifndef RM_H
#define RM_H

#include<memory>
#include<utility>
#include<iostream>
class ResourceManager
{
    public:
        ResourceManager(int size):size(size){data = std::make_unique<int[]>(size);}
        ResourceManager(const ResourceManager& other);
        ResourceManager(ResourceManager&& other)noexcept;

        ResourceManager& operator=(const ResourceManager& other);
        ResourceManager& operator=(ResourceManager&& other) noexcept;
        
        void setValue(const int& index,const int& num);
        const int& getValue(const int& index)const; 
        ~ResourceManager(){}
    private:
        std::unique_ptr<int[]> data;
        int size;
};

#endif