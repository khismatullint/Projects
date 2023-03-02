#include <cmath>
#include <iostream>
#include <string>
#include <vector>

void sift_up(std::vector<int>& heap, int i) {
    int parent = (int)std::floor((i - 1) / 2);
    if (i > 0 && heap[parent] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[parent];
        heap[parent] = temp;
        sift_up(heap, parent);
    }
}

void sift_down(std::vector<int>& heap, int i) {
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int largerChild;
    if (rightChild < heap.size() && heap[rightChild] > heap[leftChild]) {
        largerChild = rightChild;
    } else {
        largerChild = leftChild;
    }
    if (largerChild < heap.size() && heap[largerChild] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[largerChild];
        heap[largerChild] = temp;
        sift_down(heap, largerChild);
    }
}

void clear(std::vector<int>& heap) {
    for (int i = heap.size(); i > 0; --i) {
        heap.pop_back();
    }
}

void add(std::vector<int>& heap, int val) {
    heap.push_back(val);
    sift_up(heap, heap.size() - 1);
}

int extract(std::vector<int>& heap) {
    if (heap.size() != 0) {
        int res = heap[0];
        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        sift_down(heap, 0);
        std::cout << res << std::endl;
        return res;
    } else
        std::cout << "CANNOT" << std::endl;
    return 0;
}

int main() {
    std::vector<int> heap;
    std::string command;
    int val;
    while (std::cin >> command) {
        if (command == "ADD") {
            std::cin >> val;
            add(heap, val);
        } else if (command == "EXTRACT") {
            extract(heap);
        } else if (command == "CLEAR") {
            clear(heap);
        }
    }
    return 0;
}