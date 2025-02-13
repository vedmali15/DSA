#include <iostream>
#define MAX_VALUE 65536
using namespace std;

class N { 
   public:
      int k;
      N *l, *r;
      bool leftTh, rightTh;
};

class TBT {
   private:
      N *root;
   public:
      TBT() { 
         root = new N();
         root->r = root->l = root;
         root->leftTh = true;
         root->k = MAX_VALUE;
      }

      void insert(int key) {
         N *p = root;
         for (;;) {
            if (p->k < key) { 
               if (p->rightTh) break;
               p = p->r;
            } 
            else if (p->k > key) { 
               if (p->leftTh) break;
               p = p->l;
            } 
            else return;
         }

         N *temp = new N();
         temp->k = key;
         temp->rightTh = temp->leftTh = true;

         if (p->k < key) {
            temp->r = p->r;
            temp->l = p;
            p->r = temp;
            p->rightTh = false;
         } 
         else {
            temp->r = p;
            temp->l = p->l;
            p->l = temp;
            p->leftTh = false;
         }
      }

      void inorder() { 
         N *temp = root, *p;
         for (;;) {
            p = temp;
            temp = temp->r;
            if (!p->rightTh) {
               while (!temp->leftTh) {
                  temp = temp->l;
               }
            }
            if (temp == root) break;
            cout << temp->k << " ";
         }
         cout << endl;
      }
};

int main() {
   TBT tbt;
   int n, key;
   cout << "Enter number of elements: ";
   cin >> n;
   cout << "Enter elements: ";
   for (int i = 0; i < n; i++) {
      cin >> key;
      tbt.insert(key);
   }
   cout << "Inorder Traversal: ";
   tbt.inorder();
}
