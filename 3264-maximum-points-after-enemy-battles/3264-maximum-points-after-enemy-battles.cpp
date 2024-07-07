class Solution {
public:
    long long maximumPoints(std::vector<int>& enemyEnergies, int currentEnergy) {
        long long x = 0;
        sort(enemyEnergies.begin(), enemyEnergies.end());
        int j = enemyEnergies.size() - 1;
        int i = 0;
        while (i <= j) {
            // If the current energy is sufficient to defeat the enemy at position i
            if (currentEnergy >= enemyEnergies[i]) {
                // Calculate how many enemies of this type can be defeated and add to points
                x += currentEnergy / enemyEnergies[i];
                // Update the remaining energy after defeating as many enemies as possible
                currentEnergy = currentEnergy % enemyEnergies[i];
            } else {
                // If current energy is not enough for the enemy at position i,
                // Increase the energy by adding the energy of the enemy at position j
                currentEnergy += enemyEnergies[j--];
            }
            // If no points are gained, break the loop early
            if (x == 0) break;
        }
        return x;
    }
};