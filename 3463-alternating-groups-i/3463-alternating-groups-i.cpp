class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
if (n < 3) {
    return 0;
}

int alternating_groups = 0;

for (int i = 0; i < n; i++) {
    if (i > 0 && i < n - 1) {
        if (colors[i] != colors[i - 1] && colors[i] != colors[i + 1]) {
            alternating_groups++;
        }
    } else if (i == 0) {
        if (colors[i] != colors[n - 1] && colors[i] != colors[i + 1]) {
            alternating_groups++;
        }
    } else if (i == n - 1) {
        if (colors[i] != colors[i - 1] && colors[i] != colors[0]) {
            alternating_groups++;
        }
    }
}

return alternating_groups;
    }
};