#include <iostream>
#include <vector>

struct Teque {
	int val;
	Teque *next;
    Teque *front;
    Teque *back;
    Teque() : val(0), next(nullptr), prev(nullptr) {}
	Teque(int x) : val(x), next(nullptr), prev(nullptr) {}
	Teque(int x, Teque *next) : val(x), next(next), prev(nullptr) {}
};

void get(Teque* node, int i) {
    if (i > 0) {
        get(node->next, i-1);
        return;
    } else {
        cout << node.val << "\n";
        return;
    }
}

void push_back(Teque* head, int i) {
    Teque* newNode(i);
    if (head->back) {
        head->back->next = newNode;
        head->back = newNode;
    } else {
        // Gonna assume that the list is empty here

    }
}

void push_middle(Teque* head, int i) {
    // Use slow and fast pointer method
    
}

// Consider using slow & fast ptr to get to middle?
int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string curr;

    // Initialize a Teque
    Teque* teque;
    teque->front = teque;
    teque->back = teque;
    
    while (string curr) {
        // Find a way to extract the method calls and argument
    }
}