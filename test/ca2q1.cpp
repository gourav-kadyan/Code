#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
#define pq priority_queue
#define pb push_back
#define ld long double
#define REP(x, n) for (int x = 0; x < n; x++)

using namespace std;

class Solution {
   public:
};
struct Node {
    ll value;
    Node *left, *right;
    Node(ll v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};
void bst(ll n, Node* root) {
    Node* node = new Node(n);
    if (n > root->value && !root->right) {
        root->right = node;
        return;
    }
    if (n < root->value && !root->left) {
        root->left = node;
        return;
    }
    if (n > root->value) {
        bst(n, root->right);
        return;
    } else {
        bst(n, root->left);
        return;
    }
}

void printTree(Node* root) {
    if (!root)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        ll c = q.size();
        while (c--) {
            Node* t = q.front();
            q.pop();
            if (t)
                cout << t->value << "\t";
            else {
                cout << "\t";
            }
            if (t) {
                q.push(t->left);
                q.push(t->right);
            }
        }

        cout << endl;
    }
}

void solve(Node* root, ll level) {
    queue<pair<Node*, char>> q;
    q.push({root, 'z'});
    level = 0;
    while (!q.empty()) {
        int c = q.size();
        while (c--) {
            Node* t = q.front().first;
            if (level % 2 == 0 && q.front().second == 'l') {
                cout << t->value << " ";
            } else if (level % 2 != 0 && q.front().second == 'r') {
                cout << t->value << " ";
            }
            q.pop();

            if (t->left) q.push({t->left, 'l'});

            if (t->right) q.push({t->right, 'r'});
        }
        level++;
    }
}
int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    REP(x, n) {
        cin >> v[x];
    }

    Node* virt = new Node(-1);
    for (int x = 0; x < n; x++) {
        bst(v[x], virt);
    }
    // printTree(virt->right);
    solve(virt->right, 0);

    return 0;
}