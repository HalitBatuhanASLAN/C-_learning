#include"ResourceManager.h"
#include<exception>
#include<iostream>
ResourceManager::ResourceManager(const ResourceManager& other)
{
    size = other.size;
    data = std::make_unique<int[]>(other.size);
    for(int i = 0; i<size;i++)
        data[i] = other.data[i];
}
ResourceManager::ResourceManager(ResourceManager&& other)noexcept
{
    size = other.size;
    data = move(other.data);
    other.size = 0;
    other.data = nullptr;
}



ResourceManager& ResourceManager::operator=(const ResourceManager& other)
{
    size = other.size;
    data = std::make_unique<int[]>(other.size);
    for(int i = 0; i<size;i++)
        data[i] = other.data[i];
    return *this;
}
ResourceManager& ResourceManager::operator=(ResourceManager&& other)noexcept
{
    size = other.size;
    data = move(other.data);
    other.size = 0;
    other.data = nullptr;
    return *this;
}

void ResourceManager::setValue(const int& index,const int& num)
{
    if(index < size && index >= 0)
        data[index] = num;
    else
        throw std::out_of_range("index is out of range");
}

const int& ResourceManager::getValue(const int& index)const
{
    if(index < size && index >= 0)
        return data[index];
    else
        throw std::out_of_range("index is out of range");
} 