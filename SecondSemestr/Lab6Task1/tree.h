#ifndef TREE_H
#define TREE_H
#include <QString>

namespace stlMax {
class MyTree
{
private:

    struct  TreeNode
    {
        int key;
        QString data;
        TreeNode* left;
        TreeNode* right;
        short height;
        TreeNode(int key, QString data) :
            key(key), data(data),
            left(nullptr), right(nullptr),
            height(1)
        {}
    };

    TreeNode* root;

    static void destroyNode(TreeNode* node) {
        if (node) {
            destroyNode(node->left);
            destroyNode(node->right);
            delete node;
        }

    }


    static QString inOrderPrint(TreeNode* root)
    {
        if (root == nullptr) {
            return "";
        }
        QString ans;
        ans += inOrderPrint(root->left);
        ans += root->data + " ";
        ans += inOrderPrint(root->right);
        return ans;
    }

    static QString preOrderPrint(TreeNode* root)
    {
        if (root == nullptr) {
            return "";
        }
        QString ans;
        ans += root->data + " ";
        ans += preOrderPrint(root->left);
        ans += preOrderPrint(root->right);
        return ans;
    }

    static QString postOrderPrint(TreeNode* root)
    {
        if (root == nullptr) {
            return "";
        }
        QString ans;
        ans += postOrderPrint(root->left);
        ans += postOrderPrint(root->right);
        ans += root->data + " ";
        return ans;
    }

    short preOrderCounter(TreeNode* root, short& counter) {
        if (root) {
            if (root->left && root->right)
                ++counter;
            preOrderCounter(root->left, counter);
            preOrderCounter(root->right, counter);
        }
        return counter;
    }

    static short Height(TreeNode* p)
    {
        return p ? p->height : 0;
    }

    static short Bfactor(TreeNode* p)
    {
        return Height(p->right) - Height(p->left);
    }

    static void fixHeight(TreeNode* p)
    {
        short hl = Height(p->left);
        short hr = Height(p->right);
        p->height = std::max(hl, hr) + 1;
    }

    static TreeNode* rotateRight(TreeNode* p)
    {
        TreeNode* q = p->left;
        p->left = q->right;
        q->right = p;
        fixHeight(p);
        fixHeight(q);
        return q;
    }

    static TreeNode* rotateLeft(TreeNode* q)
    {
        TreeNode* p = q->right;
        q->right = p->left;
        p->left = q;
        fixHeight(q);
        fixHeight(p);
        return p;
    }

    static TreeNode* Balance(TreeNode* p)
    {
        fixHeight(p);
        if (Bfactor(p) == 2) {
            if (Bfactor(p->right) < 0)
                p->right = rotateRight(p->right);
            return rotateLeft(p);
        }
        if (Bfactor(p) == -2) {
            if (Bfactor(p->left) > 0)
                p->left = rotateLeft(p->left);
            return rotateRight(p);
        }
        return p;
    }

    static TreeNode* Insert(TreeNode* p, int key, QString data)
    {
        if (!p) return new TreeNode(key, data);
        if (key < p->key)
            p->left = Insert(p->left, key, data);
        else
            p->right = Insert(p->right, key, data);
        return Balance(p);
    }

    static TreeNode* findMin(TreeNode* p) // поиск узла с минимальным ключом в дереве p
    {
        return p->left ? findMin(p->left) : p;
    }

    static TreeNode* removeMin(TreeNode* p) // удаление узла с минимальным ключом из дерева p
    {
        if (p->left == 0)
            return p->right;
        p->left = removeMin(p->left);
        return Balance(p);
    }

    static TreeNode* Delete(TreeNode* cur, int key) // удаление ключа k из дерева p
    {
        if (!cur) return 0;
        if (key < cur->key)
            cur->left = Delete(cur->left, key);
        else if (key > cur->key)
            cur->right = Delete(cur->right, key);
        else {
            TreeNode* q = cur->left;
            TreeNode* r = cur->right;
            delete cur;
            if (!r) return q;
            TreeNode* min = findMin(r);
            min->right = removeMin(r);
            min->left = q;
            return Balance(min);
        }
        return Balance(cur);
    }
public:
    MyTree() :
        root(nullptr) {}


    void Insert(int key, QString data) {
        root = Insert(root, key, data);
        //Balance();
    }

    QString Search(int key) {
        TreeNode* cur = root;
        while (cur) {
            if (key < cur->key) {
                cur = cur->left;
            }
            else if (key > cur->key) {
                cur = cur->right;
            }
            else {
                return cur->data;
            }
        }
        return "Not find";
    }

    short preOrderCounter() {
        short counter = 0;
        return preOrderCounter(root, counter);
    }

    void Delete(int key) {
        root = Delete(root, key);
        //Balance();
    }

    QString preOrderPrint()
    {
        return preOrderPrint(root);
    }

    QString inOrderPrint()
    {
        return inOrderPrint(root);
    }

    QString postOrderPrint()
    {
        return postOrderPrint(root);
    }

    void Destroy(int key) {
        TreeNode* cur = root;
        while (cur) {
            if (key < cur->key) {
                cur = cur->left;
            }
            else if (key > cur->key) {
                cur = cur->right;
            }
            else {
                destroyNode(cur);
            }
        }
        //Balance();
    }

    void Balance() {
        //RecBal(root);
    }

    bool isEmpty() {
        if(!Height(root))
            return true;
        else
            return false;
    }

};
}

#endif // TREE_H
