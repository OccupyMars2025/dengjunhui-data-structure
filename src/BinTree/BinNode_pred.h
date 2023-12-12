// get 

#pragma once

// get the predecessor of the current node in the inorder sequence
template <typename T>
BinNodePosi<T> BinNode<T>::pred() {
    BinNodePosi<T> node = this;

    if(lc) {
        node = lc;
        while (HasRChild(*node))
        {
            node = node->rc;
        }
    } else {
        while (IsLChild(*node))
        {
            node = node->parent;
        }
        node = node->parent;     
    }

    return node;
}