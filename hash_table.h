#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#ifndef HASH_TABLE
#define HASH_TABLE

struct hash_map { // hash map structure

  int size;

  int *hash;

  hash_map(int);
  void Linear_Probing(int);
  void Quadratic_Probing(int);
  void print(std::ofstream&);
  void Contents_To_Vector(std::vector<int>&);
};

hash_map::hash_map(int s) { // hash default constructor

  size = s;

  hash = new int[size];

  for (int i = 0; i < size; ++i) {

    hash[i] = -1;

  }

}

void hash_map::Linear_Probing(int key) { // linear probing for hash

  int index;

  for (int i = 0; i < size; ++i) {

    index = ((key % size) + i) % size;

    if (hash[index] == -1) {

      hash[index] = key;

      return;

    }
  }
}

void hash_map::Quadratic_Probing(int key) { // quadratic probing for hash

  int index;

  for (int i = 0; i < size; ++i) {

    index = ((key % size) + (3 * i) + (5 * i * i)) % size;

    if (hash[index] == -1) {

      hash[index] = key;

      return;
    }
  }
}

void hash_map::print(std::ofstream& ofs) { // take all non-'-1' values from hash and print in order

  std::vector<int> output_nums;

  for (int i = 0; i < size; ++i) {

    if (hash[i] != -1) {

      output_nums.push_back(hash[i]);

    }

  }

  for (int i = 0; i < output_nums.size() - 1; ++i) {

    ofs << output_nums[i] << ",";
  }

  ofs << output_nums[output_nums.size() - 1] << std::endl;

  return;

}

void hash_map::Contents_To_Vector(std::vector<int>& user_vector) { // relay hash contents to referenced vector for insertion into heap

    for (int i = 0; i < size; ++i) {

        if (hash[i] != -1) {

            user_vector.push_back(hash[i]);

        }

    }

    return;

}

struct min_heap { // heap structure

  int size;

  int *heap;

  min_heap(int);
  void push(int);

  void min_print(std::ofstream&);

};

min_heap::min_heap(int s) { // heap default constructor

  size = s;

  heap = new int[size];

  for (int i = 0; i < size; ++i) {

    heap[i] = -1;

  }
}

void min_heap::push(int key) { // insert into heap, switching indices of index and parent if index < parent

    int index;

    for (int i = 0; i < size; ++i) { // inserting into first possible place
        if (heap[i] == -1) {
            index = i;
            heap[i] = key;
            break;
        }
    }

    int parent = floor((index + 1) / 2) - 1;
    
    while ((heap[index] < heap[parent]) && (parent >= 0))  {

        int temp = heap[index];

        heap[index] = heap[parent];

        heap[parent] = temp;

        index = parent;

        parent = floor((index + 1) / 2) - 1;

    }

    return;
}

void min_heap::min_print(std::ofstream& ofs) { // prints contents of heap, all non-'-1' values

    std::vector<int> output_nums;

    for (int i = 0; i < size; ++i) {

        if (heap[i] != -1) {

            output_nums.push_back(heap[i]);

        }
    }

    for (int i = 0; i < output_nums.size() - 1; ++i) {

        ofs << output_nums[i] << ",";

    }

    ofs << output_nums[output_nums.size() - 1];

    return;

}

#endif
