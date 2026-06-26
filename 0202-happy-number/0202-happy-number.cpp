class Solution {
public:
    int find(int n) {
        int sum = 0;

        while (n > 0) {
            int d = n % 10;
            sum = sum + d * d;
            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (true) {
            slow = find(slow);
            fast = find(find(fast));

            if (slow == fast)
                break;
        }

        return slow == 1;
    }
};