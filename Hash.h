#pragma once
/*
 *C++ Program to Implement Hash Tables
 */
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 32;
 
/*
 * HashEntry Class Declaration
 */
class HashEntry
{
    public:
        int key;
        string value;
        HashEntry(int key, string value)
        {
            this->key = key;
            this->value = value;
        }
};
 
/*
 * HashMap Class Declaration
 */
class HashMap
{
    private:
        HashEntry **table;
    public:   
        HashMap()
	{
            table = new HashEntry * [TABLE_SIZE];
            for (int i = 0; i< TABLE_SIZE; i++)
            {
                table[i] = NULL;
            }
        }
        /*
         * Hash Function
         */
        int HashFunc(int key)
        {
            return key % TABLE_SIZE;
        }
        /*
         * Insert Element at a key
         */
	void Insert(int key, string value)
	{
            int hash = HashFunc(key);
            while (table[hash] != NULL && table[hash]->key != key)
            {
                hash = HashFunc(hash + 1);
            }
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key, value);
	}
        /*
         * Search Element at a key
         */
        string Search(int key)
	{
	    int  hash = HashFunc(key);
	    while (table[hash] != NULL && table[hash]->key != key)
	    {
	        hash = HashFunc(hash + 1);
	    }
	    if (table[hash] == NULL)
	        return "Not Found ";
	    else
	        return table[hash]->value;
        }
 
        /*
         * Remove Element at a key
         */
        void Remove(int key)
	{
	    int hash = HashFunc(key);
	    while (table[hash] != NULL)
	    {
	        if (table[hash]->key == key)
	            break;
	        hash = HashFunc(hash + 1);
	    }
            if (table[hash] == NULL)
	    {
                cout<<"No Element found at key "<<key<<endl;
                return;
            }
            else
            {
                delete table[hash];
            }
            cout<<"Element Deleted"<<endl;
        }
        ~HashMap()
	{
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                if (table[i] != NULL)
                    delete table[i];
                delete[] table;
            }
        }
};