#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Activity Selection Problem - Greedy Algorithm
 * Selects maximum number of non-overlapping activities
 */
struct Activity {
    int start, finish;
};

bool compareActivities(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

int activitySelection(vector<Activity>& activities) {
    // Sort activities by finish time
    sort(activities.begin(), activities.end(), compareActivities);
    
    int count = 0;
    int last_finish = -1;
    
    for (const auto& activity : activities) {
        if (activity.start >= last_finish) {
            count++;
            last_finish = activity.finish;
            cout << "Selected activity: start=" << activity.start 
                 << ", finish=" << activity.finish << endl;
        }
    }
    
    return count;
}

/**
 * Fractional Knapsack Problem - Greedy Algorithm
 * Maximizes value by taking fractions of items
 */
struct Item {
    int value, weight;
};

bool compareItems(Item i1, Item i2) {
    return (double)i1.value / i1.weight > (double)i2.value / i2.weight;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareItems);
    
    double total_value = 0.0;
    
    for (const auto& item : items) {
        if (capacity == 0) break;
        
        int taken_weight = min(item.weight, capacity);
        double fraction = (double)taken_weight / item.weight;
        
        total_value += fraction * item.value;
        capacity -= taken_weight;
        
        cout << "Taken: " << fraction * 100 << "% of item (value=" 
             << item.value << ", weight=" << item.weight << ")" << endl;
    }
    
    return total_value;
}

/**
 * Huffman Coding - Greedy Algorithm
 * Constructs optimal prefix codes for compression
 */
struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode *left, *right;
    
    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

void printCodes(HuffmanNode* root, string code) {
    if (!root) return;
    
    if (root->data != '$') {
        cout << root->data << ": " << code << endl;
    }
    
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

HuffmanNode* buildHuffmanTree(const string& text) {
    // Count frequency of each character
    vector<int> freq(256, 0);
    for (char c : text) {
        freq[(unsigned char)c]++;
    }
    
    // Create priority queue
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    
    // Create leaf nodes
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            pq.push(new HuffmanNode((char)i, freq[i]));
        }
    }
    
    // Build tree
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        
        HuffmanNode* internal = new HuffmanNode('$', left->freq + right->freq);
        internal->left = left;
        internal->right = right;
        
        pq.push(internal);
    }
    
    return pq.top();
}

// Test function
void testGreedyAlgorithms() {
    cout << "=== Activity Selection ===" << endl;
    vector<Activity> activities = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    int max_activities = activitySelection(activities);
    cout << "Maximum activities: " << max_activities << endl;
    
    cout << "\n=== Fractional Knapsack ===" << endl;
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    double max_value = fractionalKnapsack(items, capacity);
    cout << "Maximum value: " << max_value << endl;
    
    cout << "\n=== Huffman Coding ===" << endl;
    string text = "abracadabra";
    HuffmanNode* root = buildHuffmanTree(text);
    cout << "Huffman codes:" << endl;
    printCodes(root, "");
}

int main() {
    testGreedyAlgorithms();
    return 0;
}