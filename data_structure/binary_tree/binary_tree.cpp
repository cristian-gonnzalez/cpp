#include "binary_tree.h"
#include <queue>


template<typename T>
Node<T>::Node(T data)
:m_data{data}
{
}
 
template<typename T>
BinaryTree<T>::BinaryTree()
{
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& obj)
{
    copy(obj);
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
    std::queue<Node<T> *> q;
    if(m_root != nullptr)
        q.push(m_root);

    while(!q.empty())
    {
        Node<T> *current = q.front();
        q.pop();
        
        if(current->m_left != nullptr)
            q.push(current->m_left);
        
        if(current->m_rigth != nullptr)
            q.push(current->m_rigth);
        
        delete current;
    }
}


template<typename T>
void BinaryTree<T>::copy(const BinaryTree<T>& obj)
{
    std::queue<Node<T> *> q;
    if(obj.m_root != nullptr)
        q.push(obj.m_root);

    while(!q.empty())
    {
        Node<T> *current = q.front();
        q.pop();
        
        if(current->m_left != nullptr)
            q.push(current->m_left);
        
        if(current->m_rigth != nullptr)
            q.push(current->m_rigth);
        
        add(current->m_data);
    }
}

template<typename T>
void BinaryTree<T>::vertical_sum_interanl( Node<T>* current, int level, std::map<int, T>& sum_map)
{
    if(current != nullptr )
    {
        if( sum_map.contains(level))
            sum_map[level] += current->m_data;
        else
            sum_map[level] = current->m_data;
        
        vertical_sum_interanl( current->m_left, level-1, sum_map);
        vertical_sum_interanl( current->m_rigth, level+1, sum_map);
    }
}


/** Adds a node in BFS. 
 * 
 *  /param  data    Node data.
 *  /return  Pointer to the new node.
 */
template<typename T>
Node<T>* BinaryTree<T>::add(T data)
{
    // NOTE:
    //     We are allocating heap memory, we must release in the destructor
    Node<T>* node = new Node<T>(data);
    if(m_root == nullptr)
        m_root = node;
    else {
        std::queue<Node<T> *> q;
        q.push(m_root);

        while(!q.empty())
        {
            Node<T> *current = q.front();
            q.pop();
        
            if(current->m_left == nullptr)
            {
                current->m_left = node;
                break;
            }
            else 
                q.push(current->m_left);
            
            if(current->m_rigth == nullptr)
            {
                current->m_rigth = node;
                break;
            }
            else 
                q.push(current->m_rigth);
        }
    }
    return node;
}


/** Gets the maximun width.
 * 
 *  /return The maximun width.
 * 
 * NOTE:  
 *               1       = 1
 *            /    \   
 *           2      3    = 2
 *          / \    / \
 *         4   5  6   7  = 4 -> Maximun width 
 */
template<typename T>
int BinaryTree<T>::max_witdh()
{
    int max_width = 0;
    std::queue<Node<T> *> q;
    if(m_root != nullptr )
        q.push(m_root);
    
    while(!q.empty())
    {
        int width = q.size();
        if(width > max_width)
            max_width = width;
        
        while( width > 0)
        {
            Node<T>* current = q.front();
            q.pop();
            if(current->m_left != nullptr)
                q.push(current->m_left);
            if(current->m_rigth != nullptr)
                q.push(current->m_rigth);

            width--;
        }
    }

    return max_width;
}


/** Get the vertical sum.
 * 
 *  /return A map with {vertical_level, sum}.
 * 
 * NOTE:      
 *       -2 -1   0   1  2    
 *       _________________
 *        |  |   1   |  |  
 *        |  | / |  \|  |    
 *        |  2   |   3  |  
 *        | /| \ |  /| \|
 *        4  |   5 / |  7
 *        |  |   6   |  | 
 * 
 *        4  2  12   3  7 
 */
template<typename T>
std::map<int, T> BinaryTree<T>::vertical_sum()
{
    std::map<int, T> sum_map;
    if(m_root != nullptr )
    {
        int level = 0;
        vertical_sum_interanl( m_root, level, sum_map);
    }

    return sum_map;
}

template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& obj)
{
    copy(obj);
    return *this;
}

