#pragma once

#include <iostream>
#include <map>
#include <queue>


template<typename T>
struct Node 
{
    // NOTE:
    //   We are containing pointers to Node objects. 
    //   This means that it is a 'has a' relationship but as it is an 'aggregation', 
    //   it is not responsible for releasing the objects 
    Node<T> *m_left{nullptr};
    
    Node<T> *m_rigth{nullptr};
    T m_data;

    Node(T data);
};

template<typename T>
class BinaryTree
{
    private:
        // non-trivial type: we need a shadow copy since it is a pointer (rule of three).
        Node<T>* m_root{nullptr};

        void copy(const BinaryTree<T>& obj);
        void vertical_sum_interanl( Node<T>* current, int level, std::map<int, T>& sum_map);
    
    public:
        // Rule of three
        // 1 - constructor
        BinaryTree();
        // 2 - destructor
        ~BinaryTree();
        // 3 - copy constructor
        BinaryTree(const BinaryTree<T>& obj);
        // 3 - operator =
        BinaryTree<T>& operator=(const BinaryTree<T>& obj);
    
        Node<T>* add(T data);
    
        int max_witdh();
        std::map<int, T> vertical_sum();
    
        friend std::ostream& operator<<(std::ostream& lhs, const BinaryTree<T>& rhs)
        {
            std::queue<Node<T> *> q;
            if(rhs.m_root != nullptr)
                q.push(rhs.m_root);

            lhs << "[";
            while(!q.empty())
            {
                Node<T> *current = q.front();
                q.pop();

                if(current->m_left != nullptr)
                    q.push(current->m_left);
                
                if(current->m_rigth != nullptr)
                    q.push(current->m_rigth);
                
                lhs << current->m_data << ", ";
            }
            lhs << "]\n";
            
            return lhs;
        }
};

// explicitly instantiate the template, and its member definitions 
// Otherwise, it will not generate the version we need when we call it from main
template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<double>;