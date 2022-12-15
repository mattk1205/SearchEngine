//
// Created by mattw on 11/18/2022.
//

#ifndef FINALPROJEXAMPLES_HASHMAP_H
#define FINALPROJEXAMPLES_HASHMAP_H

#include <algorithm>
#include <string>
#include <vector>
#include <forward_list>
#include <cmath>

using namespace std;
template <typename Object>
class HashMap
{
private:
    vector<forward_list<Object>> buckets;   // The array of Lists
    size_t size;

    size_t hash(const string &key) const {
        size_t val = 0;
        for(size_t i = 0; i < key.length(); i++)
            val+=key[i]*pow(37,i);
        return val;
    }
    size_t hash(size_t key) const {
        return key;
    }

    void rehash()
    {
        vector<forward_list<Object>> tmp = buckets;
        size_t newSize = getNextPrime(buckets.size()*2);

        buckets.resize(newSize);
        for(size_t i = 0; i < buckets.size(); i++)
            buckets[i].clear();

        size = 0;
        for(size_t i = 0; i < tmp.size(); i++)
        {
            auto itr = tmp[i].cbegin();
            while(itr != tmp[i].cend())
                insert(*itr++);
        }
    }

    int getHash(const Object &x) const {
        int hashVal = hash(x);
        hashVal %= buckets.size();
        if(hashVal < 0)
            hashVal += buckets.size();
        return hashVal;
    }

    //GeeksForGeeks
    //https://www.geeksforgeeks.org/program-to-find-the-next-prime-number/
    bool isPrime(size_t x){
        if(x <= 1)
            return false;
        if(x == 2||x == 3)
            return true;
        if (x % 2 == 0 || x % 3 == 0)
            return false;

        for (size_t i = 5 ; i*i <= x; i+= 6)
            if ( x % i == 0 || x % (i+2) == 0)
                return false;

        return true;
    }
    size_t getNextPrime(size_t x) {
        if (x <= 1)
            return 2;
        bool prime = false;
        size_t nextPrime = x;
        while (!prime) {
            nextPrime++;
            if (isPrime(nextPrime))
                prime = true;
        }
        return nextPrime;
    }
public:
    HashMap(){
        size = 0;
        buckets.resize(101);
    }

    bool contains(const Object & x) const
    {
        const forward_list<Object> & whichList = buckets[getHash(x)];
        return find(whichList.begin(), whichList.end(), x) != whichList.end();
    }

    void makeEmpty()
    {
        for(size_t i = 0; i < buckets.size(); i++)
            buckets[i].clear();
    }

    HashMap& operator[](const Object& rhs){
        return getHash(hash(rhs));
    }

    bool remove(const Object &x){
        forward_list<Object> & list = buckets[getHash(x)];
        if(find(list.begin(), list.end(), x) == list.end())
            return false;
        list.remove(x);
        --size;
        return true;
    }

    bool insert(const Object &x)
    {
        forward_list<Object> & list = buckets[getHash(x)];
        if(find(list.begin(), list.end(), x) != list.end())
            return false;
        list.push_front(x);

        if(++size > buckets.size())
            rehash();
        return true;
    }

    void print(){
        vector<forward_list<Object>> tmp = buckets;
        cout << "Contents:" << endl;
        for(size_t i = 0; i < tmp.size(); i++){
                auto itr = tmp[i].cbegin();
                while(itr != tmp[i].cend()){
                    Object val = *itr;
                    cout << "value: " << val << "   key: " << getHash(val) << endl;
                    itr++;
                }
        }
        cout << "End" << endl;
    }
};






#endif //FINALPROJEXAMPLES_HASHMAP_H
