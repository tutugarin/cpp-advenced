#pragma once

#include <vector>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <exception>
#include <vector>

template <class T>
class RubbishCollector {
private:
    std::vector<T*> data_{};

public:
    T* New(T* ptr) {
        data_.push_back(ptr);
        return ptr;
    }

    ~RubbishCollector() {
        for (T* ptr : data_) {
            delete ptr;
        }
    }
};

// HuffmanTree decoder for DHT section.
class HuffmanTree {
public:
    HuffmanTree() {
        root_ = collector_.New(new Node());
        building_node_ = root_;
        moving_node_ = root_;
    }
    // code_lengths is the array of size no more than 16 with number of
    // terminated nodes in the Huffman tree.
    // values are the values of the terminated nodes in the consecutive
    // level order.
    void Build(const std::vector<uint8_t>& code_lengths, const std::vector<uint8_t>& values);

    // Moves the state of the huffman tree by |bit|. If the node is terminated,
    // returns true and overwrites |value|. If it is intermediate, returns false
    // and value is unmodified.
    bool Move(bool bit, int& value);

private:
    struct Node {
        std::optional<uint8_t> value;
        Node* parent = nullptr;
        Node* left = nullptr;
        Node* right = nullptr;
        Node() = default;
        Node(Node* par) : parent(par) {
        }
    };

private:
    RubbishCollector<Node> collector_{};
    Node* root_;
    Node* building_node_;
    Node* moving_node_;
};
