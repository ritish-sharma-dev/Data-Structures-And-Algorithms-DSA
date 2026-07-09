// LEETCODE - 1823. Find the Winner of the Circular Game




class Solution {
public:
    int findTheWinner(int n, int k) {
        // TC : O(n^2)
        // AS : O(n)
        vector<int> no;

        for (int i = 1; i <= n; i++) {
            no.push_back(i);
        }

        int i = 0, cnt = 0;
        while (no.size() != 1) {
            while (cnt != k) {
                if (i > no.size() - 1)
                    i = i % no.size();
                cnt++;
                if (cnt != k)
                    i++;
            }

            no.erase(no.begin() + i);
            cnt = 0;
        }

        return no[0];
    }
};




class Node {
    int value;
    Node next;

    Node(int value) {
        this.value = value;
        next = null;
    }
}

class Solution{
    Node createLL(int n) {
        Node head = new Node(1);
        Node prev = head;
        for (int i = 2; i <= n; i++) {
            Node newNode = new Node(i);
            prev.next = newNode;
            prev = newNode;
        }
        prev.next = head;
        return head;
    }

    public int findTheWinner(int n, int k) {
        // TC : O(n*k)
        // AS : O(n)
        if (k == 1) return n;
        Node head = createLL(n);

        Node temp = head;
        int cnt = 0;
        while (temp.next != temp) {
            cnt++;

            if (cnt == k - 1) {
                temp.next = temp.next.next;
                cnt = 0;
            }
            temp = temp.next;
        }
        return temp.value;
    }
}




class Solution {
    public int findTheWinner(int n, int k) {
        // TC : O(n)
        // SC : O(n)
        if (n == 1) return 1;
        return (findTheWinner(n - 1, k) + k - 1) % n + 1;
    }
}



class Solution {
    public int findTheWinner(int n, int k) {
        // TC : O(n)
        // SC : O(1)
        int i = 1, ans = 0;
        while (i <= n){
            ans = (ans + k) % i;
            i++;
        }
        return ans + 1;
    }
}