#include <iostream>
#include <string>
#include <vector>
#include <stack>
 
using namespace std;

struct Post {
    string name;
    deque<int> s;
    void createPost(int num, string n);
    void printPost() const;
};

struct PostCompare {
    bool operator() (const Post& a, const Post&b) const {
        return a.name < b.name;
    }
};

void Post::createPost(int num, string n) {
    name = n;
    for(int i = num; i >= 1; i--) {
        s.push_front(i);
    }
}

void Post::printPost() const {
    for(int i : s) {
        cout << string(i, '_') << i << string(i, '_') << endl;
    }
}

void printDirection(Post source, Post dest) {
    cout << "Move a disc from peg " << source.name 
        << " to " << dest.name <<endl;
}

void makeMove(Post& source, Post& dest) {
    dest.s.push_front(source.s.front());
    source.s.pop_front();
}


void printRing(int total, int i, Post el) {
    if(el.s.size() > i) {
        int ring = el.s.at(i);
        int numspaces = total - ring;
        cout << string(numspaces, ' ') << string(ring, '_') 
            << ring << string(ring, '_') << string(numspaces, ' ');
    } else {
        cout << string((total*2) + 1, ' ');
    }
}

void printStacks(int total, Post source, Post spare, Post dest) {
    vector<Post> v;
    v.push_back(source);
    v.push_back(spare);
    v.push_back(dest);
    sort(v.begin(), v.end(), PostCompare());
    for(int i = 0; i < total; i++) {
        for(Post el : v) {
            printRing(total, i, el);
        }
        cout << endl;
    }
}

void directions(int total, int disk, Post& source, 
    Post& spare, Post& dest) {
    if(disk != 0) {
        directions(total, disk - 1, source, dest, spare);
        printDirection(source, dest);
        makeMove(source, dest);
        printStacks(total, source, spare, dest);
        directions(total, disk - 1, spare, source, dest);
    }
}


int main() {
    int num;
    cout << "Number of discs? ";
    cin >> num;
    Post a; Post b; Post c;
    a.createPost(num, "a");
    b.createPost(0, "b");
    c.createPost(0, "c");
    directions(num, num, a, b, c);
    return 0;
}
