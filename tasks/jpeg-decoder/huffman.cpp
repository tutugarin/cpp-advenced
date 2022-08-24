#include "huffman.h"

void HuffmanTree::Build(const std::vector<uint8_t> &code_lengths,
                        const std::vector<uint8_t> &values) {
    if (code_lengths.size() > 16) {
        throw std::invalid_argument("Huffman too big");
    }
    uint32_t expected_count = 0;
    for (uint8_t i = 0; i != code_lengths.size(); ++i) {
        expected_count += code_lengths[i];
        if (code_lengths[i] > (1 << (i + 1))) {
            throw std::invalid_argument("Too many values at same height");
        }
    }
    if (expected_count < values.size()) {
        throw std::invalid_argument("Huffman short");
    }
    if (expected_count > values.size()) {
        throw std::invalid_argument("Huffman fat");
    }

    size_t index = 0;
    int16_t current_height = 0;
    for (uint8_t len = 0; len != code_lengths.size(); ++len) {
        size_t inserted_nodes = 0;
        while (inserted_nodes < code_lengths[len]) {
            if (current_height == len + 1) {
                if (building_node_->value.has_value()) {
                    throw std::invalid_argument("Node has already got value");
                }
                building_node_->value = values[index++];
                ++inserted_nodes;

                if (current_height == 0 || building_node_->parent == nullptr) {
                    throw std::invalid_argument("Something goes wrong while inserting value");
                }
                building_node_ = building_node_->parent;
                --current_height;
                continue;
            }
            if (building_node_->left == nullptr) {
                building_node_->left = collector_.New(new Node(building_node_));
                building_node_ = building_node_->left;
                ++current_height;
                continue;
            }
            if (building_node_->right == nullptr) {
                building_node_->right = collector_.New(new Node(building_node_));
                building_node_ = building_node_->right;
                ++current_height;
                continue;
            }
            if (building_node_->parent == nullptr) {
                throw std::invalid_argument("Something goes wrong while building");
            }
            building_node_ = building_node_->parent;
            --current_height;
        }
    }
}

bool HuffmanTree::Move(bool bit, int &value) {
    if (moving_node_ == nullptr) {
        throw std::invalid_argument("Something goes wrong while moving");
    }
    if (bit) {
        moving_node_ = moving_node_->right;
    } else {
        moving_node_ = moving_node_->left;
    }
    if (moving_node_ == nullptr) {
        throw std::invalid_argument("Something goes wrong while moving");
    }
    if (moving_node_->value.has_value()) {
        value = moving_node_->value.value();
        moving_node_ = root_;
        return true;
    }
    return false;
}
