// Link - https://bit.ly/3KbIjIW
// Time Complexity - O(1)
// Space Complexity - O(1)

class Queue {
public:
    int arr[10000];
    int qfront;
    int qrear;
    int size;
    Queue() {
        qfront = 0;
        qrear = 0;
        size = 10000;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == qrear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(qrear == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[qrear] = data;
            qrear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront == qrear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == qrear)
            {
                qfront = 0;
                qrear = 0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront == qrear)
        {
            return -1;
        }
        return arr[qfront];
    }
};
