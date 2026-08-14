class Solution {
public:
    vector<int> aStack;

    vector<int> asteroidCollision(vector<int>& asteroids) {

        if (asteroids.size() < 2)
            return asteroids;

        aStack.clear();
        aStack.push_back(asteroids[0]);

        for (int i = 1; i < asteroids.size(); i++) {

            // No collision
            if (aStack.empty() ||
                aStack.back() < 0 ||
                asteroids[i] > 0) {

                aStack.push_back(asteroids[i]);
                continue;
            }

            // Collision: top is positive, current is negative
            while (!aStack.empty() &&
                   aStack.back() > 0 &&
                   abs(aStack.back()) < abs(asteroids[i])) {

                aStack.pop_back();
            }

            // Stack is empty -> current survives
            if (aStack.empty()) {
                aStack.push_back(asteroids[i]);
                continue;
            }

            // Equal size -> both destroyed
            if (aStack.back() > 0 &&
                abs(aStack.back()) == abs(asteroids[i])) {

                aStack.pop_back();
                continue;
            }

            // Top is bigger -> current destroyed
            if (aStack.back() > 0 &&
                abs(aStack.back()) > abs(asteroids[i])) {

                continue;
            }

            // Otherwise current survives
            aStack.push_back(asteroids[i]);
        }

        return aStack;
    }
};